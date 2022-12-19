#include <vector>
using namespace std;
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int ingress[n]={0};int egress[n]={0};
        for(int i=0;i<trust.size();i++)
        {
            int a=trust[i][0];
            int b=trust[i][1];
            ingress[a]++;egress[b]++;
        }
        for(int i=0;i<n;i++)
        {
            if(ingress[i]==0&&egress[i]==n-1) return i+1;
        }
        return -1;
    }
};