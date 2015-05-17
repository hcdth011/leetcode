/*
 * kmeans.cpp
 *
 *  Created on: Apr 27, 2015
 *      Author: will
 */
/*kmeans算法实现（此处只考虑元组只有两个属性的情况）
*@File:k_means.cpp
*@Author:Cai0538
*@Create:2011-12-10
*@Last Modified:2011-12-10
*/
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>

#define k 3
using namespace std;
//存放元组的属性信息
struct Tuple{
	float attr1;
	float attr2;
};
//计算两个元组间的欧几里距离
float getDistXY(Tuple t1, Tuple t2)
{
	return sqrt((t1.attr1 - t2.attr1) * (t1.attr1 - t2.attr1) + (t1.attr2 - t2.attr2) * (t1.attr2 - t2.attr2));
}

//根据质心，决定当前元组属于哪个簇
int clusterOfTuple(Tuple means[],Tuple tuple){
	float dist=getDistXY(means[0],tuple);
	float tmp;
	int label=0;//标示属于哪一个簇
	for(int i=1;i<k;i++){
		tmp=getDistXY(means[i],tuple);
		if(tmp<dist) {dist=tmp;label=i;}
	}
	return label;
}
//获得给定簇集的平方误差
float getVar(vector<Tuple> clusters[],Tuple means[]){
	float var = 0;
	for (int i = 0; i < k; i++)
	{
		vector<Tuple> t = clusters[i];
		for (int j = 0; j< t.size(); j++)
		{
			var += getDistXY(t[j],means[i]);
		}
	}
	//cout<<"sum:"<<sum<<endl;
	return var;

}
//获得当前簇的均值（质心）
Tuple getMeans(vector<Tuple> cluster){

	int num = cluster.size();
	double meansX = 0, meansY = 0;
	Tuple t;
	for (int i = 0; i < num; i++)
	{
		meansX += cluster[i].attr1;
		meansY += cluster[i].attr2;
	}
	t.attr1 = meansX / num;
	t.attr2 = meansY / num;
	return t;
	//cout<<"sum:"<<sum<<endl;


}
void KMeans(vector<Tuple> tuples){
	vector<Tuple> clusters[k];
	Tuple means[k];
	int i=0;
	//默认一开始将前K个元组的值作为k个簇的质心（均值）
	for(i=0;i<k;i++){
		means[i].attr1=tuples[i].attr1;
		means[i].attr2=tuples[i].attr2;
	}
	int lable=0;
	//根据默认的质心给簇赋值
	for(i=0;i!=tuples.size();++i){
		lable=clusterOfTuple(means,tuples[i]);
		clusters[lable].push_back(tuples[i]);
	}
	//输出刚开始的簇
	for(lable=0;lable<3;lable++){
		cout<<"第"<<lable+1<<"个簇："<<endl;
		vector<Tuple> t = clusters[lable];
		for (i = 0; i< t.size(); i++)
		{
			cout<<"("<<t[i].attr1<<","<<t[i].attr2<<")"<<"   ";
		}
		cout<<endl;
	}
	float oldVar=-1;
	float newVar=getVar(clusters,means);
	while(fabs(newVar-oldVar) >= 1) //当新旧函数值相差不到1即准则函数值不发生明显变化时，算法终止
	{

		for (i = 0; i < k; i++) //更新每个簇的中心点
		{
			means[i] = getMeans(clusters[i]);
			//cout<<"means["<<i<<"]:"<<means[i].attr1<<"  "<<means[i].attr2<<endl;
		}
		oldVar = newVar;
		newVar = getVar(clusters,means); //计算新的准则函数值
		for (i = 0; i < k; i++) //清空每个簇
		{
			clusters[i].clear();
		}
		//根据新的质心获得新的簇
		for(i=0;i!=tuples.size();++i){
			lable=clusterOfTuple(means,tuples[i]);
			clusters[lable].push_back(tuples[i]);
		}
		//输出当前的簇
		for(lable=0;lable<3;lable++){
			cout<<"第"<<lable+1<<"个簇："<<endl;
			vector<Tuple> t = clusters[lable];
			for (i = 0; i< t.size(); i++)
			{
				cout<<"("<<t[i].attr1<<","<<t[i].attr2<<")"<<"   ";
			}
			cout<<endl;
		}
	}

}
int main(){

	char fname[256];
	cout<<"请输入存放数据的文件名： ";
	cin>>fname;
	cout<<endl;
	ifstream infile;
	infile.open(fname,ios::in);
	if(!infile){
		cout<<"不能打开输入的文件"<<fname<<endl;
		return 0;
	}
	int count=0;
	vector<Tuple> tuples;
	Tuple tuple;
	//从文件流中读入数据
	while(!infile.eof()){
		count++;
		if(count%2==1) infile>>tuple.attr1;
		else {
			infile>>tuple.attr2;
			tuples.push_back(tuple);
		}
	}
	//int k;
	//cout<<"请输入期望的簇的个数："
	//cin>>k;
	//cout<<endl;

	//输出文件中的元组信息
	for(vector<Tuple>::size_type ix=0;ix!=tuples.size();++ix)
		cout<<"("<<tuples[ix].attr1<<","<<tuples[ix].attr2<<")"<<"    ";
    cout<<endl;
	KMeans(tuples);
	return 0;
}




