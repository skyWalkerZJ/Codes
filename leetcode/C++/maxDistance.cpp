#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n=position.size();int ans=0;
        int left=1;int right=position[n-1]-position[0];
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            int count=0;int last=-mid;
            for(int pos:position)
            {
                if(pos-last>=mid) {count++;last=pos;}
            }
            if(count>=m)
            {
                left=mid+1;
                ans=mid;
            }else{
                right=mid-1;
            }
        }
        return ans;
    }
};