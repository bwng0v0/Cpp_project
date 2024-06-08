/*************************************************************************
 *   아래 Circle 클래스는 원의 반지름을 관리한다.
 *   연산자 + (2개의 함수), << (1개의 함수)가 정상적으로 동작하도록 추가하시오.
 *   추가되는 연산자 함수는 클래스의 반지름을 이용하여 연산을 수행한다.
 *      1)  Circle 객체 =  Circle 객체 +  Circle 객체   
 *             우변 두 개의 Circle 객체가 갖고 있는 radius값을 더해서 
               좌변의 Circle 객체의 radius 값에 대입한다.
 *      2)  Circle 객체 =  int +  Circle 객체
 *             우변에 주어진 int 값과 Circle 객체의 radius값을 더해서 
               좌변의 Circle 객체의 radius 값에 대입한다.
 *      3)  Circle 객체 <<  int
*              우변의 int 값을 좌변의 Circle 객체의 radius값에 대입한다.
 *************************************************************************/

#include <iostream>
using namespace std;

class Circle {
private:
	int radius; 
public:
	Circle(int r = 0) {radius = r;};
	void show() { cout <<  "radius = "  << radius <<  endl;}
	void setRadius(int r) { this->radius = r;}
	int  getRadius() { return this->radius;}

            /*****************************************************************/
	/*  여기에 ( Circle 객체 =  Circle 객체 +  Circle 객체 )  처리를 위한 내부 연산자 함수 선언 */
	Circle operator + ( Circle c ){
        Circle tmp(this->radius+c.radius);
        return tmp;
    }

	/*  여기에  ( Circle 객체 <<  int ) 처리를 위한 내부 연산자 함수 선언 */
    Circle& operator << (int a){
		this->radius = a;
		return *this;
	}

            
	/*  여기에  (Circle 객체 =  int +  Circle 객체)  처리를 위한 외부 연산자 함수를 클래스 내에 프레드 함수 선언 */
	friend Circle operator + (int a, Circle b);

	/*****************************************************************/
      
}; 



/*****************************************************************/
/* 여기에 ( Circle 객체 =  Circle 객체 +  Circle 객체 )  처리를 위한 내부 연산자 함수 구현 */


/* 여기에  ( Circle 객체 <<  int ) 처리를 위한 내부 연산자 함수 구현 */


/* 여기에  (Circle 객체 =  int +  Circle 객체)  처리를 위한 외부 연산자 함수 구현 */
Circle operator + (int a, Circle b){
	Circle tmp(a + b.radius);
	return tmp;
}
/*****************************************************************/



/* 입출력 예
(출력)input radius = (입력)5
(출력)radius = 5
(출력)radius = 15
(출력)radius = 20
(출력)radius = 10
*/


/*********************************************************************
 * 아래 main() 함수는 위의 Circle 클래스를 이용한 예이다.
 * 아래 코드는 절대 수정하지 마시오. 
 *********************************************************************/

int main () {
	Circle a, b, c, d;
	int radius ;

	cout << "input radius = " ;
	cin >> radius;

	a.setRadius(radius);

	/* Circle 객체 b에 radius값을 대입한다. */	
	b << (radius*3);

	/* 두 Circle 객체 a, b의 radius값을  더해서  Circle 객체 c에 대입한다. */	
	c = a + b ;
           
    	/* 주어진 숫자 radius와 Circle 객체 a의 radius값을 더해서 Circle 객체 d에 대입한다. */
	d = radius + a ;

	a.show();
	b.show();
	c.show();
	d.show();
}
