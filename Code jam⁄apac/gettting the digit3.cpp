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
ll mod(ll a, ll md = MOD) { ll r = a % md;  return r < 0 ? r + md : r; }
int stringtobits(string s) {    int n = 0;  loop(i, 0, s.size()) n = (n<<1) | (s[i] - '0');  return n; }

ll stringtoint(string s) {  ll j = 0, n = 0, sign = 1;
    if (s[0] == '-') { j++; sign = -1; }
    loop(i, j, s.size()) { n = n*10 + s[i] - '0'; }
    return n*sign;
}

string s;
int main() {
    //freopen("A-large-practice.in","rt",stdin);
    //freopen("A-small-practice.in","rt",stdin);
	//freopen("A_large.out","wt",stdout);

	int t;
	cin >> t;
	for(int f = 1; f <=t; f++)
    {
        cin >> s;
        int n = s.size();
        int ans[10];
        memset(ans, 0, sizeof(ans));

        while(s.find('Z') < s.size()) {
            ans[0]++;
            s.erase(s.find('Z'), 1);
            s.erase(s.find('E'), 1);
            s.erase(s.find('R'), 1);
            s.erase(s.find('O'), 1);
        }

        while(s.find('U') < s.size()) {
            ans[4]++;
            s.erase(s.find('F'), 1);
            s.erase(s.find('O'), 1);
            s.erase(s.find('U'), 1);
            s.erase(s.find('R'), 1);
        }

        while(s.find('W') < s.size()) {
            ans[2]++;
            s.erase(s.find('T'), 1);
            s.erase(s.find('W'), 1);
            s.erase(s.find('O'), 1);
        }

        while(s.find('R') < s.size()) {
            ans[3]++;
            s.erase(s.find('T'), 1);
            s.erase(s.find('H'), 1);
            s.erase(s.find('R'), 1);
            s.erase(s.find('E'), 1);
            s.erase(s.find('E'), 1);
        }

        while(s.find('F') < s.size()) {
            ans[5]++;
            s.erase(s.find('F'), 1);
            s.erase(s.find('I'), 1);
            s.erase(s.find('V'), 1);
            s.erase(s.find('E'), 1);
        }

        while(s.find('X') < s.size()) {
            ans[6]++;
            s.erase(s.find('S'), 1);
            s.erase(s.find('I'), 1);
            s.erase(s.find('X'), 1);
        }

        while(s.find('S') < s.size()) {
            ans[7]++;
            s.erase(s.find('S'), 1);
            s.erase(s.find('E'), 1);
            s.erase(s.find('V'), 1);
            s.erase(s.find('E'), 1);
            s.erase(s.find('N'), 1);
        }

        while(s.find('G') < s.size()) {
            ans[8]++;
            s.erase(s.find('E'), 1);
            s.erase(s.find('I'), 1);
            s.erase(s.find('G'), 1);
            s.erase(s.find('H'), 1);
            s.erase(s.find('T'), 1);
        }

         while(s.find('I') < s.size()) {
            ans[9]++;
            s.erase(s.find('N'), 1);
            s.erase(s.find('I'), 1);
            s.erase(s.find('N'), 1);
            s.erase(s.find('E'), 1);
        }

        while(s.find('O') < s.size()) {
            ans[1]++;
            s.erase(s.find('O'), 1);
            s.erase(s.find('N'), 1);
            s.erase(s.find('E'), 1);
        }

        cout << "Case #"<< f << ": ";
        loop(i, 0, 10) {
            while(ans[i]--) cout << i;
        }
        cout << endl;
    }

	return 0;
}
