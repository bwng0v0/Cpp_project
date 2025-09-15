//https://www.acmicpc.net/problem/9012 괄호
#include <bits/stdc++.h>
using namespace std;

int main(){
ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

string s;
int N; cin>>N;

for( int n=0; n<N; n++ ){
    cin>>s;
    stack<char> st;
    for( int i=0; i<s.size(); i++ ){
        if( s[i] == ')' && !st.empty() && st.top() == '(' ){
            st.pop();
        }
        else{
            st.push(s[i]);
        }
    }

    if( st.empty() ){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
    
    
}

    return 0;
}