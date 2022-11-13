#include <iostream>
using namespace std;
class Solution {
public:
    int binaryGap(int n) {
        int ans=0;
        int i=0;int lastflag=-1;
        while(n>0)
        {
            if(n%2==1) {
                if(lastflag==-1) lastflag=i;
                else {ans=max(ans,i-lastflag);
                lastflag=i;}
            }
            n=n>>1;i++; 
        }
        return ans;
    }
};