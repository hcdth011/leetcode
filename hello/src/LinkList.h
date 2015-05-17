/*
 * LinkList.h
 *
 *  Created on: Mar 5, 2015
 *      Author: will
 */

#ifndef LINKLIST_H_
#define LINKLIST_H_

typedef  int DataType;
typedef struct Node
{
  DataType data;
  struct Node *next;
}ListNode,*LinkList;

void InitList(LinkList *head)
{
   if((*head=(LinkList)malloc(sizeof(ListNode)))== NULL)
	    exit(-1);
   (*head)->next = NULL ;
}



#endif /* LINKLIST_H_ */
