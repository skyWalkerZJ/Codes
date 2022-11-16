#include <vector>
using namespace std;
class Solution {
public:
    int temperatureTrend(vector<int>& temperatureA, vector<int>& temperatureB) {
        int days=temperatureA.size();
        int state_one[days-1];int state_two[days-1];
        for(int i=0;i<days-1;i++)
        {
            if(temperatureA[i]<temperatureA[i+1]) state_one[i]=1;
            else if(temperatureA[i]>temperatureA[i+1]) state_one[i]=-1;
            else if(temperatureA[i]==temperatureA[i+1]) state_one[i]=0;

            if(temperatureB[i]<temperatureB[i+1]) state_two[i]=1;
            else if(temperatureB[i]>temperatureB[i+1]) state_two[i]=-1;
            else if(temperatureB[i]==temperatureB[i+1]) state_two[i]=0;
        }
        int ans=0;int times=0;
        for(int i=0;i<days-1;i++)
        {
            if(state_one[i]==state_two[i])
            {
                times++;
                ans=max(ans,times);
            }else{
                times=0;
            }
        }
        return ans;
    }
};