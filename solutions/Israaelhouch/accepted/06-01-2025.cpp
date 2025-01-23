#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    cin >> t; 
    vector<vector<pair<int, int>>> vec_of_sorted_maps;

    while (t--) {
        cin >> n; 

        map<int, int> freq_map; 
        vector<vector<int>> matrix(n, vector<int>(n - 1)); 

        for (int l = 0; l < n; l++) {
            int h = n;
            for (int j = 0; j < n - 1; j++) {
                cin >> matrix[l][j];
                freq_map[matrix[l][j]] += h;
                h--;
            }
        }

        vector<pair<int, int>> sorted_vector(freq_map.begin(), freq_map.end());
        sort(sorted_vector.begin(), sorted_vector.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 return a.second > b.second; 
             });

        vec_of_sorted_maps.push_back(sorted_vector);
    }

    for (size_t i = 0; i < vec_of_sorted_maps.size(); ++i) {
        for (const auto& pair : vec_of_sorted_maps[i]) {
            cout << pair.first << " ";
        }
        cout<<endl;
    }

    return 0;
}
