#include <iostream>
using namespace std;

int main(){

cout<<"| 메뉴 : 1. 아메리카노(1000), 2. 라떼(2000), 3. 에스프레소(500) |\n";
cout<<"> 금액을 넣어주세요. : ";
int m; cin>>m;
int arr[3] = {0,0,0};

while( m>=500 ){
cout<<"| 메뉴 : ";
if( m >=1000 ){ cout<<"1. 아메리카노(1000), "; }
if( m >=2000 ){ cout<<"2. 라떼(2000), "; }
if( m >=500 ){ cout<<"3. 에스프레소(500), "; }
cout<<"0. 잔돈반환("<<m<<") |\n"<<"> 메뉴를 입력해 주세요. : ";

int input; cin>>input;
if( input < 0 || input > 3 ){ cout<<"| 잘못된 입력입니다. 다시 입력해주세요. |\n"; continue; }
if( input==0 ) break;
else if( input == 1 && m>=1000 ){
    arr[0] += 1; m-=1000;
}else if( input == 2 && m>=2000 ){
    arr[1] += 1; m-= 2000;
}else if( input == 3 && m>=500 ){
    arr[2] += 1; m-= 500;
}
else
cout<<"| 금액이 부족합니다. |\n";
}

printf("| 총 메뉴 : 아메리카노(%d), 라떼(%d), 에스프레소(%d) |\n",arr[0],arr[1],arr[2]);
printf("| 잔돈 %d원이 반환되었습니다. |",m);


    return 0;
}