#include <math.h>
class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hDimen=(hour%12)*30+((double)minutes)/2;
        double mDimen=minutes*6;
        double ans=abs(hDimen-mDimen);
        if(ans>=180) return 360.0-ans;
        else return ans;
    }
};