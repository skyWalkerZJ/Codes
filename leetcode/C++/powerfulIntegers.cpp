#include <vector>
#include <math.h>
#include <set>
using namespace std;
class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> ans;
        set<int> hashset;
        int logi=0;
        int logj=0;
        if(bound==0) return ans;
        if(x!=1) logi=log(bound)/log(x);
        if(y!=1) logj=log(bound)/log(y);
        for(int i=0;i<=logi;i++)
        {
            for(int j=0;j<=logj;j++)
            {
                int t=pow(x,i)+pow(y,j);
                if(t<=bound) hashset.emplace(t);
            }
        }
        for(auto itr=hashset.begin();itr!=hashset.end();itr++)
        {
            ans.push_back(*itr);
        }
        return ans;
    }
};