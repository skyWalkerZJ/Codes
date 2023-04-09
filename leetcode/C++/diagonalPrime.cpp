#include <vector>
#include <math.h>
using namespace std;
class Solution {
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        int n=nums.size();int ans=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i][i]>ans && isPrime_3(nums[i][i])) ans=nums[i][i];
            if(nums[i][n-i-1]>ans && isPrime_3(nums[i][n-i-1])) ans=nums[i][n-i-1];
        }
        return ans;
    }
    
    
bool isPrime_3(int num)
{
    if(num==1)
        return 0;
    if(num==2||num==3)
        return 1;
    if(num%6!=1&&num%6!=5)
        return 0;
    int tmp=sqrt(num);
    for(int i=5;i<=tmp;i+=6)
        if(num%i==0||num%(i+2)==0) return 0;
    return 1;
}
};