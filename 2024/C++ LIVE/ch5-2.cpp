#include <iostream>
#include <string>
using namespace std;


class MyStack {
private:
	string *element; // 스택의 메모리로 사용할 포인터
	int size;           // 스택의 최대 크기
	int tos;            // 스택의 top을 가리키는 인덱스
public:
	MyStack(int size);    // 생성자 스택의 최대 크기를 입력 받아서 element 객체 배열을 생성해줌.
	MyStack(MyStack& s);  // 깊은 복사 생성자
	~MyStack();           // 소멸자

	bool push(string item); // item을 스택에 삽입
			// 스택이 가득 차 있으면 false를, 아니면 true 리턴
	bool pop(string &item); // 스택의 탑에 있는 값을 item에 반환  그리고 top에 있는 자료 삭제
	bool peek(string &item); // 스택의 탑에 있는 값을 item에 반환
	void print_stack();  // 스택 내용 출력

};
// 위에 코드는 수정 불가



// 여기에 MyStack의 모든 멤버 함수들을 작성하라.
MyStack::MyStack(int size){
	element = new string[size];
	this->size = size;
	tos = -1;
	cout<<"MyStack("<<size<<")\n";
}
bool MyStack::push(string item){
	if( tos==size-1 ){
		cout<<"stack is full\n";
	}else{
		tos += 1;
		element[tos] = item;
	}

	return tos==size?0:1;
}
void MyStack::print_stack(){
	for( int i=0; i<=tos; i++ ){
		cout<<element[i]<<" ";
	}
	cout<<"\n";
}
MyStack::MyStack(MyStack& s){//복사생성자
	element = new string[s.tos+1];
	//아 할당하고 값도 옮겨야지
	tos = s.tos;
	size = s.tos+1;
	for( int i=0; i<=tos; i++ ){
		element[i] = s.element[i];
	}
cout<<"MyStack(MyStack& s): tos+1 = "<<tos+1<<"\n";
}
bool MyStack::pop(string &item){ // 스택의 탑에 있는 값을 item에 반환  그리고 top에 있는 자료 삭제
	if(tos >= 0){
	item = element[tos];
	tos -= 1;
	return 1;
	}else{
		cout<<"stack is empty\n";
		return 0;
	}
}
bool MyStack::peek(string &item){
	if(tos >= 0){
	item = element[tos];
	return 1;
	}else{
		cout<<"stack is empty\n";
		return 0;
	}
}
MyStack::~MyStack(){
	//~MyStack(): tos+1 = 0
	delete[] element;
	cout<<"~MyStack(): tos+1 = "<<tos+1<<"\n";
}

// 아래 코드는 수정 불가
int main() {

	int stack_size;

	// 스택이 저장할수 있는 최대 크기를 입력 받는다
	cout << "Enter stack size : ";
	cin >> stack_size;

	// 스택을 생성해 줌
	MyStack first_stack(stack_size);

	// 입력할 데이터의 수를 입력 받는다
	// 데이터를 숫자 만큼 입력 받고 stack에 푸시한다.
	int  input_size;
	string  item;
	cout << "Enter number of input string : " ;
	cin >> input_size;
	for (int i=0; i < input_size; i++ ) {
		cout <<"Enter string : " ;
		cin >> item;
		first_stack.push(item);
	}

	// 스택의 자료를 출력
	cout << "first stack : " ;
	first_stack.print_stack();

	// 스택을 생성해 줌
	MyStack second_stack(first_stack);

	// 스택의 자료를 출력

	cout << "second stack : " ;
	second_stack.print_stack();

	first_stack.pop(item);
	cout << "first stack pop: " << item << endl ;
	second_stack.peek(item);
	cout << "second stack peek: " << item << endl ;

	// 스택의 자료를 출력
	cout << "first stack : " ;
	first_stack.print_stack();

	cout << "second stack : " ;
	second_stack.print_stack();

	cout << "second stack all pop: " << endl;
	while (second_stack.pop(item))
		cout << item << endl;

	return 0;
}