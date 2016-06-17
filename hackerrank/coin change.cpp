#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
long long s[250][250] = {0};

int main() {
    int n , m;
    scanf("%d %d", &n , &m);
    vector<int> c;
    //int
    for (int i = 0; i < m; i++) {
        int a;
        scanf("%d", &a);
        c.push_back(a);
        s[i][0] = 1;
    }
    sort(c.begin(), c.end());

    for (int i = 0; i < m; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != 0)
                s[i][j] = s[i-1][j];
            else {
                if (j%c[0] == 0) {
                    s[0][j] = 1;
                } /*else {
                    s[i][j] = 0;
                }*/
            }

            if (j-c[i] >= 0 && i != 0)
                s[i][j] += s[i][j-c[i]];
        }
    }

    cout << s[m-1][n];
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
