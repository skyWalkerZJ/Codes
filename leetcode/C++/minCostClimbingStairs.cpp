#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        //return max(minCostClimbingStairs(cost,0),minCostClimbingStairs(cost,1));
        int cost1=0;int cost2=0;
        for(int i=2;i<=cost.size();i++)
        {
            int temp=cost2;
            cost2=min(cost[i-2]+cost1,cost[i-1]+cost2);
            cost1=temp;
        }
        return cost2;
    }

    /*
    int minCostClimbingStairs(vector<int>& cost,int begin) {
        if(begin>=cost.size()) return 0;
        if(begin==cost.size()-1) return cost[begin];
        else return max(cost[begin]+minCostClimbingStairs(cost,begin+1),cost[begin]+minCostClimbingStairs(cost,begin+2));
    }
    */
};