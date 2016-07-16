
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

ll a = 0, k = 0;
ll total = 0;
string op = "";

void solve(string &s, ll i, ll sum) {
    if (!op.empty()) return;
    if (sum<0) return;
    if (i >= a) {
        if (sum == 0) {
            total++;
            if (total == k) {
                op = s;
            }
        }
        return;
    }

    s.push_back('(');
    solve(s, i+1, sum+1);
    s.pop_back();

    s.push_back(')');
    solve(s, i+1, sum-1);
    s.pop_back();
}
int main() {
    freopen("D-large-practice.in","rt",stdin);
    //freopen("D-small-practice.in","rt",stdin);
	//freopen("A_large.out","wt",stdout);
	int t;
	cin >> t;
	for(int i = 1; i <=t; i++)
    {
        ll n;
        cin >> n >> k;
        a = 2*n;
        //kk = k;
        op = "";
        total = 0;
        cout << "Case #" << i << ": ";
        string ss = "";
        solve(ss, 0, 0);
        if(op.empty()) cout << "Doesn't Exist!";
        else cout << op;
        cout << endl;
    }
	return 0;
}
