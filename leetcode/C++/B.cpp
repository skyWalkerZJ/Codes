#include <vector>
#include <unordered_map>
#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

void dfs(vector<unordered_set<int>> e,int length,int root,unordered_set<int> blockSet,string str,string &res,int &len)
{
    str+="->";
    str+=to_string(root);
    length++;
    if(blockSet.count(root)!=0) return;
    if(e[root].empty() && length<len){
        res=str;
        len=length+1;
    }
    for(auto itr=e[root].begin();itr!=e[root].end();itr++)
    {
        dfs(e,length,*itr,blockSet,str,res,len);
    }
}
int main()
{
    int n;
    cin >> n;
    int edge ;
    cin >> edge;
    int ans = 1000000;
    vector<unordered_set<int>> e(n, unordered_set<int>());
    for (int i = 0 ; i < edge; i ++)
    {
        int x, y;
        cin >> x >> y;
        e[x].emplace(y);
        e[y].emplace(x);
    }
    int block;
    unordered_set<int> blockSet;
    cin >> block;
    for (int i = 0; i < block; i ++)
    {
        int x;
        cin >> x;
        blockSet.emplace(x);
    }

    queue<int> queue;
    queue.emplace(0);
    while (!queue.empty())
    {
        int front=queue.front();
        for(auto itr=e[front].begin();itr!=e[front].end();itr++)
        {
            e[*itr].erase(front);
            queue.emplace(*itr);
        }
        queue.pop();
    }
    string res="NULL";
    int len=INT_MAX;
    dfs(e,0,0,blockSet,"",res,len);
    if(res=="NULL") cout<<res;
    else cout<<res.substr(2);
    return 0;
}