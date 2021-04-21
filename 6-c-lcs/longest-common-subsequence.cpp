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

int MatrixChainOrder(int p[], int n) 
{ 
    int m[n][n]; 
  
    int i, j, k, L, q; 
    for (i = 1; i < n; i++) 
        m[i][i] = 0; 
    for (L = 2; L < n; L++) 
    { 
        for (i = 1; i < n - L + 1; i++) 
        { 
            j = i + L - 1; 
            m[i][j] = INT_MAX; 
            for (k = i; k <= j - 1; k++) 
            { 
                q = m[i][k] + m[k + 1][j] +  
                    p[i - 1] * p[k] * p[j]; 
                if (q < m[i][j]) 
                    m[i][j] = q; 
            } 
        } 
    } 
  
    return m[1][n - 1]; 
} 

void solve()   
{  
    int n;
    cin>>n;
    int *array1 = new int[n];
    int *array2 = new int[n];
    for(int i = 0; i < n; i++) {
        cin>>array1[i];
    }
    for(int i = 0; i < n; i++) {
        cin>>array2[i];
    }
    
    int **matrix = new int*[n+1];
    for(int i = 0; i <= n; i++) {
        matrix[i] = new int[n+1];
        for(int j = 0; j <= n; j++) {
            matrix[i][j] = 0;
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(array1[i-1] == array2[j-1]) {

                matrix[i][j] = matrix[i-1][j-1] + 1;
            } else {
                matrix[i][j] = max(matrix[i-1][j], matrix[i][j-1]);
            }
        }
    }
    int *lcs = new int[matrix[n][n]];
    int count = matrix[n][n];
    cout<<count<<endl;
    int i = n, j = n;
    while(count > 0) {
        if(matrix[i-1][j] == matrix[i][j]) {
            // Value came from smaller array1
            i--;
        } else if(matrix[i][j-1] == matrix[i][j]) {
            // Value came from smaller array2
            j--;
        } else {
            // Value came from the letter at the current index
            lcs[count-1] = array1[i-1];
            i--;
            j--;
            count--;
        }
    }
    int ind=0;
    for(int i = 0; i < n; i++) {
        if(array1[i]==lcs[ind]){
            cout<<i<<" ";
            ind++;
        }
    }
    cout<<endl;
    ind=0;
    for(int i = 0; i < n; i++) {
        if(array2[i]==lcs[ind]){
            cout<<i<<" ";
            ind++;
        }
    }
    
    cout<<endl;


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


