/*
	Swamy Saranam

	Date	: 05/02/2018 23:50:54
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
const int N = 50;

int n, k, tmp, ans;
int pre[N+5][N+5], cur[N+5][N+5];

int main()
{
      FASTIO
      cin>>n>>k;
      REP(i, N+1){
            REP(j, k+1)
                  pre[i][j] = -1e9;
      }
      cin>>tmp;
      pre[tmp][0] = 1;
      while(--n){
            cin>>tmp;
            REP(i, N+1){
                  REP(j, k+1)
                        cur[i][j] = pre[i][j];
            }
            REP(i, N+1){
                  int cost = abs(i-tmp);
                  for(int j=0; j+cost<=k; j++){
                        cur[tmp][j+cost] = max(cur[tmp][j+cost], pre[i][j]+1);
                  }
            }
            REP(i, N+1){
                  REP(j, k+1)
                        pre[i][j] = cur[i][j];
            }
      }
      REP(i, N+1){
            REP(j, k+1)
                  ans = max(ans, cur[i][j]);
      }
      cout<<ans<<"\n";
      return 0;
}
