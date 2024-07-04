//https://www.acmicpc.net/problem/3961 
#include <bits/stdc++.h>
#define ll long long
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

bool cmp(pair<string,int> a, pair<string,int> b){
    if( a.second > b.second ) return 0;
    else if ( a.second < b.second ) return 1;
    else if( a.first > b.first ) return 0;
    else return 1;
}

int main(){
fastio

// map
// qwertyuiop
// asdfghjkl
// zxcvbnm
map<char,pair<int,int>> M;
string arr[3] = {"qwertyuiop","asdfghjkl","zxcvbnm"};
for( int i=0; i<3; i++ ){
    for( int j=0; j<arr[i].size(); j++ ){
        M[arr[i][j]] = {i,j};
    }
}

vector<pair<string,int>> vec;

int T; cin>>T;
for( int t=0; t<T; t++ ){
    vec.clear();
    string ori,s; int n,cnt;
    cin>>ori>>n;
    for( int i=0; i<n; i++ ){
        cin>>s; cnt=0;
        for(int j=0; j<s.size(); j++){
            cnt += abs(M[ori[j]].first-M[s[j]].first) + abs(M[ori[j]].second-M[s[j]].second);
        }

        vec.push_back({s,cnt});
    }

    sort(vec.begin(),vec.end(),cmp);

    for( auto x : vec )
    cout<<x.first<<" "<<x.second<<"\n";
}

    return 0;
}
