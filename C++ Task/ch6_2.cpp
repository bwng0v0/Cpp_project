/*
* CH2: ch2.cpp
*
*  Created on: 2022. ?. ?.
*      Author: your name
*
*
*  + class VectorPerson: erase(), insert() 추가
*  + class PersonManager: remove(), insert() 추가
*  + class ClassAndObject: 멤버 객체 변수의 초기화 시점 및 방법 추가
*        (멤버 선언시, 생성자 서두, 생성자 본체 등)
*        함수 선언 시 매개변수 const의 필요성 제기
*  + 이를 위해 class Init1 ~ class Init6 추가, ClassAndObject 내부에
*        memberInitialization(), class Parameter, normalParameter(),
*        constParameter(), temporaryParameter(), stringParameter(),
*        parameters() 멤버 추가
*/
#include <iostream>
#include <cstring>

using namespace std;  // 헤드 파일은 반드시 이 문장 앞쪽에 include해야 한다.

/******************************************************************************
 * 아래 상수 정의는 필요에 따라 변경하여 사용하라.
 ******************************************************************************/
#define AUTOMATIC_ERROR_CHECK 0 // false: 자동 오류 체크, true: 키보드에서 직접 입력하여 프로그램 실행

/******************************************************************************
 * Person structure and its manipulation functions
 ******************************************************************************/
class Person
{
    string name;            // 이름: 변경
    int    id;              // Identifier
    double weight;          // 체중
    bool   married;         // 결혼여부
    char*  address;         // 주소:  5_2에서 []에서 *로 변경
    char*  memo_c_str;      // 메모장: 5_2에서 []에서 *로 변경
    string passwd;          // 비번

protected:
    void inputMembers(istream& in);
    void printMembers(ostream& out);

public:
    // Person();
    // Person(const string name);
    Person(const string& name={}, int id={}, double weight={}, bool married={}, const char *address={});
    Person(const Person& p);
    ~Person();

    void set(const string& pname, int pid, double pweight, bool pmarried, const char *paddress);
    void setName(const string& pname)      { name = pname; }
    void setPasswd(const string& passwd)   { this->passwd = passwd; }
    void set(int pid){id = pid;} void set(double pweight){weight = pweight;} void set(bool pmarried){married = pmarried;}
    void setAddress(const char* address); // 5_2에서 수정

    const string& getName()    const{ return name; }
    const string& getPasswd()  { return passwd; }
    int         getId()      const{ return id; }
    double      getWeight()  const{  return weight; }  // 구현 시
    bool        getMarried() const{  return married; }  // 리턴 값들을
    const char* getAddress() const{  return address; } // 수정하시오.

    void input(istream& in)  { inputMembers(in); } // ch3_2에서 추가
    void print(ostream& out) { printMembers(out); }
    void println()            { print(cout); cout << endl; }
    void whatAreYouDoing();                          // ch3_2에서 추가
    bool isSame(const string& name, int pid);         // ch3_2에서 추가
    void setMemo(const char* c_str);      // 5_2에서 수정
    const char* getMemo()    { return memo_c_str; }
    void copyAddress(const char* address); // 5_2에서 추가
    void copyMemo(const char* c_str);      // 5_2에서 추가
    Person& assign(const Person& p);
};

// Person::Person(): Person("") {
// }

// Person::Person(const string name): Person("",0,0,0,"") {
// }

Person::Person(const string& name, int id, double weight, bool married, const char* address):
        name(name), id{id}, weight{weight}, married{married}, memo_c_str{} {
    // 생성자 서두에서 memo_c_str{}은 초기 값으로 디폴트 값인 nullptr(실제로는 주소 값 0)로 설정됨
    copyAddress(address);
    cout << "Person::Person(...):"; println();
}
// 클래스 멤버들 중 메모리를 할당 받은 포인터 변수가 있으면 복사 생성자도 수정하여야 한다.
// Person의 복사 생성자를 아래처럼 수정하라.
// copyAddress()와 copyMemo()는 멤버 address와 memo_c_str 를 위한 메모리를 동적으로 할당받고
// p 객체의 주소와 메모를 복사하는 역할을 한다. 
// 이 두 함수는 생성자 또는 복사생성자에서 처음으로 두 멤버를 초기화할 때만 사용된다. 
// 이렇게 초기화된 두 멤버들을 수정하고자 할 때는 setAddress()와 setMemo()를 사용해야 함
Person::Person(const Person& p): name(p.name), id{p.id}, weight{p.weight}, married{p.married} {
    // TODO: p 객체의 address 문자열을 멤버 address에 복사함 
    //       (즉, setAddress() 대신 copyAddress() 사용해야 함)
    //       p 객체의 메모 문자열을 멤버 memo_c_str에 복사함 (copyMemo() 사용해야 함)
    copyAddress(p.address);
    copyMemo(p.memo_c_str);
    cout << "Person::Person(const Person&):"; println();
}


Person::~Person() {
    cout << "Person::~Person():"; println();

    if( address != nullptr )
    delete[] address;

    if( memo_c_str != nullptr )
    delete[] memo_c_str;
    // TODO: address와 memo_c_str가 포인터하는 배열 메모리를 반납한다.
    //       이들 포인터가 nullptr인 경우 반납하지 말아야 한다.
}

// void Person::printMembers(ostream* pout)   {
//     // TODO: [문제 1]
//     *pout<<name<<' '<<id<<' '<<weight<<' '<<married<<" :"<<address<<':';
// }
void Person::printMembers(ostream& out) {
    out<<name<<" "<<id<<" "<<weight<<" "<<married<< " :"<<(address==nullptr?"":address)<< ":";
    // 3항 연산자를 이용하여 address가 nullptr일 경우 ""를 출력하고 아닌 경우 address를 출력하라. 
}

void Person::set(const string& pname, int pid, double pweight,
    bool pmarried, const char *paddress) {
    // TODO: [문제 4]
    name = pname;
    id = pid;
    weight = pweight;
    married = pmarried;
    setAddress(paddress);
}

// void Person::inputMembers(istream* pin)   {
//     // TODO: [문제 7]
//     *pin>>name>>id>>weight>>married;
//     pin->getline(address, sizeof(address), ':'); // 말씀하셨던 버퍼에 \n이 남아서 그걸 치우고 입력받기위해 두번씀
//     pin->getline(address, sizeof(address), ':');
// }

void Person::inputMembers(istream& in)   {
    in >> name >> id >> weight >> married;
    if (!(in)) return;
    
    // 지역변수로 미리 큰 주소용 배열을 잡는다.
    char address[40];    // ch5_2에서 추가됨
    in.getline(address, sizeof(address), ':'); // 말씀하셨던 버퍼에 \n이 남아서 그걸 치우고 입력받기위해 두번씀
    in.getline(address, sizeof(address), ':');
    // TODO: 기존 코드를 그대로 사용해서 키보드에서 주소를 읽어 위 지역변수 address[40]에 저장한다.
    //       기존 코드와 동일하지만 기존의 코드는 멤버 address에 바로 읽어 들이는 것이고,
    //       여기선 위 지역변수 address[40]에 먼저 읽어 들이고 이를 멤버에 복사한다.

    // 아래 함수를 통해 위 지역변수 address[]에 있는 주소를 멤버 address로 복사한다. 
    // 아래 함수에서 address[]의 문자열 길이만큼 메모리를 할당(멤버 address용) 받은 후 복사한다.
    // 멤버 address는 이전에 이미 초기화되었기 때문에 copyAddress()가 아닌 아래 함수를 사용함
    setAddress(address); // ch5_2에서 추가됨
}







void Person::whatAreYouDoing() {
    // TODO: [문제 5]
    cout<<name<<" is taking a rest.\n";
}

// 깊은 대입(=) 연산: p의 모든 멤버 값을 this에 복사한다. 멤버가 동적으로 메모리를 할당받은 경우
// 먼저 this의 멤버의 메모리를 먼저 반납하고 새로 메모리를 할당 받은 후 복사한다. 
Person& Person::assign(const Person& p) {

// TODO: name, passwd, id, weight, married 멤버의 경우 = 연산자를 사용하여 p의 상응하는 
//       멤버 값을 this의 멤버에 바로 대입시켜라. (C++의 기본 데이타 타입과 string인 경우)
//       즉, this의 각 멤버에 =를 이용해 p의 멤버 값을 저장하라.
name = p.name; id = p.id; weight = p.weight; married = p.married;

          
//p.addres와 p.memo_c_str의 경우 각각 setAddress(), setMemo()를 호출하여
//this의 addres와 memo_c_str에 복사하라. 이 함수들은 기존에 할당 받았던 this의
//address와 memo_c_str 멤버의 메모리를 먼저 반납하고 새로 할당 받은 후 복사한다.
setAddress(p.address);
setMemo(p.memo_c_str);

// 복사생성자에서는 copyAddress()와 copyMemo()를 호출했는데 (처음 초기화할 때)
// 여기서는 setAddress(), setMemo()를 호출하였다. (기존 값을 변경하고자 할 때)
// 왜 그렇게 했는지 이해했는가?

//set은 기존멤버의 포인터가 nullptr이 아니라면(가리키는 메모리가있다면) 반납후 새문자열을 가리킴
//

    return *this; // this 객체 자신의 참조자를 반환한다.
    // 자신 객체의 참조자를 리턴했기 때문에 c.assign(p.assign(backup)).println() 등의
    // 연속된 함수 호출도 가능해 진다. 즉 (c = p = backup).println()과 같은 효과
}

bool Person::isSame(const string& pname, int pid) {
    // TODO: [문제 6]
    return name == pname && id == pid;
}

// 처음 객체가 초기화될 때(생성자 또는 복사생성자) address 멤버를 초기화하고자 할 때 호출된다. 
// 즉, 일반 생성자 또는 복사 생성자에서만 호출됨.
// 새로 할당받은 메모리에 매개변수 address 문자열을 복사한다.
void Person::copyAddress(const char* address) {
    // TODO: 매개변수 address가 nullptr인 경우, address 멤버도 nullptr로 설정하고 리턴하라.
    //       매개변수 address가 포인터하는 문자열을 포함할 수 있는 배열 메모리를 할당 받은 후
    //       할당된 메모리 주소를 멤버 address에 저장하고, 
    //       매개변수의 문자열을 멤버 변수의 할당받은 메모리로 복사한다. 
    if( address==nullptr ){
    this->address = nullptr;
    return;
    }
    
    char* tmp = new char[strlen(address)+1];//메모리할당
    strcpy(tmp,address);//할당받은 메모리에 매개변수 복사
    this->address = tmp;//매개변수를 복사한 문자열을 가리키는 포인터를 멤버변수에 복사
    

          // [교재 예제 5-11]의 복사 생성자  참조할 것
          // strlen(), strcpy() 함수는 구글링 또는 http://www.cplusplus.com/reference/에서 검색
          // strlen()은 끝의 null 문자를 포함하지 않은 길이이므로 
          // 이를 포함하기 위해 할당해야 할 메모리는 strlen()+1이어야 함 
          // strcpy()는 끝의 null 문자도 함께 복사해 준다라는 사실에 유의하라.
}

// 복사 생성자에 의해 처음 메모 문자열 memo_c_str을 초기화할 때 호출된다. 
// 복사 생성자에서만 호출되고 일반 생성자에서는 nullptr로 설정됨
void Person::copyMemo(const char* c_str)      {
    // TODO: 매개변수 c_str가 nullptr인 경우, memo_c_str만 nullptr로 설정하고 리턴하라.
    //       매개변수 c_str가 포인터하는 문자열을 포함할 수 있는 배열 메모리를 할당 받아 
    //       멤버 memo_c_str에 주소를 저장하고 매개변수의 문자열을 멤버 변수로 복사한다.
    if( c_str == nullptr ){
        memo_c_str = nullptr;
        return;
    }

    char* tmp = new char[strlen(c_str)+1];
    strcpy(tmp,c_str);
    memo_c_str = tmp;    
}


