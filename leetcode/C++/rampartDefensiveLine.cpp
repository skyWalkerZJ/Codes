#include <vector>
using namespace std;
class Solution {
public:
    bool check(int num,vector<vector<int>>& rampart){
        int len=rampart.size();
        int tmp=rampart[0][1];
        for(int i=1;i<len;i++){
            if(tmp>rampart[i][0])
                return false;
            int r_num=num-(rampart[i][0]-tmp);
            if(r_num>0)
            tmp=rampart[i][1]+r_num;
            else
            tmp=rampart[i][1];
        }
        return true;
    }
    int rampartDefensiveLine(vector<vector<int>>& rampart) {
        int r=1e9,l=0;
        int ans=0;
        while(l<=r){
            int mid=(r-l)/2+l;
            if(check(mid,rampart)){
                ans=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return ans;
    }
};