#include <iostream>
#include <string>

using namespace std;

/******************************************************************************
 * Person Container
 ******************************************************************************/

class Container {
    string title;  // 컨테이너 타이틀
    int    size;   // 컨테이너에 저장된 정수 배열 arr의 크기
    int    *arr;   // size 개의 원소를 가진 배열 시작 주소
public:
    Container();
    Container(string title);
    Container(string title, int size);
    Container(const Container &ori){
    // 위 문제를 해결하기 위해 클래스 Container에 깊은 복사를 수행하는 복사생성자를 추가하라.
    // 복사생성자는 매개변수 객체(원본 객체)의 title, size를 상응하는 멤버에 저장하고
    title = ori.title;
    size = ori.size;
    // size가 0보다 클경우 size개의 배열 메모리를 동적으로 할당받아 arr에 저장하고원본 객체의 arr[]의 모든 원소를 복사한다.
    if( ori.arr == nullptr ){
        arr = nullptr;
    }else{
        arr = new int[size];
        for( int i=0; i<size; i++ ){
            arr[i] = ori.arr[i];
        }
    }
    // size가 0보다 크지 않을 경우 nullptr를 arr에 저장한다. 
    // 마지막에 아래 문장을 추가한다.
    cout << "Container(Container& c): "; printIntArray();
    }

    ~Container();
    void setTitle(string title);
    string getTitle();
    void printIntArray();
    Container& newIntArray();
    Container& inputIntArray();
};

Container::Container(): Container("no-title") { }

Container::Container(string title): Container(title,0) { }

Container::Container(string title, int size) {
    setTitle(title);
    arr = new int[3];
    this->size = size;
    for( int i=0; i<size; i++ )
    arr[i] = 0;

    cout << "Container(): "; printIntArray();
}

Container::~Container() {
    cout << "~Container(): "; printIntArray();
    if (arr != nullptr){
        delete [] arr;
    }
    //cout<<this->getTitle()<<arr<<"\n";
        
}

void Container::setTitle(string title) {
    this->title = title;
}

string Container::getTitle() {
    return title;
}

void Container::printIntArray() {
    cout << title << ": arr[" << size << "]: ";
    for (int i = 0; i < size; ++i)
    	cout << arr[i] << " ";
    cout << endl;
}

Container& Container::newIntArray() {
    if (arr != nullptr)
        delete [] arr;
    cout << "element numbers of int array[]? ";
    cin >> size;
    arr = new int[size];

    return *this;
}

Container& Container::inputIntArray() {
    cout << "input " << size << " integers: ";
    for (int i = 0; i < size; ++i)
        cin >> arr[i];

    return *this;
}

/******************************************************************************
 * Global functions
 ******************************************************************************/
void skipEnter() {
    string s;
    getline(cin, s); // 메뉴항목 번호 뒤의 [엔터]를 제거함
}
void inputTitle(Container &C){
    cout<<"input title: ";
    string s;
    getline(cin,s);
    C.setTitle(s);

}
void refParam() {
    Container c("C", 3);
    Container b("B");
    Container a;
    Container d;
    skipEnter();
    inputTitle(d);
}
Container& changeTitle(Container& rc) {
    string s;
    cout << "title to change: ";
    getline(cin, s);
    rc.setTitle(s);
    return rc;       // rc의 원본 객체의 참조를 리턴함
}
void refRet1() {
    skipEnter();
    Container c("C");
    Container& rc = changeTitle(c); // rc는 원본 객체 c의 데이타를 공유하는 참조변수임
    cout << " c.getTitle(): " <<  c.getTitle() << endl;
    cout << "rc.getTitle(): " << rc.getTitle() << endl;
    cout << "---" << endl;
    cout << "appendTitle(c).getTitle(): " << changeTitle(rc).getTitle() << endl;
    cout << "             c.getTitle(): " <<               c.getTitle() << endl;
    cout << "            rc.getTitle(): " <<              rc.getTitle() << endl;
    // changeTitle(rc)에 의해 반환되는 참조 역시 원본 객체 c의 데이타를 공유하는 참조변수임
    // 참조 변수는 생성자 및 소멸자가 없다. 원본 객체의 데이터를 공유하는 또 다른 변수 이름일 뿐이다.
}

void refRet2() {
    Container c("C");
    c.newIntArray().inputIntArray().printIntArray();
}

void explicitCopy() {
    Container c1("c1", 4);
    c1.inputIntArray().printIntArray();
    cout << "---" << endl;
    Container c2(c1);//얕은복사 == 주소복사
    c2.setTitle("c2");
    c2.printIntArray();
    cout << "---" << endl;
    c2.inputIntArray().printIntArray();
    c1.printIntArray();
}
void callByValue(Container v) {
    cout << "callByValue" << endl;
    v.setTitle("V");
    v.inputIntArray().printIntArray();
}
Container returnValue(Container& r) {
    cout << "returnValue" << endl;
    return r;  // 자동으로 복사생성자 호출
}
void implicitCopy() {
    Container a("A", 2);
    a.inputIntArray().printIntArray();
    cout << "---" << endl;
    Container b = a; // 자동으로 복사생성자 호출
    b.setTitle("B");
    b.inputIntArray().printIntArray();
    cout << "---" << endl;
    callByValue(a); // 자동으로 복사생성자 호출
    cout << "---" << endl;
    Container c = returnValue(a);
    c.setTitle("C");
    c.inputIntArray().printIntArray();
    cout << "---" << endl;
}

string menuStr =
"****************************** Main Menu ******************************\n"
"* 0.Exit 1.refParam 2.refRet1 3.refRet2 4.explicitCopy 5.implicitCopy *\n"
"***********************************************************************\n";

int main() {
    while (true) {
        int menuItem;
        cout << endl << menuStr << "menu? ";
        cin >> menuItem;
        if (menuItem == 0)
            break;
        switch(menuItem) {
        case 1: refParam();     break;
        case 2: refRet1();      break;
        case 3: refRet2();      break;
        case 4: explicitCopy(); break;
        case 5: implicitCopy(); break;
        }
    }
    cout << "Good bye!!" << endl;
    return 0;
}