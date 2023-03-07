#include <vector>
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
    queue<TreeNode*> queue;
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return vector<int>{};
        int CurLaySize=1;queue.emplace(root);vector<int> ans;
        int nextLaySize=0;
        while(!queue.empty())
        {
            TreeNode* node=queue.front();
            queue.pop();CurLaySize--;
            if(node->left!=nullptr) {queue.push(node->left);nextLaySize++;}
            if(node->right!=nullptr) {queue.push(node->right);nextLaySize++;}
            if(CurLaySize==0) {
                ans.push_back(node->val);
                CurLaySize=nextLaySize;
                nextLaySize=0;
            }
        }
        return ans;
    }
};