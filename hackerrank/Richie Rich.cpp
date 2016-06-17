#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    char s[n];
    bool s_b[n];
    memset(s_b, false, sizeof(s_b));
    cin >> s;

    for(int i = 0; ( i < n/2 ) && (n-i-1 >= n/2); i++) {
        int a = ((int)s[i]) - 48;
        int b = ((int)s[n - i - 1]) - 48;
        if (a == b)
            continue;

        if (k < 1) {
            k = -1;
            break;
        }

        k--;
        if (a > b)
        {
            s[n - i -1] = (char)(a + 48);
            s_b[n-i-1] = true;
        }
        else
        {
            s_b[i] = true;
            s[i] = (char)(b + 48);
        }
    }

    int i = 0;
    while ((k > 0) && (n-i-1 >= n/2) && (i < n/2) ) {
        if (s_b[i] && (57 != (int)s[i]))
        {
            s[n-i-1] = '9';
            s[i] = '9';
            k--;
        }
        else if (s_b[n-i-1] && (57 != (int)s[n-i-1]))
        {
            s[n-i-1] = '9';
            s[i] = '9';
            k--;
        }
        else if ((!s_b[i]) && (!s_b[i]) && (k > 1) && (57 != (int)s[n-i-1]))
        {
            s[n-i-1] = '9';
            s[i] = '9';
            k -= 2;
        }

        i++;
    }

    if (k > 0 && n%2 != 0)
        s[n/2] = '9';


    if (k == -1)
        cout << "-1";
    else
        cout << s;
    return 0;
}
