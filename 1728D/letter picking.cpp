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
   string s; cin >> s;

   // dfs call lgani pdegi aur subtree m search krna hoga aur dekhna hoga kaun jeetega 

   // Agar 1 value aa jati h to alice , 2 pe Bob , 3 pe draw . -1 pe 
   int n = s.length();
   vector<vector<int> >dp(n+1 , vector<int>(n+1));
  
function<int(int ,int )>dfs = [&](int l , int r)->int{
    if(l > r){
    // m playing with an empty string 
    return 2; // draw 
    }

    //    if(r - l == 1){
    //     if(s[l]!=s[r]){
    //         return dp[l][r]  = 3;
    //     }
    //     else return dp[l][r] = 2;
    //    }
    if(dp[l][r]>0)return dp[l][r] ;
    // int ans = 2; // assumed the state of beving draw
    int kk1 = dfs(l+1 , r-1);
    int kk2 = dfs(l+2 , r);
    int kk3 = dfs(l , r-2);
    int ans = 0;
    // if alice chooses l
    int res = min(kk1 , kk2);
    int case1;
    if(res != 2)case1 = res;
  else{  
    if(kk1 < kk2){
        // Of course i am getting up from this path and always the result is a draw
        if(s[l]<s[r]){
           case1 = 3;
        }
        else if(s[l] == s[r]){
            case1 = 2;
        }
        else case1 = 1;
    }
    else if(kk2 < kk1) {
       if(s[l]<s[l+1]){
           case1 = 3;
        }
        else if(s[l] == s[l+1]){
            case1 = 2;
        }
        else case1 = 1;
    }
    else{
        // both are getting me a draw 
        if(s[r]<s[l] || s[l+1]<s[r]){
            case1  = 1;
        }
        else if(s[r]==s[l] and s[l+1]==s[l]){
            case1  = 2;
        }
        else{
            case1 = 3;
        }
    }
  }
    // if alice chooses r
    res = min(kk1 , kk3);
    int case2 ;
    if(res!=2)case2 = res;
  else{  
    if(kk1 < kk3){
        // Of course i am getting up from this path and always the result is a draw
        if(s[r]<s[l]){
           case2 = 3;
        }
        else if(s[l] == s[r]){
            case2 = 2;
        }
        else case2 = 1;
    }
    else if(kk3 < kk1) {
       if(s[r]<s[r-1]){
           case2 = 3;
        }
        else if(s[r] == s[r-1]){
            case2 = 2;
        }
        else case2 = 1;
    }
    else{
        // both are getting me a draw 
        if(s[l]<s[r] || s[r-1]<s[r]){
            case2  = 1;
        }
        else if(s[r]==s[l] and s[r-1]==s[r]){
            case2  = 2;
        }
        else{
            case2 = 3;
        }
    }
  }
    return dp[l][r] =max(case1 , case2);
    
};


   int k = dfs(0 , n-1) ;
    //   de(dp);
   switch(k){
    case 3:
        cout << "Alice\n" ; 
        break;
    case 2:
        cout << "Draw\n";
        break;
    default : 
        cout << "Bob\n";
   }
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
  // google();
  solve();}
  // solve();
}