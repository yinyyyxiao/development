#include "CLinkList.h"
#include <iostream>
#include "CLog.h"
using namespace std;
LinkList* CLinkList::initlist()
{
	DBUG_LOG(" call\n");
	LinkList* phead = (LinkList*)malloc(sizeof(LinkList));
	if(NULL == phead)
	{
		return NULL;
	}
	DBUG_LOG(" end\n");
	return phead;
}
void CLinkList::destroy(LinkList*phead)
{
	DBUG_LOG(" call\n");
	if(NULL != phead)
	{
		if(phead->pNext)
		{
			LinkList *pTmp =  phead->pNext;
			LinkList*pDel = NULL;
			int i = 0;
			while(pTmp != NULL)
			{
				cout<<++i<<endl;
				pDel = pTmp->pNext;
				free(pTmp);
				pTmp = pDel;
			}
			free(phead);
			phead = NULL;
		}
	}
	DBUG_LOG(" end\n");
}
int CLinkList::insertList(LinkList*phead,int data,int offset)
{
	DBUG_LOG(" call\n");
	if(( NULL == phead ) || ( offset < -2 ))
	{
		return D_ERR;
	}
	LinkList* pNode = (LinkList*)malloc(sizeof(LinkList));
	if(NULL == pNode)
	{
		return D_ERR;		
	}
	pNode->data = data;
	switch(offset)
	{	case HEADER:
			{
				pNode->pNext = phead->pNext;
				phead->pNext = pNode;
			}
			break;
		case TAIL:
			{
				LinkList*pTmp = phead->pNext;
				while(NULL != pTmp->pNext)
				{
					pTmp = pTmp->pNext;
				}
				pTmp->pNext = pNode;
			}
			break;
		default:
			{
				LinkList*pTmp = phead;
				while(offset--)
				{
					if(NULL == pTmp)
					{
						free(pNode);
						pNode = NULL;
						return D_ERR;
					}
					else
					{
						pTmp = pTmp->pNext;
					}
				}
				if(NULL == pTmp->pNext)
				{
					pTmp->pNext = pNode;
					return D_OK;
				}
				pNode->pNext = pTmp->pNext;
				pTmp->pNext = pNode;
				cout<<pNode->data<<endl;
			}
			break;
	}
	DBUG_LOG(" end\n");
	return D_OK;
}
int CLinkList::delList(LinkList*phead,int* data,int offset)
{
	DBUG_LOG(" call\n");
	if((NULL == phead) || (offset < -2) || (NULL == data))
	{
		return D_ERR;
	}
	if(offset == HEADER)
	{
		if(phead->pNext == NULL)
		{
			return D_ERR;
		}
		LinkList*pDel = phead->pNext;
		*data = pDel->data;
		phead->pNext = pDel->pNext;
		if(pDel != NULL)
		{
			free(pDel);
			pDel = NULL;
		}
	}
	else
	{ 
		LinkList*pTmp = phead;
		while(offset--)
		{
			if(pTmp == NULL)
			{
				return D_ERR;
			}
			else if(pTmp->pNext == NULL)
			{
				return D_ERR;
			}
			else
			{
				pTmp = pTmp->pNext;
			}
		}
		LinkList* pDel = pTmp->pNext;
		*data = pDel->data;
		pTmp->pNext = pDel->pNext;
		if(pDel !=  NULL)
		{
			free(pDel);
			pDel = NULL;
		}
	}
	cout<<endl;
	return D_OK;
}
int CLinkList::showList(LinkList * phead)
{
	DBUG_LOG(" call\n");
	if(NULL == phead)
	{
		return D_ERR;
	}
	if(phead->pNext == NULL)
	{
		return D_ERR;
	}
	LinkList*pTmp = phead->pNext;
	while(pTmp != NULL)
	{
		printf(" %d ",pTmp->data);
		pTmp = pTmp->pNext;
	}
	DBUG_LOG(" end\n");
	return D_OK;
}
int CLinkList::serchList(LinkList*phead,int data)
{
}
int CLinkList::updateList(LinkList*phead,int New ,int old)
{
}
CLinkList::CLinkList()
{
}
CLinkList::~CLinkList()
{
}
