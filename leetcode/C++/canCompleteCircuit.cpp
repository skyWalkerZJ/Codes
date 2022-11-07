#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int flag=__INT32_MAX__;int gasNum=0;
        for(int i=0;i<gas.size();i++)
        {
            if(gas[i]>=cost[i]) {
                int temp=flag;
                flag=min(flag,i);
            }
            gasNum=gasNum+gas[i]-cost[i];
            if(gasNum<0) {
                flag=__INT32_MAX__;
                gasNum=0;
            }
        }
        if(flag==INT32_MAX) return -1;
        int recycle=gas.size();        
        for(int i=flag,gasNum=0;recycle>0;recycle--)
        {
            gasNum=gasNum+gas[i]-cost[i];
            if(gasNum<0) return -1;
            if(i==gas.size()-1) i=0;
            else i++;
        }
        return flag;
    }
};
int main()
{
    Solution s;
    vector<int> gas={2,3,4};
    vector<int> cost={3,4,3};
    int res=s.canCompleteCircuit(gas,cost);
    cout<<res;
}