//https://www.acmicpc.net/problem/2096 내려가기
#include <iostream>
using namespace std;
inline int amax(int a,int b,int c){
    int max = a;
    if( max < b ) max = b;
    if( max < c ) max = c;
    return max;
}
inline int amin(int a,int b,int c){
    int min = a;
    if( min > b ) min = b;
    if( min > c ) min = c;
    return min;
}
int main(){
ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

int n; cin>>n;
int max[3] {};
int min[3] {};
int curmax[3] {};
int curmin[3] {};

cin>>max[0]>>max[1]>>max[2];
for( int i=0; i<3; i++ )min[i] = max[i];

for( int i=1; i<n; i++ ){
    cin>>curmax[0]>>curmax[1]>>curmax[2];
    for( int i=0; i<3; i++ )curmin[i] = curmax[i];

    curmax[0] += max[0]<max[1]?max[1]:max[0];
    curmin[0] += min[0]>min[1]?min[1]:min[0];
    
    curmax[1] += amax(max[0],max[1],max[2]);//왜 그냥 max는 오류나지
    curmin[1] += amin(min[0],min[1],min[2]);

    curmax[2] += max[1]<max[2]?max[2]:max[1];
    curmin[2] += min[1]>min[2]?min[2]:min[1];

    //넘겨주기
    for( int j=0; j<3; j++ ){
        max[j] = curmax[j];
        min[j] = curmin[j];
    }
}

cout<<amax(max[0],max[1],max[2])<<" "<<amin(min[0],min[1],min[2]);

    return 0;
}