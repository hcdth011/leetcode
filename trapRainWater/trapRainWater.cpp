#include<stdio.h>
#include<iostream>
#include <stdlib.h>

using namespace std;

class Solution {
public:
//    int maxSubArray(int A[], int n) {
//    	int max=0;
//    	int sum=0;
//    	for(int i = 0; i < n; i++)
//    	{
//			sum = 0;
//			for(int j = i; j < n; j++)
//			{
//				sum += A[j];
//				if(sum > max)
//				max = sum;
//			}
//    	}
//    	return max;
//
//    }
	int trap(int* A, int n)
	{
		   int vol=0,temp;
           for(int i=1;i<n-1;i++)
           {
               temp=min(A[i-1],A[i+1])-A[i];
               if(temp>0)
            	   vol=vol+temp;
           }
	}
};

int main()
{
    Solution s;
    int A[12]={0,1,0,2,1,0,1,3,2,1,2,1};
    int res =s.trap(A,12);
    cout << "res=" << res ;

    return 0;
}
