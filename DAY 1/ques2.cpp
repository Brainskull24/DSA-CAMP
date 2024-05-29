#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int sumOfRegions(vector<int>& heights) {
    int n = heights.size();
    vector<int> left(n), right(n);
    stack<int> st;
    
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && heights[st.top()] < heights[i]) st.pop();
        left[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    
    while (!st.empty()) st.pop();
    
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && heights[st.top()] <= heights[i]) st.pop();
        right[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += (i - left[i]) * (right[i] - i);
    }
    return sum;
}

int main() {
    vector<int> heights = {3, 5, 6};
    cout << "Sum of regions : " << sumOfRegions(heights) << endl;
    return 0;
}
