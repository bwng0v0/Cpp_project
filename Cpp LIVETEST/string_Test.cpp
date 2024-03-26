#include <iostream>
#include <algorithm>
using namespace std;
int main(){

string arr[3];

arr[0] = "ABC";
arr[1] = "CDE";
arr[2] = "AHDSFWEFKSDANFJADF";

sort(arr[3].begin(),arr[3].end());//아니 스트링도 정렬해준다고?

for( string s : arr )
cout<<s<<'\n';

    return 0;
}