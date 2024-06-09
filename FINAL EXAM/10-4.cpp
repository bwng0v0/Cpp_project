/******************************************************************/
// 아래 코드([문제 0] 앞까지)를 마킹하여 복사한 후 소스 파일에 삽입하라.
// #include <   > 사이의 공백은 컴파일 에러가 발생하니 제거해 주세요.
/******************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
    
/******************************************************************************
 * Class Rand
 ******************************************************************************/
// 난수를 발생시키는 클래스: 이 클래스는 무시하고 넘어 가세요.
#include <random>

const int RAND_COUNT = 10;
int seed = 0;

class Rand {
    default_random_engine re;
    uniform_int_distribution< int > dist;
public:
    Rand(int low, int high): dist(low, high) { }
    int getInt() { return dist(re); }
    void setSeed(int s = 0) {
        seed = s;
        if (seed == 0) {
            cout << "seed for random number? ";
            cin >> seed;
        }
        re.seed(seed);
    }
};
Rand rnd(0, RAND_COUNT-1); // [0, RAND_COUNT-1] 범위의 난수 발생기


/******************************************************************************
 * Test
 ******************************************************************************/

void displayVector(vector<int>& v) { // vector의 모든 원소 출력함
    cout << "vector[size=" << v.size() << "]: ";

    // TODO: 벡터 v의 모든 원소를 출력하라.
    for( int a : v ) cout<<a<<" ";

    cout << endl;
}

void createVector(vector<int>& v) {  // 벡터에 RAND_COUNT개의 원소를 삽입하고 화면에 보여줌

    // TODO: RAND_COUNT개(10개)의 난수를 발생시켜 벡터 v에 추가하라.
    //       rnd.getInt()의 리턴 값이 난수이다.
    for( int i=0; i<10; i++ ){
        v.push_back(rnd.getInt());
    }

    displayVector(v);
}

void createVector() {
    vector< int > v;
    createVector(v);
}

void sortVector() {
    vector< int > v;
    createVector(v);

    // 벡터 v의 앞쪽  5개 원소들을 정렬하라.
    // 벡터 v의 마지막 5개 원소들을 정렬하라.
    sort(v.begin(),v.end()-5);
    sort(v.begin()+5,v. end());
    displayVector(v);
}

void displayMap(map< int, int >& m) { // map의 모든 원소를 출력함
    cout << "map[size=" << m.size() << "]: ";
    for (auto p : m)
        cout << "(" << p.first << "," << p.second << ") "; // (키,값)
    cout << endl;
}

void createMap(map<int,int>& m) {

    // TODO: RAND_COUNT개(10개)의 (키, 값) 쌍을 맵 m에 추가하라. 
    //       난수 발생 함수 rnd.getInt()를 이용하여 (키, 값) 쌍을 생성하라. 
    //       하나의 (키, 값) 생성 시 '키'를 먼저 생성하고 그 뒤에 '값'을 생성하라.(생성 순서 중요)
    for( int i=0; i<10; i++ ){
        int k = rnd.getInt(), v = rnd.getInt();
        // m.insert({k,v}); ??????????????
        m[k] = v;
    }

    displayMap(m);
}

void createMap() {
    map< int, int > m;
    createMap(m);
}

void findMap() {
    map< int, int > m;
    createMap(m);
    int key = rnd.getInt();
    
    // TODO: 맵 m에서 key를 검색한 후 해당 key를 
    //       찾았으면 아래 문장을 이용하여 상응하는 '값'을 출력하고 (아래 문장에서 '값' 대신 실제 값을 출력하라.)
    //           cout << "found(key,value): (" << key << "," << '값' << ")" << endl;
    //       찾지 못한 경우 아래 문장을 출력하라.
    if( m.find(key) != m.end() )
        cout<<"found(key,value): (" << key << "," << m.at(key) << ")" << endl;
    else
        cout << "not found(key)  : (" << key << ")" << endl;
}

void lambda_1() {
    vector< int > v;
    createVector(v);
    int value = rnd.getInt();
    cout << "added value: (" << value << ")" << endl;

    // TODO: 반드시 for_each() 문과 람다 함수를 이용하여 
    //       벡터 v의 각각의 원소에 위 지역변수 value를 더하라.
    // 주의: 람다 함수의 캡쳐리스트와 매개변수 타입에 주의하라. value or reference or pointer?
    //      for_each()와 람다 함수를 사용하지 않은 경우 0점 처리함
    for_each(v.begin(),v.end(),[value](int &a){a += value;});

    displayVector(v);
}

void lambda_2() {
    vector< int > v;
    createVector(v);
    int sum = 0;

    // TODO: 반드시 for_each() 문과 람다 함수를 이용하여 
    //       벡터 v의 모든 원소 값들의 합 sum을 구한 후 평균 값(실수)을 출력하라.
    // 주의: 람다 함수의 캡쳐리스트와 매개변수 타입에 주의하라. value or reference or pointer?
    //      for_each()와 람다 함수를 사용하지 않은 경우 0점 처리함
    // 평균 값(실수) 출력 시 아래 문장을 사용하라. 
    for_each(v.begin(),v.end(),[&sum](int x){sum += x;});
    
    cout << "average: " << sum*1.0/v.size() << endl; // 0.0 대신 실제 평균 값(실수)을 출력하라.
}

/******************************************************************************
 * main() 함수
 ******************************************************************************/
int main()
{
    string menuStr =
    "--------------- STL and Lambda -------------\n"
    "  0.exit 1.createVector 2.sort 3.createMap  \n"
    "  4.findMap 5.lambda-1 6.lambda-2           \n"
    "--------------------------------------------\n"
    "menu item? ";

    rnd.setSeed(); // 난수 발생을 위한 seed 값 설정
    
    while (true) {
        int menu;
        cout << menuStr;
        cin >> menu;
        if (menu == 0) break;

        switch (menu) {
        case 1: createVector(); break;
        case 2: sortVector();   break;
        case 3: createMap();    break;
        case 4: findMap();      break;
        case 5: lambda_1();     break;
        case 6: lambda_2();     break;
        }
        cout << endl;
    }
    cout << "\nGood bye!!" << endl;
}