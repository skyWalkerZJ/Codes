#include <unordered_set>
using namespace std;
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> set;
        while(n!=1&&set.count(n)==0)
        {
            set.emplace(n);
            int sum=0;
            while(n>0)
            {
                int rest=n%10;
                sum+=(rest*rest);
                n=n/10;
            }
            n=sum;
        }
        if(n==1) return true;
        return false;
    }
};