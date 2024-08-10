
/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
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



void solve(){
    string str;
    cin >> str;

    map<char,int> ch;

    for(auto i : str) ch[i]++;

    for(auto i : ch){
        cout << i.first << ": " << i.second << endl;
    }

}
signed main(){


    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}
