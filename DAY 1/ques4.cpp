#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int minOperations(vector<int>& nums) {
    unordered_map<int, int> count;
    for (int num : nums) {
        count[num]++;
    }
    
    int operations = 0;
    for (auto& [num, cnt] : count) {
        while (cnt > 0) {
            if (cnt >= 3) {
                cnt -= 3;
                operations++;
            } else if (cnt >= 2) {
                cnt -= 2;
                operations++;
            } else {
                return -1;
            }
        }
    }
    return operations;
}

int main() {
    vector<int> nums = {2, 3, 3, 3,2, 2, 4, 2, 3, 4};
    cout << "Minimum operations are : " << minOperations(nums) << endl;
    return 0;
}
