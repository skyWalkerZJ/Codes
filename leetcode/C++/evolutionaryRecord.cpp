#include <set>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;
struct comp{    
    bool operator()(const string& s1,const string& s2) const{
        int n=s1.length();
        int m=s2.length();
        int i=0;
        while(i<n&&i<m)
        {
            if(s1[i]==s2[i]) {i++;continue;}
            if(s1[i]<s2[i]) return true;
            else return false;
        }
        if(i<n)
        {
            return s1[i]=='0';
        }else return s2[i]=='1';
    }
};
class Solution {
public:
    string evolutionaryRecord(vector<int>& parents) {
        unordered_map<int,vector<int>> tree;
        int n=parents.size();
        int root=-1;
        for(int i=0;i<n;i++)
        {
            if(parents[i]==-1) root=i;
            else{
                tree[parents[i]].push_back(i);
            }
        }
        string ans=dfs(root,tree);

        int i=ans.length()-1;
        for(;i>=0;i--)
        {
            if(ans[i]=='0') break; 
        }
        return ans.substr(0,i+1);
    }


    string dfs(int root,unordered_map<int,vector<int>>& tree)
    {
        vector<string> ans;
        string res="";
        for(int r:tree[root])
        {
            string s=dfs(r,tree);
            ans.push_back(s);
        }
        if(ans.size()==0) return "";
        else{
            sort(ans.begin(),ans.end(),comp());
            for(string str:ans)
            {
                res.append("0");
                res.append(str);
                res.append("1");
            }
        }
        return res;
    }
};
int main()
{
    Solution s;
    vector<int> v{-1,0,1,1,2};
    //cout<<s.evolutionaryRecord(v);
    vector<string> v1{"0011","00111"};
    sort(v1.begin(),v1.end(),comp());
    for(string s:v1)
    cout<<s<<endl;
    return 0;
}