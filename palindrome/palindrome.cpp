/*
 * palindrome.cpp
 *
 *  Created on: May 7, 2015
 *      Author: will
 */

#include <stdio.h>
#include <iostream>
#include<algorithm>

using namespace std;


class Solution
{
public:
	  bool isPalindrome(string s)
	  {
		 int len= s.length();
		// cout<< "len=" << len << endl;
		 if(len==0)
			 return true;
		 int begin=0 ,end =len-1;
		 while(begin<end)
		 {

			 s[begin] = tolower(s[begin]);
			 s[end] = tolower(s[end]);

			  while(!(('a'<=s[begin]&&s[begin]<='z')||('0'<=s[begin]&&s[begin]<='9')) && begin<end)
			  {
			      begin++;
			      s[begin] = tolower(s[begin]);
			  }
			  while(!(('a'<=s[end]&&s[end]<='z')||('0'<=s[end]&&s[end]<='9')) && begin<end)
			  {
			  	  end--;
			  	  s[end] = tolower(s[end]);
			  }

			  if(s[begin]!=s[end])
				  return false ;
			  begin++;
			  end--;
		 }

	     return true;
	  }

};
int main()
{
    Solution ss ;
    string s="i ,ama i1" ;
    bool result =false;

    result= ss.isPalindrome(s);
    cout << "result=" << result <<endl;
    return 0;
}


