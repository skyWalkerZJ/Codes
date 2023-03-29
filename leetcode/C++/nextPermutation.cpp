#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();int toSwap=INT_MAX;int minPos=-1;int swapPos=-1;
        for(int i=n-1;i>0;i--)
        {
            if(nums[i]<=nums[i-1]) continue;
            else{
                minPos=i-1;
                break;
            }
        }
        if(minPos==-1) {sort(nums.begin(),nums.end()); return;}
        for(int i=minPos+1;i<n;i++)
        {
            if(nums[i]>nums[minPos] && nums[i]<=toSwap)
            {
                toSwap=nums[i];
                swapPos=i;
            }
        }
        swap(nums[minPos],nums[swapPos]);
        sort(nums.begin()+minPos+1,nums.end());
        return;
    }
};
int main()
{
    Solution s;
    vector<int> v={1,2,3,4,5,6};
    s.nextPermutation(v);
    for(auto n:v)
    {
        cout<<n<<" ";
    }
}