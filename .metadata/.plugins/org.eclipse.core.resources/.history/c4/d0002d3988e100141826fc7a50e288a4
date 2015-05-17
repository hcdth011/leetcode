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
	int maxSubArray(int* A, int n)
	{
	        int Start = A[n - 1];
	        int All = A[n - 1];
	        for(int i = n - 2; i >= 0; i--)    //从后向前遍历，反之亦可。
	        {
	                Start = max( A[i], A[i] + Start);
	                All = max(Start, All);
	        }
	        return All;      //All[0] 中存放结果
	}
};

int main()
{
    Solution s;
    int A[5]={-1,3,2,-4,4};
    int res =s.maxSubArray(A,5);
    cout << "res=" << res ;

    return 0;
}
