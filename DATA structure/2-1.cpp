#include <iostream>
int fun( int N, int K, int num ){
    
if( N==K ){
    return N+num;
}else{
    return fun(N,K+1,num+K);
}

}
int main(){

int N;
std::cin>>N;
std::cout<<fun(N,1,0);

    return 0;
}