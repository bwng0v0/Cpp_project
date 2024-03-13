#include <iostream>

int main(){

int n, sum{0};
std::cin>>n;

for ( int i=n; i>=1; i-- ){
    sum += i;
}

std::cout<<sum;

    return 0;
}