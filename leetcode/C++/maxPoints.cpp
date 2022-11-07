#include <vector>
#include <math.h>
#include <iostream>
using namespace std;
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m=points.size();int n=points[0].size();
        vector<long long> lastVector;
        for(int q=0;q<n;q++)
        {
            lastVector.push_back(points[0][q]);
        }
        for(int i=1;i<m;i++)
        {
            vector<long long> currentvector;
            for(int q=0;q<n;q++)
            {
                currentvector.push_back(points[i][q]);
            }
            long long best=LLONG_MIN;
            for(int j=0;j<n;j++)
            {
                best=max(best,lastVector[j]+j);
                currentvector[j]=max(currentvector[j],points[i][j]+best-j);
            }
            best=LLONG_MIN;
            for(int j=n-1;j>=0;j--)
            {
                best=max(best,lastVector[j]-j);
                currentvector[j]=max(currentvector[j],points[i][j]+best+j);
            }
            lastVector=currentvector;
        }
        long long ans=LLONG_MIN;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,lastVector[i]);
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> test;
    test.push_back(vector<int>{1,2,3});
    test.push_back(vector<int>{1,5,1});
    test.push_back(vector<int>{3,1,1});
    cout<<s.maxPoints(test);
    return 0;
}