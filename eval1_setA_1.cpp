#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define double long double
#define endl '\n'

const int mod = 1e9 + 7;
template <typename T>void ip(vector<T> &a){ for(int i = 0; i < a.size(); i++) cin >> a[i];}
template <typename T> void op(vector<T> b){for(auto i : b) {cout << i << " ";}  cout << endl;}

vector<bool> sieve (int n){
vector<bool> is_prime(n+1, true);
is_prime[0] = is_prime[1] = false;
for (int i = 2; i <= n; i++) {
    if (is_prime[i] && (long long)i * i <= n) {
        for (int j = i * i; j <= n; j += i)
            is_prime[j] = false;
    }
}
return is_prime;
}

int powm(int a,int b,int m = mod){
    a%=m;
    if(b == 0) return 1;
    if(b == 1) return a;
    int p = powm(a*a,b/2,m);
    if(b%2) p = p*a%m;

    return p;

}

int modadd(int a,int b,int m = mod){
    return (a%m + b%m)%m;
}

int modsub(int a,int b,int m = mod){
    return (a%m - b%m)%m;
}


int modmul(int a,int b,int m = mod){
    return ((a%m) *(b%m))%m;
}

int moddiv(int a,int b,int m = mod){
    return (a%m)*powm(b,m-2)%m;
}


int solve(vector<vector<int>> grid){
if(grid.size() == 2) return grid[0][0]*grid[1][1] - grid[0][1]*grid[1][0];

int n = grid.size();
int ans = 0;
int h = 1;
for(int i = 0; i < n; i++){
    vector<vector<int>> temp;
    for(int j = 1; j < n; j++){
        vector<int> temp1;
        for(int k = 0; k < n; k++){
            if(k != i){
                temp1.push_back(grid[j][k]);
            }
        }
        temp.push_back(temp1);
    }

    ans = ans + h*grid[0][i]*solve(temp);
    h = -h;
}

return ans;

}

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> grid(n,vector<int> (n));

    for(int i = 0; i < n; i++) ip(grid[i]);


    cout << solve(grid) << endl;

}
signed main(){


    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
