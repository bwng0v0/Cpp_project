#include <iostream>
#include <string>
using namespace std;

/******************************************************************************
 * class Cal
 ******************************************************************************/

class Cal {
    int x;
    int y;
    static int count;
    public:
    static void print_count(){
        cout<<"\ntotal count: "<<count<<"\n\n";
    }
    Cal(int x=100, int y=200): x{x},y{y} {
        //cout<<"Cal::Cal(100, 200)";
        printf("Cal::Cal(%d, %d)\n",x,y);
        count += 1;
    }
    ~Cal(){
        printf("Cal::~Cal(): x=%d, y=%d\n",x,y);
        count -= 1;
    }
    int add(){
        return x+y;
    }
    int add(int x){
        return x+y;
    }
    int add(int x,int y){
        return x+y;
    }
};
int Cal::count = 0; 
/******************************************************************************
 * Global functions
 ******************************************************************************/

void function_overload(int x, int y){
    Cal c1(100, 200);
    cout << "c1.add(): " << c1.add() << endl;
    cout << "c1.add(" << x << "): " << c1.add(x) << endl;
    cout << "c1.add(" << x << ", " << y << "): " << c1.add(x, y) << endl;
}

void default_parameter(int x, int y){
    Cal *c1 = new Cal();
    cout << "c1->add(): " << c1->add() << endl << endl;

    Cal *c2 = new Cal(x);
    cout << "c2->add(): " << c2->add() << endl << endl;

    Cal *c3 = new Cal(x, y);
    cout << "c3->add(): " << c3->add() << endl << endl;
    Cal::print_count();
    Cal *cal = new Cal[5]; //TODO: 원소 5개를 가진 Cal 배열을 동적으로 할당하라.
    Cal::print_count();

    //TODO 1: 실행결과를 보고 여기에 필요한 코드를 더 추가하라.
    delete c2;
    delete c3;
    delete c1;
    Cal::print_count();
    //TODO: 동적으로 할당 받은 배열 cal의 메모리를 반납하라.
    delete[] cal;
    Cal::print_count();
}

void printXY(int x=0, int y=0)
{
    cout << "x, y: " << x << ", " << y << endl;
}

/* 함수호출시 넘겨 준 main()의 원본 인자 값이 수정되도록 매개변수 선언을 적절히 수정하라.*/
void inputXY(int &x, int &y)
{
    /* 여기서 "x and y? "를 출력하고
       x, y 값을 입력 받는 코드를 삽입하라. */
    cout<<"x and y? ";cin>>x>>y;
    printXY(x, y);
}

string menuStr =
"************************* Main Menu ************************\n"
"* 0.Exit 1.function_overload 2.default_parameter 3.inputXY *\n"
"************************************************************\n";

int main() {
    int x = 10, y = 20;

    while (true) {
        int menuItem;
        cout << endl << menuStr << "menu? ";
        cin >> menuItem;
        if (menuItem == 0)
            break;
        switch(menuItem) {
        case 1: function_overload(x, y); break;
        case 2: default_parameter(x, y); break;
        case 3: inputXY(x, y);
                cout << "X, Y: " << x << ", " << y  << endl;
                printXY(x);
                printXY();
                break;
        }
    }
    cout << "Good bye!!" << endl;
}