#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<vector<char>> board;
    vector<vector<bool>> flags;
    string word;
    vector<vector<int>> dirs{{0,1},{0,-1},{-1,0},{1,0}};
    bool exist(vector<vector<char>>& board, string word) {
        this->board=board;this->word=word;
        int m=board.size();int n=board[0].size();
        vector<vector<bool>> flags(m,vector<bool>(n,false));
        this->flags=flags;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dfs(word,0,i,j)) return true;
            }
        }
        return false;
    }

    bool dfs(string& word,int pos,int row,int col)
    {
        if(word[pos]!=board[row][col]) return false;
        if(pos==word.size()-1) return true;
        flags[row][col]=true;
        bool ans=false;
        for(int i=0;i<4;i++)
        {
            int ni=row+dirs[i][0];
            int nj=col+dirs[i][1];
            if(ni>=0 && ni<board.size() && nj>=0 && nj<board[0].size() &&!flags[ni][nj])
            ans |= dfs(word,pos+1,ni,nj);
            if(ans) return true;
        }

        flags[row][col]=false;
        return false;
    }
};
int main()
{
    Solution s;
    vector<vector<char>> v{{'A','B'},{'D','C'}};
    s.exist(v,"ABCD");
}