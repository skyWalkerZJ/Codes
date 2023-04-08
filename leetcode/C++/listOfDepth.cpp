#include <queue>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
    vector<ListNode*> listOfDepth(TreeNode* tree) {
        vector<ListNode*> ans;
        if(tree==nullptr) return ans;
        queue<TreeNode*> q;
        q.emplace(tree);
        while(!q.empty())
        {
            int n=q.size();
            ListNode* start=nullptr;
            ListNode* end=nullptr;
            for(int i=0;i<n;i++)
            {
                TreeNode * node=q.front();
                if(node->left!=nullptr) q.push(node->left);
                if(node->right!=nullptr) q.push(node->right);
                q.pop();
                ListNode* l=new ListNode(node->val);
                if(start==nullptr) {
                    start=l;end=l;
                }
                else{
                    end->next=l;
                    end=end->next;
                }
            }
            ans.push_back(start);
        }
        return ans;
    }
};