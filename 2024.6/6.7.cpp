//https://www.acmicpc.net/problem/11008 복붙의 달인
#include <iostream>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int main(){
fastio

int n; cin>>n;
string s,copy;
for( int i=0; i<n; i++ ){
    cin>>s>>copy;
    string tmp;
    int t = 0;
    for( int i=0; i<s.size(); i++ ){
        tmp += s[i];
        if( s[i] == copy[copy.size()-1] && tmp.find(copy) != string::npos ){
            tmp.erase(tmp.find(copy),copy.size());
            t += 1;
        }
    }
    t += tmp.size();
    cout<<t<<"\n";
}

    return 0;
}