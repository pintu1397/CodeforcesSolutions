#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<int , null_type , less_equal<int> ,rb_tree_tag , tree_order_statistics_node_update> indexed_set;


// Defines
#define int long long
#define nl cout << '\n'
#define FF first
#define SS second  
#define all(x) x.begin() , x.end()
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector<pii>
// Constansts 
const int mod = 998244353;
const int inf = 1e18;

// Helpers
template<typename U,typename V>ostream& operator<<(ostream&os,pair<U,V>&p){os<<p.FF<<' '<<p.SS;nl;return os;}
template<typename T>ostream& operator<<(ostream&os,vector<T>&p){for(auto& e:p){os << e << ' ';}nl;return os;}
template<typename...  Args>void de(Args&&... args){((cout << args << ' '),...);}

template<typename U,typename V>istream& operator>>(istream&is,pair<U,V>&p){is>>p.FF>>p.SS;return is;}
template<typename T>istream& operator>>(istream&is,vector<T>& p){for(auto& e:p){is>>e;}return is;}
template<typename...  Args>void le(Args&&... args){((cin >> args),...);}
int TEST = 0;
void google(){
    cout << "Case #" << TEST+1 << ": " ;
}
// CODE /////////////////////////////////////////////////////////////////////////////////////////////////////

using ld = long double ;
const ld PI = 3.1415926535;
const ld eps = 1e-10;

int dp[2][101][101];
int N ;
int dfs(int cs , int o , int e){
  if(o==0 && e==0){
    return (cs==0);
  }
  if(dp[cs][o][e] != -1){
    return dp[cs][o][e];
  }
  
  bool al = ((N - o  - e)%2 == 0);
  int ans = 0;
  if(al){
    if(o>0){
      ans = dfs(1-cs , o-1 , e);
    }
    else ans  = 0;
    if(e>0)ans = ans | dfs(cs , o , e-1);
    else ans = ans | 0;
  }
  else{
      // ans = ((o>0)?dfs(cs , o-1 , e):1) & ((e>0)?dfs(cs , o , e-1):1);
      
    if(o>0){
      ans = dfs(cs , o-1 , e);
    }
    else ans  = 1;
    if(e>0)ans = ans & dfs(cs , o , e-1);
    else ans = ans & 1;   
  }
   return dp[cs][o][e] = ans ;
}

void solve(){
  int n ; cin>> n ; 
  // Alice won -> 1; else 0 
 for(int p = 0 ; p<2 ; p++){ 
  for(int i = 0; i<101 ; i++){
    for(int j  =0; j<101 ; j++){
      dp[p][i][j] = -1;
    }
  }
 }
N = n;
  int o = 0; int e = 0; vi a(n); le(a);
  for(auto ee:a){if(ee%2)o++; else e++;}
  if(dfs(0 , o , e)){
    cout << "Alice\n";
  }
  else cout << "Bob\n";
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cout << setprecision(15) ;
  #ifndef ONLINE_JUDGE
      freopen("input.txt" , "r" , stdin);
      freopen("output.txt" , "w" , stdout);
      freopen("error.txt" , "w" ,stderr);
  #endif
  
  int t; cin >> t; 
  // inverse();

  for(TEST = 0; TEST<t ; TEST++){
  // google();
  solve();}
  // solve();
}