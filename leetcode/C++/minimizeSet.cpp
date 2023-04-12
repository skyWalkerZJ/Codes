#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    //2513 最小化两个数组中的最大值
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        int left=uniqueCnt1+uniqueCnt2;
        int right=INT_MAX;
        int ans=0;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            int c1=0,c2=0;int same=0;
            for(int i=1;i<=mid;i++)
            {
                if(c1==uniqueCnt1 && c2==uniqueCnt2) break;
                if(c1+c2+same==uniqueCnt1+uniqueCnt2) break;
                if(i%divisor1!=0 && i%divisor2!=0) {
                    same++;
                    continue;
                }
                else if(i%divisor1!=0 &&c1<uniqueCnt1)
                {
                    c1++;
                    continue;
                }
                else if(i%divisor2!=0 && c2<uniqueCnt2)
                {
                    c2++;
                    continue;
                }
            }
            if(c1==uniqueCnt1 && c2==uniqueCnt2 || c1+c2+same == uniqueCnt1+uniqueCnt2)
            {
                ans=mid;
                right=mid-1;
            }else left=mid+1;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    cout<<s.minimizeSet(2,7,1,3);
}