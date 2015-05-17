/*
 * romoveListNodeFromEnd.cpp
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
         int N=0 ; //节点数目
         int j=0;
         ListNode *p , *pre;
         p=head;
         while(p->next != NULL)
         {
             N++;
             p=p->next;
         }
         if(N<n)
        	 exit(-1);
         pre=head;
         while(j<N-n)
         {
        	pre=pre->next;
        	j++;
         }
         p=pre->next;
         pre->next=p;

         return head;
    }
};


