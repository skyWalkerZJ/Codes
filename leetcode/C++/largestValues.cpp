#include <vector>
#include <queue>
#include <math.h>
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
    vector<int> largestValues(TreeNode* root) {
        if(!root) return vector<int>{};
        int CurLaySize=1;queue.emplace(root);vector<int> ans;
        int nextLaySize=0;int curAns=INT_MIN;
        while(!queue.empty())
        {
            TreeNode* node=queue.front();
            queue.pop();CurLaySize--;
            if(node->val>curAns) curAns=node->val;
            if(node->left!=nullptr) {queue.push(node->left);nextLaySize++;}
            if(node->right!=nullptr) {queue.push(node->right);nextLaySize++;}
            if(CurLaySize==0) {
                ans.push_back(curAns);
                curAns=INT_MIN;
                CurLaySize=nextLaySize;
                nextLaySize=0;
            }
        }
        return ans;
    }
};