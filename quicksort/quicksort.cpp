/*
 * quicksort.cpp
 *
 *  Created on: Apr 24, 2015
 *      Author: will
 */
#include <stdio.h>
#include <iostream>

using namespace std;

//快速排序
void quick_sort(int s[], int l, int r)
{
    if (l < r)
    {
		//Swap(s[l], s[(l + r) / 2]); //将中间的这个数和第一个数交换 参见注1
        int i = l, j = r, x = s[l];
        while (i < j)
        {
            while(i < j && s[j] >= x) // 从右向左找第一个小于x的数
				j--;
            if(i < j)
				s[i++] = s[j];

            while(i < j && s[i] < x) // 从左向右找第一个大于等于x的数
				i++;
            if(i < j)
				s[j--] = s[i];
        }
        s[i] = x;
        quick_sort(s, l, i - 1); // 递归调用
        quick_sort(s, i + 1, r);
    }
}

int main()
{
  int a[6]={3,1,6,7,11,10};
  for(int i=0;i<6;i++)
     cout << a[i]<<",";
  quick_sort(a,0,5);
  cout<<endl;
  for(int i=0;i<6;i++)
       cout << a[i]<<",";
  return 0;
}
