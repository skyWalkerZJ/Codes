#include <vector>
using namespace std;
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        for (int gap = 1; gap <= 3; ++gap) {
            for (int i = 0; i + gap < n; ++i) {
                if (nums[i] == nums[i + gap]) {
                    return nums[i];
                }
            }
        }
        return -1;
    }
};