#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* Basically what we'll do is for every router we will check its range 
in both the directions and add 1 to the index of the houses that particular 
router can provide internet to and in last we check for all the houses if 
the value of coverage[i] >= no of people in the house and increase count if its 
the case and finally return that count value...  */

int servedBuildings(vector<int> &buildingCount, vector<int> &routerLocation, vector<int> &routerRange)
{
    int n = buildingCount.size();
    int m = routerLocation.size();
    vector<int> coverage(n, 0);

    for (int i = 0; i < m; ++i)
    {
        int loc = routerLocation[i] - 1; // convert to 0-indexed
        int range = routerRange[i];
        int left = max(0, loc - range);
        int right = min(n - 1, loc + range);
        for (int j = left; j <= right; ++j)
        {
            coverage[j]++;
        }
    }

    int served = 0;
    for (int i = 0; i < n; ++i)
    {
        if (coverage[i] >= buildingCount[i])
        {
            served++;
        }
    }
    return served;
}

int main()
{
    vector<int> buildingCount = {1, 3, 1, 1, 1};
    vector<int> routerLocation = {3, 2};
    vector<int> routerRange = {2, 3};

    cout << "No of buildings served are : " << servedBuildings(buildingCount, routerLocation, routerRange) << endl;
    return 0;
}
