/*
	Swamy Saranam

	Date	: 27/01/2018 11:15:49
	Author	: Krishna Mohan A M
	Problem	: https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/k-devices-96ab1c02/
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
const int N = 1e5+5;

ll n, k, x[N], y[N];
vector<ll> rad;

int main()
{
      FASTIO
      cin>>n>>k;
      REP(i, n){
            cin>>x[i];
      }
      REP(i, n){
            cin>>y[i];
      }
      REP(i, n){
            rad.PB(x[i]*x[i] + y[i]*y[i]);
      }
      SORT(rad);
      cout<<ceil(sqrt(rad[k-1]))<<"\n";
      return 0;
}
