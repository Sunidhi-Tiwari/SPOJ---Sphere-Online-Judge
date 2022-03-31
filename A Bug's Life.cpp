//BUGLIFE - A Bug’s Life
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


vi ar[2001];
int vis[2001], col[2001];


bool dfs(int node, int c)
{
                              vis[node] = 1;
                              col[node] = c;
                              
                              for(auto ad: ar[node])
                              {
                                                            if(!vis[ad])
                                                            {
                                                                                          if(!dfs(ad,c^1))
                                                                                          return false;
                                                            }
                                                            
                                                            if(col[ad] == col[node])
                                                            return false;
                              }
                              
                              return true;
}

void solve()
{   
    int t;
    cin>>t;
    
    for(int i = 1; i<=t; i++)
    {
                                  int n,m,a,b;
                                  cin>>n>>m;
                                  
                                  for(int i = 1; i<=n; i++) ar[i].clear(), vis[i] = 0;
                                  
                                  for(int i = 1; i<=m; i++)
                                  cin>>a>>b, ar[a].pb(b), ar[b].pb(a);
                                  
                                  int flag = true;
                                  
                                  for(int i = 1; i<=n; i++)
                                  {
                                              if(!vis[i])
                                              if(!dfs(i,0))
                                              flag = false;
                                              
                                  }
                                  
                                  if(flag)
                                  cout<<"Scenario #"<<i<<":"<<"\n"<<"No suspicious bugs found!"<<"\n";
                                  else
                                  cout<<"Scenario #"<<i<<":"<<"\n"<<"Suspicious bugs found!"<<"\n";
                                 
    }
    return;
}

signed main()
{   IOS
    
    solve();
    return 0;
}


