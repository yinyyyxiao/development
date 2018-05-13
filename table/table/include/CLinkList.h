#ifndef _LINK_LIST_H
#define _LINK_LIST_H
#include "CLog.h"
enum
{
	D_OK,
	D_ERR
};
enum 
{
	MID  = -2,
	TAIL,
	HEADER
};

typedef struct LinkList
{
	int data;
	struct LinkList * pNext;

}LinkList;


class CLinkList
{

public:
	LinkList* initlist();
	void destroy(LinkList*phead);
	int insertList(LinkList*phead,int data,int offset);
	int delList(LinkList*phead,int* data,int offset);
	int showList(LinkList * phead);
	int serchList(LinkList*phead,int data);
	int updateList(LinkList*phead,int New ,int old);
//private:
	CLinkList();
	~CLinkList();
};




#endif //_LINK_LIST_H
