#include <iostream>
#include <vector>
using namespace std;

int minOperations(vector<int>& a, vector<int>& b) {
    // Find the minimum element in array a
    int minA = a[0];
    for (int i = 1; i < a.size(); ++i) {
        if (a[i] < minA) {
            minA = a[i];
        }
    }
    
    // Find the maximum element in array b
    int maxB = b[0];
    for (int i = 1; i < b.size(); ++i) {
        if (b[i] > maxB) {
            maxB = b[i];
        }
    }
    
    // Calculate the number of operations required
    int operations = maxB - minA;
    return operations > 0 ? operations : 0;
}

int main() {
    vector<int> a = {1, 2, 3};
    vector<int> b = {3, 4};
    cout << "Minimum ooerations required are : " << AminOperations(a, b) << endl; // Output: 1
    return 0;
}
