#include <vector>
#include <iostream>
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        TreeNode* ans=build(preorder,0,inorder,0,n-1);
        return ans;
    }

    TreeNode* build(vector<int>& preorder,int first,vector<int>& inorder,int left,int right) {
        if(first<0 || first>=preorder.size()) return nullptr;
        if(right<left) return nullptr;
        if(right==left) return new TreeNode(inorder[left]);
        int root=preorder[first];
        TreeNode *ans=new TreeNode(root);
        int mid=-1;
        for(int i=left;i<=right;i++)
        {
            if(inorder[i]==root)
            {
                mid=i;
                break;
            }
        }
        if(mid>left) ans->left=build(preorder,first+1,inorder,left,mid-1);
        if(mid<right) ans->right=build(preorder,first+right-left+1,inorder,mid+1,right);
        return ans;
    }
};

int main()
{
    int n;
    cin>>n;
    vector<int> preorder(n);
    vector<int> inorder(n);
    for(int i=0;i<n;i++)
    {
        cin>>preorder[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>inorder[i];
    }
    Solution s;
    //3,9,20,15,7
    //9,3,15,20,7
    s.buildTree(preorder,inorder);
}