#include <iostream>
#include <sstream>
#include <map>
#include <signal.h>
#include <stdio.h>
#include <memory>
#include <vector>
#include <set>
#include <assert.h>
#include <unordered_map>

using namespace std;

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
};

#pragma pack(pop)

int dbf_main(int argc,char *argv[])
{
    FILE* fdbf;
    InfoOfDbfHead dbf_head;
    if ((fdbf = fopen("./show2003.dbf", "r+b")) == NULL) {
        return -1;
    }

    fseek(fdbf, 0L, SEEK_SET);
    fread(&dbf_head, sizeof(InfoOfDbfHead), 1, fdbf);
    cout << "recnum:" << dbf_head.recnum << " offset:" << dbf_head.offset << " reclen:" << dbf_head.reclen << endl;

    int fieldnum = (dbf_head.offset - 1) / 32 - 1;
    cout << "fieldnum: " << fieldnum << endl;
    fseek(fdbf, sizeof(InfoOfDbfHead), SEEK_SET);

    InfoOfDbfIndex* dbf_index = new InfoOfDbfIndex[fieldnum];

    for (int i = 0; i < fieldnum; i++)
    {
        fread(&(dbf_index[i]), sizeof(InfoOfDbfIndex), 1, fdbf);

        cout << "fname:" << dbf_index[i].fname << " type:" << dbf_index[i].type 
             << " addr:" << dbf_index[i].addr << " width:" << dbf_index[i].width 
             << " doc:" << dbf_index[i].doc << endl;
    }

	getchar();
	return 0;
}

