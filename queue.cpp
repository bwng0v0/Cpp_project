#include <iostream>
#include <queue>
using namespace std;

struct Compare {
    bool operator()(int a, int b) {
        return a > b; // 내림차순으로 정렬
    }
};
class comp {
    public:
    bool operator()(int a, int b) {
        return a > b; // 내림차순으로 정렬
    }
};
bool compfun(int a,int b){
    return a > b;
}

int main(){

priority_queue<int, vector<int>, comp> Q;
priority_queue<int> Q2;

for( int i=0; i<10; i++ ){
    Q.push(i+1);
    Q2.push(i+1);
}

while( !Q.empty() ){
    cout<<Q.top()<<" ";
    Q.pop();
}
cout<<"\n";

while( !Q2.empty() ){
    cout<<Q2.top()<<" ";
    Q2.pop();
}
cout<<"\n";

    return 0;
}