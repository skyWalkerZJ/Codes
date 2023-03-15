#include <vector>
using namespace std;
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left=0,right=arr.size()-1;
        int ans=0;
        while(left<=right)
        {
            int mid=((right-left) >> 1) + left;
            if(arr[mid]>arr[mid-1]&&arr[mid]>arr[mid+1])
            {
                ans=mid;
                break;
            }
            else if(arr[mid]<arr[mid+1]) 
            {
                left=mid+1;
                ans=mid;
            }else if(arr[mid]>arr[mid+1])
            {
                right=mid-1;
                ans=mid;
            }
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> v{3,5,3,2,0};
    vector<int> &q=v;
    s.peakIndexInMountainArray(q);
}