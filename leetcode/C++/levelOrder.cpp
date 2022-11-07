#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {};
 };
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        if(root==NULL) return ans;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* temp=q.front();
            q.pop();
            ans.push_back(temp->val);
            if(temp->left!=NULL) q.push(temp->left);
            if(temp->right!=NULL) q.push(temp->right); 
        }
        return ans;
    }
};