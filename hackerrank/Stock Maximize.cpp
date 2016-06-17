#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> maxindex(int p[], int st, int ed) {
    int mx = 0;
    int mxindex = st;
    for (int i = st; i <= ed; i++) {
        if (mx < p[i]) {
            mx = p[i];
            mxindex = i;
        }
    }

    return pair<int,int> (mxindex, mx);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int p[n];
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }

        int st = 0;
        int ed = n-1;
        int mx = 0;
        long long sum = 0;

        while (true) {
            pair<int, int> nw = maxindex(p, st, ed);
            ed = nw.first;
            mx = nw.second;

            for (int i = st; i <= ed; i++) {
                sum += mx - p[i];
            }

            if (ed >= n-1)
                break;

            st = ed + 1;
            ed = n - 1;
        }

        cout << sum <<endl;

    }
    return 0;
}
