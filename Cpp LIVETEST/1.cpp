//문자열 검색변환 반복 무조건나온다
#include <iostream>
using namespace std;
int main(){

string s = "asdf asdf asdf qwer asdf hello qwer asdf hello hello asdf";

//모두 변환
string f; cin>>f;
string rp; cin>>rp;

int index;
while( s.find(f) != string::npos ){
    index = s.find(f);//대상 시작인덱스 저장
    s.erase(index,f.size());//대상 시작인덱스부터 대상 길이만큼 삭제
    //erase (인덱스 삭제개수)
    s.insert(index,rp);//대상 시작인덱스 자리에 대체문자열 삽입
    //insert (인덱스 삽입문자열)
}

cout<<s;


    return 0;
}