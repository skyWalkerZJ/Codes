class Solution {
public:
    int lastRemaining(int n) {
        int a1=1;
        int k=0,cnt=n,setp=1;
        while(cnt>1)
        {
            if(k%2==0) a1=a1+setp;
            else{
                a1=(cnt%2==0)?a1:a1+setp;
            }
            k++;
            setp=setp<<1;
            cnt=cnt>>1;
        }
        return a1;
    }
};