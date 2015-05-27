#include<stdio.h>
#include<stdlib.h>
#include"list.h"

/*局部函数原型*/
static void CopyToNode(Item item,Node * pnode);

/*接口函数*/
/*把列表设置为空列表*/
void InitializeList(List  *plist)
{
	*plist = NULL;
}
int ListIsEmpty(const List *plist)
{
	if(* plist == NULL)
		return true;
	else
		return false;
}
int ListIsFull(const List * plist)
{
	Node * pt;
	int full;
	pt = (Node *)malloc(sizeof(Node) );
	if(pt == NULL)
		full = true;
	else
		full =false;
	free(pt);
	return full;
}

/*返回节点数*/
unsigned int ListItemCount(const List * plist)
{
	unsigned int count = 0;
	Node * pnode = *plist;
	while(pnode != NULL)
	{
		++count;
		pnode = pnode->next;
	}
	return count;

}
/*创建存放项目的节点，并把它添加到 */
/*由plist指向的尾部*/
int AddItem(Item item,List * plist)
{
	Node * pnew;
	Node * scan = *plist;
	pnew = (Node *)malloc(sizeof(Node) );
	if(pnew == NULL)
		return false;/*失败时退出函数*/

	CopyToNode(item,pnew);
	pnew->next = NULL;
	if(scan == NULL)
		* plist = pnew;
	else
	{
		while(scan -> next != NULL)
			scan = scan->next;
		scan ->next = pnew;
	}
	return true;

}
	void Traverse (const List * plist,void(* pfun)(Item item) )
	{
		Node * pnode = * plist;
		while(pnode != NULL)
		{
			(* pfun)(pnode->item);
			pnode = pnode ->next;

		}
	}
void EmptyTheList(List * plist)
{
	Node * psave;
	while(*plist != NULL)
	{
		psave = (*plist) ->next;
		free(*plist);
		*plist = psave;
	}
}
/*局部函数定义*/
/*把一个项目复制到一个节点上*/
static void CopyToNode(Item item,Node *pnode)
{
	pnode->item = item;
}