// 생성자 또는 복사생성자에 의해 이미 한번 초기화된 주소 문자열(기존의 주소)을 다른 주소로 변경할 때 호출됨 
// 이미 멤버 address용 메모리가 할당되었기 때문에 기존 메모리를 먼저 반납해야 하고 새로 할당해야 함
void Person::setAddress(const char* address) {
    //TODO: 기존의 멤버 address가 nullptr이 아닌 경우
    if( this->address != nullptr ){
    delete[] this->address;
    }

    copyAddress(address); // 새로 메모리 할당받은 후 복사한다.
}

// 멤버 memo_c_str은 생성자에 의해 nullptr로 설정되었거나 복사생성자에 의해 이미 초기화되었 수도 있음
// 만약 멤버 memo_c_str용 메모리가 할당되었다면 먼저 반납해야 함
void Person::setMemo(const char* c_str)      {
    // TODO: 기존의 멤버 memo_c_str가 nullptr이 아닌 경우
    if( this->memo_c_str != nullptr ){
        //멤버 memo_c_str가 포인터하는 [배열] 메모리를 반납한다. []를 잊지 마라.
        delete[] this->memo_c_str;
    }

    copyMemo(c_str); // 새로 메모리 할당받아 복사한다.
}

/******************************************************************************
 * User Interface
 ******************************************************************************/
// 기본적인 입력과 관련된 전역 함수들을 UI라는 이름공간 내부에 정의함

class UI {
static string line, emptyLine;
public:
static bool echo_input;
static bool checkInputError(istream& in, const string& msg);//그냥 안에서 스태틱만 붙히면 안되나
static bool checkDataFormatError(istream& in);
static bool inputPerson(Person& p);
static const string& getNext(const string& msg);
static const string& getNextLine(const string& msg);
static int getInt(const string& msg);
static int getPositiveInt(const string& msg);
static int getIndex(const string& msg, int size);
static int selectMenu(const string& menuStr, int menuItemCount);
//UI::


}; // namespace UI
bool UI::echo_input = false;
string UI::line, UI::emptyLine; // ""로 초기화됨

// 입력에서 정수 대신 일반 문자가 입력되었는지 체크하고 에러 발생시 에러 메시지 출력
bool UI::checkInputError(istream& in, const string& msg) {
    if (!(in)) { // 에러가 발생했다면
        cout << msg;  // 에러 메시지를 출력
        in.clear(); // 에러 발생 상태정보를 리셋함; 그래야 다음 문장에서 읽을 수 있음
        getline(in, emptyLine); // 에러가 발생한 행 전체를 읽어 데이터를 버림
        return true;
    }
    return false;
}
// 정수나 실수를 입력해야 하는 곳에 일반 문자열을 입력한 경우의 에러 체크
bool UI::checkDataFormatError(istream& in) {
    return checkInputError(in, "Input-data format MISMATCHED\n");
}
// 한 사람의 정보 즉, 각 멤버 데이터를 순서적으로 입력 받아 p에 저장하고
// 입력 중 입력 데이터에 오류가 있는지 확인하고 오류가 있을 시 에러 메시지를 출력한다.
bool UI::inputPerson(Person& p) {
    cout << "input person information:" << endl;
    p.input(cin);
    if (checkDataFormatError(cin)) return false;
    if (echo_input) p.println(); // 자동체크에서 사용됨
    return true;
}
// 입력장치에서 하나의 단어로 구성된 문자열을 입력 받음
const string& UI::getNext(const string& msg) {
cout << msg; // 입력용 메시지를 출력
cin >> line; // 하나의 단어를 읽어 들임
if (echo_input) cout << line << endl; // 자동체크 시 출력됨
getline(cin, emptyLine); // 입력받은 한 단어 외 그 행의 나머지 데이타(엔터포함)는 읽어서 버림
return line;             // 이유는 여기서 [엔터]를 제거하지 않으면 
}                            // 다음의 getNextLine()에서 엔터만 읽어 들일 수 있기 때문에
// 입력장치에서 한 행을 입력 받음
const string& UI::getNextLine(const string& msg) {
cout << msg; // 입력용 메시지를 출력
getline(cin, line); // 한 행을 읽어 들임
if (echo_input) cout << line << endl; // 자동체크 시 출력됨
return line;
}
// 하나의 정수를 입력 받음; 정수가 아닌 아닌 문자열 입력시 에러 메시지 출력 후 재입력 받음
int UI::getInt(const string& msg) {
    for (int value; true; ) {
        cout << msg;
        cin >> value;
        if (echo_input) cout << value << endl; // 자동체크 시 출력됨
        if (checkInputError(cin, "Input an INTEGER.\n"))
            continue;
        getline(cin, emptyLine); // skip [enter] after the number
        return value;
    }
}
// 하나의 양의 정수를 입력 받음; 음수 입력시 에러 메시지 출력 후 재입력 받음
int UI::getPositiveInt(const string& msg) {
    int value;
    while ((value = getInt(msg)) < 0)
        cout << "Input a positive INTEGER." << endl;
    return value;
}
// 0~(size-1)사이의 선택된 메뉴 항목 또는 리스트의 항목의 인덱스 값을 리턴함
// 존재하지 않는 메뉴항목을 선택한 경우 에러 출력
int UI::getIndex(const string& msg, int size) {
    while (true) {
        int index = getPositiveInt(msg);
        if (0 <= index  && index < size) return index;
        cout << index << ": OUT of selection range(0 ~ "
            << size-1 << ")" << endl;
    }
}
// 사용자에게 메뉴를 보여주고 사용자가 선택한 메뉴항목의 인덱스를 리턴함
int UI::selectMenu(const string& menuStr, int menuItemCount) {
    cout << endl << menuStr;
    return getIndex("Menu item number? ", menuItemCount);
}

/******************************************************************************
 * ch4_3: string and Memo class
 ******************************************************************************/

class Memo
{
string mStr; // 메모를 저장해 두는 문자열

string& get_next_line(size_t& ppos, string& line);
bool find_line(int line, size_t& start, size_t& next);
size_t find_last_line();

public:
Memo(const char* c_str={} ): mStr{c_str==nullptr?"":c_str} { }
string& getNext(size_t& ppos, string& word);
void displayMemo();
void findString();
void compareWord();
void dispByLine();
void deleteLine();
void replaceLine();
void scrollUp();
void scrollDown();
void inputMemo();
void run();
//TODO: mStr의 C 스트링 문자열(string의 적절한 멤버 함수 호출할 것)을 리턴하라.
const char *c_str(){return mStr.c_str();}
void c_str(const char *c_str){mStr = c_str==nullptr?"":c_str;}

// const char *get_c_str() { return mStr.c_str(); }
// void set_c_str(const char *c_str) {// C 문자열로 메모 mStr 초기화
// // TODO: 매개변수 c_str이 nullptr일 경우 mStr을 ""로 설정하고 
// //       아닌 경우 mStr을 c_str로 설정하라. 
// //       mStr = ? : ; 3항 연산자를 사용하여 한 문장으로 완성하라.
// mStr = c_str==nullptr?"":c_str;
// }
};

void Memo::displayMemo() { // Menu item 1
cout << "------- Memo -------" << endl;
cout << mStr;
if (mStr.length() > 0 && mStr[mStr.length()-1] != '\n')
    cout << endl; // 메모 끝에 줄바꾸기 문자가 없을 경우 출력
cout << "--------------------" << endl;
}

void Memo::findString() {
string word = UI::getNext("Word to find? ");
int count = 0, len = word.length();
/*
TODO: for 문을 사용하여 반복적으로 string::find() 함수를 호출하여 찾은 단어의 
        출현 회수(count)를 세어라. find()를 통해 찾은 위치에서 len을 더하면 
        찾은 단어의 끝 위치가 되는데 이것이 다음 번에 찾기 시작할 위치이다.
        string::find()의 리턴 값이 string::npos와 같으면 
        단어를 찾지 못했다는 것을 의미한다. 못 찾을 때까지 반복 수행하면 됨.
        찾기 시작 위치 또는 리턴 값의 타입은 size_t를 사용하라.
*/
int f_index = 0;
for(;;){
if( mStr.find(word,f_index) == mStr.npos ) break;
f_index = mStr.find(word,f_index) + len;
count += 1;
}

cout << "Found count: " << count << endl;
}

// 메모의 현 위치(pos = *ppos)에서 하나의 단어를 찾아 해당 단어를 별도의 string으로 구성해서 리턴함
// 스페이스, 탭, 엔터와 같은 공백 문자로 시작할 경우 이들을 먼저 모두 스킵함
// 단어의 끝은 공백, 탭, 엔터, 구두점(punctuation)으로 구분함
// 구두점이란 숫자, 영문자를 제외한 문자들을 의미한다. ,.';:"][{}()*&^%$#@!~`?>< 등
// 각 구두점 글자는 단어를 구분하는 구분자로 사용되고 그 글자 하나만으로도 하나의 단어로 취급받음
// isspace()와 ispunct() 함수는 www.cplusplus.com/reference/에서 검색해 보기 바란다.

string& Memo::getNext(size_t& ppos, string& word) {
size_t pos = ppos, end;
for ( ; pos < mStr.size() && isspace(mStr[pos]); ++pos) ; // 단어 앞의 공백 문자들 스킵(있을 경우)
end = pos; // pos는 단어의 시작 위치이고 end는 단어의 끝 다음 위치이다.
if (end < mStr.size() && ispunct(mStr[end])) // 첫 글자가 구두점일 경우
    ++end;
else { // 단어의 끝을 찾음
    for ( ; end < mStr.size() && !isspace(mStr[end]) &&
            !ispunct(mStr[end]); ++end) ;
}
ppos = end; // 다음 단어의 시작 위치를 기록해 둠
/*
TODO: string::substr()을 이용해서 찾은 단어를 발췌해서 별도의 string으로 구성하여 리턴하라.
        mStr의 끝에 도착하여 더 이상 찾을 단어가 없을 경우 "" 문자열을 반환하게 된다.
        발췌할 단어의 길이는 pos와 end의 간단한 계산으로 구할 수 있다. 
*/
word = mStr.substr(pos,end-pos);
return word;
}

// 사용자로부터 비교할 단어를 입력받고 메모 문자열에서 
// 해당 단어와 동일한 단어의 출현 회수 same,
// 사전적 순서에서 이 단어보다 앞쪽에 있는 단어의 출현 회수 less, 
// 그리고 이 단어보다 뒤쪽에 있는 단어의 출현 회수 larger를 세어서 각각을 출력한다.
void Memo::compareWord() {
string next, word = UI::getNext("Word to compare? ");
int less = 0, same = 0, larger = 0;
/*
아래 pos는 getNext(&pos)를 호출할 때 다음 단어를 찾아야 할 시작 위치임
TODO: for(size_t pos = 0; getNext(&pos)를 호출하여 mStr의 끝까지 반복 수행; )
            위 getNext(&pos)를 호출시 리턴된 다음 단어를 next에 저장한 후
            next가 ""일 경우 mStr의 끝을 의미하므로 for문 종료
            ""가 아닌 경우 찾을 단어인 word와 비교(<, >, ==)하여 
            적절한 less, same, larger 변수의 값을 증가시킨다.
*/
for(size_t pos = 0; !getNext(pos, next).empty(); ){ //이럴거면 while이 낫지않나

if( next == word )
same += 1;
else if( next>word )
larger += 1;
else if ( next<word )
less += 1;
}

cout << "less: "   << less   << endl;
cout << "same: "   << same   << endl;
cout << "larger: " << larger << endl;
}

// 메모의 현 위치(pos = *ppos)에서 그 행의 끝을 찾은 후 행 전체를 별도의 string으로 구성해서 리턴함
// string::npos는 해당 문자를 찾지 못했을 경우의 리턴 값이며 (-1)과 동일 값임
string& Memo::get_next_line(size_t& ppos, string& line) {
size_t pos = ppos, end;

/*
TODO: string::find()를 이용해 행의 끝('\n') 위치를 찾아서(현재 행의 시작 위치는 pos임) end에 저장
*/
end = mStr.find("\n",pos);
// 메모의 끝에 '\n'이 없을 경우: (end == string::npos) 
end = (end == string::npos)? mStr.length() : end+1; 
ppos = end; // 다음 행의 시작 위치를 기록해 둠

/*
TODO: 찾은 현재 행을 string::substr()으로 발췌해서 별도의 string으로 구성하여 리턴하라.
        발췌할 단어 길이는 pos와 end로 간단히 계산할 수 있음
*/
line = mStr.substr(pos,end-pos);
return line;
}

