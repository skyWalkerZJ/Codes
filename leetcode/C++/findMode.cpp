#include <vector>
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
    vector<int> ans;
    int base,count,maxCount;
    vector<int> findMode1(TreeNode* root) {
        dfs(root);
        return ans;
    }
    void update(int x)
    {
        if(x==base) count++;
        else{
            count=1;
            base=x;
        }
        if(count==maxCount) ans.push_back(x);
        if(count>maxCount) {maxCount=count;ans=vector<int>{x};}
    }
    void dfs(TreeNode* root)
    {
        if(root==NULL) return;
        dfs(root->left);
        update(root->val);
        dfs(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        int base,count,maxCount;
        TreeNode* pre=NULL;
        while(root!=NULL)
        {
            if(root->left!=NULL)
            {
                pre=root->left;
                while(pre->right!=root&&pre->right!=NULL)
                {
                    pre=pre->right;
                }
                if(pre->right==NULL) {pre->right=root;root=root->left;}
                else{
                    if(root->val==base) count++;
                    else{
                        count=1;
                        base=root->val;
                    }
                    if(count==maxCount) ans.push_back(root->val);
                    if(count>maxCount) {ans=vector<int>{root->val};maxCount=count;}
                    pre->right=NULL;
                    root=root->right;
                }
            }else{
                if(root->val==base) count++;
                else{
                    count=1;
                    base=root->val;
                }
                if(count==maxCount) ans.push_back(root->val);
                if(count>maxCount) {ans=vector<int>{root->val};maxCount=count;}
                root=root->right;
            }
        }
        return ans;
    }
};