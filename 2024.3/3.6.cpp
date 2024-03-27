//https://www.acmicpc.net/problem/2460 지능형 기차 2
#include <iostream>
int main(){

	int in,out,train = 0,max = 0;
	for ( int i=0; i<10; i++ ){
		std::cin>>out>>in;
		train -= out;
		train += in;
		if ( train > max ){
			max = train;
		}
	}

	std::cout<<max;

	return 0;
}