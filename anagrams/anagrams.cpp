/*
 * anagrams.cpp
 *
 *  Created on: May 12, 2015
 *      Author: will
 */

#include <stdio.h>
#include <iostream>
#include<algorithm>
#include <string.h>
#include <vector>
#include <tr1/unordered_map>

using namespace std;
using namespace std::tr1;

class Solution {
public:
    vector<string> anagrams(vector<string>& strs) {

    	unordered_map <string,vector<string> > groups;
    	for(int i=0;i<strs.size();i++)
    	{
    		string key =strs[i];
    		sort(key.begin(),key.end());
    		groups[key].push_back(strs[i]);
    	}
    	vector<string> result;

    	for(unordered_map <string,vector<string> >::iterator it=groups.begin();it!=groups.end();it++)
    	{
             if(it->second.size()>1) //必须有1个以上的anagram字符串
             {
            	 result.insert(result.end(),it->second.begin(),it->second.end());
             }
    	}

    	return result;

    }
};

int main()
{
   Solution s;
   vector<string> result;
   vector<string> input;
   input.insert(input.end(),"tea");
   input.insert(input.end(),"eat");
   input.insert(input.end(),"ate");
   input.insert(input.end(),"and");
   input.insert(input.end(),"den");

   result=s.anagrams(input);

   cout<< "result= " << result[0] <<endl;
  return 0;
}