// 메모 텍스트 mStr를 한 행씩 잘라서 행 번호와 함께 화면에 보여즘; 행 번호는 0부터 시작함
void Memo::dispByLine() {
cout << "--- Memo by line ---" << endl;
/*
아래 pos는 get_next_line(&pos)를 호출할 때 다음 행의 시작 위치임
TODO: for(size_t pos = 0, ... 문을 이용하여 pos가 mStr의 길이보다 작을 동안 반복 수행
            get_next_line(&pos)를 호출하여 반환된 다음 행 문자열을 line에 저장하고 
            적절한 행 번호와 함께 해당 행(line)을 출력(행번호 출력은 PersonManager::display() 참조)
            행의 끝에 줄바꾸기 문자 '\n'가 없을 경우 endl 출력 (displayMemo() 참조)
*/
int i=0;
for(size_t pos = 0; pos<mStr.size(); ){//pos증감은 get_next_line(&pos)에서 해줌

string line;
get_next_line(pos, line);
cout<<"["<<i<<"] "<<line;
if (line.size() > 0 && line[line.size()-1] != '\n')
    cout << "\n"; // 메모 끝에 줄바꾸기 문자가 없을 경우 출력
i += 1;
}
cout << "--------------------" << endl;
}

// 행번호가 line_num(0부터 시작)인 행을 찾아 행의 시작 위치 *start와 행 길이 *plen를 계산함
// 해당 행 번호를 찾았으면 true, 찾지 못했으면 false 반환
bool Memo::find_line(int line_num, size_t& pstart, size_t& plen) {
size_t start = 0;

// TODO: for 문을 이용해 line_num번 반복 수행 (0 행에서 line_num-1 행까지 반복)
//           string::find()를 이용해 start에서부터 행의 끝('\n')을 찾고, 
//           find()의 리턴된 값을 다시 start에 저장
//           행의 끝을 찾지 못했을 경우(line_num 행까지 진행하지 못한 경우) 즉,
//           find()의 반환된 값 start가 string::npos이면 
//               여기서 false 리턴함 (line_num행을 찾지 못한 경우)
//           start 값을 1 증가시켜 다음 행의 시작 위치로 조정
for( int i=0; i<line_num; i++ ){
    start = mStr.find("\n",start);
    if( start == mStr.npos )
    return false;
    start += 1;
}
            
pstart = start; // line_num 행의 시작 위치를 기록

// TODO: line_num 행의 끝 위치를 찾고, 
//       찾았으면 그 행의 길이를 계산하여 *plen에 저장
//       찾지 못한 경우 string::npos를 *plen에 저장 /* 예를들어, 실제로 행이 
//           [0], [1], [2] 행까지 있는데 [3] 행의 시작(메모의 끝 위치)을 찾을 경우에 해당함 */
plen = mStr.find("\n",start);
if( plen != mStr.npos ){
    plen -= start;
}
return true; // line_num 행을 찾았다는 것을 의미함
}

// 사용자로부터 삭제할 행 번호를 입력 받은 후 해당 행 전체를 삭제함
void Memo::deleteLine() {
size_t start, len, line_num = UI::getPositiveInt("Line number to delete? ");

// TODO: 만약 line_num 행을 찾지 못한 경우 
//       ( 즉, mStr이 비어 있거나 또는
//         find_line(line_num,&start,&len) 호출하여 line_num 행을 못 찾았거나(false) 또는
//         찾았지만(true) 행의 시작 위치인 start가 메모 텍스트의 끝인 경우(start == mStr.size()) )
//           "Out of line range" 문장 출력
//       line_num 행을 찾은 경우 mStr에서 해당 행을 삭제한 후 dispByLine() 호출

if( find_line(line_num,start,len) && start != mStr.size()  ){
mStr.erase(start,len+1);
dispByLine();
}else{
    cout<<"Out of line range\n";
}
}

// 교체할 행 번호와 교체할 문자열을 입력 받은 후 해당 행을 입력 받은 행으로 교체함
void Memo::replaceLine() {
size_t start, len, line_num = UI::getPositiveInt("Line number to replace? ");

// TODO: find_line(line_num, &start, &len) 호출하여 line_num 행을 찾음
//       만약 해당 행을 찾지 못한 경우 "Out of line range"를 출력하고 리턴함
if( find_line(line_num, start, len) == false ){// if 조건문 돌면서 다 구함
    cout<<"Out of line range\n";
    return;
}

string line = UI::getNextLine("Input a line to replace:\n");
//지우고 삽입
mStr.erase(start,len+1);
mStr.insert(start,line+'\n');
dispByLine();
// TODO: 읽은 line의 끝에 '\n'을 추가하라.
//       찾은 행을 line 문자열로 교체한 후 dispByLine() 호출
}

// 모든 행을 한 행씩 앞으로 옮김 (즉, 첫행을 마지막으로 옮김)
// 즉, 첫 행(행 번호 0)을 삭제한 후 삭제된 행을 맨 마지막에 다시 추가함
void Memo::scrollUp() {
size_t start, len;
// TODO: find_line()를 이용해 첫 행을 찾음
//       mStr의 첫 행을 mStr의 맨 마지막에 추가함
//       mStr의 첫 행을 삭제한 후 dispByLine() 호출

find_line(0,start,len);//첫줄 시작과 길이 가져와서
string tmp = mStr.substr(start,len+1);//첫줄 저장하고
mStr.erase(start,len+1);//첫줄 삭제
mStr.insert(mStr.size(),tmp);//저장했던 첫줄 끝에 붙이기 어펜드해도됨

dispByLine();
}

// 마지막 행의 시작 위치를 찾아서 반환함
size_t Memo::find_last_line() {
for (size_t start = 0, pos = 0; true; start = pos) {

    pos = mStr.find("\n",start+1);
    if( pos == mStr.npos || ++pos == mStr.size() ){
        return start;
    }
    // TODO: start 위치 이후로 행 끝을 찾아 pos에 저장 
    //       행 끝을 못 찾았거나 또는 ++pos가 mStr의 길이와 같으면(마지막 행) start 값 리턴
}
}

void Memo::scrollDown() {
size_t last = find_last_line();
size_t len = mStr.size() - last;
// 마지막 행을 서브 string으로 발췌하여 별도 저장
string tmp = mStr.substr(last,len);
// 마지막 행 삭제
mStr.erase(last,len);
// 발췌했던 마지막 행을 맨 처음에 삽입한 후 
mStr.insert(0,tmp);

dispByLine();
}

/*
In war, he is daring, boastful, cunning, ruthless, self-denying,
and self-devoted; in peace, just, generous, hospitable, revengeful,
superstitious, modest, and commonly chaste.
These are qualities, it is true, which do not distinguish all alike;
but they are so far the predominating traits of these remarkable people
as to be characteristic.
It is generally believed that the Aborigines of the American continent
have an Asiatic origin.

*/
// 사용자로부터 메모 데이타를 행 단위로 입력받아 기존의 mStr에 계속 추가함
// 입력의 끝은 빈 줄을 입력하면 된다. 
void Memo::inputMemo() {

// TODO: 기존 mStr의 문자열을 모두 삭제하고, 크기를 0으로 만듦
mStr.clear();

string line;
cout << "--- Input memo lines, and then input empty line at the end ---" << endl;
while (true) {
    getline(cin, line);
    if (UI::echo_input) cout << line << endl; 
    if( line == "" )
    return;
    
    mStr.append(line+"\n");

    // TODO: getline(cin, line)을 사용하여 키보드로부터 한 줄을 입력 받아 line에 저장
    //       if (UI::echo_input) cout << line << endl; // 자동체크 때 실행됨
    //       입력 받은 한 행이 빈 줄이면 리턴함
    //       입력 받은 행 끝에 "\n"을 추가
    //       입력 받은 행을 mStr의 끝에 추가
}
}



// 아래 R"( 와 )"는 그 사이에 있는 모든 문자를 하나의 문자열로 취급하라는 의미이다.
// 따라서 행과 행 사이에 있는 줄바꾸기 \n 문자도 문자열에 그대로 포함된다.
// 이런 방식을 사용하지 않으면 여러 행에 걸친 문자열을 만들려면 복잡해진다.
const char* memoData = R"(The Last of the Mohicans
James Fenimore Cooper
Author's Introduction
It is believed that the scene of this tale, and most of the information
necessary to understand its allusions, are rendered sufficiently 
obvious to the reader in the text itself, or in the accompanying notes.
Still there is so much obscurity in the Indian traditions, and so much
confusion in the Indian names, as to render some explanation useful.
Few men exhibit greater diversity, or, if we may so express it, 
greater antithesis of character, 
than the native warrior of North America.
)";

void Memo::run() {
using func_t = void (Memo::*)();
// TODO 문제 [1]: func_arr[], menuCount 선언


func_t func_arr[] = {
        nullptr, &Memo::displayMemo
        ,&Memo::findString, &Memo::compareWord, &Memo::dispByLine,
            &Memo::deleteLine, &Memo::replaceLine, &Memo::scrollUp, &Memo::scrollDown, &Memo::inputMemo
    };

int menuCount = sizeof(func_arr) / sizeof(func_arr[0]); // func_arr[] 배열의 길이


string menuStr =
    "++++++++++++++++++++++ Memo Management Menu +++++++++++++++++++++\n"
    "+ 0.Exit 1.DisplayMemo 2.FindString 3.CompareWord 4.DispByLine  +\n"
    "+ 5.DeleteLine 6.RepaceLine 7.ScrollUp 8.ScrollDown 9.InputMemo +\n"
    "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";

if (mStr == "") mStr = memoData;// 멤버 mStr이 비었을 경우 위 memoData로 초기화한다.

// TODO 문제 [1]: while 문장 삽입하여 선택된 메뉴항목 실행하는 함수 호출
while (true) {
        int menuItem = UI::selectMenu(menuStr, menuCount);
        if (menuItem == 0) return;
        (this->*func_arr[menuItem])();
    }

}



/******************************************************************************
 * ch3_2: CurrentUser class
 ******************************************************************************/

class CurrentUser
{
    Person& rUser;
    Memo    memo; // ch4_3에서 추가
public:
//  CurrentUser(Person u): user(u) { }
    CurrentUser(Person& rUser): rUser(rUser)/* TODO [문제 1]:  멤버 초기화 */ { }
    void display();
    void setter();
    void getter();
    void set();
    void whatAreYouDoing();
    void isSame();
    void inputPerson();
    void changePasswd();
    void manageMemo();
    void defaultParameter();
    void staticMember();
    void run();
};

void CurrentUser::display() { // Menu item 1
    rUser.println();
}

void CurrentUser::getter() { // Menu item 2
    cout << "name:" << rUser.getName() << ", id:" << rUser.getId() << ", weight:" <<
            rUser.getWeight() << ", married:" << rUser.getMarried() <<
            ", address:" << rUser.getAddress() << endl;
}

void CurrentUser::setter() { // Menu item 3
    Person p("rp"), &rp = p; // Person p("rp"); Person& rp = p;와 동일
    rp.setName(rp.getName());
    rp.set(rUser.getId());
    rp.set(rUser.getWeight());
    rp.set(rUser.getMarried());
    rp.setAddress(rUser.getAddress());
    cout << "rp.setMembers():"; rp.println();
}

void CurrentUser::set() { // Menu item 4
    Person p("rp"), &rp = p; // Person p("rp"); Person& rp = p;와 동일
    rp.set(rp.getName(), rUser.getId(), rUser.getWeight(),
            !rUser.getMarried(), rUser.getAddress());
    cout << "rp.set():"; rp.println();

}

void CurrentUser::whatAreYouDoing() {  // Menu item 5
    rUser.whatAreYouDoing();
}

void CurrentUser::isSame() { // Menu item 6
    rUser.println();
    cout << "isSame(\"user\", 1): " << rUser.isSame("user", 1) << endl;
}

