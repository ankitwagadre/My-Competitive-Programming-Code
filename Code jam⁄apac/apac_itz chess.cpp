
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

//int ap[50001];
int safe[66][66];
char cb[66][66];
void mov(int i, int j, int ii, int ji)
{
    safe[i][j]++;
    if (!cb[i][j] && i > 0 && j > 0 && i < 65 && j < 65)
        mov(i+ii, j+ji, ii, ji);
}

void movN(int i, int j)
{
    if (i < 1 || i > 64 || j < 1 || j > 64)
        return;

    safe[i][j]++;
}

int main() {
    freopen("D-large-practice.in","rt",stdin);
    //freopen("D-small-practice.in","rt",stdin);
	freopen("A_large.out","wt",stdout);
	int t;
	cin >> t;
	for(int i = 1; i <=t; i++)
    {
        cout << "Case #"<< i << ": ";
        int n;
        cin >> n;
        vector<pii> b;
        memset(safe, 0, sizeof(safe));
        memset(cb, 0, sizeof(cb));
        loop(j, 0, n)
        {
            string s;
            cin >> s;
            int si = (int)s[0] - 64;
            int sj = (int)s[1] - 48;
            cb[si][sj] = s[3];
            b.pb(mp(si, sj));
        }

        loop(j, 0, n)
        {
            if (cb[b[j].F][b[j].S] == 'K')
            {
                safe[b[j].F + 1][b[j].S - 1]++;
                safe[b[j].F + 1][b[j].S]++;
                safe[b[j].F + 1][b[j].S + 1]++;
                safe[b[j].F][b[j].S - 1]++;
                safe[b[j].F][b[j].S + 1]++;
                safe[b[j].F - 1][b[j].S - 1]++;
                safe[b[j].F - 1][b[j].S]++;
                safe[b[j].F - 1][b[j].S + 1]++;
            }
            if (cb[b[j].F][b[j].S] == 'Q')
            {
                mov(b[j].F + 1, b[j].S + 1, 1, 1);
                mov(b[j].F + 1, b[j].S, 1, 0);
                mov(b[j].F + 1, b[j].S - 1, 1, -1);

                mov(b[j].F , b[j].S + 1, 0, 1);
                mov(b[j].F , b[j].S - 1, 0, -1);

                mov(b[j].F - 1, b[j].S - 1, -1, -1);
                mov(b[j].F - 1, b[j].S, -1, 0);
                mov(b[j].F - 1, b[j].S + 1, -1, 1);
            }
            if (cb[b[j].F][b[j].S] == 'R')
            {
                mov(b[j].F , b[j].S + 1, 0, 1);
                mov(b[j].F , b[j].S - 1, 0, -1);
                mov(b[j].F + 1, b[j].S, 1, 0);
                mov(b[j].F - 1, b[j].S, -1, 0);

            }
            if (cb[b[j].F][b[j].S] == 'B')
            {
                mov(b[j].F + 1, b[j].S + 1, 1, 1);
                mov(b[j].F + 1, b[j].S - 1, 1, -1);
                mov(b[j].F - 1, b[j].S - 1, -1, -1);
                mov(b[j].F - 1, b[j].S + 1, -1, 1);

            }
            if (cb[b[j].F][b[j].S] == 'N')
            {
                movN(b[j].F+2, b[j].S+1);
                movN(b[j].F-2, b[j].S+1);
                movN(b[j].F+2, b[j].S-1);
                movN(b[j].F-2, b[j].S-1);

                movN(b[j].F+1, b[j].S+2);
                movN(b[j].F-1, b[j].S+2);
                movN(b[j].F+1, b[j].S-2);
                movN(b[j].F-1, b[j].S-2);
            }
            if (cb[b[j].F][b[j].S] == 'P')
            {
                safe[b[j].F + 1][b[j].S + 1]++;
                safe[b[j].F + 1][b[j].S - 1]++;
            }
        }

        int cnt = 0;
        loop(j, 0, n)
        {
            cnt += safe[b[j].F][b[j].S];
        }

        cout << cnt;
        cout << endl;
    }
	return 0;
}
