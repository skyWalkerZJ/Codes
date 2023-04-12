#include <vector>
#include <iostream>
#include <math.h>
using namespace std;
class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n=dist.size();int ans=-1;
        if((double)n-1>hour) return -1;

        int left=1;int right=10000000;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            double sum=0;
            for(int d:dist)
            {
                sum=(double)ceil(sum);
                sum+=((double)d/(double)mid);
            }
            if(sum<=hour)
            {
                ans=mid;
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return ans;
    }
};
int main()
{
    cout<<ceil(-5.1);
}