/******************************************************************/
// 아래 코드([문제 0] 앞까지)를 마킹하여 복사한 후 소스 파일에 삽입하라.
// #include <   > 사이의 공백은 컴파일 에러가 발생하니 제거해 주세요.
/******************************************************************/

#include <iostream>
#include <string>
#include <map>
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
 * template class
 ******************************************************************************/
// 템플릿 클래스를 위한 원본 클래스: 키(int)와 값(string)을 저장할 수 있는 사전
template<typename K, typename V>
class Dic {
    K keys[20];             // key 저장
    V values[20];        // value 저장
    int count;                // 삽입한 원소의 개수
    int getKeyIndex(K key); // key를 검색한 후 찾은 키의 인덱스를 반환

public:
    Dic();

    int size();                   // 삽입한 원소의 개수
    void clear();                 // 사전의 모든 원소 제거
    void insert(K key, V value);  // 사전에 (key, value) 쌍을 삽입
    bool search(K key, V &value); // 사전에서 key를 검색하여 상응하는 값을 찾아줌
    void display();               // 사전의 모든 원소를 출력함
};

template<typename K, typename V>
Dic<K,V>::Dic() { count = 0; }

template<typename K, typename V>
int Dic<K,V>::size() { return count; }

template<typename K, typename V>
void Dic<K,V>::clear() { count = 0; }  // 사전의 모든 원소 제거

// key를 검색한 후 찾은 키의 인덱스를 반환; 찾지 못하면 -1 반환
template<typename K, typename V>
int Dic<K,V>::getKeyIndex(K key) {
    for (int i = 0; i < count; ++i)
        if (keys[i] == key) return i;
    return -1;
}

template<typename K, typename V>
void Dic<K,V>::insert(K key, V value)  { // 사전에 (key, value) 쌍을 삽입
    int i = getKeyIndex(key);
    if (i < 0) {                // 기존의 키가 존재하지 않을 경우 추가
        keys[count]   = key;
        values[count] = value;
        count++;
    }
    else
        values[i] = value;      // 기존의 키가 존재할 경우 값만 수정
}

// 사전에서 key를 검색하여 상응하는 값을 찾아주고  key가 존재하지 않을 경우 false 반환
template<typename K, typename V>
bool Dic<K,V>::search(K key, V &value) {
    int i = getKeyIndex(key);
    if (i < 0) return false;
    value = values[i];
    return true;
}

template<typename K, typename V>
void Dic<K,V>::display() { // 사전의 모든 원소를 출력함
    cout << "dic: size(" << count << ")" << endl;  // insert()한 횟수
    for (int i = 0; i < count; ++i)
        cout << "(" << keys[i] << "," << values[i] << ") ";
    cout << endl;
}

/******************************************************************************
 * template function
 ******************************************************************************/
// 템플릿 함수를 위한 원본 함수: 사전 dic에서 key를 검색하여 상응하는 값을 출력함
template<typename K, typename V>
void find(Dic<K,V>& dic, K key) {
    V value;
    if (dic.search(key, value))
        cout << "found(key,value): (" << key << "," << value << ")" << endl;
    else
        cout << "not found(key)  : (" << key << ")" << endl;
}

/******************************************************************************
 * Test
 ******************************************************************************/
// DicIntStr dicS; // 키가 int, 값이 string인 사전
Dic<int, string> dicS; // 키가 int, 값이 string인 사전
Dic<string, int> dicI; // 키가 string, 값이 int인 사전

void templateClass() {
    cout << endl << "Dic< int, string >" << endl;
    dicS.clear(); // 사전의 모든 원소를 제거함
    for (int i = 0, key = rnd.getInt(); i < RAND_COUNT; ++i, key = rnd.getInt())
        dicS.insert(key, "V"+to_string(key));
        // rnd.getInt(): [0, 9] 범위의 난수 발생
        // to_string(key): 정수 key 50을 문자열(string) "50"으로 변환해 주는 함수이다.
    dicS.display(); // 사전의 내용을 모두 출력함
    cout << endl << "Dic< string, int >" << endl;
    dicI.clear();
    for (int i = 0; i < RAND_COUNT; ++i) {
        int key = rnd.getInt();
        dicI.insert("K"+ to_string(key), key);
    }
    dicI.display();
}

void templateFunction() {
    cout << endl << "find Dic< int, string >" << endl;
    find(dicS, rnd.getInt()); // rnd.getInt(): [0, 9] 범위의 난수 발생
    find(dicS, rnd.getInt());
    cout << endl << "find Dic< string, int >" << endl;
    find(dicI, "K"+to_string(rnd.getInt()));
    find(dicI, "K"+to_string(rnd.getInt()));
}

/******************************************************************************
 * main() 함수
 ******************************************************************************/
int main()
{
    string menuStr =
        "------------------- Template ------------------\n"
        "  0.exit 1.template_class 2.template_function  \n"
        "-----------------------------------------------\n"
        "menu item? ";

    rnd.setSeed(); // 난수 발생을 위한 seed 값 설정

    while (true) {
        int menu;
        cout << menuStr;
        cin >> menu;
        if (menu == 0) break;

        switch (menu) {
            case 1: templateClass();    break;
            case 2: templateFunction(); break;
        }
        cout << endl;
    }
    cout << "\nGood bye!!" << endl;
}
