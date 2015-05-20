/*
 * PathSum.cpp
 *
 *  Created on: May 18, 2015
 *      Author: will
 */

#include <stdio.h>
#include <iostream>
#include<algorithm>
#include <string>
#include <sstream>
#include <vector>
using namespace std;


 // Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==nullptr) return false;
        if(root->left==nullptr&&root->right==nullptr)
        {
        	return sum-root->val==0?true:false;
        }

//        if(root->left!=nullptr)
//        	return hasPathSum(root->left,sum-root->val);
//        else if(root->right!=nullptr)
//        	return hasPathSum(root->right,sum-root->val);
    //    return hasPathSum(root->left,sum-root->val)||hasPathSum(root->right,sum-root->val);

        if(hasPathSum(root->left,sum-root->val))
        	return true;
        else if(hasPathSum(root->right,sum-root->val))
            return true;
        else
        	return false;

    }
};

int main()
{
  Solution s;
  TreeNode* root;
  bool res=s.hasPathSum(root,24);
  cout<< "res=" <<res <<endl;
  return 0;
}








