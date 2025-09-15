//https://www.acmicpc.net/problem/15921 수찬은 마린보이야!!
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int main(){
fastio

double n; cin>>n;
if( n==0 ){ cout<<"divide by zero"; return 0; }
double avg = 0, expt = 0;
for( int i=0; i<n; i++ ){
    double x; cin>>x;
    avg += x;
    expt += 1/n * x;
}
avg /= n;

cout<<fixed<<setprecision(2)<<avg/expt;


    return 0;
}