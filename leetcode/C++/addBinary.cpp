#include <string>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        int jinwei=0;
        int aLength=a.length();
        int bLength=b.length();
        int i=aLength-1,j=bLength-1;
        string ans="";
        while(i>=0&&j>=0)
        {
            int c=a[i]-'0'+b[j]-'0'+jinwei;
            jinwei=c/2;
            c=c%2;
            if(c==0) ans.insert(ans.begin(),'0');
            else ans.insert(ans.begin(),'1');
            i--;j--;
        }
        if(i>=0)
        {
            while(i>=0)
            {
                int c=a[i]-'0'+jinwei;
                jinwei=c/2;
                c=c%2;
                if(c==0) ans.insert(ans.begin(),'0');
                else ans.insert(ans.begin(),'1');
                i--;
            }
        }else if(j>=0)
        {
            while(j>=0){
                int c=b[j]-'0'+jinwei;
                jinwei=c/2;
                c=c%2;
                if(c==0) ans.insert(ans.begin(),'0');
                else ans.insert(ans.begin(),'1');
                j--;
            }
        }
        if(jinwei!=0) ans.insert(ans.begin(),'1');
        return ans;
    }
};