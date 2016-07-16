
#include<bits/stdc++.h>
#include <string>
#include <cstring>

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
int stringtonum(string s) {
    int num = 0;
    loop(i, 0, s.size()) {
        //const char c = s[i];
        num = num*10 + (int)s[i] - '0';
    }
    return num;
}
int main() {
    //freopen("B-large-practice.in","rt",stdin);
    //freopen("B-small-practice.in","rt",stdin);
	//freopen("A_large.out","wt",stdout);
	int t;
	cin >> t;
	for(int f = 1; f <=t; f++)
    {
        //cout << "Case #"<< f << ": ";
        int n;
        cin >> n;
        map< string, vector< pair<string, int> > > ed;
        loop(i, 0, n) {
            string in;
            cin >> in;
            int eq = 0;
            int pl = 0;
            loop(i, 0, in.size()) {
                if (in[i] == '=') eq = i;
                if (in[i] == '+') pl = i;
            }

            string a = in.substr(0, pl);
            string b = in.substr(pl+1, eq - pl - 1);
            int val = stringtonum(in.substr(eq+1, in.size() - eq - 1));


        }

        cout << endl;
    }
	return 0;
}
