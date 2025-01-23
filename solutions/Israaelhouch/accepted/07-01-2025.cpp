#include <bits/stdc++.h>
using namespace std;

long mask(long a) {
    long res = 0;
    long multiplier = 1;
    
    while (a != 0) {
        int digit = a % 10;
        if (digit == 4 || digit == 7) {
            res += digit * multiplier;
            multiplier *= 10;
        }
        a /= 10;
    }
    
    return res;
}

int main() {
    long a, b;
    cin>>a>>b;
    a++;
    while(mask(a) != b){
        a++;
    }
    cout<<a;

    return 0;
}
