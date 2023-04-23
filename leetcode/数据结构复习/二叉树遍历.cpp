#include <vector>
#include <stack>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
    //1、前序遍历 递归实现
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==nullptr) return ans;
        preorderTraversal1(root,ans);
        return ans;
    }

    vector<int> preorderTraversal1(TreeNode* root,vector<int>& ans) {
        if(root!=nullptr)
        {
            ans.push_back(root->val);
            preorderTraversal1(root->left,ans);
            preorderTraversal1(root->right,ans);
        }
    }
    //2. 前序遍历 非递归实现

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        while(!st.empty() || root!=nullptr)
        {
            while(root!=nullptr)
            {
                ans.push_back(root->val);
                st.push(root);
                root=root->left;
            }

            root=st.top();
            st.pop();

            root=root->right;
        }
        return ans;
    }

    //1. 中序遍历，递归实现
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorderTraversal1(root,ans);
        return ans;
    }

    void inorderTraversal1(TreeNode* root,vector<int>& ans) {
        if(root!=nullptr)
        {
            inorderTraversal1(root->left,ans);
            ans.push_back(root->val);
            inorderTraversal1(root->right,ans);
        }
    }

    //2.中序遍历，非递归实现
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;

        vector<int> ans;
        if(root==nullptr) return ans;
        while(!st.empty() || root!=nullptr)
        {
            while(root!=nullptr)
            {
                st.push(root);
                root=root->left;
            }

            root=st.top();
            st.pop();
            ans.push_back(root->val);

            root=root->right;
        }
        return ans;
    }

    //后续遍历 递归实现
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==nullptr) return ans;
        postorderTraversal1(root,ans);
        return ans;
    }

    vector<int> postorderTraversal1(TreeNode* root,vector<int>& ans) {
        if(root!=nullptr)
        {
            postorderTraversal1(root->left,ans);
            postorderTraversal1(root->right,ans);
            ans.push_back(root->val);
        }   
    }

    //后续遍历 非递归实现
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==nullptr) return ans;
        
        stack<TreeNode*> st;
        TreeNode* lastNode;
        while( !st.empty() || root != nullptr )
        {
            while(root!=nullptr)
            {
                st.push(root);
                root=root->left;
            }

            root=st.top();

            if(root->right==nullptr || root->right==lastNode)
            {
                ans.push_back(root->val);
                lastNode=root;
                st.pop();
                root=nullptr;
            }else{
                root=root->right;
            }
        }
        return ans;
    }

    //morris 前序遍历
    

