#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;



int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int mxsum[n] = {0};
        int sum_b[n] = {0};
        int b[n] = {0};
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            mxsum[i] = 0;
            sum_b[i] = 0;
        }


        sum_b[n-1] = b[n-1];
        for (int i = n-2; i >= 0; i--) {
            sum_b[i] = sum_b[i + 1] + b[i];
        }
        mxsum[n-1] = sum_b[n-1];

        if (n > 3) {
            mxsum[n-2] = sum_b[n-2];
            mxsum[n-3] = sum_b[n-3];
            for (int i = n-4; i >= 0; i--) {
                int p = sum_b[i] - mxsum[i+1];
                int q = sum_b[i] -  mxsum[i+2];
                int r = sum_b[i] -  mxsum[i+3];
                if (p > q && p > r)
                {
                    mxsum[i] = p;
                }
                else if (q >= p && q > r)
                {
                    mxsum[i] = q;
                }
                else
                {
                    mxsum[i] = r;
                }
            }
        }

        cout <<  mxsum[0] << endl;
    }
    return 0;
}
