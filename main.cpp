/* Problem:
Given daily stock prices, calculate the span of each day.
The span is the number of consecutive days (including today) where the price was less than or equal to today’s price. */

#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int n=7;
    int price[7] = {100, 80, 60, 70, 60, 75, 85};
    int span[7];

    stack<int> st;

    for(int i=0; i<n; i++) {
        while( !st.empty() && price[st.top()] <= price [i]) {
            st.pop();
        }
        if(st.empty())
            span[i]=i+1;
        else
            span[i]=i-st.top();
        st.push(i);

    }

    for (int i=0; i<n; i++)
        cout << span[i] << " ";

    return 0;
}
