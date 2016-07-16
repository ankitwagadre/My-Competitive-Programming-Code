
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
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<int> ed[n+1];
        int dist[n+1];
        memset(dist, -1, sizeof(dist));
        loop(i, 0, m) {
            int a, b;
            cin >> a >> b;
            ed[a].pb(b);
            ed[b].pb(a);
        }
        int  s;
        cin >> s;
        vi st;
        st.pb(s);
        dist[s] = 0;
        while(!st.empty()) {
            int node = st.front();
            st.erase(st.begin());
            for(vi::iterator it = ed[node].begin(); it != ed[node].end(); ++it) {
                if (dist[(*it)] == -1) {
                    st.pb(*it);
                    dist[*it] = dist[node] + 6;
                }
            }
        }

        loop(i, 1, n+1) {
            if(i != s) cout << dist[i] << " ";
        }
        cout << endl;
    }
	return 0;
}
