#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int right=0;int left=-1;
        while(right<flowerbed.size())
        {
            if(flowerbed[right]==1) {
                if(left==-1){n-=(right-0)/2;}
                else{n-=(right-left-2)/2;}
                left=right;
            }
            right++; 
        }
        if(left==-1){n-=(flowerbed.size()+1)/2; }
        else{n-=(flowerbed.size()-1-left)/2;}
        return n<=0?true:false;
    }
};