#include <vector>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int pos=nums[i]%n;
            nums[pos]+=n;
            if(nums[pos]>2*n) return pos;
        }
        return 0;
    }
};