#include <bits/stdc++.h>
using namespace std;

void options(int n, string a, string b, int r, int d, string current, vector<string>& paths) {

    if (current.length() == n) {
        current += b[n - 1];
        paths.push_back(current);
        return;
    }
    
    if (r + 1 < n) {
        if (d == 1) {
            options(n, a, b, r + 1, d, current + b[r + 1], paths);
        } else {
            options(n, a, b, r + 1, d, current + a[r + 1], paths);
        }
    }

    if (d == 0) { 
        options(n, a, b, r, d + 1, current + b[r], paths);
    }
}

int main() {
    int t, n;
    cin >> t;
    vector<string> res;
    vector<int> frqs;
    
    for(int k=0; k<t; k++) {
        cin >> n;
        string a, b;
        cin >> a >> b;

        vector<string> paths;
        options(n, a, b, 0, 0, string(1, a[0]), paths);

        sort(paths.begin(), paths.end());
        string smallest = paths[0];

        int FrqSmallest = count(paths.begin(), paths.end(), smallest);

        res.push_back(smallest);
        frqs.push_back(FrqSmallest);
        
    }

    
    for (int i=0; i<t; i++){
        cout<<res[i]<<endl;
        cout<<frqs[i]<<endl;
    }
    return 0;
}
