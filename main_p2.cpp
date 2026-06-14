/* Problem 2:
Given heights of histogram bars, find the maximum rectangular area possible. */

#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n=6;
    int h[6] = {2,1,5,6,2,3};
    stack<int> st;
    int maxArea=0;
    int i=0;
    while (i<n) {
        if (st.empty() || h[st.top()] <= h[i])
        {
            st.push(i++);
        } else {
        int top=st.top();
        st.pop();
        int width;
        if(st.empty())
            width=i;
        else
            width = i - st.top() -1;
        int area = h[top] * width;
        if (area >maxArea)
            maxArea = area;
        }
    }
    while (!st.empty()) {
        int top =st.top();
        st.pop();
        int width;
        if (st.empty())
            width=i;
        else
            width = i - st.top() - 1;
        int area = h[top]*width;
        if(area>maxArea)
            maxArea=area;
    }
    cout << maxArea;
    return 0;
}
