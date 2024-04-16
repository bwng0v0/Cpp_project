//https://www.acmicpc.net/problem/1629 곱셈
#include <iostream>
//2147483647
using namespace std;

long long A, B, C;

long long  dq(long long a, long long b) {
    if (b == 1) {//a에1제곱
        return a % C;
    }
    else {
        long long x = dq(a, b/2) % C;// n**k/2 %m를 구함
        if (b % 2 == 0) {//짝수라면 리턴 
            return x*x %C;
        }
        else {//짝수가 아니라면 *a , 모듈러는 왜 두번이지
            return x*x %C *a %C;
        }
    }
}
int main() {

    cin >> A >> B >> C;
    cout << dq(A, B) % C;

    return 0;
}
