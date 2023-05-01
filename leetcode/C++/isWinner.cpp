#include <vector>
using namespace std;
class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int n=player1.size();
        int sum1=0;
        int sum2=0;
        for(int i=0;i<3&&i<n;i++)
        {   
            sum1+=player1[i];
            sum2+=player2[i];
        }
        if(n<3) {
            if(sum1==sum2) return 0;
            else if(sum1<sum2) return 2;
            else return 1;
        }

        int pre1=player1[0];
        int pre2=player2[0];
        int last1=player1[1];
        int last2=player2[1];
        for(int i=2;i<n;i++)
        {
            if(pre1+last1==10){
                sum1+=2*player1[i];
            }else{
                sum1+=player1[i];
            }

            if(pre2+last2==10)
            {
                sum2+=2*player2[i];
            }else{
                sum2+=player2[i];
            }
            pre1=last1;
            last1=player1[i];
            pre2=last2;
            last2=player2[i];
        }

        if(sum1==sum2) return 0;
        else if(sum1>sum2) return 1;
        return 2;
    }
};