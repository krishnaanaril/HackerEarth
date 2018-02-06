#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, k, rem, top, cnt, mn;
ll res, tmp;

int main(){
      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      cin>>n>>k;
      rem = n%k;
      if(rem){
            cnt = n/k;
            top = (cnt+1)*k;
            rem = top-n;
            cnt++;
            tmp = cnt*(cnt-1)/2;
            res = (k-rem)*tmp;
            tmp = (cnt-1)*(cnt-2)/2;
            res += rem*tmp;
      }
      else{
            cnt = n/k;
            tmp = cnt*(cnt-1)/2;
            res = n*tmp;
      }
      cout<<res<<"\n";
      return 0;
}
