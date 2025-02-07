#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int min_cost = INT_MAX; 
        options(days, costs, 0, days[0], min_cost);
        return min_cost;
     
    }
private:
    void options(vector<int>& days, vector<int>& costs, int current_cost, int day, int& min_cost) {

        if (day > days.back()) {
            if (current_cost < min_cost) {
                min_cost = current_cost;
            }
            return;
        }

        if (current_cost >= min_cost) {
            return;
        }

        auto it = lower_bound(days.begin(), days.end(), day);
        if (it == days.end()) {
            return;
        }
        int next_day = *it;

        options(days, costs, current_cost + costs[0], next_day + 1, min_cost);

        options(days, costs, current_cost + costs[1], next_day + 7, min_cost);

        options(days, costs, current_cost + costs[2], next_day + 30, min_cost);
    }
};
