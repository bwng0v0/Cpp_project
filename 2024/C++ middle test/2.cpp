#include <iostream>
using namespace std;

class Circle {
	int radius; // 원의 반지름 값
public:
	void setRadius(int radius); // 반지름을 설정한다.
	double getArea(); // 면적을 리턴한다.
};

void Circle::setRadius(int radius) {
	this->radius = radius;
/* 소스작성 */

}
double Circle::getArea() {
	return radius*2*3.14*3.14;
	/* 소스작성 */
}


int main() {
	int n;
	cout<<"원의 개수 >> "; cin>>n;
	Circle* p = new Circle[n];
	for( int i=0; i<n; i++ ){
		cout<<"원 "<<i+1<<"의 반지름 >> ";
		int tmp; cin>>tmp;
		p[i].setRadius(tmp);
	}

	int cnt = 0;
	for( int i=0; i<n; i++ ){
//		cout<<p[i].getArea()<<"\n";
		if( p[i].getArea() > 100 ){
		cnt += 1;
		}
	}

	cout<<"면적이 100보다 큰 원은 "<<cnt<<"개 입니다";

		delete[] p; // 객체 배열 소멸
}
