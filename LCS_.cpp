/*************************************
 * An Easy LCS LightOJ - 1110 >> DP
 * @author Amirul Islam (shiningflash)
 ************************************/

#include <cstdio>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <sstream>
#include <stack>
#include <list>
#include <iostream>
#include <assert.h>

#define mem(x,y) memset(x,y,sizeof(x))
#define CLEAR(x) memset(x,0,sizeof(x))

#define pb push_back
#define Sort(v) sort(v.begin(),v.end())
#define _sort(s, n) sort(s, s+n)
#define sqr(x) ((x)*(x))

#define le 50001
#define ERR 1e-9
#define pi (2*acos(0))
#define PI 3.141592653589793

#define scanint(a) scanf("%d",&a)
#define scanLLD(a) scanf("%lld",&a)

typedef unsigned long long ll;
using namespace std;

/**********************End*******************/

string s1, s2;
int cost[105][105], path[105][105], lcs[105];
int t, l1, l2, lcs_len;

inline void LCS_LENGTH() {
    for (int i = 1; i <= l1; cost[i][0] = 0, i++);
    for (int j = 1; j <= l2; cost[0][j] = 0, j++);

    for (int i = 1; i <= l1; i++) {
        for (int j = 1; j <= l2; j++) {
            if (s1[i-1] == s2[j-1]) {
                cost[i][j] = cost[i-1][j-1] + 1;
                path[i][j] = 1;
            }
            else if (cost[i-1][j] >= cost[i][j-1]) {
                cost[i][j] = cost[i-1][j];
                path[i][j] = 2;
            }
            else {
                cost[i][j] = cost[i][j-1];
                path[i][j] = 3;
            }
        }
    }
    lcs_len = cost[l1][l2];
}

inline void LCS() {
    int i = l1, j = l2, k = lcs_len-1;
    while (k >= 0) {
        if (path[i][j] == 1) {
            lcs[k] = s1[i-1];
            i--; j--; k--;
        }
        else if (path[i][j] == 2) i--;
        else if (path[i][j] == 3) j--;
    }
}

inline void LCS_PRINT() {
    if (lcs_len <= 0) cout << ":(";
    else
        for (int i = 0; i < lcs_len; i++)
            cout << (char) lcs[i];
    cout << endl;
}

int main() {
    scanint(t);
    for (int i = 1; i <= t; i++) {
        cin >> s1 >> s2;
        l1 = s1.length(); l2 = s2.length();
        LCS_LENGTH();
        LCS();
        cout << "Case " << i << ": ";
        LCS_PRINT();
    }
}
