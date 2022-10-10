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
const int mod = 1e9+7;
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

const int mut = 998244353;
using ld = long double ;
const ld PI = 3.1415926535;
const ld eps = 1e-5;


void solve()
{
   int n , m  ; cin >> n >> m ; int sr , sc; cin>> sr >> sc; int d; cin>> d; sr--; sc--;
   auto dis = [&](int  r, int c)->int{
    return (abs(sr-r)+abs(sc-c));
   }    ;

   if(dis(sr , m-1)<=d and dis(n-1 , sc)<=d){
    cout << "-1\n";
   }   
   else if(dis(sr,0)<=d and dis(0 , sc)<=d){
    cout << "-1\n";
   }
   else if(dis(n-1 , m-1)<=d){
    cout << "-1\n";
   }
   else if(dis(sr, 0)<=d and dis(sr ,m-1)<=d){
    cout << "-1\n";
   }
   else if(dis(0,sc)<=d and dis(n-1 , sc)<=d){
    cout << "-1\n";
   }
   else cout << m+n-2 << '\n';
}


signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cout << setprecision(15) ;
  #ifndef ONLINE_JUDGE
      freopen("input.txt" , "r" , stdin);
      freopen("output.txt" , "w" , stdout);
      freopen("error.txt" , "w" ,stderr);
  #endif
  
  int t; cin >> t; for(TEST = 0; TEST<t ; TEST++){
  // google();
  solve();}

}