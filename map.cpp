#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
/*
iterator에 + 연산은 벡터만 지원됨
*/
int main(){

map<string,int> student_num;
student_num.insert({"um",10});
student_num["um"] = 3;
student_num["lee"] = 50;
student_num[""] = 999;
// cout<<student_num["um"];
// string s = "";
// if( student_num.find(s) != student_num.end() ){
//     cout<<"OK "<<s<<"'s number is "<<student_num.at(s);
// }else
//     cout<<"not found";

for( auto& p : student_num ){
    cout<<p.first<<" "<<p.second<<"\n";
    p.second += 1;
}
// for_each(student_num.begin(), student_num.end(), [](const auto& pair) { cout << pair.first << ": " << pair.second <<"\n"; });




    return 0;
}