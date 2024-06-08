#include <iostream>
#include <string>
// #include 
using namespace std;

class MyStack {
private:
	string *element; // 스택의 메모리로 사용할 포인터
	int size;        // 스택의 최대 크기
	int tos;         // 스택의 top을 가리키는 인덱스

	void copy(const MyStack& s);

public:
	MyStack(int size);         // 생성자 스택의 최대 크기를 입력 받아서 element 객체 배열을 생성해줌.
	MyStack(const MyStack &s); // 깊은 복사 생성자
	~MyStack();                // 소멸자

	bool push(string item); // item을 스택에 삽입
			                // 스택이 가득 차 있으면 false를, 아니면 true 리턴
	bool pop(string &item); // 스택의 탑에 있는 값을 item에 반환  그리고 top에 있는 자료 삭제
	void print_stack();  // 스택 내용 출력

    // TODO: 1) 새로 추가된 멤버 연산자 선언
	MyStack& operator << ( const string& s );
	MyStack& operator >> ( string& s );
	bool operator ! ();
	MyStack& operator = ( const MyStack& s );
    // TODO: 2) friend 함수 선언
	friend MyStack operator + (const MyStack& s1, const MyStack& s2);
	
};

MyStack::MyStack(int size = 10) {
	tos =-1;
	this->size = size;
	this->element = (this->size > 0)? new string[this->size]: nullptr;
}

void MyStack::copy(const MyStack &s) {
	this->size = s.size;
	this->tos = s.tos;
	this->element = (this->size > 0)? new string[this->size]: nullptr;

	for (int i=0; i <= this->tos; i++)
		this->element[i] = s.element[i];
}

MyStack::MyStack(const MyStack &s) {
	copy(s);
}


MyStack::~MyStack() {
	if(element)
		delete [] element;
}

bool MyStack::push(string item) {
	if (this->tos == this->size-1) {
		cout << "stack is full" << endl;
		return false;
	}
	else {
		this->element[++this->tos] = item;
		return true;
	}
}

bool MyStack::pop(string &item) {
	if (this->tos == -1) {
		cout << "stack is empty" << endl;
		return false;
	}
	else {
		item = this->element[this->tos--];
		return true;
	}
}

void MyStack::print_stack() {
	for (int i=0; i <= tos; i++)
		cout << element[i] << " ";
	cout << endl << endl;
}

// 함수 구현 : 매개 변수 선언은 push() 참조, 이 객체의 참조를 리턴하라.
MyStack& MyStack::operator << ( const string& s )
{
//    기존의 push() 함수 호출
//    이 객체의 참조 리턴, 예제 7-14 참조
	push(s);
	return *this;
}

//함수 구현 : 매개 변수 선언은 pop() 참조, 이 객체의 참조를 리턴하라.
MyStack& MyStack::operator >> ( string& s )
{
//    기존의 pop() 함수 호출
//    이 객체의 참조 리턴
	pop(s);
	return *this;
}

// 함수 구현 : 예제 7-9 참조
bool MyStack::operator ! ()
{
//    스택이 비어 있으면 true 리턴, 스택의 빈 상태 체크는 pop() 함수 참조
//    그렇지 않으면 false 리턴
	if( tos == -1 ) return 1;
	else return 0;
}

//함수 구현: 매개변수는 const로 선언해야 하며, 이 객체의 참조자가 리턴됨
MyStack& MyStack::operator = ( const MyStack& s )
{
//    소멸자 함수 참고하여 element가 가리키는 메모리 반환
//    복사 생성자 함수의 내용을 그대로 복사해서 넣을 것
//    이 객체의 참조 리턴
	if(element) delete [] element;

	this->size = s.size;
	this->tos = s.tos;
	this->element = (this->size > 0)? new string[this->size]: nullptr;

	for (int i=0; i <= this->tos; i++)
		this->element[i] = s.element[i];
	return *this;
}

// 외부 함수임
//: 예제 7-12 참고, 두 매개변수 타입 유의할 것
MyStack operator + (const MyStack& s1, const MyStack& s2)
{
//    MyStack 타입의 지역변수 tmp(스택_크기) 선언; 예제 7-12 참고
//    이때 새로운 스택_크기는 s1 스택 크기와 s2 스택 크기를 합친 크기여야 함
//    tmp의 tos 값은 무엇으로 해야할까?
//    s1 스택의 element[]와 s2의 element[]를 tmp에 복사하되,
//    각 스택의 실제 원소의 개수까지만 복사하라.
//    tmp를 리턴함
	MyStack tmp(s1.size+s2.size);
	for( int i=0; i<=s1.tos; i++ ){
		tmp.push(s1.element[i]);
	}
	for( int i=0; i<=s2.tos; i++ ){
		tmp.push(s2.element[i]);
	}
	return tmp;
}

int main() {
	int size, half;
	string  item;

	cout << "Enter the first stack size : " ;
	cin >> size;
	half = size / 2;

	MyStack s1(size), s2(size), s3(size);

	for (int i = 0; i < size; i++) {
		item = to_string(i+10000); // integer -> string translation
		s1.push(item);
	}
	while (!s1 == false)
		s1.pop(item);
	cout << "After automatic push and pop, s1 is (should be empty)" << endl;
	s1.print_stack();

	for (int i = 0; i < half; i++)
		s1 << to_string(i+100); // push
	cout << "After automatic half << (push), s1 is" << endl;
	s1.print_stack();

	s1 << "11" << "22" << "33"; // continuous push
	cout << "After s1 << \"10\" << \"20\" << \"30\";, s1 is" << endl;
	s1.print_stack();

	s2 = s1;
	cout << "After s2 = s1, s2 is" << endl;
	s2.print_stack();

	for (int i = 0; i < half; i++)
		s3 << to_string(i+1000); // push
	cout << "After automatic push, s3 is" << endl;
	s3.print_stack();

	s3 = s1 + s2 + s3;
	cout << "After s3 = s1 + s2 + s3, s3 is" << endl;
	s3.print_stack();

	cout << "Continuous >> (pop) of s1" << endl;
	while (!s1 == false) {
		s1 >> item;
		cout << item << ' ';
	}
	cout << endl << endl;

	string i1, i2, i3;
	s2 >> i1 >> i2 >> i3;
	cout << "After s2 >> i1 >> i2 >> i3, s2 is" << endl;
	s2.print_stack();
	cout << "i1, i2, i3 are " << i1 << ", " << i2 << ", " << i3 << endl << endl;
} 