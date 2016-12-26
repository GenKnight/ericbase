#ifndef DBF_STRUCT
#define DBF_STRUCT
#pragma pack(push,1)
struct InfoOfDbfHead {
	unsigned char  tab;
	unsigned char  year;
	unsigned char  month;
	unsigned char  day;
	unsigned int   recnum;
	unsigned short offset;
	unsigned short reclen;
	char  save[20];
};

struct InfoOfDbfIndex {
	unsigned char fname[11];
	unsigned char type;
	int  addr;
	unsigned char width;
	unsigned char doc;
	char save[14];
	InfoOfDbfIndex()
	{
	}
} ;

#pragma pack(pop)
#endif