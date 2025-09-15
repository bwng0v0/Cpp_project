#include <iostream>
#include <string>
using namespace std;

class Person
{
    string name;
    int    id;
    double weight;
    bool   married;

public:
    Person():name{"no-name"},id{0},weight{0},married{0} { cout<<"Person::Person():";println(); }
    ~Person(){
        cout<<"Person::~Person():"; println();
    }
    Person(string name, int id, double weight, bool married){
    setName(name);
    setId(id);
    setWeight(weight);
    setMarried(married);
    cout<<"Person::Person(...):";println();
    }
    void setName(string _name){name = _name;}
    void setId(int _id){ id = _id; }
    void setWeight(double _weight){ weight = _weight; }
    void setMarried(bool _married){ married = _married; }
    void println(){
        //name:p1, id:1001, weight:72.5, married:true
        cout<<"name:"<<name<<", id:"<<id<<", weight:"<<weight<<", married:"<<married<<"\n";
    }
    string getName(){return name;}
    int getId(){return id;}
    double getWeight(){return weight;}
    bool getMarried(){return married;}
};
void set(string name, int id, double weight, bool married) {
    Person p1;
    p1.setName(name);
    p1.setId(id);
    p1.setWeight(weight);
    p1.setMarried(married);
    p1.println();
}
void creator() {
    cout << "creator() begin" << endl;
    Person p2("p2", 1002, 60.5, false);
    cout << "creator() return" << endl;
}

int main() {
    cin >> boolalpha;
    cout << boolalpha;
    // 위 두 문장은 married의 값을 1, 0이 아닌 true, false로 입력 받고 출력하기 위함 

    string name = "p1";
    int id = 1001;
    double weight = 72.5;
    bool married = true;

    
    set(name, id, weight, married);
    cout << endl;
    creator();

    cout << endl;

    cout << "name id weight married? ";
    cin >> name >> id >> weight >> married;
    Person p3(name, id, weight, married);

    cout << "output name:" << p3.getName() << ", id:" << p3.getId() << ", weight:" <<
    p3.getWeight() << ", married:" << p3.getMarried() << endl;

}