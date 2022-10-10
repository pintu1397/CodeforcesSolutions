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

    int n ; cin >> n ; 
    pair<int,int>pt[3];
    for(int i = 0; i<3 ; i++){
        cin >> pt[i].first >> pt[i].second;
        pt[i].first--; pt[i].second--;
    }
    int ctr = 0;

    for(int i = 0; i<3 ; i++){
        int ss = 0;
        for(int j = 0; j<3 ;j++){
            if(j== i)continue;
            ss = ss + abs(pt[i].first - pt[j].first)+abs(pt[i].second - pt[j].second) ;
        }
        if(ss == 2){
            // cout << "YESY\n";
            ctr = i;
        }
    }
    int x,y; cin >> x >> y;
    x--; y--;

    // cout << ctr << '\n';
    if((pt[ctr].first==0 || pt[ctr].first==n-1) && (pt[ctr].second==0 || pt[ctr].second==n-1)){
        // ctr is at the corner 


        if(x==pt[ctr].first || y==pt[ctr].second){
             cout << "YES\n";
        } 
        else cout << "NO\n";
        return ;
    }
    if((x-pt[ctr].first)%2 && (y-pt[ctr].second)%2){
        cout << "NO\n"; return ;
    }
    cout << "YES\n";
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