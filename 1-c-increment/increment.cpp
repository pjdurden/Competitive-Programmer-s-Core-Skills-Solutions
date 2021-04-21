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
//(UNCOMMENT WHEN NEEDED)\

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
#define deb1(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define deblp(i, a, n) fo(i, n){cout << a[i] << " ";}
#define clr(x) memset(x, 0, sizeof(x))

ll powmod(ll x,ll y){ll t; for(t=1;y;y>>=1,x=x*x%mod) if(y&1) t=t*x%mod; return t;}
ull gcd(ll x,ll y){return y?gcd(y,x%y):x;}
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
//ll n,m,q,r,i,j;
string cards;
string str;

long long int solved(long long int A[],long long int n) 
{ 
    long long int left[n], right[n]; 
  
    stack<pair<int, int> > s1, s2; 
    for (int i = 0; i < n; ++i) { 
        int cnt = 1; 
  
        while (!s1.empty() && (s1.top().first) > A[i]) { 
            cnt += s1.top().second; 
            s1.pop(); 
        } 
  
        s1.push({ A[i], cnt }); 
        left[i] = cnt; 
    } 
    for (int i = n - 1; i >= 0; --i) { 
        int cnt = 1; 
  
        while (!s2.empty() && (s2.top().first) >= A[i]) { 
            cnt += s2.top().second; 
            s2.pop(); 
        } 
  
        s2.push({ A[i], cnt }); 
        right[i] = cnt; 
    } 
    
    long long result = 0; 
  
    for (int i = 0; i < n; ++i) 
        result = (result + A[i] * left[i] * right[i]); 
  
    return result; 
}

void solve()    
{  
    string s;
    int l,flag;
    cin>>s;
    l = s.length();
    flag=0;
    for(auto x:s){
        if(x!='9'){
            flag=1;
            break;
        }
    }
    if(flag) cout<<l<<"\n";
    else cout<<(l+1)<<"\n";
}

 
 
 
 
int main()  
{
    ///*
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.in", "r", stdin);
    // for writing output to output.txt
    freopen("output.out", "w", stdout);
    #endif
    //*/
    int k=1;
    //cin>>k;
    //sieve();
    //int counter=1;
    while(k--)
    {
        //printf("Case %d: ",counter++);
        solve();
    }
    return 0;
}


