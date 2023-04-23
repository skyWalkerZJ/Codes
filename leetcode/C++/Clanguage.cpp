#include <iostream>
#include <set>
using namespace std;
class student{
public:
    int a;
    int b;
    student(int a,int b)
    {
        this->a=a;
        this->b=b;
    }
};
int main()
{
    set<int> set;
    set.insert(10);
    set.insert(5);
    set.insert(20);
    for(auto itr=set.begin();itr!=set.end();itr++)
    {
        cout<<" "<<*itr;
    }
}