//https://www.acmicpc.net/problem/30971 육회비빔밥
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

ostream& operator << ( ostream& out,const vector<int>& vec ){
    cout<<"{";
    for( auto a : vec ) cout<<a<<" ";
    cout<<"}"<<endl;
    return out;
}


int main(){
fastio

int n,k; cin>>n>>k;
int sweet[n];
int salty[n];
int C[n];

for( int i=0; i<n; i++ ) cin>>sweet[i];
for( int i=0; i<n; i++ ) cin>>salty[i];
for( int i=0; i<n; i++ ) cin>>C[i];

vector<vector<int>> vec;
for( int i=0; i<n; i++ ){
    vec.push_back({sweet[i],salty[i],C[i]});
}

sort(vec.begin(),vec.end());

int max = -1;
int res = 0;
do {//0=단맛 1=짠맛 2=눈치
    res = 0;
    for( int i=1; i<n; i++ ){
        if( vec[i-1][2]*vec[i][2] > k ){ res = 0; break; }
        res += vec[i-1][0]*vec[i][1];
    }
    if( res!=0 && max < res ) max = res;

} while(next_permutation(vec.begin(), vec.end()));

cout<<max;

    return 0;
}