void CurrentUser::inputPerson() { // Menu item 7
    if (UI::inputPerson(rUser)) // GilDong 1 70.5 true :Jongno-gu, Seoul:
        display();              // user 1 71.1 true :Gwangju Nam-ro 21:
}

void CurrentUser::changePasswd() {
string pswd = UI::getNext("New password: ");
// pUser가 포인트하는 객체의 비번을 변경하라
rUser.setPasswd(pswd);
cout << "Password changed" << endl;
}

// Person 객체에 저장되어 있던 메모 내용을 memo 객체로 복사하고
// 메모 메뉴에서 메모의 추가, 삭제, 교체 등의 조작이 끝나고 나면 (memo.run())
// 반대로 memo에 있던 메모 내용을 다시 Person 객체로 복사한다.
void CurrentUser::manageMemo() { // Menu item 9
memo.c_str(rUser.getMemo());
memo.run();
rUser.setMemo(memo.c_str());
}

void CurrentUser::defaultParameter() { // Menu item 10
    Person ps1;
    Person ps2("ps2");
    Person ps3("ps3", 3);
    Person ps4("ps4", 4, 70.4);
    Person ps5("ps5", 5, 70.5, true);
    Person ps6("ps6", 6, 70.6, true, "ps6 address");

    cout << "\nMemo m1;" << endl;
    Memo m1; // 메모 생성자에게 인자를 넘겨 주지 않은 경우
    m1.displayMemo();

    cout << "\nMemo m2(rUser.getMemo())" << endl;
    Memo m2(rUser.getMemo()); // 메모 생성자에게 인자를 넘겨 준 경우
    m2.displayMemo();
}
void CurrentUser::staticMember() { // Menu item 11

    // TODO: string 변수 word1을 선언하고 클래스 이름을 사용하여 UI의
    //       getNext("Input a word: ")를 호출한 후 리턴 값으로 word1 변수를 초기화하라.

    string word1 = UI::getNext("Input a word: ");
    cout << "UI::getNext(): " << word1 << endl << endl;

    UI ui;

    // TODO: string 변수 word2을 선언하고 UI의 객체인 ui 이름으로 
    //       getNext("Input a word: ")를 호출한 후 리턴 값으로 word2 변수를 초기화하라.
    string word2 = ui.getNext("Input a word: ");
    cout << "ui.getNext() : " << word2 << endl;
}

void CurrentUser::run() {
    using CU = CurrentUser;
    using func_t = void (CurrentUser::*)();
    func_t func_arr[] = {
        nullptr, &CU::display, &CU::getter, &CU::setter,
        &CU::set, &CU::whatAreYouDoing,
        &CU::isSame, &CU::inputPerson, &CU::changePasswd, &CU::manageMemo,
        &CU::defaultParameter,&CU::staticMember
    };
    int menuCount = sizeof(func_arr) / sizeof(func_arr[0]); // func_arr[] 배열의 길이
    string menuStr =
    "+++++++++++++++++++++ Current User Menu ++++++++++++++++++++++++\n"
    "+ 0.Logout 1.Display 2.Getter 3.Setter 4.Set 5.WhatAreYouDoing +\n"
    "+ 6.IsSame 7.InputPerson 8.ChangePasswd(4_2) 9.ManageMemo(4_3) +\n"
    "+ 10.DefaultParameter(6_1) 11.StaticMember(6_1)                +\n"
    "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";

    while (true) {
        int menuItem = UI::selectMenu(menuStr, menuCount);
        if (menuItem == 0) return;
        (this->*func_arr[menuItem])();
    }
}
// ch3_2: CurrentUser class

/******************************************************************************
 * ch4_2: VectorPerson class
 ******************************************************************************/
// VectorPerson는 n개의 Person * 포인터를 pVector[] 배열에 담아 관리하는 클래스이다.
// 필요에 따라 포인터를 삽입, 삭제, 추가 등을 할 수 있다.
// 삽입하는 포인터 개수가 점점 많아지면 pVector[] 배열을 위한 메모리를 자동 확장하기도 한다.

class VectorPerson
{
static const int DEFAULT_SIZE = 10; // pVector의 디폴트 배열 원소 개수

Person **pVector; // Person *pVector[]; Person에 대한 포인터들의 배열, 배열에 저장될 값이 Person *이다.
int count;        // pVector 배열에 현재 삽입된 객체 포인터의 개수
int allocSize;    // 할당 받의 pVector의 총 배열 원소의 개수

void extend_capacity(); /* TODO 문제 [7] */

public:
// VectorPerson():VectorPerson(DEFAULT_SIZE) {
// }
VectorPerson(int capacity={DEFAULT_SIZE});
~VectorPerson();

// 아래 긱 함수이름 뒤의 const는 그 함수가 클래스 멤버 변수들을 수정하지 않고 읽기만 한다는 의미임
// pVector[index]의 포인터 값을 반환 
Person* at(int index) const { return pVector[index]; }
// 할당 받의 pVector의 총 배열 원소의 개수를 반환
int     capacity()    const { return allocSize; }
// pVector 배열에 현재 삽입된 객체 포인터의 개수를 0으로 설정
void    clear()             { count = 0; }
// 현재 삽입된 객체 포인터가 하나도 없으면 true, 있으면 false
bool    empty()       const {return count==0; }
// 현재 삽입된 객체 포인터의 개수를 반환
int     size()        const { return count; }
// pVector 배열에 마지막 삽입된 원소 뒤에 새로운 원소 p를 삽입하고 현재 삽입된 객체 개수를 증가
void    push_back(Person* p);
void erase(int index);
void insert(int index, Person* p);
};

void VectorPerson::push_back(Person* p){
if( count >= allocSize )
extend_capacity();

pVector[this->size()] = p; //카운트 넣어도 돌아감
count += 1; 
}

// pVector[]의 배열 크기를 두배로 확장한다.
void VectorPerson::extend_capacity() {
Person **saved_persons = pVector; // 기존의 pVector를 백업함

// allocSize 값을 두 배로 늘린 후 새로 pVector를 할당 받는다.
allocSize *= 2;
pVector = new Person*[allocSize];// 변수가 선언이 되어있으면 선언할때처럼 자료형명시 안해도되네

// for 문을 이용하여 count 개수만큼만 
// saved_persons[i]에 저장된 포인터를 새로 할당 받은 pVector[i]에 저장한다.
for( int i=0; i<count; i++ ){
    pVector[i] = saved_persons[i];
}


// saved_persons [배열] 메모리를 반납한다. (배열임을 명심할 것)
delete[] saved_persons;


cout << "VectorPerson: capacity extended to " << allocSize << endl;
}


// capacity는 할당해야 할 배열 원소의 개수
VectorPerson::VectorPerson(int capacity): allocSize{capacity}, count{0}/* : TODO 문제 [2]: 멤버 초기화 */ {
// allocSize = capacity, count = 0; 초기화를 위 함수 서두(위 /* */ 주석 사이)에서 할 것
// 함수 서두에서 초기화하는 방법은 Person 클래스 참고할 것
cout << "VectorPerson::VectorPerson(" << allocSize << ")" << endl;
pVector = new Person*[allocSize]; // Person* 들의 배열을 위한 동적 메모리 할당
}

VectorPerson::~VectorPerson()  {
/* TODO 문제 [2]: 동적으로 할당된 배열 pVector 반납: pVector가 배열임을 명심하라. */
delete[] pVector;
cout << "VectorPerson::~VectorPerson(): pVector deleted" << endl;
}

// 이 함수는 pVector[index] 원소를 삭제한다.
void VectorPerson::erase(int index) {
    // index가 음수이거나 마지막 원소보다 큰 인덱인 경우 바로 리턴하라.
    // pVector[index] 원소를 삭제하라. 
    //     즉, for 문을 이용하여 
    //            [index+1] 원소부터 마지막 원소까지 모두 왼쪽으로 한칸씩 이동시켜라.
    // pVector에 삽입된 원소의 개수를 하나 줄인다.
    if( index<0 || allocSize<index ) return;
    for( int i=index; i<allocSize-1; i++ ){
        pVector[i] = pVector[i+1];
    }
    count -= 1;
}
// 이 함수는 pVector의 index 위치에 새로운 원소를 삽입한다.
void VectorPerson::insert(int index, Person* p) {
    // 현재 벡터 내에 삽입된 원소의 개수가 할당된 원소의 개수와 같거나 큰 경우
    //     기존 함수를 호출하여 pVector의 용량을 먼저 확장한다. [push_back() 참조]
    if( count >= allocSize )
    extend_capacity();
    // for문을 이용하여 pVector의 마지막 원소에서부터 index까지 모두 한칸씩 오른쪽으로 이동시킨 후
    for( int i=count; i>=index; i-=1 ){
        pVector[i] = pVector[i-1]; 
    }
    // index 위치에 p를 저장한다.
    pVector[index] = p;
    //삽입된 원소 개수를 하나 늘린다.
    count += 1;
}


/******************************************************************************
 * ch4_2: Factory class
 ******************************************************************************/

class Factory
{
public:
// 동적으로 Person 객체를 할당 받은 후 키보드로부터 새로 추가하고자 하는 사람의
// 인적정보를 읽어 들여 해당 객체에 저장한 후 그 객체의 포인터를 반환한다.
static Person* inputPerson(istream& in) {
    Person* p = new Person();

    p->input(in);  // 멤버들을 입력 받음
    if (UI::checkDataFormatError(in)) { // 정수입력할 곳에 일반 문자 입력한 경우
        delete p;         // 할당한 메모리 반납
        return nullptr;   // nullptr 반환은 에러가 발생했다는 의미임
    }
    if (UI::echo_input) p->println(); // 자동체크에서 사용됨
    return p;
}
};




/******************************************************************************
 * ch4_2: PersonManager class
 ******************************************************************************/

class PersonManager
{
VectorPerson persons;
// Factory factory;

void deleteElemets();
void printNotice(const string& preMessage, const string& postMessage);
Person* findByName(const string& name);

public:
PersonManager(Person* array[], int len); // 6장에서 default 매개변수 설정
~PersonManager();
void display();
void append();
void clear();
void login();
void run();
void insert();
void remove();

};

PersonManager::PersonManager(Person* array[], int len) {
cout << "PersonManager::PersonManager(array[], len)" << endl;
/* TODO 문제 [4] */
for( int i=0; i<len; i++ ){
    Person *tmp = new Person(*array[i]);
    persons.push_back(tmp);
}

display();
}

PersonManager::~PersonManager() {
deleteElemets();
}

void PersonManager::deleteElemets() {
/* TODO 문제 [5] */

for(int i=0; i<persons.size(); i++){
    Person *target =  persons.at(i);
    delete target;
}
persons.clear();
}

void PersonManager::display() { // Menu item 1
int count = persons.size();
cout << "display(): count " << count << endl;
for (int i = 0; i < count; ++i) {
    cout << "[" << i << "] ";
    persons.at(i)->println();
}
cout << "empty():" << persons.empty() << ", size():" << persons.size()
        << ", capacity():" << persons.capacity() << endl;
}

void PersonManager::printNotice(const string& preMessage, const string& postMessage) {
cout << preMessage;
cout << " [person information] ";
cout << postMessage << endl;
}
// 아래 함수는 사용자로부터 새로 추가할 Person 객체의 수를 입력 받고 for문을 이용하여 
// 그 개수만큼의 Person 객체를 생성하고 인적정보를 입력받은 후 (factory.inputPerson(&cin)을 통해)
// 그 객체 포인터를 VectorPerson persons의 맨 끝 원소로 추가한다.
void PersonManager::append() { // Menu item 2
int count = UI::getPositiveInt("The number of persons to append? ");
// to_string(10) 함수: 정수 10을 문자열 "10"으로 변환
// stoi("10") 함수: 문자열 "10"을 정수 10으로 변환
printNotice("Input "+to_string(count), ":");
for (int i = 0; i < count; ++i) {
    Person* p = Factory::inputPerson(cin); // 한 사람 정보 입력 받음
    if (p) persons.push_back(p); // if (p != nullptr) 와 동일; 
    // 만약 p가 nullptr이면 이는 입력 시 에러가 발생한 것임 
    // (즉, 정수를 입력해야 하는 곳에 일반 문자를 입력한 경우)
}
display();
}

