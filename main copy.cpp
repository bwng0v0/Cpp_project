#include <iostream>
using namespace std;

class hello{
    public:
    int data;
    void say(){
        cout<<this->data<<"hello!\n";
    }
    static void staticsay(hello &hl){
        cout<<hl.data<<"static hello!\n";
        hl.data = 1234;
        hl.say();
    }
};
int main(){
using h = void (hello::*)();

hello h1;
h1.say();

hello::staticsay(h1);





    return 0;
}