/*
	Swamy Saranam

	Date	: 06/02/2018 23:39:07
	Author	: Krishna Mohan A M
	Problem	:
	Status	:
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,int>	pii;
typedef pair<ld,ld>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef pair<ll,ll> pll;

#define FASTIO                ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,a,b)            for(int i=(a);i<(b);i++)
#define REP(i,n)              FOR(i,0,n)
#define SORT(v)               sort((v).begin(),(v).end())
#define UN(v)                 SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)               memset(a,b,sizeof a)
#define PB                    push_back
#define F                     first
#define S                     second

const int MOD = 1000000007;
const int N = 555;

int n, m;

int main()
{
      FASTIO
      cin>>n>>m;
      if(n<=22){
            int M[N];
            ll C[N], dp[1<<n];
            REP(i, m){
                  REP(j, n){
                        int tmp;
                        cin>>tmp;
                        M[i] |= (tmp*(1<<j));
                  }
                  // cout<<M[i]<<" : "<<i<<"\n";
                  cin>>C[i];
            }
            for(int i=0; i<(1<<n); i++)
                  dp[i] = 1e9;
            dp[0] = 0;
            for(int i=0; i<(1<<n); i++){
                  REP(j, m){
                        dp[i|M[j]] = min(dp[i|M[j]], dp[i]+C[j]);
                  }
            }
            cout<<dp[(1<<n)-1]<<"\n";
      }
      else
      {
            bitset<N> M[55];
            ll C[N];
            REP(i, m){
                  M[i].reset();
                  REP(j, n){
                        int tmp;
                        cin>>tmp;
                        if(tmp)
                              M[i][j] = 1;
                  }
                  cin>>C[i];
            }
            ll ans = 1e18;
            for(int i=0; i<(1<<m); i++){
                  bitset<N> mask;
                  mask.reset();
                  int tmp = i, j=0;
                  ll cst = 0;
                  while(tmp){
                        if(tmp&1)
                              mask |= M[j], cst+= C[j];
                        tmp>>=1;
                        j++;
                  }
                  if(mask.count()==n){
                        // cout<<i<<" "<<cst<<" : "<<ans<<" : "<<mask.count()<<"\n";
                        ans = min(ans, cst);
                  }
            }
            cout<<ans<<"\n";
      }
      return 0;
}
