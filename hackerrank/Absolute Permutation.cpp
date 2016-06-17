#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;


int main() {

    int t;
    cin >> t;
    while (t--)
    {
        int n = 0;
        int k = 0;
        scanf("%d  %d", &n, &k);
        //cin >> n >> k;
        bool regularOrder = true;
        bool possible = true;
        if (n%2 != 0)
        {
            if (k == 0)
                regularOrder = true;
            else
                possible = false;
        }
        else
        {
            if (k == 0)
                regularOrder = true;
            else if (k == n/2)
                regularOrder = false;
            else
                possible = false;
        }

        for (int i = 1; i <= n; i++)
        {
            if (!possible)
            {
                cout << "-1";
                break;
            }
            else
            {
                if (regularOrder)
                    cout << i << " ";
                else
                    if (i <= n/2)
                        cout << i + k<< " ";
                    else if ( i + k == n)
                        cout << n;
                    else
                        cout << i - k<< " ";
            }
        }
        cout << endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
