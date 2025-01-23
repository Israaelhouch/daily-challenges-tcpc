#include <bits/stdc++.h>
using namespace std;

int main() {
    long n, k;
    cin >> n >> k;

    vector<int> heights(n);
    for (long i = 0; i < n; i++) {
        cin >> heights[i];
    }

    long current_sum = 0;
    for (long i = 0; i < k; i++) {
        current_sum += heights[i];
    }

    long min_sum = current_sum;
    long min_index = 0; // 0-based index for the starting plank

    for (long i = 1; i <= n - k; i++) {
        current_sum = current_sum - heights[i - 1] + heights[i + k - 1];

        if (current_sum < min_sum) {
            min_sum = current_sum;
            min_index = i;
        }
    }
    cout << min_index + 1 << endl;

    return 0;
}
