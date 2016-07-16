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

ll mod(ll a, ll md = MOD) {
    ll r = a % md;
    return r < 0 ? r + md : r;
}

int rnk = 1;

int main() {
    freopen("A-large-practice.in","rt",stdin);
    //freopen("A-small-practice.in","rt",stdin);
	freopen("A2__large.out","wt",stdout);
	int t;
	cin >> t;
	for(int f = 1; f <=t; f++)
    {
        int p;
        cin >> p;
        int points[p];
        loop(i, 0, p) cin >> points[i];
        int n;
        cin >> n;
        map<string, vector<int> > lst;
        loop(i, 0, n) {
            int w;
            cin >> w;
            loop(j, 0, p) {
                string name;
                cin >> name;
                lst[name].push_back(w*points[j]);
            }
        }

        int m;
        cin >> m;
        vector< pair<int, string> > scbd;
        for(map<string, vector<int> > :: iterator it = lst.begin(); it != lst.end(); ++it) {
                sort(it->second.begin(), it->second.end());
                scbd.pb(mp(it->second.back(), it->first));
                int limit = 0;
                if (m < it->second.size()) {
                    limit = it->second.size() - m;
                }
                for(int i = it->second.size() - 2; i >= limit; i--) {
                    scbd.back().first += it->second[i];
                }
        }

        sort(scbd.begin(), scbd.end());
        cout << "Case #"<< f << ":" << endl;
        rnk = 1;
        rloop(i, 0, scbd.size()) {
            vector<string> ranks;
            ranks.clear();
            int k = i;
            int tpcs = scbd[i].first;
            while(k >= 0 && tpcs == scbd[k].first) {
                ranks.pb(scbd[k].second);
                k--;
            }
            sort(ranks.begin(), ranks.end());
            loop(j, 0, ranks.size()) {cout << rnk << ": " << ranks[j]<< endl;}
            i = k + 1;
            rnk += ranks.size();
        }
    }
	return 0;
}
