#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;
class CombinationIterator {
private:
    vector<int> pos;
    string s;
    bool finished;

public:
    CombinationIterator(string characters, int combinationLength) {
        s = characters;
        pos.resize(combinationLength);
        iota(pos.begin(), pos.end(), 0);
        finished = false;
    }
    
    string next() {
        string ans;
        for(int p:pos)
        {
            ans+=s[p];
        }
        //找到第flag个 表明第flag个字母可以继续加
        int flag=-1;
        for(int k=pos.size()-1;k>=0;k--)
        {
            if(pos[k]!=s.length()-pos.size()+k)
            {
                flag=k;
                break;
            }
        }
        if(flag==-1){
            finished=true;
        }else{
        pos[flag]++;
        for(int j=flag+1;j<pos.size();j++)
        {
            pos[j]=pos[j-1]+1;
        }
        }
        return ans;
    }
    
    bool hasNext() {
        return !finished;
    }
};

int main()
{
    CombinationIterator *c=new CombinationIterator("abcdefg",3);
    cout<<c->next();
}