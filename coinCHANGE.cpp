/*************************************************
 * The Legendry Coin Change Problem CodeChef - CTY2
 * @author Amirul Islam (shiningflash) >> DP O(n)
 *************************************************/

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

/**Define memory set function**/
#define mem(x,y) memset(x,y,sizeof(x))
#define CLEAR(x) memset(x,0,sizeof(x))

/**Define function and object**/
#define pb push_back
#define Sort(v) sort(v.begin(),v.end())
#define _sort(s, n) sort(s, s+n)
#define sqr(x) ((x)*(x))

/**Define constant value**/
#define le 9999999
#define ERR 1e-9
#define pi (2*acos(0))
#define PI 3.141592653589793

/**Define input**/
#define scanint(a) scanf("%d", &a)
#define scanint2(a, b) scanf("%d %d", &a, &b)
#define scanLLD(a) scanf("%llu", &a)

typedef long long ll;

using namespace std;

/**********************End*******************/

int n, m;

int main() {
    scanint2(n, m);
    int* a = new int[m];
    long* dp = new long[n+1];
    dp[0] = 1;

    for (int i = 0; i < m; scanint(a[i]), i++);

    for (int i = 0; i < m; i++)
        for (int j = a[i]; j <= n; j++)
            dp[j] += dp[j-a[i]];

    cout << dp[n] << endl;
    return 0;
}
