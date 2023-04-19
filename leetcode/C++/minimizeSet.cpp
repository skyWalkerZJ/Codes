#include <vector>
#include <iostream>
#include <math.h>
using namespace std;
class Solution {
public:
    //2513 最小化两个数组中的最大值
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        int i = 0;
        long n = uniqueCnt1 + uniqueCnt2;
        long l = 0, r = n * 2 - 1;
        long lcm = std::lcm((long)divisor1,(long)divisor2);
        while(l < r){
            long x = l + (r - l) / 2;
            int val1 = max(uniqueCnt1 - (int)(x / divisor2 - x / lcm),0);
            int val2 = max(uniqueCnt2 - (int)(x / divisor1 - x / lcm),0);
            int common = x - x / divisor1 - x / divisor2 + x / lcm;
            if(common >= val1 + val2){
                r = x;
            }else{
                l = x + 1;
            }
        } 
        return l;
    }
};

int main()
{
    Solution s;
    cout<<s.minimizeSet(2,7,1,3);
}