#include <iostream>
#include <string>
using namespace std;

/******************************************************************************
 * class Container
 ******************************************************************************/

class Container {
    string title;  // 컨테이너 타이틀
    int size;   // 컨테이너에 저장된 정수 배열 arr의 크기
    int *arr;   // size 개의 원소를 가진 배열 시작 주소
public:
    Container(): arr{}, size{} {
    	cout<<"Container(): arr = nullptr; size = 0;\n";
    }
    ~Container(){
    	if( arr == nullptr )
    	cout<<"~Container(): "<<title<<"\n";
    	else
    	cout<<"~Container(): arr["<<size<<"] deleted;\n";
    }
    void setTitle(string title);
    string getTitle();
    void newArray();
    void average(){
    	double res = 0;
    	for( int i=0; i<size; i++ )
    		res += arr[i];
    	cout<<"average: "<<res/size<<"\n";
    }
    void rightRotateTitle(){
    	for( int i=0; i<title.size(); i++ ){
    		string tmp = title.substr(title.size()-1,1);
            title.resize(title.size()-1);
            title.insert(0,tmp);
    		cout<<title<<"\n";
    	}
    }
    void findDeleteTitle(){
        cout<<"word to delete? ";
        string tg; cin>>tg;
        while( title.find(tg) != string::npos ){
            int index = title.find(tg);
            title.erase(index,tg.size());
        }
        cout<<title<<"\n";
    }
    void newIntArray(){
    	cout<<"element numbers of int array[]? ";
    	cin>>size;
    	arr = new int[size];
    }
    void inputIntArray(){
    	cout<<"input "<<size<<" integers: ";
    	for( int i=0; i<size; i++ ){
    		cin>>arr[i];
    	}
    	cout<<"arr["<<size<<"]: ";
    	for( int i=0; i<size; i++ ){
    		cout<<arr[i]<<" ";
    	}
    	cout<<"\n";
    }
};


void Container::setTitle(string title) {
    /* 매개변수 title 값을 멤버 변수 title에 저장한다. */
	this->title = title;
}

string Container::getTitle() {
    return title;  /* 멤버변수 title을 반환하라. */
}

/******************************************************************************
 * Global functions
 ******************************************************************************/

void constructor() {
    Container c;
    c.setTitle("constructor-title");
    cout << "c.getTitle(): " << c.getTitle() << endl;
}

void intArray() {
    Container c;
    c.newIntArray();
    c.inputIntArray();
    c.average();
}

Container* newObjectArray(int size) {
    Container *pArr = nullptr; // Container 객체 배열 시작 주소
    /* 여기에 코드를 구현하라. */
    pArr = new Container[size];
    cout<<"input "<<size<<" words: ";
    for( int i=0; i<size; i++ ){
    	string s; cin>>s;
    	pArr[i].setTitle(s);
    }
    return pArr;
}

void printTitles(Container *pArr, int size) {
	//words: abc de f
	cout<<"words: ";
	for( int i=0; i<size; i++ ){
		cout<<pArr[i].getTitle()<<" ";
	}
	cout<<"\n";
}

void objectArray() {
    Container *pArr; // Container 객체 배열 시작 주소
    int size;        // Container 객체 배열 원소 개수
    cout << "element numbers of Container array[]? ";
    cin >> size;
    pArr = newObjectArray(size);
    printTitles(pArr, size);
    /* 여기서 pArr이 포인터 하는 메모리를 반납하시오. */
    delete[] pArr;
}

void inputTitle(Container* cp) {
    string s;
    getline(cin, s); // 앞서 입력된 메뉴항목 번호 뒤의 [엔터]를 제거함
    /* 여기에 코드를 구현하라. */
    cout<<"input title: ";
    getline(cin, s);
    cp->setTitle(s);
}

void rotateTitle() {
    Container c;
    inputTitle(&c);
    cout << "c.getTitle(): " << c.getTitle() << endl;
    c.rightRotateTitle();
}

void findDelete() {
    Container c;
    inputTitle(&c);      // This AAis aAA AAtest AAtitle.
    c.findDeleteTitle();
}

/******************************************************************************
 * main()
 ******************************************************************************/

string menuStr =
"******************************** Main Menu *********************************\n"
"* 0.Exit 1.constructor 2.intArray 3.objectArray 4.rotateTitle 5.findDelete *\n"
"****************************************************************************\n";

int main() {
    while (true) {
        int menuItem;
        cout << endl << menuStr << "menu? ";
        cin >> menuItem;
        if (menuItem == 0)
            break;
        switch(menuItem) {
        case 1: constructor(); break;
        case 2: intArray();    break;
        case 3: objectArray(); break;
        case 4: rotateTitle(); break;
        case 5: findDelete(); break;
        }
    }
    cout << "Good bye!!" << endl;
}
