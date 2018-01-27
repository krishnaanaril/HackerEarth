/*
	Swamy Saranam

	Date	: 27/01/2018 16:13:39
	Author	: Krishna Mohan A M
	Problem	: https://www.hackerearth.com/practice/algorithms/dynamic-programming/bit-masking/practice-problems/algorithm/string-matching-google-3dc355a5/
	Status	: DP, bitmask
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
const int N = 1e5+5;
const int M = (1<<10)+5;
const int LIM = (1<<10)-1;

string st;
int mask, n, l, r, sz, tmp;
ll dp[N][M];
ll ans;

int main()
{
      FASTIO
      cin>>st;
      sz = st.size();
      cin>>n;
      REP(i, n){
            cin>>tmp;
            mask |= (1<<tmp);
      }
      REP(i, sz){
            dp[i][(1<<(st[i]-'0'))] = 1;
            if(i>0){
                  REP(j, LIM+1){
                        dp[i][j|(1<<(st[i]-'0'))] += dp[i-1][j];
                  }
            }
      }
      // REP(i, sz){
      //       REP(j, 20)
      //             cout<<dp[i][j]<<" ";
      //       cout<<"\n";
      // }
      // cout<<mask<<"\n";
      REP(i, sz){
            REP(j, LIM+1){
                  if((j&mask)==mask){
                        // cout<<i<<" : "<<j<<" : "<<dp[i][j]<<"\n";
                        ans += dp[i][j];
                  }
            }
      }
      cout<<ans<<"\n";
      return 0;
}
