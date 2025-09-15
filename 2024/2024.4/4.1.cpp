//https://www.acmicpc.net/problem/5046 전국 대학생 프로그래밍 대회 동아리 연합
#include <iostream>
using namespace std;

int main(){

int n,money,h,w;
cin>>n>>money>>h>>w;
int price[h];
int week[h][w];
int minarr[h] = {};

for( int i=0; i<h; i++ ){
    cin>>price[i];

    int max = 0;
    for( int j=0; j<w; j++ ){
    cin>>week[i][j];
    if( week[i][j] > max )
    max = week[i][j];
    }

    //투숙가능하면 최소비용저장
    if( n <= max && n*price[i] <= money )
    {minarr[i] = n*price[i];}

}

int res = 9999999;
for( int i=0; i<h; i++ ){
    if( minarr[i] != 0 && res > minarr[i] ){
        res = minarr[i];
    }
}

if( res == 9999999 )
cout<<"stay home";
else{
cout<<res;
}

    return 0;
}