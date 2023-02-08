#include <vector>
using namespace std;
class Solution {
public:
    //有符号数会出错
    int singleNumber(vector<int>& nums) {
        int cur=0;int ans=0;
        for(int i=0;i<32;i++)
        {
            int n=0;
            for(int j=0;j<nums.size();j++)
            {
                if(nums[j]%2==1) n++;
                nums[j]=((nums[j]>>1));
            }
            if(n%3==1) ans+=(1<<i);
            n=0;
        }
        return ans;
    }

    //官方题解
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            int total = 0;
            for (int num: nums) {
                total += ((num >> i) & 1);
            }
            if (total % 3) {
                ans |= (1 << i);
            }
        }
        return ans;
    }
};