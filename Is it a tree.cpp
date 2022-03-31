
#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int
#define forn(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define ff first 
#define ss second 
#define vi vector<int>
const int M = 1e9 + 7;

int n,m;
vi ar[20001];
int vis[10001];


void dfs(int node)
{
                              vis[node] = 1;
                              
                              for(int ad: ar[node])
                              if(!vis[ad])
                              dfs(ad);
}
void solve()
{   
                              
    cin>>n>>m;
    
    for(int i = 1; i<=m; i++)
    {
                                  int a,b;
                                  cin>>a>>b;
                                  ar[a].pb(b);
                                  ar[b].pb(a);
    }
    int cc = 0;
    for(int i = 1; i<=n; i++)
    {
                                  if(!vis[i])
                                   dfs(i), cc++;
    }
    
    if(cc == 1 && m == n-1)
    cout<<"YES";
    else
    cout<<"NO";
    
    return;
}

signed main()
{   IOS
    //int t;
    //cin>>t;
    //while(t--)
    solve();
    return 0;
}


