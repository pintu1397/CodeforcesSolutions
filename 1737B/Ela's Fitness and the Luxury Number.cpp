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

void Engine(){
    int l , r; cin>> l >> r;
    
    int a1 = floor(sqrtl(l));
    int a2 = floor(sqrtl(r));
    if(l == r){
        cout << (l%a1==0) << '\n'; return ;
    }
    if(a2-a1<=5){
        int an = 0;
        for(int aa = a1 ; aa<=a2 ; aa++){
            for(int j = aa; (j*aa<=r)  && j*aa < (aa+1)*(aa+1) ; j++){
                if((j*aa >=l))an++;
            }
        }
        cout << an << '\n'; return ;
    }
    int ans = 0;
    ans = ans + (a2 - (a1+1) )*3;
    
    int j = a1;
    while(j*a1 < (a1+1)*(a1+1) and j*a1<=r){
        if(j*a1>=l)ans++;j++;
    }
    j = a2;
    while(j*a2>=l and j*a2 < (a2+1)*(a2+1)){
        if(j*a2 <= r)ans++;j++;
    }

    cout << ans << '\n';
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
//  int t  = 1;
  for(TEST = 0; TEST<t ; TEST++){
  // google();
  Engine();}
  // solve();
}