#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
    vector<int> subSort(vector<int>& array) {
        vector<int> minArr(array.size());
        int minNum=INT_MAX;
        for(int i=array.size()-1;i>=0;i--)
        {
            if(array[i]<minNum) minNum=array[i];
            minArr[i]=minNum;
        }
        vector<int> maxArr(array.size());
        int maxNum=INT_MIN;
        for(int i=0;i<array.size();i++)
        {
            if(array[i]>maxNum) maxNum=array[i];
            maxArr[i]=maxNum;
        }
        int left=-1;int right=-1;
        for(int i=0;i<array.size();i++)
        {
            if(array[i]>minArr[i]) {left=i;break;}
        }
        for(int i=array.size()-1;i>=0;i--)
        {
            if(array[i]<maxArr[i]) {right=i;break;}
        }
        return vector<int>{left,right};
    }
};