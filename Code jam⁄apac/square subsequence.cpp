
#include<bits/stdc++.h>

#define ll                    long long int
#define loop(i,a,b)           for(int i=(int)a;i<(int)b;++i)
#define loopl(i,a,b)          for(ll i=(ll)a;i<(ll)b;++i)
#define rloop(i,a,b)          for(int i=(int)b - 1;i>=(int)0;--i)
#define rloopl(i,a,b)         for(ll i=(ll)b - 1;i>=(ll)0;--i)
#define mems(a, b)            memset(a, b, sizeof(a))
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

ll d[201][201];
vector<int> ep1[201[201];
vector<int> ep2[201][201];

int sqsub(int i, int j, int l, string s)
{
    if (i >= j)
        return 0;

    if (i+l-1 >= j)
        return 0;

    //bool found = false;
    for(int n = i; n < j; n++)
    {
        for (int m = j; m < s.length(); m++)
        {

        }
        //if (found) break;
    }

    if (found)
    {
        d[i][j] = l;
        return l;
    }
    else
    {
        return 0;
    }
}

int main() {
    int t;
    cin >>t;
    while(t--)
    {
        string a;
        cin >>a;
        mems(d, 0);

        ll cnt = 0;
        loop(i, 0, a.length())
        {
            loop(j, 0, a.length())
            {
                if ( i < j  && a[i] == a[j])
                {
                    ep1[i][1] = i;
                    ep2[j][1] = j;
                    d[i][j] = 1;
                    cnt++;
                    cnt %= 1000000007;
                }
            }
        }



        //ll cnt = 0;
        loop(i, 0, a.length())
        {
            loop(j, 0, a.length())
            {
                loop(k, 2, a.length())
                {
                    if ( sqsub(i, j, k, a)  == k)
                    {
                        cnt++;
                        cnt %= 1000000007;
                    }
                }
            }
        }
        //cout << sqsub(0, 2, 2, a);

        cout << cnt;


    }

	return 0;
}
