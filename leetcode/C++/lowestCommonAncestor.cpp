#include <unordered_set>
#include <iostream>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };
class Solution {
public:
    long long pnode=0;
    long long qnode=0;
    TreeNode* res;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root,p,q,1);
        unordered_set<int> hashSet;
        while(pnode>0)
        {
            hashSet.emplace(pnode);
            pnode/=2;
        }

        while(qnode>0)
        {
            if(hashSet.count(qnode)!=0) break;
            qnode/=2;
        }
        getAns(root,1,qnode);
        return res;
    }

    void getAns(TreeNode* root,long long index,long long targetIndex)
    {
        if(index==targetIndex){
            res=root;
            return;
        }
        if(root->left!=nullptr) getAns(root->left,index*2,targetIndex);
        if(root->right!=nullptr) getAns(root->right,index*2+1,targetIndex);
    } 
    void dfs(TreeNode* root,TreeNode *p,TreeNode* q,long long index)
    {
        if(root==p) 
        {
            pnode=index;
        }
        if(root==q)
        {
            qnode=index;
        }
        if(pnode && qnode) return;
        if(root->left!=nullptr)
        {
            dfs(root->left,p,q,index*2);
        }
        if(root->right!=nullptr)
        {
            dfs(root->right,p,q,index*2+1);
        }
    }


    TreeNode* ans;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs1(root,p,q);
        return ans;
    }
    bool dfs1(TreeNode* root,TreeNode* p,TreeNode* q)
    {
        if(root==nullptr) return false;
        bool left=dfs1(root->left,p,q);
        bool right=dfs1(root->right,p,q);
        if((left && right) || ((root==p || root==q) && (left || right)))
        {
            ans=root;
        }
        return left || right || root==p || root==q;
    }
};
int main()
{
    TreeNode* root=new TreeNode(1);
    TreeNode* root1=new TreeNode(2);
    TreeNode* root2=new TreeNode(3);
    root->left=root1;root->right=root2;
    Solution s;
    cout<<s.lowestCommonAncestor(root,root1,root2)->val;
}