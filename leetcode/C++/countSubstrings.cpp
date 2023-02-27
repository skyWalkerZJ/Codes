#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    //马拉车算法-Manacher 算法
    int countSubstrings(string s) {
        int n = s.size();
        string t = "$#";
        for (const char &c: s) {
            t += c;
            t += '#';
        }
        n = t.size();
        t += '!';

        auto f = vector <int> (n);
        int iMax = 0, rMax = 0, ans = 0;
        for (int i = 1; i < n; ++i) {
            // 初始化 f[i]
            f[i] = (i <= rMax) ? min(rMax - i + 1, f[2 * iMax - i]) : 1;
            // 中心拓展
            while (t[i + f[i]] == t[i - f[i]]) ++f[i];
            // 动态维护 iMax 和 rMax
            if (i + f[i] - 1 > rMax) {
                iMax = i;
                rMax = i + f[i] - 1;
            }
            // 统计答案, 当前贡献为 (f[i] - 1) / 2 上取整
            ans += (f[i] / 2);
        }

        return ans;
    }

    int countSubstrings1(string s)
    {
        //奇偶处理
        string t="$#";int ans=0;
        for(const char c:s)
        {
            t+=c;
            t+="#";
        }
        t+="!";
        int n=t.length();
        vector<int> f(n);int last=-1;int mid=-1;
        for(int i=1;i<n-1;i++)
        {   
            //初始化
            f[i]=i<last?min(f[2*mid-i],last-i+1):1;
            //中心扩展
            while(t[i+f[i]]==t[i-f[i]]) ++f[i];
            //维护回文串的右端点以及对应的回文中心
            if(i+f[i]>last) 
            {
                last=i+f[i]-1;
                mid=i;
            }
            ans+=(f[i]/2);
        }
        return ans;
    }
};
int main()
{
    Solution s;
    cout<<s.countSubstrings("aaa");
}