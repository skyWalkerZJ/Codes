#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> v{a,b,c};
        sort(v.begin(),v.end());
        a=v[0];b=v[1];c=v[2];
        int maxNum=b-a-1+c-b-1;
        int minNum=0;
        if(maxNum==0) minNum=0;
        else if(b-a==2||c-b==2||a+1==b||c-b==1) minNum=1;
        else minNum=2;
        return vector<int>{minNum,maxNum};
    }
};