#include <iostream>
using namespace std;

class rect{
    double width;
    double height;

    public:
    void area(){
        cout<<width*height;
    }
};
int main() {

rect r1;

r1.area();

    return 0;
}
