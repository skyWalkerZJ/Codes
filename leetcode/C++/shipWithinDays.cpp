#include <vector>
using namespace std;
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left=0;
        int right=0;int ans=0;
        for(int w:weights) {right+=w;left=max(left,w);}
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            int sum=0;int size=0;
            for(int w:weights)
            {
                sum+=w;
                if(sum>mid)
                {
                    sum=w;
                    size++;
                }else if(sum==mid)
                {
                    sum=0;
                    size++;
                }
            }
            if(sum>0) size++;
            if(size<=days) 
            {
                ans=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return ans;
    }
};