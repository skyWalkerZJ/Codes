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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        TreeNode *root=build(inorder,postorder,0,n-1,n-1);
        return root;
    }

    TreeNode* build(vector<int>& inorder,vector<int> postorder,int left,int right,int rootPos)
    {
        if(left>right) return nullptr;
        if(left==right) return new TreeNode(postorder[rootPos]);

        int root=postorder[rootPos];
        int mid=-1;
        for(int i=left;i<=right;i++)
        {
            if(inorder[i]==root)
            {
                mid=i;
                break;
            }
        }
        TreeNode *rootTree=new TreeNode(root);
        if(mid>left)
        {
            rootTree->left=build(inorder,postorder,left,mid-1,rootPos-right+mid);
        }

        if(mid<right)
        {
            rootTree->right=build(inorder,postorder,mid+1,right,rootPos-1);
        }
        return rootTree;
    }
};