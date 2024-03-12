#include <iostream>
#include <cstring>

using namespace std;  // 헤드 파일은 반드시 이 문장 앞쪽에 include해야 한다.

/******************************************************************************
 * 아래 상수 정의는 필요에 따라 변경하여 사용하라.
 ******************************************************************************/
#define AUTOMATIC_ERROR_CHECK false // false: 자동 오류 체크, true: 키보드에서 직접 입력하여 프로그램 실행

/******************************************************************************
 * Person structure and its manipulation functions
 ******************************************************************************/

struct Person {
    char   name[20];        // 이름
    int    id;              // Identifier
    double weight;          // 체중
    bool   married;         // 결혼여부
    char   address[50];     // 주소
};

void print(Person* p) {
    // TODO: [문제 1]
    cout<<p->name<<' '<<p->id<<' '<<p->weight<<' '<<p->married<<" :"<<p->address<<':';
}

void println(Person* p) {
    // TODO: [문제 1]
    print(p);
    cout<<'\n';
}

void input(Person* p) {
    // TODO: [문제 9]
    // 여기까지 했음
    // 여기까지 했음
    // 여기까지 했음
    // 여기까지 했음
    // 여기까지 했음
    cin>>p->name>>p->id>>p->weight>>p->married;
    if (!cin) return;
    cin.getline(p->address, sizeof(p->address), ':');
}

bool isSame(const Person* p, const char* pname, int pid){
    // C 스타일 문자열 비교는 [교제 예제 2-5]를 참조하라.
    // 만약 (p가 포인터하는 구조체의 name 멤버가 매개변수 pname과 동일하고, 
    //      p가 포인터하는 구조체의 id 멤버가 매개변수 pid와 동일하면) 
    // true 반환하고, 그렇지 않으면 false를 반환
    // return 조건문; 형식으로 하나의 문장으로만 코드를 작성해 보라.
    return strcmp( p->name , pname ) == 0 && p->id == pid;
    
}
void whatAreYouDoing(Person* p) {
    // TODO: [문제 6]
    cout<<p->name<<" is taking a rest.\n";
}

void init(Person* p, const char *pname, int pid, double pweight,bool pmarried, const char *paddress) {
    strcpy(p->name,  pname);//이름 넣기
    p->id = pid; //id넣기
    // TODO: [문제 2]
    p->weight = pweight;
    p->married = pmarried;
    strcpy(p->address, paddress);
    cout << "init("; print(p); cout << ")" << endl;
}

/******************************************************************************
 * User Interface
 ******************************************************************************/
// 기본적인 입력과 관련된 전역 함수들을 UI라는 이름공간 내부에 정의함
 
namespace UI {

bool echo_input = false;
string line, emptyLine;

// 입력에서 정수 대신 일반 문자가 입력되었는지 체크하고 에러 발생시 에러 메시지 출력
bool checkInputError(istream* pin, const string msg) {
    if (!(*pin)) { // 에러가 발생했다면
        cout << msg;  // 에러 메시지를 출력
        pin->clear(); // 에러 발생 상태정보를 리셋함; 그래야 다음 문장에서 읽을 수 있음
        getline(*pin, emptyLine); // 에러가 발생한 행 전체를 읽어 데이터를 버림
        return true;
    }
    return false;
}

// 정수나 실수를 입력해야 하는 곳에 일반 문자열을 입력한 경우의 에러 체크
bool checkDataFormatError(istream* pin) {
    return checkInputError(pin, "Input-data format MISMATCHED\n");
}

// 한 사람의 정보 즉, 각 멤버 데이터를 순서적으로 입력 받아 p에 저장하고
// 입력 중 입력 데이터에 오류가 있는지 확인하고 오류가 있을 시 에러 메시지를 출력한다.
bool inputPerson(Person* p) {
    cout << "input person information:" << endl;
    input(p); // p-name 100 65 true :426 hakdong-ro, Gangnam-gu, Seoul:
    if (checkDataFormatError(&cin)) return false;
    if (echo_input) println(p); // 자동체크에서 사용됨
    return true;
}

// 하나의 정수를 입력 받음; 정수가 아닌 아닌 문자열 입력시 에러 메시지 출력 후 재입력 받음
int getInt(const string msg) {
    for (int value; true; ) {
        cout << msg;
        cin >> value;
        if (echo_input) cout << value << endl; // 자동체크 시 출력됨
        if (checkInputError(&cin, "Input an INTEGER.\n"))
            continue;
        getline(cin, emptyLine); // skip [enter] after the number
        return value;
    }
}

// 하나의 양의 정수를 입력 받음; 음수 입력시 에러 메시지 출력 후 재입력 받음
int getPositiveInt(const string msg) {
    int value;
    while ((value = getInt(msg)) < 0)
        cout << "Input a positive INTEGER." << endl;
    return value;
}

// 0~(size-1)사이의 선택된 메뉴 항목 또는 리스트의 항목의 인덱스 값을 리턴함
// 존재하지 않는 메뉴항목을 선택한 경우 에러 출력
int getIndex(const string msg, int size) {
    while (true) {
        int index = getPositiveInt(msg);
        if (0 <= index  && index < size) return index;
        cout << index << ": OUT of selection range(0 ~ "
             << size-1 << ")" << endl;
    }
}

// 사용자에게 메뉴를 보여주고 사용자가 선택한 메뉴항목의 인덱스를 리턴함
int selectMenu(const string menuStr, int menuItemCount) {
    cout << endl << menuStr;
    return getIndex("Menu item number? ", menuItemCount);
}

} // namespace UI

