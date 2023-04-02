#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    static bool myCompare(pair<int,int> a,pair<int,int> b)
    {
        return a.second>b.second;
    }
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n=reward1.size();int r=n-k;
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
        {
            v.push_back(pair<int,int>{i,reward1[i]-reward2[i]});
        }
        sort(v.begin(),v.end(),myCompare);
        int ans=0;int i=0;
        for ( i = 0; k>0; i++)
        {
            ans+=reward1[v[i].first];
            k--;
        }
        for(i;i<n;i++)
        {
            ans+=reward2[v[i].first];
        }
        return ans;
    }
};
int main()
{
    vector<int> v={1,1,4,4};
    vector<int> v1={4,3,1,1};
    Solution s;
    cout<<s.miceAndCheese(v,v1,3);
}