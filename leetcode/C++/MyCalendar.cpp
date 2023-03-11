#include <unordered_set>
using namespace std;
class MyCalendar {
public:
    unordered_set<int> lazy,tree;
    MyCalendar() {

    }
    
    bool query(int start,int end,int l,int r,int pos)
    {
        if(start>r||end<l) return false;
        if(lazy.count(pos)) return true;
        if(start<=l&&end>=r) return tree.count(pos);
        int mid=(l+r) >> 1;
        return query(start,end,l,mid,2*pos)||query(start,end,mid+1,r,2*pos+1);
    }

    void update(int start,int end,int l,int r,int pos)
    {
        if(start>r || end<l) return ;
        if(start<=l && end>=r)
        {
            tree.emplace(pos);
            lazy.emplace(pos);
        }else{
            int mid= (l+r) >>1;
            update(start,end, l, mid,2*pos);
            update(start,end,mid+1,r,2*pos+1);
            tree.emplace(pos);
            if(lazy.count(2*pos) && lazy.count(2*pos+1)) lazy.emplace(pos);
        }
    }
    bool book(int start, int end) {
        if(query(start,end-1,0,1e9,1)) return false;
        update(start,end-1,0,1e9,1);
        return true;
    }

    
};