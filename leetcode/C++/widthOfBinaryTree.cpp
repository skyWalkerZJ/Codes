#include <unordered_map>
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
    int widthOfBinaryTree(TreeNode* root) {
        queue<TreeNode*> treeQueue;
        unordered_map<TreeNode*,unsigned long long> hashmap;
        int ans=-1;
        treeQueue.emplace(root);
        hashmap[root]=1;
        while(!treeQueue.empty())
        {
            int size=treeQueue.size();
            TreeNode* firstOne=treeQueue.front();
            while(size>0)
            {
                TreeNode* front=treeQueue.front();
                treeQueue.pop();
                unsigned long long pos=hashmap[front];
                if(front->left!=nullptr)
                {
                    treeQueue.emplace(front->left);
                    hashmap[front->left]=2*pos;
                }    
                if(front->right!=nullptr)
                {
                    treeQueue.emplace(front->right);
                    hashmap[front->right]=2*pos+1;
                }
                if(size==1)
                {
                    ans=max((unsigned long long)ans,pos-hashmap[firstOne]);
                }
                size--;
            }
        }
        return ans+1;
    }
};