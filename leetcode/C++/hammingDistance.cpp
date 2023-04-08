class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans=0;
        int t=x^y;
        while(t>0)
        {
            if(t%2==1)
            {
                ans++;
            }
            t>>1;
        }      
        return ans;
    }
};