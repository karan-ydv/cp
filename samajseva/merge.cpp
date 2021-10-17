#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
    priority_queue<int, deque<int>, greater<int>> minheap;
    priority_queue<int> maxheap;
    int s1 = 0, s2 = 0;
public:
    MedianFinder() {}
    double findMedian()
    {
        if(s1 == s2)
            return (minheap.top() + maxheap.top()) / 2.0;
        return s1 > s2 ? minheap.top() : maxheap.top();
    }
    void addNum(int num)
    {
        if(num < minheap.top())
            maxheap.push(num), s2++;
        else
            minheap.push(num), s1++;
        if(s1 - s2 == 2)
        {
            maxheap.push(minheap.top());
            minheap.pop();
            s1--, s2++;
        }
        if(s2 - s1 == 2)
        {
            minheap.push(maxheap.top());
            maxheap.pop();
            s1++, s2--;
        }
    }
    
};

int main()
{
    MedianFinder mf{};
    mf.addNum(1);
    cout << mf.findMedian() << '\n';
    mf.addNum(2);
    cout << mf.findMedian() << '\n';
    mf.addNum(3);
    cout << mf.findMedian() << '\n';
}