#include <iostream>
//https://www.acmicpc.net/problem/1673
int main(){
    using namespace std;

int coupon,stamp,K,chicken;

while (cin>>coupon>>K){ //EOF인식
    
    stamp = 0;
    chicken = 0;

    while( coupon > 0 ){
    stamp += coupon;
    chicken += coupon;
    coupon = 0;
    // 모든 쿠폰 -> 스탬프
    coupon += stamp/K;
    stamp -= coupon*K;
    // 모든 스탬프 -> 쿠폰
    }

    cout<<chicken<<'\n';
}

    return 0;
}