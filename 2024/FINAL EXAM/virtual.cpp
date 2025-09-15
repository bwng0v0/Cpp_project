#include <iostream>
using namespace std;

class speeker{
    public:
    virtual void hello();
    virtual void a() = 0;
};
class MEGAspeeker : public speeker {
    public:
    void hello() override{
        cout<<"mega: hello\n";
    }
    void a() override{
        cout<<"A";
    }
};

int main(){

MEGAspeeker m;

    return 0;
}