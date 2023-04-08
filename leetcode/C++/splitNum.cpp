#include <vector>
using namespace std;
class Solution {
public:
    int splitNum(int num) {
        vector<int> v(10,0);
        while (num>0)
        {
            int flag=num%10;
            v[flag]++;
            num/=10;
        }
        int n1=0;int n2=0;
        bool flag=false;
        for(int i=1;i<10;i++)
        {
            while(v[i]>0)
            {
                if(flag)
                {
                    n1=n1*10+i;
                }else{
                    n2=n2*10+i;
                }
                flag=(!flag);
                v[i]--;
            }
        }
        return n1+n2;
    }
};