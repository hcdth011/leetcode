/*
 * countandsay.cpp
 *
 *  Created on: May 13, 2015
 *      Author: will
 */
#include <stdio.h>
#include <iostream>
#include<algorithm>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
	string unguarded_convert(const string &say)
	{
	   stringstream out;
	   if(say.length()==1)
		   return "11";
	   for(int i=0;i<say.length();)
	   {
		   int j=0;
		   for(j=i+1;j<say.length();j++)
		   {
			   if(say[j]!=say[i])
			   {
				   break;
			   }

		   }
		   out<<j-i<<say[i];
		   i=j;
	   }
       return out.str();
	}
    string countAndSay(int n) {
       if(n<=1) return "1";
       string say="1";

       for(int i=1;i<n;i++)
       {
            say=unguarded_convert(say);
       }

       return say;
    }
};

int main()
{
  Solution s;
  string res=s.countAndSay(5);
  cout<< "res=" <<res <<endl;
  return 0;
}





