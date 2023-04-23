class Solution {
public:
    int sumOfMultiples(int n) {
        int x=15;
        int y=21;
        int z=35;
        int m=3*5*7;
        int last3=n-n%3;
        int last5=n-n%5;
        int last7=n-n%7;
        int last15=n-n%15;
        int last21=n-n%21;
        int last35=n-n%35;
        int lastm=n-n%m;
        int sum1=(last3/3)*(3+last3)/2;
        int sum2=(last5/5)*(5+last5)/2;
        int sum3=(last7/7)*(7+last7)/2;
        int sum4=(last15/15)*(15+last15)/2;
        int sum5=(last21/21)*(21+last21)/2;
        int sum6=(last35/35)*(35+last35)/2;
        int sum7=(lastm/m)*(m+lastm)/2;
        return sum1+sum2+sum3-sum4-sum5-sum6+sum7;
    }
};