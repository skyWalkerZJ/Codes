class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int ans=0;
        if(k<=numOnes) return k;
        else{
            ans+=numOnes;
            k-=numOnes;
        }
        if(k<=numZeros) return ans;
        else{
            k-=numZeros;
        }
        if(k<=numNegOnes) return ans-k;
        else return ans-numNegOnes;
    }
};