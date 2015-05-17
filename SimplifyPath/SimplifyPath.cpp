/*
 * SimplifyPath.cpp
 *
 *  Created on: May 12, 2015
 *      Author: will
 */
/*
 * lastwordlen.cpp
 *
 *  Created on: May 12, 2015
 *      Author: will
 */

#include <stdio.h>
#include <iostream>
#include<algorithm>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
/*
class Solution {
public:
	string simplifyPath(string path){
      vector<string> result;
      string res="";
      for(int i=0;i<path.length();i++)
      {
    	  if(path[i]!='.')
    	  {
    		  if(!result.empty())
    		  {
    			  string temp=result[result.size()-1];
    			  result.pop_back();
    			  if(temp=="/" && path[i]=='/')
    			  {
     			     continue;
    			  }
    			  else
    			  {
    				  result.push_back(temp);
    				  char tem[1];
    				  tem[0]=path[i];
    				  string tem2(tem);
    				  result.push_back(tem2);
    			  }
    		  }
    		  else
    		  {
    			  char tem[1];
    				  tem[0]=path[i];
    				  string tem2(tem);
    				  result.push_back(tem2);
    		  }
    	  }
    	  else
    	  {
    		  //i++; //一个'.'就当没有，直接往后
    		  if(path[i+1]=='.') //看是不是第二个还是'.'
    		  {
    			  result.pop_back(); //先删除前一个'/'
    			  while(result.back()!="/")
    				  result.pop_back(); //直到删到'/'为止

    		  }

    	  }
      }

      for(int i=0;i<result.size();i++)
      {
    	  res=res+ result[i];
      }

      return res;
    }
};
*/

class Solution {
public:
	string simplifyPath(string path){
		vector<string> dirs;

		for(auto i=path.begin();i!=path.end();)
		{
			++i; //第一个直接跳过，因为是'/'
			auto j=find(i,path.end(),'/');
			auto dir=string(i,j);

			if(!dir.empty()&&dir!=".")
			{
				if(dir=="..")
				{
					if(!dirs.empty())
						dirs.pop_back();
				}
				else
				{
					dirs.push_back(dir);
				}
			}
			i=j;
		}

		stringstream out;
		if(dirs.empty())
			out<<'/' ;
		else
		{
			for(auto dir:dirs)
				out<<'/'<<dir ;
		}

		return out.str();
	}
};

int main()
{
  Solution s;
  string ss="/a/./b/../../c/";
  cout<< "ss=" <<ss <<endl;
  string res=s.simplifyPath(ss);
  cout<< "res=" <<res <<endl;
  return 0;
}








