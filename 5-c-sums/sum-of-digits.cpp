/*
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.in", "r", stdin);
    // for writing output to output.txt
    freopen("output.out", "w", stdout);
#endif
*/

//(UNCOMMENT WHEN HAVING LOTS OF RECURSIONS)
//#pragma comment(linker, "/stack:200000000")
//(UNCOMMENT WHEN NEEDED)

#include <bits/stdc++.h>
#include<time.h>
using namespace std;
// typedef long long ll;
// typedef unsigned long long ull;
// const int mod=1e9+7;
// #define eps 1e-7
// #define PI 3.1415926535897932384626
// #define all(x) x.begin(), x.end()
// #define rall(x) x.rbegin(), x.rend()
// #define sortall(x) sort(all(x))
// #define vpi vector<pi>
// #define vi vector<ll>
// #define pi pair<ll,ll>
// #define pb push_back
// #define ppb pop_back
// #define umap unordered_map
// #define uset unordered_set
// #define vvi vector<vector<ll>>
// #define minheap priority_queue<ll,vi,greater<ll>>
// #define maxheap priority_queue<ll>
// #define minheapi priority_queue<pi,vpi,greater<pi>>
// #define maxheapi priority_queue<pi>
// #define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
// #define fo(i, n) for(i=0;i<n;i++)
// #define fox(i,a,b) for(i=a;i<b;i++)
// #define deb1(x) cout << #x << " = " << x << endl;
// #define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
// #define deblp(i, a, n) fo(i, n){cout << a[i] << " ";}
// #define clr(x) memset(x, 0, sizeof(x))
// #define fills(a,val) fill_n(a, sizeof(a)/sizeof(a[0]), val)

// ll powmod(ll x,ll y){ll t; for(t=1;y;y>>=1,x=x*x%mod) if(y&1) t=t*x%mod; return t;}
// ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
// ll lcm(ll x,ll y){return x*(y/gcd(x,y)); }
// ll modd(ll a){return (a%mod + mod)%mod;}
// ll add(ll a,ll b){return modd(modd(a)+modd(b));}
// ll mul(ll a,ll b){return modd(modd(a)*modd(b));}
// int smask(int i,int pos){ return (i|(1<<pos)); }
// int clmask(int i,int pos){return (i&(~(1<<pos))) ; }
// bool chmask(int i,int pos){return (i&(1<<pos))!=0 ;}
// double cordist(pair<double,double> a,pair<double,double> b)
// {return sqrt(((a.first-b.first)*(a.first-b.first))+((a.second-b.second)*(a.second-b.second)));}

#define MOD 1000000007
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
#define loops(i,a,b,step) for(int i=a;i<b;i+=step)
#define looprs(i,a,b,step) for(int i=a;i>=b;i-=step)
#define ull unsigned long long int
#define ll long long int
#define P pair
#define PLL pair<long long, long long>
#define PII pair<int, int>
#define PUU pair<unsigned long long int, unsigned long long int>
#define L list
#define V vector
#define D deque
#define ST set
#define MS multiset
#define M map
#define UM unordered_map
#define mp make_pair
#define pb push_back
#define pf push_front
#define MM multimap
#define F first
#define S second
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);


//ll prime[60];
//int posx[10];
//int posy[10];
//im,q,r;nt price[30]; 
//char board[26][26];
ll n,m,q,r,i,j;
//every node should not be connected to 2 nodes

const ll maxn = 1e5;
int s,l;
ll dp[200][20];

ll cal(ll sum, ll dig){
    if(sum > s)return 0;
    if(dig == l){
        if(sum == s)return 1;
        return 0;
    }
    if(dp[sum][dig] != -1)return dp[sum][dig];
    ll res = 0;
    loop(i,0,10){
        if(dig == 0 && i == 0)continue;
        res+=cal(sum+i,dig+1);
    }
    dp[sum][dig] = res;
    return dp[sum][dig];
}

void solve()   
{  
    memset(dp,-1,sizeof(dp));
    cin >> s >> l;
    if(s == 0 && l == 1)cout << "1";
    else cout << cal(0,0);

}

 
 
 
 
int main()  
{
    //IOS
    // #ifndef ONLINE_JUDGE
    // // for getting input from input.txt
    // freopen("input.in", "r", stdin);
    // // for writing output to output.txt
    // freopen("output.out", "w", stdout);
    // #endif
    
    int k=1;
    //cin>>k;
    //sieve();
    //int counter=1;
    while(k--)
    {
        //printf("Case #%d: ",counter++);
        solve();
    }
    return 0;
}


