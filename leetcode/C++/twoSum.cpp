#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int right=numbers.size()-1;
        int left=0;
        while(left<right)
        {
            if(numbers[left]+numbers[right]==target) return vector<int>{left,right};
            else if(numbers[left]+numbers[right]<target) left++;
            else right--;
        }
        return vector<int>{-1,-1};
    }
};