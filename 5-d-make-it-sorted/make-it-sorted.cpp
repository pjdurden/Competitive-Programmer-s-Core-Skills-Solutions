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
typedef long long ll;
typedef unsigned long long ull;
const int mod=1e9+7;
#define eps 1e-7
#define PI 3.1415926535897932384626
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sortall(x) sort(all(x))
#define vpi vector<pi>
#define vi vector<ll>
#define pi pair<ll,ll>
#define pb push_back
#define ppb pop_back
#define umap unordered_map
#define uset unordered_set
#define vvi vector<vector<ll>>
#define minheap priority_queue<ll,vi,greater<ll>>
#define maxheap priority_queue<ll>
#define minheapi priority_queue<pi,vpi,greater<pi>>
#define maxheapi priority_queue<pi>
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define fo(i, n) for(i=0;i<n;i++)
#define fox(i,a,b) for(i=a;i<b;i++)
#define deb1(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define deblp(i, a, n) fo(i, n){cout << a[i] << " ";}
#define clr(x) memset(x, 0, sizeof(x))
#define fills(a,val) fill_n(a, sizeof(a)/sizeof(a[0]), val)

ll powmod(ll x,ll y){ll t; for(t=1;y;y>>=1,x=x*x%mod) if(y&1) t=t*x%mod; return t;}
ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
ll lcm(ll x,ll y){return x*(y/gcd(x,y)); }
ll modd(ll a){return (a%mod + mod)%mod;}
ll add(ll a,ll b){return modd(modd(a)+modd(b));}
ll mul(ll a,ll b){return modd(modd(a)*modd(b));}
int smask(int i,int pos){ return (i|(1<<pos)); }
int clmask(int i,int pos){return (i&(~(1<<pos))) ; }
bool chmask(int i,int pos){return (i&(1<<pos))!=0 ;}
double cordist(pair<double,double> a,pair<double,double> b)
{return sqrt(((a.first-b.first)*(a.first-b.first))+((a.second-b.second)*(a.second-b.second)));}



//ll prime[60];
//int posx[10];
//int posy[10];
//im,q,r;nt price[30]; 
//char board[26][26];
ll n,m,q,r,i,j;
//every node should not be connected to 2 nodes
bool part[100005][101];
int sum;


bool findPartiion(int arr[], int n)
{
    sum = 0;
    int i, j;
 
    // Calculate sum of all elements
    for (i = 0; i < n; i++)
        sum += arr[i];
 
    if (sum % 2 != 0)
        return false;
 

 
    // initialize top row as true
    for (i = 0; i <= n; i++)
        part[0][i] = true;
 
    // initialize leftmost column,
    // except part[0][0], as 0
    for (i = 1; i <= sum / 2; i++)
        part[i][0] = false;
 
    // Fill the partition table in bottom up manner
    for (i = 1; i <= sum / 2; i++) {
        for (j = 1; j <= n; j++) {
            part[i][j] = part[i][j - 1];
            if (i >= arr[j - 1])
                part[i][j] = part[i][j]
                             || part[i - arr[j - 1]][j - 1];
        }
    }
 
    /* // uncomment this part to print table
    for (i = 0; i <= sum/2; i++)
    {
    for (j = 0; j <= n; j++)
        cout<<part[i][j];
    cout<<endl;
    } */
 
    return part[sum / 2][n];
}

void solve()   
{  
     int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int m = *max_element(a.begin(), a.end());
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        int bestBelow = 1e9;
        for (int j = 0; j <= m; ++j) {
            bestBelow = min(bestBelow, dp[i][j]);
            dp[i + 1][j] = bestBelow + abs(a[i] - j);
        }
    }

    cout << *min_element(dp[n].begin(), dp[n].end()) << '\n';

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


