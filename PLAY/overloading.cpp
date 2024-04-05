#include <iostream>
using namespace std;

static int asdf;

class person{
    public:
    string name;
    int old;
    
    person(string nm, int old): name{nm}, old{old} {
        
    }

    void self(){
        cout<<name<<" "<<old;
    }
};

void df( double a, int b){
    cout<<1;
}
void df( int a, int b, int c=99){
    cout<<2;
}
int main(){

df(1,2);


cout<<(double)3;

    return 0;
}