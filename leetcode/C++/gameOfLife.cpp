#include <vector>
using namespace std;
class Solution {
public:
    //由活到死 为-1
    //由死到活 为2
    //死 0 活 1
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==1)
                {
                    int ans=returnLiveCell(n,m,board,i,j);
                    if(ans<2 || ans>3) board[i][j]=-1;
                }else{
                    int ans=returnLiveCell(n,m,board,i,j);
                    if(ans==3) board[i][j]=2;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==-1) board[i][j]=0;
                else if(board[i][j]==2) board[i][j]=1;
            }
        }
        return;
    }
    int returnLiveCell(int n,int m,vector<vector<int>>& board,int i,int j)
    {
        vector<vector<int>> ngi{{0,1},{0,-1},{-1,0},{1,0},{1,1},{-1,-1},{1,-1},{-1,1}};
        int count=0;
        for(int k=0;k<8;k++)
        {
            int row=i+ngi[k][0];
            int col=j+ngi[k][1];
            if(row<0 || row>=n || col<0 || col >=m) continue;
            if(board[row][col]==1 || board[row][col]==-1) count++;
        }
        return count;
    }

};