void PersonManager::clear() { // Menu item 3
deleteElemets();
display();
}
// VectorPerson에 저장된 사람들 중 매개변수 name과 동일한 이름을 가진 사람을 찾는다. 
Person* PersonManager::findByName(const string& name) {
// for 문을 이용하여 persons에 저장된 각각(i)의 사람 객체에 대해
//     매개변수 name과 비교해서 동일한 이름을 가진 객체이면 해당 객체의 포인터(Person*)를 반환한다.
//     persons의 size(), at(i), at(i)->getName() 등의 멤버함수 활용하라.
for( int i=0; i<persons.size(); i++ ){
    if( (persons.at(i))->getName() == name )
    return persons.at(i);
}// 찾지 못한 경우   
cout << name + ": NOT found" << endl;
return nullptr;
}

// 이 함수는 새로운 Person 객체를 동적으로 할당한 후 
// 사용자로부터 벡터 persons에 삽일할 위치와 새로운 인적정보를 입력 받아 할당된 객체에 저장하고 
// 이 객체를 위 VectorPerson::insert()를 호출하여 해당 객체 포인터를 persons에 삽입한다.
void PersonManager::insert() { // Menu item 5
    // persons 벡터가 비어 있을 경우 삽입할 index 위치를 무조건 0으로 설정하고
    // 그렇지 않은 경우 UI::getIndex()를 호출하여 사용자로부터 입력할 위치(index)를 입력 받아라.
    //     주의: 기존 원소의 맨 끝에 추가하는 것도 가능해야 한다.(인덱스 값의 범위에 주의)
    //          UI::getIndex() 호출 시 출력할 메시지는 실행 결과를 참조하라.
    int index;
    if( persons.empty() ) index = 0;
    else index = UI::getIndex("Index to insert in front? ", persons.size()+1);
    // printNotice(...); // 호출 시 이 함수 인자는 append()와 실행 결과를 참조하여 완성하라.
    //Input [person information] to insert:
    printNotice("Input","to insert:");
    // 새로운 Person 객체를 할당받고 인적정보를 입력 받은 후 새 변수 p에 저장
    //    (위 문장은 append() 함수 참조)
    Person* p = Factory::inputPerson(cin); // 한 사람 정보 입력 받음
    if (p == nullptr) return;
    // persons 벡터의 index 위치에 p를 삽입하라.
    persons.insert(index,p);
    display();
}
/* 입력할 때 아래 인적 정보를 복사하여 입력하면 편리하다.
HongGilDong 0 71.5 false :Gwangju Nam-gu Bongseon-dong 21:
LeeMongRyong 1 65 true :Jong-ro 1-gil, Jongno-gu, Seoul:
LeeSoonShin 2 80 true :1001, Jungang-daero, Yeonje-gu, Busan:
*/

// 이 함수는 사용자로부터 벡터 persons에 저장된 Person 객체 중 삭제할 인덱스를 입력 받고 
// 위 VectorPerson::erase()를 호출하여 해당 원소를 삭제한다.
void PersonManager::remove() { // Menu item 6
    // 벡터 persons가 비어 있을 경우 아래 메시지만 출력하고 바로 리턴하라.
    if( persons.empty() ){ cout << "No entry to remove" << endl; return; }
    // UI::getIndex("Index to delete? ", persons.size())를 호출하여 삭제할
    // Person 객체의 인덱스를 사용자로부터 입력 받는다.
    int index = UI::getIndex("Index to delete? ", persons.size());
    // persons의 index 위치에 저장된 포인터가 포인트하는 Person 객체의 메모리를 반납한다.
    delete persons.at(index);
    // persons의 위 VectorPerson::erase(...)를 호출하여 index 원소를 삭제하라.
    persons.erase(index);
    display();
}




// 사용자로부터 로그인할 사람의 이름과 비번을 입력받고 동일한 이름을 가진 Person 객체를
// persons에서 찾고 비번이 일치하는지 체크한 후 CurrentUser(p).run() 실행한다.
// 기존(ch4-1)의 Main Menu에서 호출하던 CurrentUser를 메뉴항목에서 삭제한 후
// 대신 여기서 호출함(사용자가 선택한 인적정보 p를 인자로 넘겨 주면서)
void PersonManager::login() {
string name = UI::getNext("user name: ");
Person* p = findByName(name); // 해당 사람을 VectorPerson에서 찾는다.
if (p == nullptr) return;     // 해당 사람 존재하지 않음
string passwd = UI::getNextLine("password: ");
if (passwd != p->getPasswd()) // 비번 불일치
    cout << "WRONG password!!" << endl;
else
    CurrentUser(*p).run();
}

void PersonManager::run() {
using func_t = void (PersonManager::*)();
using PM = PersonManager; // 코딩 길이를 줄이기 위해
func_t func_arr[] = {
    nullptr, &PM::display, &PM::append, &PM::clear, &PM::login,
    &PM::insert, &PM::remove,
};
int menuCount = sizeof(func_arr) / sizeof(func_arr[0]); // func_arr[] 길이
string menuStr =
    "====================== Person Management Menu ===================\n"
    "= 0.Exit 1.Display 2.Append 3.Clear 4.Login(CurrentUser, ch6)   =\n"
    "= 5.Insert(6_2) 6.Delete(6_2)                                   =\n"
    "=================================================================\n";

while (true) {
    int menuItem = UI::selectMenu(menuStr, menuCount);
    if (menuItem == 0) return;
    (this->*func_arr[menuItem])();
}
}









/******************************************************************************
 * ch3_2, 4_1, 4_2: MultiManager class
 ******************************************************************************/
class MultiManager
{
static const int personCount = 5;
Person persons[personCount] = {
    Person("p0", 10, 70.0, false, "Gwangju Nam-gu Bongseon-dong 21"),
    Person("p1", 11, 61.1, true,  "Jong-ro 1-gil, Jongno-gu, Seoul"),
    Person("p2", 12, 52.2, false, "1001, Jungang-daero, Yeonje-gu, Busan"),
    Person("p3", 13, 83.3, true,  "100 Dunsan-ro Seo-gu Daejeon"),
    Person("p4", 14, 64.4, false, "88 Gongpyeong-ro, Jung-gu, Daegu"),
};
// new를 이용해 동적으로 할당할 경우 소멸자 함수를 만들어 거기서 delete 해 주어야 함

static const int allPersonCount = personCount;
Person* allPersons[allPersonCount] = {
    &persons[0], &persons[1], &persons[2], &persons[3], &persons[4],
};

PersonManager personMng { allPersons, allPersonCount };
// 위 문장은 PersonManager personMng(allPersons, allPersonCount);와 동일함

public:
void run() {
    cout << "PersonManager::run() starts" << endl;
    personMng.run();
    cout << "PersonManager::run() returned" << endl;
}
}; // ch3_2, 4_1, 4_2: MultiManager class

/******************************************************************************
 * ch3_1: Class And Object
 ******************************************************************************/

//Person gps("gps", 1000, 100, true, "gps adress");

class ClassAndObject
{
    void defualConstructor() { // Menu item 1
        Person ps;    // Person::Person() 기본 생성자 및 소멸자 실행
    }

    void constructor() { // Menu item 2: 지역객체의 다양한 생성자 및 소멸자 실행
        Person ps1;
        Person ps2("ps2");
        Person ps3("ps3", 3, 70.3, true, "ps3 address");
    }

    void construcor_destructor_inner_inner() {
        cout << "\n--- construcor_destructor_inner_inner() begins ---" << endl;
        Person ps3("ps3");
        cout << "\n- if begins -" << endl;
        if (true) {
            Person ps4("ps4");
        }
        cout << "- if ends -\n" << endl;
        cout << "- temporary object begins -" << endl;
        Person("temp_ps_1"); // 임시객체(이름 없는 객체) 성성 및 소멸
        cout << endl;
        Person("temp_ps_2").setName("TEMP_PS_2"); // 임시객체 생성, 
                                                // setName() 호출, 임시객체 소멸
        cout << "- temporary object ends -\n" << endl;
        Person ps5("ps5");
    }

    void construcor_destructor_inner() {
        cout << "\n--- construcor_destructor_inner() begins ---" << endl;
        Person ps2("ps2");
        construcor_destructor_inner_inner();
        cout << "--- construcor_destructor_inner_inner() returned ---\n" << endl;
        Person ps6("ps6");
    }

    void construcorDestructor() { // Menu item 3
        Person ps1("ps1");
        construcor_destructor_inner();
        cout << "--- construcor_destructor_inner() returned ---\n" << endl;
    }

    void global_static_local_objects_inner() {
        cout << "\n--- global_static_local_objects_inner() begins ---" << endl;
        //static Person sps("sps", 2000, 200, false, "sps adress");
    }

    void globalStaticLocalObjects() { // Menu item 4
        global_static_local_objects_inner();
        cout << "--- global_static_local_objects_inner() returned ---" << endl;
        global_static_local_objects_inner();
        cout << "--- global_static_local_objects_inner() returned ---" << endl;
    }

    // 이 클래스는 기본 생성자 Init1()가 없기 때문에 컴파일러가 자동으로 기본 생성자를 생성해 준다. 
    // 이 기본 생성자에 의해 여기서는 다행히 모든 멤버가 0으로 초기화되는데 
    // 이는 컴파일러마다 다르게 실행될 수 있다.
    // 따라서 사용자가 직접 생성자를 만들어 초기화시켜 주는 습관을 가지는 것이 좋다.
    class Init1 { // ch6_2 추가
        Person p;
        int i, j;
        double d;
        char name[5];
    public:
        void print() {
             d = i = j = 0;
            cout << "Init1 i: " << i << ", j: " << j << 
                    ", d: " << d << ", name: " << name << endl;
        }
    };
    // 기본 생성자가 있지만 아무것도 실행하지 않는다. 
    // 이럴 경우 객체 멤버들(여기선 p)은 자동으로 기본 생성자가 실행되어 초기화된다.
    // 하지만 기본 데이타 타입 변수(i, j, d)들은 자동으로 초기화되지 않는다.
    // 따라서 필요한 경우 기본 데이타 타입 변수들은 생성자 내에서 반드시 초기화 해 주어야 한다.
    class Init2 {
        Person p;
        int i=6, j=6;
        double d;
    public:
        void print() { 
            cout << "Init2 i: " << i << ", j: " << j << ", d: " << d << endl; 
        }
    };
    // 기본 생성자가 있지만 아무것도 실행하지 않는다. 
    // 그러나 멤버 변수 선언 시에 멤버 p와 i처럼 선언과 동시에 초기화를 할 수 있다.
    // 멤버를 초기화하는 한 방법이지만 추천하고 싶은 방법은 아니다.
    // (일부 컴파일러는 이를 지원하지 않을 수 있는데 그럴경우 class Init4처럼 수정하라.)
    class Init3 {
        Person p { "p-Init3" };  
        //Person p("p-Init3");와 동일한 기능이나 이렇게 표현하면 컴파일 에러가 발생할 것이다.
        // 즉, 함수 리턴 타입이 Person이고 함수 이름 p, 매개변수가 "p-Init3"인 새로운 
        // [함수 선언]으로 컴파일러가 오해하여 에러 메시지(매개변수가 잘못되었다는)를 출력한다.
        // 컴파일러는 함수 선언인지 객체변수 선언인지 구분할 수 없기 때문이다. 
        // 그래서 { }를 사용한다. { }는 객체 변수 선언이며 생성자 함수 인자를 의미한다.
        int i {3}, j;  // i {3}는 i = 3으로 표현해도 됨; 그러나 i(3)은 에러
        double d;      // i는 초기화되지만 j, d는 초기화되지 않음
    public:
        Init3() { j = 6; d = 0; }
        void print() { 
            cout << "Init3 i: " << i << ", j: " << j << ", d: " << d << endl; 
        }
    };
    // 아래 주석문과 class Init4를 ClassAndObject 클래스 내의 Init3 클래스 뒤쪽(아래쪽)에
    // 배치하고, memberInitialization() 함수에서 Init4().print()의 주석을 풀어라.
    //----------------------------------------------------------------------------

