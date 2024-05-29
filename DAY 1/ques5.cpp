#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minTaps(int n, vector<int>& ranges) {
    vector<int> maxRange(n + 1, 0);
    for (int i = 0; i <= n; ++i) {
        int left = max(0, i - ranges[i]);
        int right = min(n, i + ranges[i]);
        maxRange[left] = max(maxRange[left], right);
    }
    
    int taps = 0, farthest = 0, currentEnd = 0;
    for (int i = 0; i <= n; ++i) {
        if (i > farthest) return -1;
        if (i > currentEnd) {
            taps++;
            currentEnd = farthest;
        }
        farthest = max(farthest, maxRange[i]);
    }
    return taps;
}

int main() {
    int n = 5;
    vector<int> ranges = {3, 2, 1, 0, 0,2};
    cout << "Minimum taps required arec : " << minTaps(n, ranges) << endl;
    return 0;
}
