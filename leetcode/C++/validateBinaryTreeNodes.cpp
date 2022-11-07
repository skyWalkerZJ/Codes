#include <vector>
using namespace std;
class Solution {
public:
    void validateBinaryTree(int n,vector<int>& leftChild, vector<int>& rightChild,vector<int>& flag){
        flag[n]--;
        if(flag[n]!=0) return;
        if(leftChild[n]!=-1) validateBinaryTree(leftChild[n],leftChild,rightChild,flag);
        if(rightChild[n]!=-1) validateBinaryTree(rightChild[n],leftChild,rightChild,flag);
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        if(n<=1) return true;
        vector<int> flag(n,1);
        //查找根节点
        vector<int> indeg(n);
        for (int i = 0; i < n; ++i) {
            if (leftChild[i] != -1) {
                ++indeg[leftChild[i]];
            }
            if (rightChild[i] != -1) {
                ++indeg[rightChild[i]];
            }
        }
        int root = -1;
        for (int i = 0; i < n; ++i) {
            if (!indeg[i]) {
                root = i;
                break;
            }
        }
        if (root == -1) {
            return false;
        }
        //深度优先遍历 如果一个节点被遍历到两次 那么就不是一棵树
        validateBinaryTree(root,leftChild,rightChild,flag);
        for(auto iter=flag.begin();iter!=flag.end();iter++)
        {
            if(*iter!=0) return false;
        }
        return true;
    }
};