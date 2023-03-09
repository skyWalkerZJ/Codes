#include <queue>
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
class BSTIterator {
public:
    queue<TreeNode*> q;
    stack<TreeNode*> s;
    BSTIterator(TreeNode* root) {
        while(!s.empty()||root!=nullptr)
        {
            while(root!=nullptr)
            {
                s.emplace(root);
                root=root->left;
            }
            root=s.top();
            s.pop();
            q.push(root);
            root=root->right;
        }
    }
    
    int next() {
        if(hasNext()){
            TreeNode* front=q.front();
            q.pop();
            return front->val;
        }
        return -1;
    }
    
    bool hasNext() {
        return !q.empty();
    }
};