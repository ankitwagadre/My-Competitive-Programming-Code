
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
    vector< pair<int, int> > ed[n+1];
    loop(i, 0, m) {
        int a, b, c;
        cin >> a >> b >> c;
        ed[a].pb(mp(b, c));
        ed[b].pb(mp(a, c));
    }

    //vi st;
    //st.pb(1);
    int s;
    cin >> s;
    int dist[n+1];
    memset(dist, -1, sizeof(dist));
    dist[s] = 0;
    bool visited[n+1];
    memset(visited, false, sizeof(visited));
    int sm = 0;
    //cout << "size of 1st is " << ed[1].size() << endl;
    while(true) {
        int node = -1;
        loop(i, 1, n+1) {
            if(dist[i] != -1 && !visited[i])
            {
                if(node == -1 || dist[i] < dist[node])
                    node = i;
            }
        }

        //cout << " node " << node << " " << endl;
        if(node == -1) break;
        else {
            visited[node] = true;
            sm += dist[node];
            //cout << dist[node] << endl;
            for(vector< pair<int, int> >::iterator it = ed[node].begin(); it != ed[node].end(); ++it) {
                if (dist[(*it).F] == -1 || dist[(*it).F] > (*it).S)
                    dist[(*it).F] = (*it).S;
            }
        }
    }
    cout << sm << endl;
	return 0;
}