    // 생성자의 서두에서 멤버 초기화(p{"p-Init4-head"})가 있을 경우 멤버 변수 선언 때 즉, 
    // Person p는 초기화(생성자 실행 X)하지 않고 생성자의 서두에서 멤버 p와 i를 초기화 한다.
    // 이처럼 생성자 서두에서 멤버를 초기화하는 것이 일반적인 방법이다.
    class Init4 {
        Person p;
        int i, j;
        double d;
    public:
        Init4(): p{"p-Init4-head"}, i{4} { j = 6; d = 0; }
         // 위 함수 서두에서는 p("p-Init4-head") 로 초기화해도 됨; 그러나 i = 4는 안됨 
        void print() { 
            cout << "Init4 i: " << i << ", j: " << j << ", d: " << d << endl; 
        }
    };
    // 멤버 선언 때도 초기화하고, 생성자 서두에서도 초기화를 하면 생성자가 두번 실행될까?
    // 정답은 생성자 서두에 있는 멤버 초기화만 한번 실행된다. 멤버 선언 때의 초기화는 무시된다.
    class Init5 {
        Person p { "p-Init5" };
        int i{4}, j;
        double d;
    public:
        Init5(): p{ "p-Init5-head" }, i{5} {  j = 6; d = 0;  }
        void print() { 
            cout << "Init5 i: " << i << ", j: " << j << ", d: " << d << endl; 
        }
    };
    // 멤버 선언과 생성자 서두에서 객체를 초기화 하지 않으면 객체 p의 기본 생성자가 자동으로 무조건 실행된다.
    // 생성자 함수 본체에서는 객체 p의 생성자를 호출할 수는 없고 set() 함수를 호출하여 초기화해야 한다.
    // 그래서 생성자 Init6()의 셍성자 본체 { } 에서 p.set()을 호출하면 객체 p는 두번 초기화되는 것이다.
    //----------------------------------------------------------------------------
    // 중요: 결국 객체 멤버(p)는 생성자의 서두에서 초기화하는 것이 가장 좋으며, 
    //      기본 데이타 타입(int, double 등)의 경우 생성자 본체 또는 서두에서 초기화해도 상관없다. 
    //      어차피 멤버 변수 선언 때 자동으로 초기화되지 않으니까.
    class Init6 {
        Person p;
        int i, j;
        double d;
    public:
        // 여기서는 p.set(...) 대신 편의상 p.setName(...)을 호출했다.
        Init6() { i = j = 6; d = 0; p.setName("p-Init6-body"); p.println(); }
        void print() { 
            cout << "Init6 i: " << i << ", j: " << j << ", d: " << d << endl; 
        }
    };

    void memberInitialization() { // Menu item 5
        int i = 0, i2 = i; i = i2; // 의미 없는 문장이지만, 삭제하지 말 것
        
        // 임시객체 생성 후 print()를 호출하고 바로 소멸된다.
        Init1().print(); cout << endl;
        Init2().print(); cout << endl;
        Init3().print(); cout << endl;
        Init4().print(); cout << endl;
        Init5().print(); cout << endl;
        Init6().print();
    }

    class Parameter {
    public:
        // 아래 각 함수 선언에서 const가 있는 매개변수는 해당 함수에서 객체 p를 수정하지 않는다는 의미이고,
        // const가 없는 매개변수는 해당 함수에서 객체 p를 수정할 수 있다는 의미임
        // 함수 호출한 곳에서 함수의 실행 결과를 매개변수를 통해 넘겨 받아야 하는 경우는 const가 없어야 함
        void normalValue(Person p)           { cout << "normalValue(Person p)" << endl; }
        void constValue(const Person p)      { cout << "constValue(const Person p)" << endl; }
        void normalReference(Person& p)      { cout << "normalReference(Person& p)" << endl; }
        void constReference(const Person& p) { cout << "constReference(const Person& p)" << endl; }

        void printStr(string& s)             { cout << "printStr(string& s): " << s << endl; }
        void printConstStr(const string& s)  { cout << "printConstStr(const string& s): " << s << endl; }
        void printPerson(const Person& p) { // const Person p로 선언해도 동일한 결과가 나옴
            cout << "printPerson(const Person& p)" << endl;
            // 위 const Person& p 선언의 의미: 이 함수에서 객체 p를 수정하지 않겠다는 의미임
            // 따라서 아래의 p.setName("const-value")처럼 p의 멤버함수를 호출하면 에러로 처리함; 
            // 이유는 이 함수가 const 객체인 p의 멤버 name를 수정하기기 때문에.

            /* p.setName("const-value"); */ // 명백히 이름을 수정하는 것이므로 컴파일 에러 발생
            cout << p.getName() << " " << p.getId() << " " << p.getWeight() << " " <<
                    p.getMarried() << " :" << ((p.getAddress()==nullptr)?"":p.getAddress()) <<
                    ":" << endl;

            // 주석을 풀 경우 발생하는 컴파일 에러는 매개변수가 const로 선언되었기 때문에  
            // 발생하는 것이다. 컴파일러 입장에서는 위 멤버함수들이 p의 멤버를 수정하는지 아니면 
            // 읽기만하는지 알 수 없기 때문에 컴파일 시 에러로 처리함; 
        }
    };

    Parameter cp;

    void normalParameter() {
        cout << "normalParameter()" << endl;
        cout << "Person p1(\"p1-name\")" << endl;

        // 요점: 아래 Person p1처럼 p1이 일반적인 객체일 경우 
        //      함수의 매개변수 타입에 상관없이 이 객체를 함수 인자로 넘겨 줄 수 있다.
        Person p1("p1-name");

        cp.normalValue(p1);     // 복사생성자 통해 매개변수 p에 p1을 복사해서 넘겨 줌
        cp.constValue(p1);      // 복사생성자 통해 매개변수 p에 p1을 복사해서 넘겨 줌
        cp.normalReference(p1); // 매개변수 p에 단순히 p1의 참조만 넘겨 줌
        cp.constReference(p1);  // 매개변수 p에 단순히 p1의 참조만 넘겨 줌
    }
    void constParameter() {
        cout << "constParameter()" << endl;
        cout << "const Person p2(\"const-p2-name\")" << endl;

        // 요점: p2처럼 상수(const) 객체일 경우 
        //      매개변수 타입 선언에 따라 인자로 넘겨 줄 수 없는 함수가 있다.
        const Person p2("const-p2-name"); // p2는 상수이므로 수정되어서는 안된다.

        // 아래 인자 p2가 일반 매개변수 p에 복사되므로 
        // 매개변수 p는 수정될지언정 원래 인자 p2는 수정되지 않는다. OK
        cp.normalValue(p2); 
        // 아래 인자 p2가 상수 매개변수 p에 복사되므로 원래 인자 p2는 수정되지 않는다. OK
        cp.constValue(p2);  
        //cp.normalReference(p2);
        //매개변수에 const한정자가 없음 == 변경할거임 /근데 넘겨주는타입은 변경불가임 - 에러
        //매개변수에 한정자를 붙히던가 넘기는타입에서 const를 빼던가

        // 위 함수의 일반 참조 매개변수 p는 p2와 메모리를 공유하므로 해당 함수에서 상수인 p2를 
        // 수정할 가능성이 있다.(const로 선언되지 않았으므로) 
        // 이런 경우 상수 객체 p2을 normalReference()의 인자로 줄 수 없다. 컴파일 에러.
        cp.constReference(p2); // 상수 참조 매개변수 p는 p2와 메모리를 공유하지만 p가 상수  
        // 객체의 참조로 선언되어 있으므로 해당 함수에서 p2를 수정하지 않는다는 것을 보장한다. OK
    }
    void temporaryParameter() {
        cout << "temporaryParameter()" << endl;

        // 요점: 아래의 Person("Person-name")는 임시객체가 생성되며, 
        //      이 임시객체는 컴파일러에 의해 const로 취급된다.
        //      따라서 이 임시객체는 위 [문제 10]의 const p2와 동일하게 취급된다.

        cp.normalValue(Person("Person-name"));       // 불필요한 객체 복사 일어남
        cp.constValue(Person("Person-name"));        // 불필요한 객체 복사 일어남
        //cp.normalReference(Person("Person-name")); // 컴파일 에러 발생
        cp.constReference(Person("Person-name"));    // 임시 객체 참조만 넘어감

        // 결론: 일반적으로 객체는 함수의 매개변수로 value로 복사해서 넘기지 않고 객체의 참조를 넘긴다.
        //      이유는 객체의 크기가 커지면 복사 오버헤드가 발생하기 때문이다. 
        //      그런데 함수의 매개변수가 const가 아닌 일반 참조 변수로 선언된 경우 
        //      그 함수에서 이 참조변수를 통해 원본 객체를 수정할 수 있기 때문에
        //      const p2 또는 위 임시객체(const 취급)와 같은 객체들을 함수 인자로 넘길 수 없다. 
        //      따라서 [만약 함수 내에서 매개변수인 객체를 수정하지 않는다면]
        //      일반 & 매개변수로 선언하기 보다는 const &로 습관적으로 선언하는 것이 유리하다.
        //      (이렇게 선언하면 위 cp.constReference()처럼 
        //       임시객체의 참조를 함수의 매개변수로 바로 넘길 수 있다.)
    }
    void stringParameter() {
        cout << "stringParameter()" << endl;

        string s("name1"); // string s = "name1"; 과 동일

        cp.printStr(s);
        cp.printConstStr(s);
        // 아래는 임시 string 객체 생성 (임시객체는 항상 const): 컴파일 에러
        //cp.printStr(string("name")); 임시객체 = 무조건 const
        //매개변수가 const 한정자가 없다면 에러

        cp.printConstStr(string("name2")); // const 임시 객체 생성
        // 아래 "name"은 자동으로 임시 string("name") 객체 생성: 컴파일 에러
        //cp.printStr("name"); 리터럴 문자열도 const, 즉 상수

        cp.printConstStr("name3"); // const 임시 객체 생성
        // 결론: 함수의 매개변수로 "name3"처럼 문자열을 직접 넘겨 주고 싶으면
        //      함수 매개변수를 const string& 으로 선언해야 한다. string&로 선언시 에러.
        //      함수 내에서 매개변수 객체를 수정하지 않을 경우 습관적으로 항상 이렇게 선언하라.
        // 매개변수를 const string으로 선언해도 되지만 이 경우 문자열 전체가 복사되므로 비효율적임
    }
    void parameters() { // Menu item 6
        normalParameter();
        constParameter(); cout << endl;
        temporaryParameter(); cout << endl;
        stringParameter(); cout << endl;
        cp.printPerson(Person("name", 10, 77.7, true, "address"));
        // 임시 Person 객체의 참조 전달 (임시 객체는 항상 const)
    }
    


public:
    // 사용자가 선택한 메뉴 항목을 실행하는 멤버 함수(func_arr[menuItem]에 등록된 함수)를 호출
    void run() {
        // ClassAndObject의 멤버 함수에 대한 포인터 타입인 새로운 데이타 타입 func_t를 정의함
        using func_t = void (ClassAndObject::*)();
        using CO = ClassAndObject;
        // 위 using 문은 ClassAndObject 클래스의 멤버 함수(리턴 타입이 void 이면서 매개변수가 없는)에
        // 대한 포인터 타입을 앞으로는 간단히 func_t로 사용하겠다는 의미이다.

        // ClassAndObject의 멤버 함수 포인터들의 배열
        // 나중에 호출하기 위해 멤버 함수의 이름을 미리 배열에 저장(등록) 
        //     함수 이름이 곧 함수에 대한 포인터임: 즉, 함수의 첫번째 명령어의 주소를 저장함
        // 등록된 이 멤버 함수들은 나중에 run()에서 호출됨
        //     (즉, 함수 주소로 jump 해 가서 함수를 실행함)

        func_t func_arr[] = { // 메뉴항목을 실행하는 멤버 함수를 배열에 미리 저장(등록)해 둠
            nullptr, &CO::defualConstructor, &CO::constructor,
            &CO::construcorDestructor, &CO::globalStaticLocalObjects,
            &CO::memberInitialization,&CO::parameters
        };
        int menuCount = sizeof(func_arr) / sizeof(func_arr[0]); 
        // func_arr[]의 원소의 개수 = 배열 전체 크기 / 한 배열 원소의 크기

        // 화면에 보여 줄 메뉴
        string menuStr =
            "+++++++++++ Person Class And Object Menu ++++++++++++\n"
            "+ 0.Exit 1.DefualConstructor 2.Constructor          +\n"
            "+ 3.ConstrucorDestructor 4.GlobalStaticLocalObjects +\n"
            "+ 5.MemberInitialization 6.constParameter           +\n"
            "+++++++++++++++++++++++++++++++++++++++++++++++++++++\n";

        while (true) {
            int menuItem = UI::selectMenu(menuStr, menuCount); // 메뉴 번호 입력 받음
            if (menuItem == 0) return;
            (this->*func_arr[menuItem])(); // 선택된 메뉴 항목을 실행할 멤버 함수를 호출함
            /* 위 문장은 다음을 간단히 한 것이다. 앞으로 계속 나올테니 잘 이해하기 바란다.
            func_t f = func_arr[menuItem];// 배열에 저장된 멤버 함수 포인터
            (this->*f)();                 // 멤버함수 포인터를 이용하여 해당 함수를 호출함
            */
        }
    }
}; // ch3_1: class ClassAndObject



