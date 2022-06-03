#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pi = pair<int,int>;
using pl = pair<ll,ll>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (long long i = j; i < (long long)(n); i++)
const long long MOD = 1000000007;
const long long MOD2 = 998244353;
const int INF = ((1<<30)-1);
const long long LINF = (1LL<<60);
const double PI = 3.141592653589793238;
template<class T> inline void chmax(T& a, T b) {if (a < b) {a = b;}}
template<class T> inline void chmin(T& a, T b) {if (a > b) {a = b;}}

template<int MOD> struct Fp {  
    long long val;
    constexpr Fp(long long v = 0) noexcept : val(v % MOD) {
        if (val < 0) val += MOD;
    }
    constexpr int getmod() { return MOD; }
    constexpr Fp operator - () const noexcept {
        return val ? MOD - val : 0;
    }
    constexpr Fp operator + (const Fp& r) const noexcept { return Fp(*this) += r; }
    constexpr Fp operator - (const Fp& r) const noexcept { return Fp(*this) -= r; }
    constexpr Fp operator * (const Fp& r) const noexcept { return Fp(*this) *= r; }
    constexpr Fp operator / (const Fp& r) const noexcept { return Fp(*this) /= r; }
    constexpr Fp& operator += (const Fp& r) noexcept {
        val += r.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
    constexpr Fp& operator -= (const Fp& r) noexcept {
        val -= r.val;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr Fp& operator *= (const Fp& r) noexcept {
        val = val * r.val % MOD;
        return *this;
    }
    constexpr Fp& operator /= (const Fp& r) noexcept {
        long long a = r.val, b = MOD, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        val = val * u % MOD;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr bool operator > (const Fp& r) const noexcept {
		return this->val > r.val;
	}
	constexpr bool operator < (const Fp& r) const noexcept {
		return this->val < r.val;
	}
	constexpr bool operator == (const Fp& r) const noexcept {
        return this->val == r.val;
    }
    constexpr bool operator != (const Fp& r) const noexcept {
        return this->val != r.val;
    }
    friend constexpr ostream& operator << (ostream &os, const Fp<MOD>& x) noexcept {
        return os << x.val;
    }
    friend constexpr Fp<MOD> modpow(const Fp<MOD> &a, long long n) noexcept {
        if (n == 0) return 1;
        auto t = modpow(a, n / 2);
        t = t * t;
        if (n & 1) t = t * a;
        return t;
    }
};
using mint = Fp<MOD>;


template<typename T>
struct Matrix{
    using V = vector<vector<T>>;
    V mat;
    int R,C;
    Matrix(int n, int m, int tanigyouretsu = 0){
        R = n;
        C = m;
        mat.resize(n);
        for(int i = 0; i < n; i++)mat[i].resize(m);
        if(tanigyouretsu){
            for(int i = 0; i < n; i++)mat[i][i] = 1;
        }
    }

    Matrix& operator *= (Matrix& A){
        V B(R , vector<T>(C));
        for(int i = 0; i < R; i++){
            for(int j = 0; j < A.C; j++){
                for(int k = 0; k < C; k++){
                    B[i][j] += mat[i][k] * A.mat[k][j];
                }
            }
        }
        mat = B;
        C = A.C;
        return *this;
    }
    
    Matrix operator * (Matrix& A){
        return (Matrix(*this) *= A);
    }

    friend Matrix<T> pow(Matrix<T> &A , long long n){
        if(n == 0){
            Matrix<T> I(A.R , A.R);
            for(int i = 0; i < A.R; i++)I.mat[i][i] = 1;
            return I;
        }
        auto t = pow(A , n/2);
        t *= t;
        if(n & 1)t *= A;
        return t;
    }
};


unsigned solve(){
    ll n; cin >> n;
    Matrix<mint> A(3,1);
    A.mat = 
    {{1},
     {1},
     {1}};
    Matrix<mint> B(3,3);
    B.mat = 
    {{1,1,0},
     {1,0,0},
     {1,0,1}};
    B = pow(B , n);
    B *= A;
    cout << "fibonacci: " << B.mat[1][0] << endl;
    cout << "sum_of_fibonacci: " << B.mat[2][0] << endl;

    return 0;
}

signed main(){
    cout << fixed << setprecision(10);
    ios::sync_with_stdio(0), cin.tie(0);
    int t = 1; 
    //cin >> t;
    for(int i = 0; i < t; i++){
        solve();
    }
	return 0;
}