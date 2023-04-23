#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    vector<vector<int>> pos(n,vector<int>(4,0));
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin >> pos[i][0] >> pos[i][1] >> pos[i][2] >> pos[i][3];
    }
    int x,y;
    cin >> x >> y;

    int ans=-1;

    for(int i=0;i<n;i++)
    {
        if( x>=pos[i][0] && x-pos[i][0]<=pos[i][2] && y>=pos[i][1] && y-pos[i][1]<=pos[i][3])
        {
            ans=i+1;
        }
    }
    cout<<ans;
    return 0;
}