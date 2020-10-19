#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define REP(i,n) for(int i=0;i<n;i++) 
#define endl '\n'
#define INF 1e9
#define mod 1000000007 
#define N 101

ll I[N][N],ar[N][N];

void mul(ll mat1[][N],ll mat2[][N],ll m){
    int res[m][m];    
    
    REP(i,m){ 
        REP(j,m){
            res[i][j]=0;
            REP(k,m){
                res[i][j]=(res[i][j]+(mat1[i][k]*mat2[k][j])%mod)%mod;    
            }
        }
    }
    
    REP(i,m) REP(j,m) mat1[i][j]=res[i][j];
}


void power(ll mat[][N],ll n,ll m){
    
    	    REP(i,m){
            REP(j,m){
            if(i==j)
                I[i][j]=1;
            else
                I[i][j]=0;
        }
    }
    
    
    while(n){
        if(n%2==1){
            mul(I,mat,m);
            n--;
        }
        mul(mat,mat,m);
        n=n/2;
    }
    
    REP(i,m) REP(j,m) mat[i][j]=I[i][j]%mod;
    
}


 
int main() {
	ll t;
	cin>>t;
 
	while(t--){
	    ll m,n;
	    cin>>m>>n;
	   // ll mat[m][N];
	    
	    REP(i,m) REP(j,m) cin>>ar[i][j];


	    power(ar,n,m);
	    
        REP(i,m){
            
            REP(j,m) {
                cout<<ar[i][j]<<" ";
            }
            cout<<endl;
        }    
	}
	return 0;
}