//https://www.acmicpc.net/problem/2635 수 이어가기
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define X first
#define Y second
using namespace std;

int main(){
fastio

int n; cin>>n;
vector<int> vec,res;
int max = 0;

for( int i=1; i<=n; i++ ){
    vec.push_back(n);
    vec.push_back(i);

    while(vec[vec.size()-2] - vec[vec.size()-1] > -1){
        vec.push_back(vec[vec.size()-2] - vec[vec.size()-1]);
    }
    if( max < vec.size() ){
        max = vec.size();
        res = vec;
    }
    vec.clear();
}

cout<<res.size()<<"\n";
for( int x : res ) cout<<x<<" ";

    return 0;
}