#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool canChange(string start, string target) {
        string s=start;
        string t=target;
        s.erase(remove(s.begin(),s.end(),'_'),s.end());
        t.erase(remove(t.begin(),t.end(),'_'),t.end());
        if(s!=t) return false;
        for(int i=0,j=0;i<target.length();i++)
        {
            if(target[i]=='_') continue;
            while(j<start.length())
            {
                if(start[j]!='_') break;else j++;
            }
            if(i!=j&&((i<j)==(start[j]=='R'))) return false;
            j++;
        }
        return true;
    }
};