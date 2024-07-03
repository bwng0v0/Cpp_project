//https://www.acmicpc.net/problem/31869 선배님 밥 사주세요!
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int main(){
fastio

bool week[11][7] {};
int n; cin>>n;
map<string,int> paymap;
map<string,pair<int,int>> daymap;

for( int i=0; i<n; i++ ){
    string s;int w,d,p;
    cin>>s>>w>>d>>p;
    paymap[s] = p;
    daymap[s] = {w,d};
}
for( int i=0; i<n; i++ ){
    string s;int have;
    cin>>s>>have;
    if( paymap[s] <= have )
    week[daymap[s].first][daymap[s].second] = true;
}

int max = 0;
int cnt = 0;
for( int i=1; i<11; i++ ){
    for( int j=0; j<7; j++ ){
        if( week[i][j] ) cnt += 1;
        else cnt = 0;
        if( cnt > max ) max = cnt;
    }
}

cout<<max;


    return 0;
}