#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

//vector<vector<int>> 출력

vector<vector<int>> vec(10);
queue<pair<int,int>> Q;

ostream& operator << (ostream& out, const vector<int>& v){
    for( int x : v ) out<<x<<" ";
    return out<<"\n";
}

ostream& operator << (ostream& out, const vector<vector<int>>& v){
    for( int i=0; i<v.size(); i++ ){
        out<<v[i]<<endl;
    }
    return out;
}

ostream& operator << (ostream& out, const pair<int,int>& p){
    out<<"("<<p.first<<","<<p.second<<") ";
    return out;
}
ostream& operator << (ostream& out, queue<pair<int,int>> q){
    while( !q.empty() ){
        out<<q.front();
        q.pop();
    }
    return out<<"\n";
}

int main(){
fastio

for( int i=0; i<10; i++ ){
    for( int j=0; j<=i; j++ )
        vec[i].push_back(j);
    Q.push({i,i+2});
}

cout<<"vec"<<endl;
cout<<vec<<endl;
cout<<"Q"<<endl;
cout<<Q;

    return 0;
}