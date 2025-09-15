//https://www.acmicpc.net/problem/31561 시계탑
#include <iostream>
using namespace std;

int main(){

double m; cin>>m;


if( m <= 30 ){
    m = m/2;
}else{
    double tmp = m-30;
    m = (m-tmp)/2 + tmp*1.5;
}

printf("%.1lf",m);

    return 0;
}