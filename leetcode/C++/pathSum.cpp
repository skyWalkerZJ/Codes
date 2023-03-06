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
    unordered_map<long long,int> prefix;
    int dfs(TreeNode* root,long cur,long targetSum)
    {
        if(!root) return 0;
        int res=0;
        cur+=root->val;
        if(prefix.count(cur-targetSum))
        {
            res+=prefix[cur-targetSum];
        }
        prefix[cur]++;
        res+=dfs(root->left,cur,targetSum);
        res+=dfs(root->right,cur,targetSum);
        prefix[cur]--;
        return res;
    }
    int pathSum(TreeNode* root, int targetSum) {
        prefix[0]=1;
        return dfs(root,0,targetSum);
    }
};