class CopyConstructor
{
    Person u;
    Person backup;

public:
    // u는 일반 생성자, backup은 복사생성자를 이용하여 멤버를 초기화
    CopyConstructor(): u("u", 1, 70, true, "Gwangju"), backup(u) { }
    


    

    void explicitCopyConstructor() { // Menu item 1
        cout << "u: "; u.println();
        
        // TODO: Person형의 객체 p를 선언하되 복사생성자를 사용하여 u을 복사하여 초기화하라. 
        Person p(u);

        // TODO: 실행결과를 참고하여 지역 객체 p의 멤버 값들을 변경하라.
        p.set("p",2,80,false,"Seoul");

        cout << "u: "; u.println();
        cout << "p: "; p.println();
        // 함수 리턴 시 객체 p의 소멸자가 실행됨
    }

    void referenceVariable() { // Menu item 2
        cout << "p: ";
        Person p(u);
        
        //TODO: 지역 변수 p와 객체를 공유하는 Person형의 참조 변수 r을 선언하고 초기화하라. 
        Person &r(p);

        cout << "p: "; p.println();         // r은 참조이고 u와 동일한 객체를 공유하므로
        cout << "r: "; r.println();         // 두 출력물은 동일한 객체를 출력함

        //TODO: 실행결과를 참고하여 참조 변수 r의 멤버 값들을 변경하라.
        r.set("r",2,80,false,"Seoul");
        //r 2 80 false :Seoul:

        cout << "p: "; p.println();
        cout << "r: "; r.println();

        //TODO: 실행결과를 참고하여 지역 객체 p의 멤버 값들을 변경하라.
        p.set("p",1,70,true,"Gwangju");
        //p 1 70 true :Gwangju:

        cout << "p: "; p.println();
        cout << "r: "; r.println();
        // r은 객체 p를 공유하는 참조이므로 함수 리턴 시 소멸자가 실행되지 않음
    }




    // 매개변수 a는 함수호출시 복사 생성자에 의해 복사되어 초기화됨; call by value로 매개변수를 선언하라.
    void function_argument( Person a/* TODO: 매개변수 a 선언; [교재 예제 5-12] 참조 */ ) { // Menu item 3-1
        cout << "a: "; a.println();
        cout << "a.setName(a)" << endl;
        a.setName("a");
        cout << "a: "; a.println();
    }

    Person return_member_object() { // Menu item 3-2
        //TODO: u 객체를 반환함 (여기서는 임시 객체에 복사됨); [교재 예제 5-12] 참조
        return u;
    }

    void implicitCopyConstructor() { // Menu item 3
        cout << "u: "; u.println();
        cout << "\nimplicit copy constructor 1: operator =" << endl;
        cout << "Person p = u" << endl;
        cout << "p: ";
        
        //TODO: 새로운 Person 객체 p를 선언하고 객체 u를 p에 대입하여 초기화하라.(묵시적 복사생성자를 호출) [교재 예제 5-12] 참조
        Person p = u;
        
        cout << "p.setName(p)" << endl;
        p.setName("p");
        cout << "p: "; p.println();

        cout << "\nimplicit copy constructor 2: function argument" << endl;
        cout << "call function_argument(u)" << endl;
        
        // 묵시적으로 복사 생성자를 호출하여 함수 인자를 복사하여 함수의 매개변수 a에 넘김
        function_argument(u); 
        cout << "function_argument(u) returned" << endl;

        cout << "\nimplicit copy constructor 3: return object" << endl;
        cout << "call return_member_object().println()" << endl;
        return_member_object().println();
          // return_member_object()의 리턴 값을 복사생성자에 의해 임시객체(이름 없는 지역변수)에 복사하고
          // 그 임시 객체의 println()을 호출하여 객체를 출력한다.
          // 출력 후 더 이상 그 임시 객체가 필요 없기 때문에 소멸자를 호출하여 바로 임시 객체를 소멸시킴
        cout << "return_member_object() returned" << endl;
    }

    Person return_local_object() { // Menu item 4-1
        Person pL("pL", 0, 70, true, "Gwangju Nam-gu");
        cout << "return_local_object() returns pL" << endl;
        return pL;
        // 정석대로 하면 리턴하기 전에 복사생성자를 호출하여 지역 객체 pL를 복사해 준 후 
        // 리턴 직전에 pL를 소멸해야 한다.
        // 그러나 컴파일러는 효율적인 실행을 위해 복사생성자와 소멸자를 호출하지 않고
        // 함수가 리턴한 후 return_local_object().println() 호출 시 
        // 함수의 지역 객체 pL의 메모리를 그대로 재사용한다. (소멸되지 않았으므로)
        // println() 실행 후 더 이상 객체가 필요 없으면 그제서야 소멸자를 호출하여 소멸시킴
    }

    Person return_temporary_object() { // Menu item 4-2
        cout << "return_temporary_object() returns Person(pT, 0, 70, true, Gwangju Nam-gu)" << endl;
        return Person("pT", 0, 70, true, "Gwangju Nam-gu"); // 임시 객체를 리턴함
        // return {"p", 0, 70, true, "Gwangju Nam-gu"}; // 위 문장과 동일한 기능임
        // 위 문장은 컴파일러가 함수의 리턴 타입을 참고하여 
        //   Person("p", 0, 70, true, "Gwangju Nam-gu")으로 자동 처리함
    }

    void temporaryObject() { // Menu item 4
        cout << "temporary object 1: Person(p0, 10, 70, true, Gwangju)" << endl;
        // 임시객체 생성 방법: 클래스이름(생성자 인자들)
        // 생성자 호출된 후 아래 문장이 끝나면 바로 소멸자가 호출됨
        // 주요: 임시 객체가 포함된 해당 문장의 실행이 종료되면 임시 객체는 소멸됨
        Person("p0", 10, 70, true, "Gwangju");

        cout << "\ntemporary object 2: Person(p1, 11, 60, false, Seoul).println()" << endl;
        // 임시객체: 생성자 호출, println() 호출, 소멸자 호출
        Person("p1", 11, 60, false, "Seoul").println();

        cout << "\nreturn_member_object().println()" << endl;
        return_member_object().println(); // 복사 생성자 활용
        cout << "return_member_object() returned" << endl;

        cout << "\nreturn_local_object().println()" << endl;
        return_local_object().println(); // 복사 생성자 사용하지 않음
        cout << "return_local_object() returned" << endl;

        cout << "\nPerson pL = return_local_object()" << endl;
        Person pL = return_local_object(); // 복사 생성자 활용
        cout << "return_local_object() returned" << endl;
        pL.println();

        cout << "\nreturn_temporary_object().println()" << endl;
        return_temporary_object().println();  // 생성자 활용
        cout << "return_temporary_object() returned" << endl;
        
        cout << "\nPerson pT = return_temporary_object()" << endl;
        Person pT = return_temporary_object();  // 생성자 활용
        cout << "return_temporary_object() returned" << endl;
        pT.println();
    }

    // TODO: 아래 함수 매개변수를 call by value가 되게 Person의 객체 p로 선언하라.
    void call_by_value( Person p ) { // Menu item 5-1: call by value: 복사생성자에 의해 복사됨
        cout << "p: "; p.println();
        cout << "u: "; u.println();
        cout << "p.set(p, 2, 80, false, Seoul)" << endl;
        p.set("p", 2, 80, false, "Seoul");
        cout << "p: "; p.println();      // p는 u과 다른 메모리를 사용하는 객체임
        cout << "u: "; u.println(); // u은 영향을 받지 않음
        // 함수 리턴 시 매개변수 p 객체의 소멸자 함수가 호출됨
    }

    // TODO: 아래 함수 매개변수를 call by reference가 되게 Person의 참조변수 p로 선언하라.
    void call_by_reference( Person &p/* TODO */ ) { // Menu item 5-2: call by reference
        cout << "p: "; p.println();   // p는 u의 참조이므로 u와 동일한 객체 메모리를 공유함
        cout << "u: "; u.println();
        cout << "p.set(p, 2, 80, false, Seoul)" << endl;
        p.set("p", 2, 80, false, "Seoul");
        cout << "p: "; p.println();   // p와 u은 동일한 객체 메모리를 공유하므로 항상 내용이 동일함
        cout << "u: "; u.println();
        u.assign(backup);
        // 매개변수 p는 참조이므로 함수 리턴 시 소멸자가 호출되지 않음
    }

    // TODO: 아래 함수 매개변수를 call by address가 되게 Person에 대한 포인터 변수 p로 선언하라.
    void call_by_address( Person *p/* TODO */ ) { // Menu item 5-3: call by address
        cout << "p: "; p->println();   // p는 u 메모리를 포인터하므로 동일한 내용이 출력됨
        cout << "u: "; u.println();
        cout << "p->set(p, 2, 80, false, Seoul)" << endl;
        p->set("p", 2, 80, false, "Seoul");
        cout << "p: "; p->println();   // p는 u 메모리를 포인터하므로 항상 동일한 내용이 출력됨
        cout << "u: "; u.println();
        u.assign(backup);       // u 값을 원래 값으로 복구
        // 매개변수 p는 포인터이므로 함수 리턴 시 소멸자가 호출되지 않음
    }

    void functionParameterType() { // Menu item 5
        cout << "call_by_value" << endl;
        // 함수 호출 시 복사생성자를 통해 u 객체를 매개변수 p에 복사
        // TODO: call_by_value(u)을 호출하되 멤버 객체 u을 인자로 넘겨 주어라.
        call_by_value(u);
        cout << endl;

        cout << "call_by_reference" << endl;
        // TODO: call_by_reference(u)을 호출하되 멤버 객체 u을 인자로 넘겨 주어라.
        call_by_reference(u);
        cout << endl; // 단순히 u의 참조만 전달됨

        cout << "call_by_address" << endl;
        // TODO: call_by_address(&u)을 호출하되 멤버 객체 u의 주소를 인자로 넘겨 주어라.
        call_by_address(&u);
        cout << endl; // 단순히 u의 주소값, 즉 포인터가 전달됨
    }

// TODO: 아래 주석(/* */)을 지우고 Person 객체를 리턴하도록 함수의 리턴 타입을 선언하라.
    Person return_value() {                   // return value
        return u;
    }

   void return_value_test() { // Menu item 6-1
        cout << "--- return_value_test() ---" << endl;
        cout << "call return_value()" << endl;
        cout << "p: ";

        //TODO: Person형 객체 변수 p를 선언하고 return_value()의 리턴 값으로 초기화하라.
        Person p = return_value();

        cout << "return_value() returned" << endl;
        cout << "p: "; p.println();
        cout << "p.set(p, 2, 80, false, Seoul)" << endl;
        p.set("p", 2, 80, false, "Seoul");
        cout << "p: "; p.println();        // 두 객체의 name은 다른 값임
        cout << "u: "; u.println();
        // 함수 리턴 시 지역변수 p 객체의 소멸자 함수가 호출됨
    }

// TODO: 아래 주석(/* */)을 지우고 
//       Person 객체의 참조를 리턴하도록 함수의 리턴 데이타 타입을 선언하라.
    Person& return_reference() {                  // return reference
        return u;
    }

