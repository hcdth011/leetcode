/*
 * addTwoNumbers.cpp
 *
 *  Created on: Mar 6, 2015
 *      Author: will
 */
#include<stdio.h>
#include<iostream>
#include <stdlib.h>
using namespace std;

typedef struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
}Node;


class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *result;
        ListNode *L1,*L2;
        ListNode *Res ,*opt;
        int carry=0,num=0;
        L1=l1;
        L2=l2;

        result=new ListNode(0); //申请新节点
        result->next=new ListNode(0);
        opt= result ;
        while( L1 != NULL && L2 !=NULL )
        {

        	Res=new ListNode(0); //申请新节点

            num= (*L1).val +(*L2).val + carry ;
            (*Res).val = num%10  ;
            carry= num /10 ;
            opt->next =Res;
            opt = opt->next ;
            L1 = (*L1).next ;
            L2 = (*L2).next ;
        }

        while(L1 != NULL)
        {

        	Res=new ListNode(0); //申请新节点

            num= (*L1).val ;
            (*Res).val = (num + carry)%10 ;
            carry= (num + carry) /10 ;

            opt->next =Res;
            opt = opt->next ;

            L1 = (*L1).next ;

        }

        while(L2 != NULL)
        {

        	Res=new ListNode(0); //申请新节点
            num= (*L2).val ;
            (*Res).val = (num + carry)%10 ;
            carry= (num + carry) /10 ;

            L2 = (*L2).next ;
            opt->next =Res;
            opt = opt->next ;
        }
        if(carry>0)
        {
        	opt->next =new ListNode(0); //申请新节点
        	opt->next->val = carry ;
        }

        return result->next ;
    }
};

int main()
{
	ListNode *l1;
	ListNode *l2;
	ListNode *result;
	ListNode *da1;
	ListNode *da2;
	cout<< "hello1"<<endl;
	l1=(ListNode *)malloc(sizeof(ListNode)); //申请新节点
	l2=(ListNode *)malloc(sizeof(ListNode)); //申请新节点
	da1=(ListNode *)malloc(sizeof(ListNode)); //申请新节点
	da1->val= 9 ;
	da2=(ListNode *)malloc(sizeof(ListNode)); //申请新节点
    da2->val= 9 ;

    da1->next=(ListNode *)malloc(sizeof(ListNode)); //申请新节点
    da1->next->val= 9 ;
    da1->next->next=(ListNode *)malloc(sizeof(ListNode)); //申请新节点
    da1->next->next->val= 9 ;
   // da2->next=(ListNode *)malloc(sizeof(ListNode)); //申请新节点
   // da2->next->val= 5 ;

	//l1->next = da1 ;
	//l2->next = da2 ;
	l1 = da1 ;
    l2 = da2 ;
	Solution add;
	result= add.addTwoNumbers(l1,l2);
	cout<< "hello2"<<endl;
	cout<< "result= " << result->next->next->next->val<< result->next->next->val << result->next->val<< result->val <<endl;
	return 1 ;
}





