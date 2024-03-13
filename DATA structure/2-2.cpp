#include <iostream>
double fun( double N, double K, double num ){
    
if( N==K ){
    return 1/N+num;
}else{
    return fun(N,K+1,num+1/K);
}

}
int main(){

double N;
std::cin>>N;
std::cout<<fun(N,1,0);

    return 0;
}