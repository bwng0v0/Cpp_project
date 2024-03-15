//https://www.acmicpc.net/problem/1343 폴리오미노
#include <iostream>
using namespace std;

int main(){

int is_possible=1;
string str;
cin>>str;

for( int i=0; i<str.length(); i++ ){
    if( str.find("XXXX")==str.npos && str.find("XX")==str.npos && !(str.find("X")==str.npos) ){
        is_possible = 0;
        break;
    }

    if( !(str.find("XXXX")==str.npos) ){
        int index = str.find("XXXX");
        str[index] = 'A';
        str[index+1] = 'A';
        str[index+2] = 'A';
        str[index+3] = 'A';
    }else
    if( !(str.find("XX")==str.npos) ){
        int index = str.find("XX");
        str[index] = 'B';
        str[index+1] = 'B';
    }

}


if( is_possible == 1 )
cout<<str;
else
cout<<-1;


    return 0;
}