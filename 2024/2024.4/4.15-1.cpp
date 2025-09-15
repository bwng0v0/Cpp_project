//https://www.acmicpc.net/problem/31562 전주 듣고 노래 맞히기
#include <bits/stdc++.h>
using namespace std;

int main(){

int N,M; cin>>N>>M;
string s[N];
string mld[N];

int tmp;
for( int i=0; i<N; i++ ){
    cin>>tmp>>s[i];
    getline(cin,mld[i]);
    mld[i].erase(0,1);
    mld[i].resize(5);
}

for( int i=0; i<M; i++ ){
    string pr;
    getline(cin,pr);
    
    //음이 같은 노래 카운팅
    int cnt = 0;
    int index;
    for( int j=0; j<N; j++ ){

        if( pr == mld[j] ){
        cnt += 1;
        index = j;
        }
    }


    if( cnt == 1 ){
        cout<<s[index]<<"\n";
    }
    if( cnt >= 2 ){
        cout<<"?\n";
    }
    if( cnt == 0 ){
        cout<<"!\n";
    }

}
    return 0;
}