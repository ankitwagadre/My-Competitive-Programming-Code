#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
//char a[201];
string a;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        cin >> a;
        int n = a.size();

        for (int i = 0; i < n; i++) {
            int s[201][201] = {0};
            for (int j = 0; j < n; j++) {
                if (a[i] == a[j]) {
                    s[i+1][j+1] = s[i][j] + 1;
                } else {
                    s[i+1][j+1] = s[i+1][j]>s[i][j+1]?s[i+1][j]:s[i][j+1];
                }
            }
        }
    }

    return 0;
}
