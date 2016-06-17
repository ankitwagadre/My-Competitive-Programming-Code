
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

int gcd(int a, int b) { if(a==0) return b; return gcd(b%a, a);}
ll gcdl(ll a, ll b) { if(a==0) return b; return gcd(b%a, a);}

long long stobinary(string a)
{
    long long ans = 0;
    for(int i = 0; i < a.length(); i++)
    {
        ans = ans << 1;
        if (a[i] == '1')
            ans = (ans|1);
    }

    return ans;
}

int main() {

    string a, b;
    cin >> a>>b;
    long long ab = stobinary(a);
    long long bb = stobinary(b);
    long long sum = 0;
    long long mod = 1000000007;
    for(int i = 0; i <= 314159; i++)
    {
        sum = (sum + (a^(b<<i)))%mod;
    }

    cout << sum;
	return 0;
}
