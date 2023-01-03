#include <iostream>
#include <vector>
using namespace std;
class solution{
public:
    void sort(vector<int>& nums)
    {
        int size=nums.size();
        int n=size/2-1;
        for(int i=n;i>=0;i--)
        {
            adjust_heap(nums,size,i);
        }
        for(int i=size;i>=1;i--)
        {
            swap(nums,0,i);
            adjust_heap(nums,i,0);
        }
    }
    void adjust_heap(vector<int>& nums,int len,int index)
    {
        int left=2*index+1;
        int right=2*index+2;
        int curindex=index;

        if(left<len&&nums[left]>nums[curindex]) curindex=left;
        if(right<len&&nums[right]>nums[curindex]) curindex=right;
        if(index!=curindex)
        {
            swap(nums,index,curindex);
            adjust_heap(nums,len,curindex);
        }
    }
    void swap(vector<int>& nums,int i,int j)
    {
        int temp=nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
    }
};