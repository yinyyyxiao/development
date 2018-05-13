#include "CLinkList.h"
#include <iostream>
using namespace std;

FILE*LogToFile = NULL;


int main()
{
	LogToFile = fopen("DBUG_LOG.txt","a+");
	DBUG_LOG(" call\n");
	int i4Ret = D_ERR;
	CLinkList* _m_pList = new CLinkList();
	if(NULL == _m_pList)
	{
		DBUG_LOG("create obj error\n");
		return D_ERR;
	}
	DBUG_LOG("create obj ok \n");
	LinkList*phead = _m_pList->initlist();
	if(NULL == phead)
	{
		DBUG_LOG("init list error\n");
		return D_ERR;
	}
	DBUG_LOG("init list ok \n");
	i4Ret = _m_pList->insertList(phead,1,HEADER);
	if(D_ERR == i4Ret)
	{
		DBUG_LOG("insert list error\n");
		return D_ERR;
	}
	DBUG_LOG("insert list ok\n");
	i4Ret = _m_pList->insertList(phead,2,TAIL);
	if(D_ERR == i4Ret)
	{
		DBUG_LOG("insert list error\n");
		return D_ERR;
	}
	DBUG_LOG("insert list ok\n");
	i4Ret = _m_pList->insertList(phead,4,2);
	if(D_ERR == i4Ret)
	{
		DBUG_LOG("insert list error\n");
		return D_ERR;
	}
	DBUG_LOG("insert list ok\n");
	i4Ret = _m_pList->insertList(phead,5,2);
	if(D_ERR == i4Ret)
	{
		DBUG_LOG("insert list error\n");
		return D_ERR;
	}
	DBUG_LOG("insert list ok\n");
	i4Ret = _m_pList->showList(phead);
	if(D_ERR == i4Ret)
	{
		return D_ERR;
	}
	DBUG_LOG("show list ok\n");
	_m_pList->destroy(phead);
	if(_m_pList != NULL)
	{
		delete _m_pList;
		_m_pList = NULL;
	
	}
	DBUG_LOG("destroy list ok\n");
	if(NULL != LogToFile)
	{
		DBUG_LOG(" end\n");
		fclose(LogToFile);
	}
	return 0;
}
