// police_record class에는 password로만 접근 가능한 경찰 정보가 있다.
// 구현해야하는 public_record는 police_record에서 상속 받으며 추가 공개 정보 name과 age가 있다
// main 함수 및 police_record를 확인하여 다음과 같은 입출력이 나오게 public_record class를 구현하라.

//(출력)이름: MikeTyson 나이: 19
//(출력)
//(출력)이름: MikeTyson 나이: 19
//(출력)전과기록 11건
//(출력)
//(출력)이름: MikeTyson 나이: 19
//(출력)경찰기록 접근 거부
//(출력)
//(출력)-1
//(출력)전과기록 11건
//(출력)경찰기록 접근 거부
//(출력)
//(출력)password prev_conviction name age 순으로 입력
//(입력)1245 0 Lennox 33
//(출력)password 입력
//(입력)1245
//(출력)이름: Lennox 나이: 33
//(출력)전과기록 0건


#include <iostream>
#include <string>
using namespace std;


class police_record { //경찰기록 class
	string password;
	int prev_conviction; //전과 기록
public:
	police_record(string password="0000", int convictions = 0) {
		this->password = password; // password 지정함
		prev_conviction = convictions; //전과 기록
	}
	int check_conviction(string password) {//전과기록 열람..
		if (this->password == password) {
			return prev_conviction; // password가 맞으면 전과 기록을 반환한다
		}
		return -1; // password가 틀리면 -1을 반환
	}
};
//위 police_record class는 수정 불가 

//공개정보 클라스 public_record를 police_record에게 상속 받아서 구현하라
//public_record의 멤버 변수는 string name, int age(나이)이고 추가 멤버 변수를 지정하면 0점 처리 됨니다. 
//전역변수 static변수도 사용 금지.

// ..........여기에 public_record 클라스 정의............
class public_record : public police_record {
    string name;
    int age;
    public:
    public_record(string p, int c, string n, int a): police_record(p,c), name{n}, age{a} {}

    void print_data(string s = ""){
        cout<<"이름: "<<name<<" 나이: "<<age<<"\n";
        int res = police_record::check_conviction(s);
        if( res != -1 )
            cout<<"전과기록 "<<res<<"건\n";
        else if( s != "" )
            cout<<"경찰기록 접근 거부\n";
    }
    void check_conviction(string s){
        int res = police_record::check_conviction(s);
        if( res != -1 )
            cout<<"전과기록 "<<res<<"건\n";
        else
            cout<<"경찰기록 접근 거부\n";
    }
};

//아래 main 함수는 수정 불가...
int main()
{
	//힌트: 기본 클라스와 파생 클라스의 생성자 호출은 어떻게 지정해줄수 있을까?
	public_record citizen1("qwert", 11, "MikeTyson", 19);  //password, prev_conviction, name, age순으로 입력된다.
	//아래 힌트:print_data는 함수 중복일까 아니면 디폴트 값을 사용할까?
	citizen1.print_data(); // 공개정보 이름 나이만 출력
	cout << endl;
	citizen1.print_data("qwert"); // password가 일치하면 이름 나이 전과기록도 출력 
        //(힌트: string에는 여러가지 연산자 중복이 있다)
	cout << endl;
	citizen1.print_data("qxert"); // password가 불일치하면 경찰기록은 접근 거부 출력
	cout << endl;
	//(아래 check_conviction 힌트 1: 기본 파생 클라스의 함수 중복은 어떻게 작동할까?)
	//(아래 check_conviction 힌트 2: police_record의 check_conviction함수는 아래와 같이 호출가능하다
	cout << citizen1.police_record::check_conviction("0000")<< endl; 
	citizen1.check_conviction("qwert");//password가 일치하면 전과기록만 출력한다 
	citizen1.check_conviction("xyzabc");//password가 불일치하면 경찰기록 접근 거부가 출력된다
	cout << endl;

	cout << "password prev_conviction name age 순으로 입력" << endl;
	string password, name;
	int convictions, age;
	cin >> password >> convictions >> name >> age;
	public_record boxer(password, convictions, name, age);
	cout << "password 입력" << endl;
	cin >> password;
	boxer.print_data(password);
	return 0;
}