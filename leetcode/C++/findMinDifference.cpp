#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> Points;int ans=INT_MAX;
        int n=timePoints.size();
        for(auto s:timePoints)
        {
            int timeStamp=strToInt(s);
            Points.push_back(timeStamp);
        }
        sort(Points.begin(),Points.end());
        Points.push_back(Points[0]+24*60);
        for(int i=0;i<n;i++)
        {
            int temp=Points[i+1]-Points[i];
            ans=min(ans,temp);
        }
        return ans;
    }
    int strToInt(string t)
    {
        return (int(t[0] - '0') * 10 + int(t[1] - '0')) * 60 + int(t[3] - '0') * 10 + int(t[4] - '0');
    }
};