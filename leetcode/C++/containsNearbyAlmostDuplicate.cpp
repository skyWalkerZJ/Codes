#include <vector>
#include <set>
#include <math.h>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool containsNearbyAlmostDuplicate1(vector<int>& nums, int k, int t) {
        set<int> set;int n=nums.size();
        for(int i=0;i<n;i++)
        {
            auto itr=set.lower_bound(nums[i]-t);
            if(itr!=set.end()&&(*itr)<=(nums[i]+t))
            {
                return true;
            }
            set.insert(nums[i]);
            if(i>=k)
            {
                set.erase(nums[i-k]);
            }
        }
        return false;
    }

    //桶的思想
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        unordered_map<int,int> hashMap;
        long w=(long)t+1;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            long x=nums[i];
            int id=getId(x,w);
            if(hashMap.count(id)) return true;
            if(hashMap.count(id-1) && abs(x-hashMap[id-1]) < w) return true;
            if(hashMap.count(id+1) && abs(hashMap[id+1]-x) < w) return true;
            hashMap[id]=nums[i];
            if(i>=k) hashMap.erase(getId(nums[i-k],w));
        }
        return false;
    }

    int getId(long i,long w)
    {
        if(i>=0) return i/w;
        return (i+1)/w-1;
    }
};

int main()
{
    Solution s;
    vector<int> v{-3,3,-6};
    s.containsNearbyAlmostDuplicate(v,2,3);
}