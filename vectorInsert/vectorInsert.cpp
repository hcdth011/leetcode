/*
 * vectorInsert.cpp
 *
 *  Created on: May 6, 2015
 *      Author: will
 */

#include<vector>
#include<iostream>

using namespace std;

int main()
{
    vector<int> v(3);
    v[0]=2;
	v[1]=7;
	v[2]=9;

	v.insert(v.begin(),8);//在最前面插入新元素。
	v.insert(v.begin()+2,1);//在迭代器中第二个元素前插入新元素
    v.insert(v.end(),3);//在向量末尾追加新元素。

	vector<int>::iterator it;

	for(it=v.begin(); it!=v.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;

}


