#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <climits>
using namespace std;
class Solution {
public:
    int ans=INT_MAX;
    int extractMantra(vector<string>& matrix, string mantra) {
        unordered_map<char,vector<pair<int,int>>> hashmap;
        for(char c:mantra)
        {
            if(hashmap.count(c)==0)  hashmap[c]=vector<pair<int,int>>{};
        }
        int n=matrix.size();
        unordered_set<char> set;
        for(int i=0;i<n;i++)
        {
            string &temp=matrix[i];
            int len=temp.size();
            for(int j=0;j<len;j++)
            {
                if(hashmap.count(temp[j]))
                {
                    hashmap[temp[j]].push_back(pair<int,int>{i,j});
                    set.emplace(temp[j]);
                }
            }
        }
        if(set.size()<hashmap.size()) return -1;
        for(pair<int,int> p:hashmap[mantra[0]])
        {
            dfs(mantra,0,hashmap,p.first+p.second,p.first,p.second);
        }
        return ans+mantra.size();
    }

    void dfs(string& mantra,int pos,unordered_map<char,vector<pair<int,int>>>& hashmap,int step,int row,int col)
    {
        if(pos==mantra.size()){
            ans=min(ans,step);
            return;
        }
        if(step>ans) return;
        char cur=mantra[pos];
        for(pair<int,int> p:hashmap[cur])
        {
            dfs(mantra,pos+1,hashmap,step+abs(p.first-row)+abs(p.second-col),p.first,p.second);
        }
    }
};
int main()
{
    Solution s;
    string m="nrahvcpkmqgsyrcpmgfpmaxvydbp";
    //nrahvcpkmqgsyrcpmgfpmaxvydbp
    vector<string> v{"hydfpyqaoir","ixpjveolliy","hidhpqciygm","icnefohovue","qcwopbcbxbn","dvahetjbfqg","uiwjsukwofm","spzjegbovxo","aflruwmvkdp"};
    cout<<s.extractMantra(v,m);
}