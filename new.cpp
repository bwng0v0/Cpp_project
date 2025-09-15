// 오늘 문제 풀 파일 만들어주는 프로그램
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <filesystem>
using namespace std;

int main() {
    // 현재 시간을 얻기 위해 시스템 시간을 사용합니다.
    auto now = chrono::system_clock::now();
    // 시간을 time_t 형식으로 변환합니다.
    time_t now_c = chrono::system_clock::to_time_t(now);
    // time_t를 tm 구조체로 변환하여 로컬 시간을 얻습니다.
    tm* local_time = localtime(&now_c);

    // yyyy.m.d 형태의 문자열 만들기
    string date = to_string(local_time->tm_year + 1900) + "." 
                + to_string(local_time->tm_mon + 1) + "." 
                + to_string(local_time->tm_mday);

    // 기본 파일 이름
    string baseName = "GOODTIME/" + date;
    string fileName = baseName + ".cpp";

    // 같은 날짜 파일이 이미 있으면 -1, -2 붙여서 새 이름 찾기
    int idx = 1;
    while (filesystem::exists(fileName)) {
        fileName = baseName + "-" + to_string(idx++) + ".cpp";
    }

    // 파일 생성
    ofstream outputFile(fileName);
    ifstream inputFile("setting.cpp");

    if (inputFile.is_open() && outputFile.is_open()) {
        outputFile << inputFile.rdbuf();
        cout << "오늘도 화이팅! 파일 이름: " << fileName << "\n";
    } else {
        cout << "어 파일이 안열려요\n";
    }

    return 0;
}
