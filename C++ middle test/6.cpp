#include <iostream>
#include <string>
using namespace std;

struct Infofood {
    string food;
    int calories;
};
class CalFood {
public:
	static struct Infofood food[100];

	static int totalCalories;
	static void addFood(Infofood _eatfood);
	static void printTotalCalories();
	static int cnt;
};
int CalFood::totalCalories = 0;
int CalFood::cnt = 0;
struct Infofood CalFood::food[100];

void CalFood::addFood(struct Infofood _eatfood) {
	food[cnt] = _eatfood;
	cnt += 1;
	totalCalories += _eatfood.calories;
}
class Person {
	struct Infofood food;
public:
	void setfood(struct Infofood eatfood){
		food = eatfood;
		CalFood::addFood(eatfood);
	}
};

void CalFood::printTotalCalories() {
    int i = 0;
    cout << "************* 누적된 칼로리 *************\n";
    cout << "지금 까지 먹은 음식 : ";
    while (i < cnt) {
        cout << food[i].food << " ";
        i++;
    }
    cout << endl;
    cout << "총 칼로리: " << totalCalories << " kcal" << endl;
    cout << endl;
}


int main() {
    Person human[3];
    int i = 0;

    while (i < 3) {
        Infofood eatfood;
        cin >> eatfood.food >> eatfood.calories;
        human[i].setfood(eatfood);
        i++;
    }
    CalFood::printTotalCalories();
}
