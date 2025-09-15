//https://www.acmicpc.net/problem/2535 아시아 정보올림피아드
#include <iostream>
#include <algorithm>
using namespace std;

int main(){

//나라당 최대 2개
int n; cin>>n;
int arr[101][3];

for( int i=0; i<n; i++ ){
    cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
}

int res[3][2];

for( int j=0; j<3; j++ ){
int maxi,max=0;

    for( int i=0; i<n; i++ ){

        if( j==2 && res[0][0]==res[1][0] && res[1][0]==arr[i][0] ){//마지막사이클이고 뽑은게 1,2등과 똑같은 국가라면
        continue;
        }

        if( arr[i][2] > max ){
            max = arr[i][2];
            maxi = i;
        }
    }

res[j][0] = arr[maxi][0];//나라번호
res[j][1] = arr[maxi][1];//학생번호
arr[maxi][2] = -1;//다음등수 뽑으려고
}


for( int i=0; i<3; i++ ){
    cout<<res[i][0]<<' '<<res[i][1]<<"\n";
}

    return 0;
}