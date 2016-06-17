#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
int d[1000][3] = {0};

int stringReduction(string s) {
    string ans = s.substr(0,1);
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == 'a') {
            if (ans[0] == 'a') {
                ans.push_back('a');
            } else {
                if (ans.length()%2 == 0) {
                    ans = "a";
                } else {
                    if (ans[0] == 'b')
                        ans = "c";
                    else
                        ans = "b";
                }
            }
        }

        if (s[i] == 'b') {
            if (ans[0] == 'b') {
                ans.push_back('b');
            } else {
                if (ans.length()%2 == 0) {
                    ans = "b";
                } else {
                    if (ans[0] == 'c')
                        ans = "a";
                    else
                        ans = "c";
                }
            }
        }

        if (s[i] == 'c') {
            if (ans[0] == 'c') {
                ans.push_back('c');
            } else {
                if (ans.length()%2 == 0) {
                    ans = "c";
                } else {
                    if (ans[0] == 'a')
                        ans = "b";
                    else
                        ans = "a";
                }
            }
        }

    }

    return ans.length();
}

int main() {
    int res, t, i;
    scanf("%d",&t);
    //char a[100001];
    for (i=0;i<t;i++) {
        string s;
        cin >> s;
        res=stringReduction(s);
        printf("%d\n",res);
    }
    return 0;
}
