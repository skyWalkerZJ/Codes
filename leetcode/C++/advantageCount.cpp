#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <numeric>
using namespace std;
class Solution {
public:
    //不知道c++有索引排序这个玩意，自己写了一个hashmap实现了索引排序，但是费时费空间
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        unordered_map<int,stack<int>> hashmap;
        for(int i=0;i<nums1.size();i++)
        {
            if(hashmap.find(nums2[i])==hashmap.end()) {
                stack<int> temp;
                temp.push(i);
                hashmap.insert(pair<int,stack<int>>{nums2[i],temp});
            }else{
                stack<int> temp=hashmap[nums2[i]];
                temp.push(i);
                hashmap[nums2[i]]=temp;
            }
        }
        sort(nums2.begin(),nums2.end());
        int pre=0;int last=nums2.size()-1;vector<int> ans(nums1.size());
        for(int i=0;i<nums1.size();i++)
        {
            if(nums1[i]>nums2[pre]) {
                stack<int> s=hashmap[nums2[pre]];
                int pos=s.top();
                s.pop();
                hashmap[nums2[pre]]=s;
                ans[pos]=nums1[i];
                pre++;
            }else{
                stack<int> s=hashmap[nums2[last]];
                int pos=s.top();
                s.pop();
                hashmap[nums2[last]]=s;
                ans[pos]=nums1[i];
                last--;
            }
        }
        return ans;
    }
    //官方题解 索引排序
    vector<int> advantageCount1(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> idx1(n), idx2(n);
        iota(idx1.begin(), idx1.end(), 0);
        iota(idx2.begin(), idx2.end(), 0);
        sort(idx1.begin(), idx1.end(), [&](int i, int j) { return nums1[i] < nums1[j]; });
        sort(idx2.begin(), idx2.end(), [&](int i, int j) { return nums2[i] < nums2[j]; });
        
        vector<int> ans(n);
        int left = 0, right = n - 1;
        for (int i = 0; i < n; ++i) {
            if (nums1[idx1[i]] > nums2[idx2[left]]) {
                ans[idx2[left]] = nums1[idx1[i]];
                ++left;
            }
            else {
                ans[idx2[right]] = nums1[idx1[i]];
                --right;
            }
        }
        return ans;
    }
};
int main()
{
    vector<int> nums1={2,0,4,1,2};
    vector<int> nums2={1,3,0,0,2};
    Solution s;
    s.advantageCount1(nums1,nums2);
}