// hyundai kia genesis에서 하나를 선택하고, 선택한 브랜드의 차 라인업에서 차를 선택하는 코드다.
// hyundai, kia, genesis class는 전부 hyundai_kia class에서 상속 받았다. 
// 입출력 예시와 main 함수를 보고 hyundai_kia class, hyundai class, kia class, genesis class를 구현하라.

//입출력 예시 1
//(출력)Avante Sonata Grandeur
//(출력)Soul Niro Sportage Sorento Stinger
//(출력)g70 g80 g90 gv70 gv80
//(출력)
//(출력)hyundai kia or genesis ?
//(입력)genesis
//(출력)g70 g80 g90 gv70 gv80 ? 
//(입력)gv70
//(출력)car available

//입출력 예시 2
//(출력)Avante Sonata Grandeur
//(출력)Soul Niro Sportage Sorento Stinger
//(출력)g70 g80 g90 gv70 gv80
//(출력)
//(출력)hyundai kia or genesis ?
//(입력)hyundai
//(출력)Avante Sonata Grandeur ?
//(입력)Elantra
//(출력)car unavailable

#include <iostream>
#include <string>
using namespace std;

// ... 여기에 코드 작성
class hyundai_kia{
    public:
    virtual string lineup() = 0;
    string find(string s){
        if( lineup().find(s) != string::npos )
            return "car available";
        else
            return "car unavailable";
    }
};
class hyundai : public hyundai_kia{
    public:
    string lineup() override{
        return "Avante Sonata Grandeur";
    }
};
class kia : public hyundai_kia{
    public:
    string lineup() override{
        return "Soul Niro Sportage Sorento Stinger";
    }
};
class genesis : public hyundai_kia{
    public:
    string lineup() override{
        return "g70 g80 g90 gv70 gv80";
    }
};

//아래 main 함수는 수정 불가...
int main()
{
	//string test = "abc xyz"; //여기저기 힌트가 있다.
	//cout << test.find("abc") << " " << test.find("xyz") << " " <<  test.find("abcd") << endl;
	hyundai myhyundai;
	kia mykia;
	genesis mygenesis;
	cout << myhyundai.lineup() << endl; //"Avante Sonata Grandeur" 출력
	cout << mykia.lineup() << endl;     //"Soul Niro Sportage Sorento Stinger" 출력
	cout << mygenesis.lineup() << endl; //"g70 g80 g90 gv70 gv80" 출력
	cout << endl;

	string choice;
	hyundai_kia* ptr=0;
	cout << "hyundai kia or genesis? " << endl; //브랜드 choice에 따라서 동적 객체 생성 
	cin >> choice;
	if ( choice == "hyundai") {
		ptr = new hyundai;
	}
	else if (choice == "kia") {
		ptr = new kia;
	}
	else if (choice == "genesis") {
		ptr = new genesis;
	}
	else {
		cout << "not found" << endl;
	}
	if (ptr != 0) {
		cout << ptr->lineup() << "?" << endl;//브랜드 choice에 따라서 생성된 클라스의 자동차 lineup
		cin >> choice; //차 choice
		cout << ptr->find(choice) << endl;
		//차 choice가 lineup에 있으면 "car available"출력, 없으면 "car unavailable" 출력
		//힌트: lineup() 반환 값을 string에 넣어서 사용할수 있다
	}

	delete ptr;
	return 0;
}