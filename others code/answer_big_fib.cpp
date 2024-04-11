#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string sum(string x, string y)
{
	int num;
	int carry = 0;
	string result;

	reverse(x.begin(), x.end());
	reverse(y.begin(), y.end());
	//일단 뒤집고 (뒤부터 연산해야편함

	while (x.length() < y.length()) {
		x += '0';
	}
	while (x.length() > y.length()) {
		y += '0';
	}
	//문자열 길이맞추기 다른게 더 크다면 0을 채움

	for (int i = 0; i < x.length(); ++i) {
		num = (x[i] - '0' + y[i] - '0' + carry) % 10;
		//x의 i번째 자릿수 + y번째 i번째 자릿수의 1의 자리수만 num에 저장
		result += to_string(num);
		//리턴할 문자열에 num 추가
		carry = (x[i] - '0' + y[i] - '0' +   carry  ) / 10;
		//carry = x의i번째자리수+y의i번째자리수+이전자릿수들의 더하고 
	}
	if (carry != 0) {//x + y 결과가 자릿수가 늘어난다면
		result += to_string(carry);// 1을 어펜드?
	}

	reverse(result.begin(), result.end());

	return result;
}

int main(int argc, char* argv[])
{
	int n;
	string DP[10010];

	cin >> n;
	
	DP[0] = '0';
	DP[1] = '1';

	for (int i = 2; i <= n; ++i) {
		DP[i] = sum(DP[i - 1], DP[i - 2]);
	}

	cout << DP[n] << endl;

	return 0;
}