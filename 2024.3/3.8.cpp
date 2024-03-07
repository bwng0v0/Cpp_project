#include <iostream>

int main(){
    using namespace std;

int coupon,stamp,K,chicken;

while (true){
    cin>>coupon>>K;
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

    cout<<chicken<<endl;
}

    return 0;
}