    void return_reference_test() { // Menu item 6-2
        cout << "--- return_reference_test() ---" << endl;
        cout << "call return_reference()" << endl;
        cout << "p: ";

        //TODO: Person형 객체 변수 p를 선언하고 return_reference()의 리턴 값으로 초기화하라.
        Person p = return_reference();

        cout << "return_reference() returned" << endl;
        cout << "p.set(p, 2, 80, false, Seoul)" << endl;
        p.set("p", 2, 80, false, "Seoul");
        cout << "p: "; p.println();
        cout << "u: "; u.println();
        cout << endl;

        cout << "call return_reference()" << endl;

        //TODO: Person형 참조 변수 r를 선언하고 return_reference()의 리턴 값으로 초기화하라.

        Person &r = return_reference();// r는 리턴된 u의 참조를 저장하고 있는 참조변수임
        cout << "return_reference() returned" << endl;
        cout << "u: "; u.println();
        cout << "r.set(p, 2, 80, false, Seoul)" << endl;
        r.set("r", 2, 80, false, "Seoul");
        cout << "r: "; r.println();
        cout << "u: "; u.println();
        u.assign(backup);
        // 함수 리턴 시 지역 객체 p의 경우 소멸자 함수가 호출되지만
        //           참조 변수 r는 소멸자가 호출되지 않음
    }

// TODO: 아래 주석을 지우고 함수의 리턴 값을 참조하여 함수의 리턴 데이타 타입을 적절히 선언하라.
    Person* return_address() {                  // return address
        return &u;
    }

    void return_address_test() { // Menu item 6-3
        cout << "--- return_address_test() ---" << endl;
        cout << "call return_address()" << endl;

        //TODO: Person형 포인터 변수 p를 선언하고 return_address()의 리턴 값으로 초기화하라.
        Person *p = return_address();

        cout << "return_address() returned" << endl;
        cout << "p: "; p->println();
        cout << "u: "; u.println();
        cout << "p.set(p, 2, 80, false, Seoul)" << endl;
        p->set("p", 2, 80, false, "Seoul"); // p는 u 객체를 포인터하므로 u과 동일한 메모리를 공유함
        cout << "p: "; p->println();
        cout << "u: "; u.println();
        u.assign(backup);
        // 함수 리턴 시 p는 포인터 변수이므로 소멸자가 호출되지 않음
    }

    void returnDataType() { // Menu item 6
        return_value_test();        cout << endl;
        return_reference_test();    cout << endl;
        return_address_test();
    }

// 아래 함수를 CopyConstructor::run() 함수 앞쪽에 배치하고,
// CopyConstructor::run() 내의 func_arr[]에 아래 멤버 함수 주소를 추가하라.
//-----------------------------------------------------------------------------
    void inputPerson() { // Menu item 7
    	cout << "u: "; u.println();
        while (!UI::inputPerson(u)) ;  // USER 11 88 false :DONG-GU, DAEGU:
        backup.assign(u);
        cout << "u: "; u.println();
    }



    void run() {
        using CC = CopyConstructor;

        // TODO 문제 [3]: func_t, func_arr[], menuCount 선언

        string menuStr =
            "+++++++++ Reference And Copy Constructor Menu ++++++++++\n"
            "+ 0.Exit 1.ExplicitCopyConstructor 2.ReferenceVariable +\n"
            "+ 3.ImplicitCopyConstructor 4.TemporaryObject          +\n"
            "+ 5.FunctionParameterType 6.FunctionReturnType         +\n"
            "+ 7.inputPerson                                        +\n"
            "++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";

        // TODO 문제 [3]: while 문장 삽입하여 선택된 메뉴항목 실행하는 함수를 호출하라.
        using func_t = void (CopyConstructor::*)();
        func_t func_arr[] = {
            nullptr,&CC::explicitCopyConstructor,&CC::referenceVariable,//주소아니어도되는데?
            &CC::implicitCopyConstructor,&CC::temporaryObject,
            &CC::functionParameterType,&CC::returnDataType,
            &CC::inputPerson
            };
        int menuCount = sizeof(func_arr) / sizeof(func_arr[0]); // func_arr[] 길이
        while(true){
            int menuItem = UI::selectMenu(menuStr,menuCount);
            if( menuItem == 0 ) return;

            (this->*func_arr[menuItem])();// func_arr의 메뉴아이템 번째의 함수를 실행
        }

// using func_t = void (PersonManager::*)();
// using PM = PersonManager; // 코딩 길이를 줄이기 위해
// func_t func_arr[] = {
//     nullptr, &PM::display, &PM::append, &PM::clear, &PM::login,
// };
// int menuCount = sizeof(func_arr) / sizeof(func_arr[0]); // func_arr[] 길이
// string menuStr =
//     "====================== Person Management Menu ===================\n"
//     "= 0.Exit 1.Display 2.Append 3.Clear 4.Login(CurrentUser, ch4)   =\n"
//     "=================================================================\n";

// while (true) {
//     int menuItem = UI::selectMenu(menuStr, menuCount);
//     if (menuItem == 0) return;
//     (this->*func_arr[menuItem])();
// }
  }
}; // ch5_1: Reference and CopyConstructor



/******************************************************************************
 * ch5_2: AllocatedMember, new을 이용한 동적 메모리 할당한 멤버 취급
 ******************************************************************************/
class AllocatedMember
{
    Person  u;
    Memo    memo;

    void set_print_address(Person& p, const char* address) {
        cout << "p.setAddress(" << (address? address : "") << ")" << endl;
        p.setAddress(address);
        p.println();
        cout << endl;
    }
    void changeAddress() { // Menu Item 1
        Person p("p", 1, 70, true, "Gwangju");
        set_print_address(p, "short address");
        set_print_address(p, "middle length Address, Seoul");
        set_print_address(p, "long length Address Seoul Mapo-gu Korea");
        set_print_address(p, u.getAddress());
    }

        void print_memo(Person& p) { // 객체 p의 메모 출력
        cout << "------ " << p.getName() << " memo ------" << endl;
        const char *pmemo = p.getMemo();
        cout << (pmemo? pmemo : ""); // 메모 출력; nullptr이면 "" 출력
        cout << "--------------------" << endl << endl;
    }
    void set_print_memo(Person& p, const char* memo) { // 객체 p에 메모 복사하고 출력
        cout << "p.setMemo(memo)" << endl;
        p.setMemo(memo);
        print_memo(p);
    }
    void changeMemo() { // Menu Item 2
        Person p("p", 1, 70, true, "Gwangju");
        set_print_memo(p, "short memo\n");
        set_print_memo(p, "middle long memo: The Last of the Mohicans\n");
        set_print_memo(p, u.getMemo());
    }

    void manageMemo() { // Menu item 3
        memo.c_str(u.getMemo());
        memo.run();
        cout << "\nmemo.run() returned" << endl;
        u.setMemo(memo.c_str());   // 메모 메뉴에서 새로 삽입한 메모를 u에 저장 
        print_memo(u);
    }

        Person call_by_value_and_return_value(Person p) { // 복사생성자로 p 초기화
        cout << "p.setName(p)" << endl;
        p.setName("p");
        // 함수 리턴 전에 p를 p2에 복사해서 초기화(복사생성자)
        cout << "p2: ";
        return p; // 함수 리턴 시 p 소멸자 실행
    }

    void copyConstructor() { // Menu Item 4
        cout << "u: ";    u.println();
        print_memo(u);

        cout << "Person p1(u)" << endl;
        cout << "p1: ";
        Person p1(u); // 명시적 복사생성자로 p1 초기화
        p1.setName("p1");
        p1.println();
        print_memo(p1);

        cout << "Person p2 = call_by_value_and_return_value(p1)" << endl;
        // 묵시적으로 두번의 복사생성자 실행: 함수 인자를 넘길 때, 함수 리턴 값을 p2에 복사할 때
        cout << "p: ";
        Person p2 = call_by_value_and_return_value(p1);
        cout << "call_by_value_and_return_value(p1) returned\n" << endl;
        cout << "p2.setName(p2)" << endl;
        p2.setName("p2");
        p2.println();
        print_memo(p2);
        cout << "copyConstructor() returns" << endl;
        // 함수 리턴 시 지역객체 p1, p2 소멸자 실행됨
    }

    void nullptrMember() { // Menu Item 5
        u.println();
        print_memo(u);
        cout << "set address = memo_c_str = nullptr" << endl;
        u.setAddress(nullptr);
        u.setMemo(nullptr);
        u.println();
        print_memo(u);

        cout << "memo.c_str(u.getMemo())" << endl;
        memo.c_str(u.getMemo()); // u.getMemo() == nullptr이므로 memo의 mStr은 ""이다.
        memo.displayMemo();

        cout << endl << "u.setMemo(memo.c_str())" << endl;
        u.setMemo(memo.c_str()); // memo.get_c_str() == nullptr 이므로
                                      // u의 memo_c_str은 nullptr로 설정
        print_memo(u);
    }

    void inputPerson() { // Menu item 6
        cout << "u: "; u.println();
        while (!UI::inputPerson(u)) ;  // USER 11 88 false :DONG-GU, DAEGU:
        cout << "u: "; u.println();
    }

public:
    AllocatedMember():
        u("u", 1, 70, true, "NAMDAEMUN-RO 123, JONGNO-GU, SEOUL, KOREA") {
        u.setMemo("It is believed that the Aborigines of the American continent\n");//왜 줄바꿈이 없지 왜 없어도 통과되지
    }

    void run() {
        using AM = AllocatedMember;

        // TODO 문제 [1]: func_t, func_arr[], menuCount 선언
        using func_t = void (AllocatedMember::*)();
        func_t func_arr[] = {
            nullptr,&AM::changeAddress,&AM::changeMemo,&AM::manageMemo,
            &AM::copyConstructor,&AM::nullptrMember,&AM::inputPerson
        };
        int menuCount = sizeof(func_arr) / sizeof(func_arr[0]); // func_arr[] 길이

        string menuStr =
            "++++++++++++++++ Allocated Member Menu ++++++++++++++++\n"
            "+ 0.Exit 1.ChangeAddress 2.ChangeMemo 3.UsingMemoMenu +\n"
            "+ 4.CopyConstructor 5.NullptrMember 6.inputPerson     +\n"
            "+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";

        // TODO 문제 [1]: while 문장 삽입하여 선택된 메뉴항목 실행하는 함수 호출
    while (true) {
        int menuItem = UI::selectMenu(menuStr, menuCount);
        if (menuItem == 0) return;
        (this->*func_arr[menuItem])();
    }
        


  }
}; // ch5_2: AllocatedMember



/******************************************************************************
 * Main Menu
 ******************************************************************************/

class MainMenu
{
public:
    void run() {
        int menuCount = 5; // 상수 정의
        string menuStr =
"******************************* Main Menu *********************************\n"
"* 0.Exit 1.PersonManager(ch3_2, 4, 6)                                     *\n"
"* 2.Class:Object(ch3_1) 3.CopyConstructor(ch5_1) 4.AllocatedMember(ch5_2) *\n"
"***************************************************************************\n";

        while (true) {
            int menuItem = UI::selectMenu(menuStr, menuCount);
            if (menuItem == 0) break;

            switch(menuItem) {
            case 1: MultiManager().run();             break;
            case 2: ClassAndObject().run();           break;
            case 3: CopyConstructor().run();          break;
            case 4: AllocatedMember().run();          break;
            }
        }
        cout << "Good bye!!" << endl;
    }
}; // class MainMenu

/******************************************************************************
 * run() 함수
 ******************************************************************************/

void run() {
MainMenu().run();
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
    cout << boolalpha;  // 11장에서 배움; bool 타입 값을 0, 1 대신 true, false로 출력하도록 설정
    cin >> boolalpha;   // bool 타입 값을 0, 1 대신 true, false로 입력 받도록 설정

#if AUTOMATIC_ERROR_CHECK
    evaluate(true);   // 각 문제에 대해 단순히 O, X만 확인하고자 할 때는 false
#else
    run();
#endif
}