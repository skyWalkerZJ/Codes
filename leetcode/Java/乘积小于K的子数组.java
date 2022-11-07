package uestc.leetcode;

public class 乘积小于K的子数组 {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        int left=0;int right=0;
        int count=0;int pre=1;
        for(;right<nums.length;right++)
        {
            pre*=nums[right];
            while (pre>=k&&left<=right)
            {
                pre/=nums[left];
                left++;
            }
            count+=right-left+1;
        }
        return count;
    }
}
