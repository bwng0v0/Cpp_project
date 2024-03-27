//https://www.acmicpc.net/problem/10992 별 찍기 - 17
#include <iostream>
int main(){
    int n;
    std::cin>>n;
    int air = n-1;
    int star = 1;

    for(int i=0; i<n; i++){
        for(int j=0; j<air; j++){
        std::cout<<' ';
        }
        for(int j=0; j<star; j++){
            if( j==0 || j==star-1 || i==n-1 ){
                std::cout<<'*';
            }else{
                std::cout<<' ';
            }
        }

    
    air -= 1;
    star += 2;
    std::cout<<'\n';
    }
    return 0;
}