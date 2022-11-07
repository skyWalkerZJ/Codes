#include <iostream>
using namespace std;
class Solution {
public:
    int insertBits(int N, int M, int i, int j) {
        return (N&~((0xffffffff>>(31-j+i))<<i)|M<<i);
    }
};