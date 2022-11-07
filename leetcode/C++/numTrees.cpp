#include <iostream>
using namespace std;
class Solution {
public:
    int numTrees(int n) {
        if(n==0) return 1;
        if(n==1) return 1;
        if(n==2) return 2;
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            sum+=numTrees(i-1)*numTrees(n-i);
        }
        return sum;
    }
};