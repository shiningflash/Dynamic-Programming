// memomizing (top down) method

#include <bits/stdc++.h>
using namespace std;

#define nil -1
#define le 100

typedef long long ll;

int lookup[le];

ll fib(int n) {
    if (lookup[n] == nil) {
        if (n <= 1) lookup[n] = n;
        else lookup[n] = fib(n-1) + fib(n-2);
    }
    return lookup[n];
}

int main() {
    int n; cin >> n;
    for (int i = 0; i <= n; lookup[i] = nil, i++);
    ll ans = fib(n);
    cout << ans << endl;
    return 0;
}
