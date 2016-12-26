#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>

#ifdef WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>
#include <io.h>
#include <fcntl.h>
#ifndef S_ISDIR
#define S_ISDIR(x) (((x) & S_IFMT) == S_IFDIR)
#endif
#else
#include <sys/stat.h>
#include <sys/socket.h>
#include <signal.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#endif

#include <event2/event.h>
#include <event2/http.h>
#include <event2/buffer.h>
#include <event2/util.h>
#include <event2/keyvalq_struct.h>
#include <event2/buffer_compat.h>
#include <evhttp.h>
#ifdef _EVENT_HAVE_NETINET_IN_H
#include <netinet/in.h>
# ifdef _XOPEN_SOURCE_EXTENDED
#  include <arpa/inet.h>
# endif
#endif
#include <string>
#include <iostream>
/* Compatibility for possible missing IPv6 declarations */
#include "util-internal.h"

#define BUF_MAX 1024*16

void
root_handler(struct evhttp_request *req, void *arg)
{
	struct evbuffer *buf;

	buf = evbuffer_new();
	if (buf == NULL) return;

	evbuffer_add_printf(buf, "Hello World!\n");
	evhttp_send_reply(req, HTTP_OK, "OK", buf);
}

void
generic_handler(struct evhttp_request *req, void *arg)
{
	const char *cmdtype;

	switch (evhttp_request_get_command(req)) {
	case EVHTTP_REQ_GET: cmdtype = "GET"; break;
	case EVHTTP_REQ_POST: cmdtype = "POST"; break;
	case EVHTTP_REQ_HEAD: cmdtype = "HEAD"; break;
	case EVHTTP_REQ_PUT: cmdtype = "PUT"; break;
	case EVHTTP_REQ_DELETE: cmdtype = "DELETE"; break;
	case EVHTTP_REQ_OPTIONS: cmdtype = "OPTIONS"; break;
	case EVHTTP_REQ_TRACE: cmdtype = "TRACE"; break;
	case EVHTTP_REQ_CONNECT: cmdtype = "CONNECT"; break;
	case EVHTTP_REQ_PATCH: cmdtype = "PATCH"; break;
	default: cmdtype = "unknown"; break;
	}

	printf("Received a %s request for %s\n",
	    cmdtype, evhttp_request_get_uri(req));

	static char _buf[ BUF_MAX ];
	std::string out;
    size_t post_size = EVBUFFER_LENGTH(req->input_buffer);

    printf("len = %d\n", post_size);
    if (post_size > 0 )
    {
        size_t copy_len = post_size > BUF_MAX ? BUF_MAX : post_size;
        memcpy (_buf, EVBUFFER_DATA(req->input_buffer), copy_len);
        out.assign(_buf, copy_len);
    }

	std::cout << out << std::endl;

    // process posted data

    struct evbuffer *pe = evbuffer_new();
    evbuffer_add(pe, out.data(), out.size());
    evhttp_send_reply(req, HTTP_OK, "OK", pe);
    evbuffer_free(pe);


	struct evkeyvalq *output_Headers = evhttp_request_get_output_headers(req);

	struct evhttp_connection *conn = evhttp_request_get_connection(req);
	char *addr;
	ev_uint16_t port;
	evhttp_connection_get_peer(conn, &addr, &port);

	const char *mncg_query_part = evhttp_request_get_uri(req);
	const char *mncg_query_part1 = NULL;

	if (strncmp(mncg_query_part, "/?", 2) == 0){
		mncg_query_part1 = mncg_query_part+2;
	}

	struct evkeyvalq mncg_http_query;
	memset(&mncg_http_query, 0, sizeof(mncg_http_query));

	evhttp_parse_query_str(mncg_query_part1, &mncg_http_query);

	const char *mncg_input_opt = evhttp_find_header (&mncg_http_query, "score");

    struct evbuffer *evb = evbuffer_new();
    if (evb == NULL) return;
    evbuffer_add_printf(evb, "Requested: %s", mncg_input_opt);
    evhttp_send_reply(req, HTTP_OK, "OK", evb);
}

int
main1(int argc, char **argv)
{
	struct event_base *base;
	struct evhttp *http;
	struct evhttp_bound_socket *handle;

	unsigned short port = 7070;
#ifdef WIN32
	WSADATA WSAData;
	WSAStartup(0x101, &WSAData);
#else
	if (signal(SIGPIPE, SIG_IGN) == SIG_ERR)
		return (1);
#endif

	base = event_base_new();
	if (!base) {
		fprintf(stderr, "Couldn't create an event_base: exiting\n");
		return 1;
	}

	/* Create a new evhttp object to handle requests. */
	http = evhttp_new(base);
	if (!http) {
		fprintf(stderr, "couldn't create evhttp. Exiting.\n");
		return 1;
	}

	/* Set a callback for requests to "/". */
	//evhttp_set_cb(http, "/order_create", root_handler, NULL);
	
	/* Set a callback for all other requests. */
	evhttp_set_gencb(http, generic_handler, NULL);

	/* Now we tell the evhttp what port to listen on */
	handle = evhttp_bind_socket_with_handle(http, "0.0.0.0", port);
	if (!handle) {
		fprintf(stderr, "couldn't bind to port %d. Exiting.\n",
		    (int)port);
		return 1;
	}

	event_base_dispatch(base);

	evhttp_free(http);

	return 0;
}