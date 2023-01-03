class solution{
public:
    void sort(int nums[],int begin,int end)
    {
        if(begin<end)
        {
            int key=nums[begin];
            int left=begin;int right=end;
            int i=left;int j=right;
            while(left<right)
            {
                while(right>left&&nums[right]>=key)
                {
                    right--;
                }
                if(left<right) nums[left++]=nums[right];
                while(left<right&&nums[left]<=key)
                {
                    left++;
                }
                if(left<right) nums[right--]=nums[left];
            }
            nums[left]=key;
            sort(nums,i+1,left);
            sort(nums,left+1,j);
        }
    }
};
int main()
{
    solution s;
    int nums[5]={1,4,2,5,3};
    s.sort(nums,0,4);
}