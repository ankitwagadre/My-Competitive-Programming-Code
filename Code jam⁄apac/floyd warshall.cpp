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

int main() {
    int n, m;
    cin >> n >> m;
    ll dist[n+1][n+1];
    loop(i, 0, n+1) {
        loop(j, 0, n+1) {
            dist[i][j] = -1;
            if (i == j) dist[i][j] = 0;
        }
    }

    loop(i, 0, m) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = c;
    }


    loop(v, 1, n+1) {
        loop(i, 1, n+1) {
            loop(j, 1, n+1) {
                if (dist[i][v] != -1 && dist[v][j] != -1) {
                    if (dist[i][j] == -1 || dist[i][j] > dist[i][v] + dist[v][j])
                        dist[i][j] = dist[i][v] + dist[v][j];
                }
            }
        }
    }

    int q;
    cin >> q;
    loop(i, 0, q) {
        int a, b;
        cin >> a >> b;
        //if (dist[a][b] == MAX) cout << -1 << endl;
        cout << dist[a][b] << endl;
    }

	return 0;
}
