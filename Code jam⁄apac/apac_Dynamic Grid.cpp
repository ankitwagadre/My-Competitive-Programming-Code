/**************************
*   Ankit Wagadre
*   ankitwagadre@github.com
**************************/
#include<bits/stdc++.h>

#define ll                    long long int
#define loop(i,a,b)           for(int i=(int)a;i<(int)b;++i)
#define loopl(i,a,b)          for(ll i=(ll)a;i<(ll)b;++i)
#define rloop(i,a,b)          for(int i=(int)b - 1;i>=(int)0;--i)
#define rloopl(i,a,b)         for(ll i=(ll)b - 1;i>=(ll)0;--i)
#define pb                    push_back
#define eb                    emplace_back
#define F                     first
#define S                     second
#define mp                    make_pair
#define clr(x)                x.clear()
#define MOD                   1000000007
#define MAX                   1e9
#define MIN                   -1e9
#define vi                    vector<int>
#define vvi                   vector<vi>
#define pll                   pair<ll,ll>
#define pii                   pair<int,int>
#define all(p)                p.begin(),p.end()
#define max(x,y)              (x>y)?x:y
#define min(x,y)              (x<y)?x:y
#define mid(s,e)              (s+(e-s)/2)
#define mini                  INT_MIN
#define itoc(c)               ((char)(((int)'0')+c))
using namespace std;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int gcd(int a, int b) { if(a==0) return b; return gcd(b%a, a);}
ll gcdl(ll a, ll b) { if(a==0) return b; return gcd(b%a, a);}

int g[110][110];
bool visited[100000];
int r, c;
int cls = 2;

ll mod(ll a, ll md = MOD) {
    ll r = a % md;
    return r < 0 ? r + md : r;
}

void dfs(int i, int j , int cls) {
    if (g[i][j] > 0 && g[i][j] != cls) {
        g[i][j] = cls;
        if (i < r - 1) dfs(i+1, j, cls);
        if (i > 0) dfs(i-1, j, cls);
        if (j < c -1) dfs(i, j+1, cls);
        if (j > 0) dfs(i, j-1, cls);
    }
}

int cntClass() {
    memset(visited, false, sizeof(visited));
    visited[0] = true;
    int ct = 0;
    loop(i, 0, r) {
        loop(j, 0, c) {
            if (!visited[g[i][j]]) {
                visited[g[i][j]] = true;
                ct++;
            }
        }
    }

    return ct;
}

int main() {
    //freopen("A-large-practice.in","rt",stdin);
    //freopen("A-small-practice.in","rt",stdin);
	//freopen("A_large.out","wt",stdout);
	int t;
	cin >> t;
	for(int f = 1; f <=t; f++)
    {
        cout << "Case #"<< f << ":" << endl;
        r = 0;
        c = 0;
        cin >> r >> c;
        memset(g, 0, sizeof(g));
        loop(i, 0, r) {
            string ss;
            cin >> ss;
            loop(j, 0, ss.size()) g[i][j] = (int)ss[j] - (int)'0';
        }

        cls = 2;
        loop(i, 0, r) {
            loop(j, 0, c) {
                if (g[i][j] == 1) {
                    dfs(i, j, cls);
                    cls++;
                }
            }
        }

        int n;
        cin >> n;
        loop(i, 0, n) {
            string s;
            cin >> s;
            if (s[0] == 'Q') {
                cout << cntClass() << endl;
            } else {
                int x, y, z;
                cin >> x >> y >> z;
                if (g[x][y] != z) {
                    if (z == 1) {
                        g[x][y] = 1;
                        dfs(x, y, cls);
                        cls++;
                    } else {
                        g[x][y] = 0;
                        dfs(x+1, y, cls);
                        cls++;
                        dfs(x-1, y, cls);
                        cls++;
                        dfs(x, y+1, cls);
                        cls++;
                        dfs(x, y-1, cls);
                        cls++;
                    }
                }
            }
        }
    }
	return 0;
}
