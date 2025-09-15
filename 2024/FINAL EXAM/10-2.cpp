/******************************************************************************

 이번에는 앞 전(10_1 문제)에 작성한 Conatiner 클래스를 Template 클래스로 작성해 보자.
 기존 Conatiner 클래스는 정수(int) 값만 저장할 수 있었다.
 따라서 기존 Conatiner 클래스를 Template 클래스로 변경하여 정수형, 실수형, 문자열 등 
 다양한 데이터 타입을 저장할 수 있는 템플릿 클래스가 되도록 하라.

 프로그램의 전체 구성도와 실행결과는 아래와 같다.

******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

// 대량의 데이터를 순서적으로 저장하고 있는 템플릿 컨테이너 클래스 선언
template <typename T>
class Container {
private:
	vector<T> v;

public:
	void push(T value);	// value를 컨테이너에 삽입
	void add(T inc);		// 컨테이너에 삽입된 모든 원소에 inc를 더함
	bool get(int index, T &value);// 컨테이너의 index(배열처럼 0부터 시작) 위치에 있는 원소 값을 반환
	int  find(T value);	// value 값을 가진 원소의 인덱스를 리턴함
	bool remove(T value);	// value 값을 가진 원소를 삭제하고 true 리턴, 존재하지 않으면 false
	void print();			// 컨테이너에 삽입된 모든 원소를 순서적으로 출력
};

template <typename T>
void Container<T>::push(T value){
	// 매개변수 value를 벡트 v의 적절한 멤버 함수를 호출하여 벡터의 맨 뒤에 추가한다. 
    v.push_back(value);
}

template <typename T>
void Container<T>::add(T inc){
	// for문을 이용하여 
	    // 벡터 v의 모든 원소에 inc를 더한다.
    for( int i=0; i<v.size(); i++ )
        v[i] += inc;
}

template <typename T>
bool Container<T>::get(int index, T &value){
	// index가 0보다 적거나 또는 index가 벡터v의 원소의 개수와 같거나 크면 
	    // false 리턴
    if( index<0 || index >= v.size() ) return false;
    else{
        value = v[index];
        return true;
    }
	// 아니면 
	//     index 위치의 벡터v의 원소를 value에 저장하고 
	//     true 반환
	    // 컨테이너의 index는 벡터의 index와 동일한 의미를 가진다.
}

template <typename T>
int Container<T>::find(T value){
	// for문을 이용하여 
	//     value와 동일한 벡터 v의 원소를 만나면 
	//         그 원소의 인덱스 값을 반환한다.
	// value와 동일한 값을 찾지 못할 경우 -1을 리턴함
    for( int i=0; i<v.size(); i++ ){
        if( v[i] == value ) return i;
    }
    return -1;
}

template <typename T>
bool Container<T>::remove(T value){
    // 벡터의 특정 원소를 삭제하기 위해선 iterator을 이용해야 한다.
    // 따라서 vector v의 iterator it 변수를 선언하고 
    // for 문을 이용하여 loop 돌면서 각각의 it에 대해
        // *it와 value가 같은 값인 it를 찾아서 
            // v.erase(it)를 호출하여 해당 원소를 삭제하고,
            // 바로 true 리턴
    for( auto it = v.begin(); it < v.end(); it++ ){
        if( *it == value ){
            v.erase(it);
            return true;
        }
    }
    return false;
    // 동일한 값을 하나도 찾지 못할 경우 false 반환 
}

template <typename T>
void Container<T>::print(){
	for (int i = 0; i < (int)v.size(); i++)
		cout << "[" << i << "]" << v[i] << " ";
	cout << endl << endl;
}


void test_int(int size) {
	Container<int> c;

	int min = 100 + size;
	int max = min + size - 1;
	int mid = min + size / 2;

	// size개 만큼 자동으로 원소를 삽입한다.
	for (int i = 0; i < size; i++)
		c.push(min+i);
	cout << "push: ";
	c.print();

	int value;
	cout << boolalpha; // boolean 값이 true, false로 출력되게 함
	cout << "get(" << size/2 << "): " << c.get(size/2, value) << " : " << value << endl;
	cout << "get(" << size << "): " << c.get(size, value) << " : " << value << endl;
	cout << "get(" << -1 << "): " << c.get(-1, value) << " : " << value << endl << endl;

	cout << "find(" << max << "): " << c.find(max) << endl;
	cout << "find(" << min-1 << "): " << c.find(min-1) << endl << endl;

	cout << "remove(" << mid << "): " << c.remove(mid) << endl;
	c.print();

	cout << "remove(" << max+1 << "): " << c.remove(max+1) << endl;
	c.print();

	c.add(100);
	cout << "add(100): ";
	c.print();
}

// Container의 모든 멤버 함수 구현에서 
// 1. 모든 함수 구현 앞에 template 를 추가하라.
// 2. 각 함수 이름 앞의 클래스 이름에 제네릭 타입 T가 들어가게 수정하라.
// 3. Container의 멤버 함수의 매개변수 value의 데이터 타입을 T로 변경하라. 

// Container의 remove(value)에서 vector v의 iterator it 변수를 auto로 선언하고 
// v.begin()으로 초기화하거나 또는 typename vector::iterator it = v.begin()로 
// 초기화한다.


void test_string(int size) {

    // 위 템플릿 클래스를 활용하여 string 형으로 구체화된 Container 클래스 객체 변수 c를 선언하라.
    // 이 클래스는 문자열을 저장할 수 있는 container이다.
    Container<string> c;

	int min = 100 + size;
	int max = min + size - 1;
	int mid = min + size / 2;

	// size개 만큼 자동으로 원소를 삽입한다.
	for (int i = 0; i < size; i++)
		c.push("abc"+ to_string(min+i));
	cout << "push: ";
	c.print();

	string value;
	cout << boolalpha; // boolean 값이 true, false로 출력되게 함
	cout << "get(" << size/2 << "): " << c.get(size/2, value) << " : " << value << endl;
	cout << "get(" << size << "): " << c.get(size, value) << " : " << value << endl;
	cout << "get(" << -1 << "): " << c.get(-1, value) << " : " << value << endl << endl;

	value = "abc" + to_string(max);
	cout << "find(\"" << value << "\"): " << c.find(value) << endl;
	value = "abc" + to_string(min-1);
	cout << "find(\"" << value << "\"): " << c.find(value) << endl << endl;

	value = "abc" + to_string(mid);
	cout << "remove(\"" << value << "\"): " << c.remove(value) << endl;
	c.print();

	value = "abc" + to_string(max+1);
	cout << "remove(\"" << value << "\"): " << c.remove(value) << endl;
	c.print();

	c.add("def");
	cout << "add(\"def\"): ";
	c.print();

}

int main()
{
	cout << "Enter the number of elements : " ;
	int size;
	cin >> size;
	cout << endl << "INTEGER Test" << endl << endl;
	test_int(size);
	cout << endl << "STRING Test" << endl << endl;
	test_string(size);
	return 0;
}