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
class CBTInserter {
public:
    queue<TreeNode*> TreeQueue;
    TreeNode* root;
    CBTInserter(TreeNode* root) {
        this->root=root;
        queue<TreeNode*> tempQueue;
        tempQueue.emplace(root);
        while(!tempQueue.empty())
        {
            TreeNode* front=tempQueue.front();
            TreeQueue.push(front);
            tempQueue.pop();
            if(front->left!=nullptr) {TreeQueue.push(front->left);tempQueue.push(front->left);}
            if(front->right!=nullptr) {TreeQueue.push(front->right);tempQueue.push(front->right);}
        }
    }
    
    int insert(int v) {
        while(!TreeQueue.empty())
        {
            TreeNode * front=TreeQueue.front();
            if(front->left!=nullptr&&front->right!=nullptr) {TreeQueue.pop();continue;}
            else{
                TreeNode * newNode=new TreeNode(v);
                if(front->left==nullptr)
                {
                    front->left=newNode;
                    TreeQueue.push(front->left);
                }else{
                    front->right=newNode;
                    TreeQueue.push(front->right);
                    TreeQueue.pop();
                }
                return front->val;
            }
        }
        return -1;
    }
    
    TreeNode* get_root() {
        return this->root;
    }
};
