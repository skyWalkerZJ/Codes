#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int> v;
        for(int i=0;i<10000;i++)
        {
            int j=n-i;
            if((to_string(i)+to_string(j)).find("0")==string::npos)
            {
                v.push_back(i);
                v.push_back(j);
                return v;
            }
        }
    }
};