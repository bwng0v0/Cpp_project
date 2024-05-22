//오늘 문제 풀 파일 만들어주는 프로그램
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <filesystem>
#include <iterator>
using namespace std;

int main(){

// 현재 시간을 얻기 위해 시스템 시간을 사용합니다.
auto now = chrono::system_clock::now();
// 시간을 time_t 형식으로 변환합니다.
time_t now_c = chrono::system_clock::to_time_t(now);
// time_t를 tm 구조체로 변환하여 로컬 시간을 얻습니다.
tm* local_time = localtime(&now_c);

string date = to_string((local_time->tm_mon + 1)) + "." + to_string(local_time->tm_mday);

if( filesystem::exists("GOODTIME/"+date+".cpp") ){
    //같은이름의 파일이 이미 존재한다면
    ofstream outputFile("GOODTIME/"+date+".cpp",ios::app);
    cout<<"파일이 이미 있는데요? 아무튼 오늘도 화이팅!\n";
}else{
    //파일이 없다면
    ofstream outputFile("GOODTIME/"+date+".cpp",ios::app);
    ifstream inputFile("setting.cpp");
    if( inputFile.is_open() && outputFile.is_open() ){
        outputFile << inputFile.rdbuf();
        cout<<"오늘도 화이팅!\n";
    }else cout<<"어 파일이 안열려요\n";
}


    return 0;
}