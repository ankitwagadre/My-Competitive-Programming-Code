#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
//int per[100001] = {0};

int main() {

    int t;
    cin >> t;
    while (t--)
    {
        int n = 0;
        int k = 0;
        bool possible = true;
        //scanf("%d  %d", &n, &k);
        cin >> n >> k;
        int per[n+1];
        memset(per, 0, sizeof(per));
        if (n%2 != 0)
        {
            if (k == 0)
            {
                for (int i = 1; i <= n; i++)
                {
                    per[i] = i;
                }
            }
            else
            {
                possible = false;
            }
        }
        else
        {
            for (int i = 1; i <= n; i++)
            {
                if (per[i] == 0)
                {
                    int a = (i + k)%(n+1);
                    per[i] = a;
                    if (per[a] == 0)
                        per[a] = i;
                    else if (k > 0)
                    {
                        possible = false;
                        break;
                    }
                }
            }
        }

        if (!possible)
            cout << "-1" << endl;
        else
        {
            for (int i = 1; i <= n; i++)
            {
                cout << per[i] << " ";
            }
            cout << endl;
        }
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
