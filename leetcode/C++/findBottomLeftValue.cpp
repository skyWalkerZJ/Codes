#include <queue>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        if(root==NULL) return -1;
        if(root->left==NULL&&root->right==NULL) return root->val;
        queue<TreeNode*> tree;
        int ans=-1;
        tree.push(root);
        int CurrentFloorSize=tree.size();int nextFloorSize=0;
        while(!tree.empty())
        {
            TreeNode* tempNode=tree.front();
            tree.pop();
            CurrentFloorSize--;
            if(tempNode->left!=NULL) {tree.push(tempNode->left);nextFloorSize++;}
            if(tempNode->right!=NULL) {tree.push(tempNode->right);nextFloorSize++;}
            if(CurrentFloorSize==0&&!tree.empty())
            {
                CurrentFloorSize=nextFloorSize;nextFloorSize=0;
                TreeNode* node=tree.front();
                ans=(*node).val;
            }
        }
        return ans;
    }
};