//https://www.acmicpc.net/problem/3077 임진왜란
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int main(){
fastio

int n; cin>>n;
int res = 0;
string arr[n];
map<string,int> cmap;
string s;
for( int i=0; i<n; i++ ){ cin>>s; cmap[s] = i; }
for( int i=0; i<n; i++ ) cin>>arr[i];

for( int i=0; i<n; i++ ){
    for( int j=i; j<n; j++ ){ //아니 진짜 이거때문에 시간초과라고?
        if( i==j ) continue;
        bool comp = ( i < j );
        if( cmap[arr[i]] < cmap[arr[j]] == comp ) res += 1;
    }
}

cout<<res<<"/"<<n*(n-1)/2;

//맵을 활용한 브루트포싱 문제
//풀이설명, 문자열 두개의 순서가 일치하는가 = index의 대소관계가 일치하는가로 생각하여
//현우가 말한 답의 모든쌍에 대해, i와 j의 인덱스 대소관계 = 정답의 i,j 문자열 인덱스의 대소관계가 일치하는지
//를 확인하고 점수를 카운팅했다. 여기서 arr[i],arr[j]문자열 두개를 들고 정답에서의 각 인덱스 2개를 가져와야했기에
//string으로 int를 가져오는 맵을 사용하였다
//첫제출에 시간초과가 나와서 당황했지만
//사실 구현하면서 어디가 중복되는 계산인지 봤었기때문에 디버그는 바로 할수있었다
//i,j쌍을 확인했다면 j,i는 확인할 필요가없다. 그리고 j보다 작은 인덱스들은 모두 이미 지나간 쌍이기에 for문의 j=0 -> j=i로 바꾸어 주었다


    return 0;
}