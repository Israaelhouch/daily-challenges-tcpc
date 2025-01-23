#include <bits/stdc++.h>
using namespace std;

int main() {
    long n, m;
    cin >> n;
    
    vector<int> prices(n), b_color(n), f_color(n);

    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b_color[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> f_color[i];
    }
    
    cin >> m;
    vector <int> choices;
    
    for (int i=0; i<m; i++){
        int c;
        cin >> c;
        
        vector <int> options;
        bool test=0;
        for (int j=0; j<n; j++){
            if (b_color[j]==c || f_color[j]==c){
                options.push_back(prices[j]);
                test=1;
            }
        }
        
        if (test){
            
            int min = *min_element(options.begin(), options.end());
            choices.push_back(min);
            
            auto it = find(prices.begin(), prices.end(), min);
            prices[it - prices.begin()]=0;
            b_color[it - prices.begin()]=0;
            f_color[it - prices.begin()]=0;
            
        }else{
            choices.push_back(-1);
        }
    }
    
    for (auto element:choices){
        cout<<element<<" ";
    }
    

    return 0;
}
