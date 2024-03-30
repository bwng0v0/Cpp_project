#include <iostream>
#include <stack>
using namespace std;

int main(){

string s; cin>>s;
stack<char> st;
stack<int> ist;
int cnt = 1;
for( int i=0; i<s.size(); i++ ){
    if( !st.empty() && s[i] == ')' && st.top() == '(' ){
        
        cout<<ist.top()<<" ";
        st.pop();
        ist.pop();

    }else{
        st.push(s[i]);
        ist.push(cnt);
        cout<<cnt<<" ";
        cnt+= 1;
    }
}

    return 0;
}