#include <iostream>
using namespace std;
int main(){

int n;
cin>>n;
int *arr = new int[n];
int *arr2 = new int[n] {};

for(int i=0; i<n; i++)
cin>>arr[i];

for(int i=0; i<n; i++)
cout<<arr[i]<<' ';

cout<<'\n';

for(int i=0; i<n; i++)
cout<<arr2[i]<<' ';

delete[] arr;
delete[] arr2;

    return 0;
}