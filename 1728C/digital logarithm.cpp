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

using ld = long double ;
const ld PI = 3.1415926535;
const ld eps = 1e-5;


void solve(){

  int n ; cin >>n ; 

  vi a(n) , b(n); le(a , b);
   auto reduce = [&](){
       map<int,int>mp1;
       map<int,int>mp2;
       vi aa , bb;
       for(auto e: a)mp1[e]++; for(auto e:b)mp2[e]++;
       for(auto e:mp1){
        int f1 = mp1[e.first];
        int f2 = mp2[e.first];

        if(f1 > f2){
          for(int i = 0; i< f1-f2 ; i++){
            aa.push_back(e.first);
          }
        }
        else{
          for(int i = 0 ; i< f2-f1 ; i++){
            bb.push_back(e.first);
          }
        }
       }
       for(auto e:b){
        if(mp1.find(e)==mp1.end()){
           bb.push_back(e);
        }
       }

       a = aa; b = bb;
   };

   auto digits = [](int x)->int{
    int tmp = x;
    int lol = 0;
    while(tmp>0){
       lol++; tmp/=10;
    }
    return lol;
   };
   reduce();
  //  de(a , b);

   // Convert every 2 digit to a single digit

   int ans  = 0;

   for(auto& e:a){
      int k = digits(e);
      if(k>1){e = k;ans++;}
   }

   for(auto& e:b){
    int k = digits(e);
    if(k>1){e = k;ans++;}
   }
  // de(a,b);
  reduce();
  // de(a,b);
   int oo = 0;

   for(auto e:a)if(e==1)oo++;
   for(auto e:b)if(e == 1)oo++;

   ans = ans + (a.size() + b.size() - oo);
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
   
  for(TEST = 0; TEST<t ; TEST++){
//   google();
  solve();}
  // solve();
}