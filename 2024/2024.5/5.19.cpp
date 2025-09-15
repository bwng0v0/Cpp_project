//https://www.acmicpc.net/problem/11650 좌표 정렬하기
#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int main(){
fastio

vector<pair<int,int>> vec;
pair<int,int> cur;
int n; cin>>n;
for( int i=0; i<n; i++ ){
    cin>>cur.first>>cur.second;
    vec.push_back(cur);
}
//입력

sort(vec.begin(), vec.end());

for( int i=0; i<n; i++ ){
    cout<<vec[i].first<<" "<<vec[i].second<<"\n";
}

    return 0;
}