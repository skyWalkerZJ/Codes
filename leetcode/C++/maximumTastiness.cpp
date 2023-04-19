#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(),price.end());
        int n=price.size();int ans=0;
        int left=0;int right=price[n-1]-price[0];
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            int count=0;int last=-mid;
            for(int pri:price)
            {
                if(pri-last>=mid){
                    count++;
                    last=pri;
                }
            }
            if(count>=k)
            {
                ans=mid;
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        return ans;
    }
};