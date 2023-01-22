#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int

int N = 1e6;

vector<bool> prime(N, 1);

void sieve()
{
              prime[1] = 0;
              prime[0] = 0;
              
              for(int i = 2; i*i<N; i++)
              
              {                              
                                            if(prime[i])
                                            {
                                                 for(int j = i*i; j<N; j+=i)
                                                 {
                                                      prime[j] = 0;                    
                                                 }
                                            }
              }
              
              
              
              
              return;
              
}

vector<int> generatePrimes(int n)
{
                              vector<int> ds;
                              for(int i = 2; i<=n; i++)
                              if(prime[i]) ds.push_back(i);
                              
                              return ds;
}



signed main()
{   IOS
    
    sieve();
    int t;
    cin>>t;
    
    while(t--)
    {
                                  int l,r;
                                  cin>>l>>r;
                                  
                                  vector<int> p = generatePrimes(sqrt(r));
                                  vector<int> dummy(r-l+1,1);
                                  
                                  for(auto pr: p)
                                  {
                                                                int firstmultiple = (l/pr)*pr;
                                                                if(firstmultiple<l) firstmultiple += pr;
                                                                
                                                                for(int j = max(firstmultiple, pr*pr); j<=r; j+=pr)
                                                                {
                                                                                              dummy[j-l] = 0;
                                                                }
                                  }
                                  
                                  
                                  for(int i = max(l,2LL); i<=r; i++)
                                  {
                                                                if(dummy[i-l] == 1) cout<<i<<"\n";
                                  }
                                  
                                  cout<<"\n";
                                  
                                  
    }
    
    
    return 0;
}