/******************************************************************************
 * simple test
 ******************************************************************************/

Person p = { "Hong", 1, 61.1, true, "Seoul Jongno-gu Nam-ro 123" };

void printlnTest() { // Menu item 1
    // 디폴트 값으로 초기화, 즉 모든 멤버 값을 0으로 초기화함
    Person p1 = {}; // 또는 Person p{};
    println(&p1);   
    // 위 p1을 Person p1;으로 선언해 놓고 p1을 출력해 보라. 아마 초기화가 되어 있지 않을 것이다.

    // 구조체의 각 멤버 초기화
    Person p2 = { "LeeSoonShin", 0, 70.1, true, "Gangnam Seoul" };
    println(&p2);

    Person p3{ "Hong,gildong", 1, 60.2, false, "Jongno-gu, Busan" };
    println(&p3);

    println(&p);
}
void initTest() { // Menu item 2
    Person u1;
    init(&u1, "u1", 10, 60.0, false, "Jongno-gu, Seoul");
    Person u2;
    init(&u2, "u2", p.id, p.weight, p.married, p.address);
    println(&p);
}
void getter() { // Menu item 3
    // TODO: [문제 3 실행 결과]를 참조하여 구조체 변수 p의 각 멤버를 직접 출력하라.
    //       (cout << ... 문장을 직접 사용하라.)
    cout<< "name:"<<p.name<<", id:"<<p.id<<", weight:"<<p.weight<<", married:"<<p.married<<", address:"<<p.address<<'\n';
}
void setter() { // Menu item 4
    Person u;
    u = p;

    strcpy(u.name, "u");
    u.id = p.id;

    // TODO: p의 weight, married, address 값들을 u의 상응하는 멤버에 저장하라.

    println(&u);
}
void isSameTest() { // Menu item 5
    println(&p);
    Person u = { "Hong", 1, };
    cout << "p.isSame(): " << isSame(&p, u.name, u.id) << endl;
}
void whatAreYouDoingTest() { // Menu item 6
    whatAreYouDoing(&p);
}
void noBoolAlphaOutput() { // Menu item 7
    // married 멤버 값 또는 bool 값이 1, 0로 출력됨
    printlnTest();
    initTest();
    getter();
    setter();
    isSameTest();
    whatAreYouDoingTest();
}
void boolAlphaOutput() { // Menu item 8
    cout << boolalpha;    // married 멤버 값 또는 bool 값이 true, false로 출력되도록 설정
    noBoolAlphaOutput();
    cout << noboolalpha;  // 원래 상태로 복구함
}
void noBoolAlphaInputPerson() { // Menu item 9
    // married 멤버 값 또는 bool 값을 0 또는 1로 입력
    // HongGilDong 0 71.5 1 :Gwangju Nam-gu Bongseon-dong 21:
    if (UI::inputPerson(&p)) // 입력시 정수 또는 실수 값을 일반 문자로 잘못 입력하지 않은 경우
        println(&p);
}
void   boolAlphaInputPerson() { }
void dataTypeSize() { }

/******************************************************************************
 * run() 함수
 ******************************************************************************/

void run() {
    int menuCount = 12; // 상수 정의
    // 화면에 보여 줄 메뉴
    string menuStr =
    "+++++++++++++++++++++ Person Structure Test Menu +++++++++++++++++++++\n"
    "+ 0.Exit 1.printlnTest 2.initTest 3.getter 4.setter 5.isSameTest     +\n"
    "+ 6.whatAreYouDoingTest 7.NoBoolAlphaOutput 8.BoolAlphaOutput        +\n"
    "+ 9.NoBoolAlphaInputPerson 10.BoolAlphaInputPerson 11.DataTypeSize() +\n"
    "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";

    while (true) {
        int menuItem = UI::selectMenu(menuStr, menuCount);
        if (menuItem == 0) break;

        switch(menuItem) {
        case 1: printlnTest();            break;
        case 2: initTest();               break;
        case 3: getter();                 break;
        case 4: setter();                 break;
        case 5: isSameTest();             break;
        case 6: whatAreYouDoingTest();    break;
        case 7: noBoolAlphaOutput();      break;
        case 8:   boolAlphaOutput();      break;
        case 9: noBoolAlphaInputPerson(); break;
        case 10:  boolAlphaInputPerson(); break;
        case 11: dataTypeSize();          break;
        }
    }
    cout << "Good bye!!" << endl;
}

/******************************************************************************
 * Program Test: Automatic Error Check
 ******************************************************************************/
#if AUTOMATIC_ERROR_CHECK
#include "check_error.h"
#endif

/******************************************************************************
 * main() 함수
 ******************************************************************************/
int main() {
#if AUTOMATIC_ERROR_CHECK
    evaluate(true);            // 함수 호출
#else
    run();
#endif
}
