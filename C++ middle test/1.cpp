#include <iostream>
#include <string>
using namespace std;


class Student{
	string s_name;
	string s_dept;
	int s_id;
public:
	Student(): s_name{"김조선"}, s_dept{"컴퓨터공학과"}, s_id{11111111} {
		cout<<"id: "<<s_id<<" 학생객체 생성\n";
	}
	Student(string name, string ma, int id): s_name{name}, s_dept{ma}, s_id{id} {
		cout<<"id: "<<s_id<<" 학생객체 생성\n";
	}
	~Student(){
		//id: 22222222 학생객체 소멸
		cout<<"id: "<<s_id<<" 학생객체 소멸\n";
	}
	void showInfo(){
		//학과: 컴퓨터공학과, 학번: 11111111, 이름: 김조선
		cout<<"학과: "<<s_dept<<", 학번: "<<s_id<<", 이름: "<<s_name<<"\n";
	}
	int getId(){
		return s_id;
	}
	double calScore(){
		cout<<"c++, 파이썬, 자바 점수를 입력하시오>> ";
		double a,b,c; cin>>a>>b>>c;
		return (a+b+c)/3;
	}
};


int main() {
    string name, major;
    int id;
    double score;

    //기본생성자 호출하여 객체 생성
    Student s1;

    s1.showInfo();
    score = s1.calScore();
    cout << "학번 " << s1.getId() << "의 세 과목 평균점수는 " << score << "입니다" << endl;

    //이름,학과, 학번을 입력받아, 매개변수 있는 생성자 호출하여 객체 생성
    cout << "이름, 학과, 학번을 입력하시오>> ";
    cin >> name >> major >> id;
    Student s2(name, major, id);
    s2.showInfo();
    score = s2.calScore();
    cout << "학번 " << s2.getId() << "의 세 과목 평균점수는 " << score << "입니다" << endl;
}