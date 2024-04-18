// 아래 4개의 static 멤버 함수를 가진 ArrayUtility2 클래스를 만들어라.
// 아래 코드와 주석을 이해하고 필요한 내용을 코딩함.

#include <iostream>
using namespace std;

class ArrayUtility2 {
public:
	// 사용자로부터 배열 원소의 개수를 입력 받아 개수 만큼의 메모리를 할당하고,
	// (만약 nullptr가 할당되었다면 exit(1);을 호출하여 프로그램이 종료되게 하라.)
	// 사용자로부터 개수만큼의 정수를 입력받아 배열에 저장
	// 배열의 주소를 리턴하고 배열 원소의 개수는 size를 통해 반환
	static int* create(int &size);

	// 배열s의 모든 원소(원소 개수 size)를 화면에 출력
	static void print(int s[], int size);

	// s1과 s2를 연결한 새로운 배열을 동적 생성하고 포인터 리턴
	// size_s1, size_s2는 각각 배열 s1과 s2의 크기
	static int* concat(int s1[], int s2[], int size_s1, int size_s2);

	// 배열 s1에서 배열 s2에 있는 원소들을 모두 삭제한 새로운 배열을 동적 생성하여 리턴 
	// 예: s1(1 2 3 4 5) - s2(2 3 4 7 8) = p(1 5)
	// 먼저 size_s1+size_s2 크기의 배열 p를 생성하여 s1에서 s2에 있는 숫자를 모두 삭제하고 남은 s1의 내용을 p로 저장
	// p에 저장된 실제 개수(retSize)만큼의 새로운 배열 q를 할당하고 p의 내용을 q에 복사한 후 p 배열의 메모리는 힙에 반납
	// q를 리턴하고 배열 원소의 개수는 retSize를 통해 반환
	static int* remove(int s1[], int s2[], int size_s1, int size_s2, int&retSize);
};
// 위에 코드는 수정 불가

// 여기에 ArrayUtility2 멤버 함수 코드 작성

int* ArrayUtility2::create(int &size){
    cout<<"Enter number of integer : ";;cin>>size;
    int *x = new int[size];
    if( x == nullptr )exit(1);
    cout<<"Enter "<<size<<" integer(s) : ";
    for( int i=0; i<size; i++ ){
        cin>>x[i];
    }
    return x;
}
int* ArrayUtility2::concat(int s1[], int s2[], int size_s1, int size_s2){
    int *arr = new int[size_s1+size_s2];
    for( int i=0; i<size_s1; i++ ){
        arr[i] = s1[i];
    }
    int j=0;
    for( int i=size_s1; i<size_s1+size_s2; i++){
        arr[i] = s2[j]; j+=1;
    }
    return arr;
}
void ArrayUtility2::print(int s[], int size){
    for( int i=0; i<size; i++ ){
        cout<<s[i]<<" ";
    }
    cout<<"\n";
}
int* ArrayUtility2::remove(int s1[], int s2[], int size_s1, int size_s2, int&retSize){
    //s1의 각 요소를 포함할지 안할지 표시할 배열
    int arr[size_s1] = {}; for( int i=0; i<size_s1; i++ ){ arr[i] = 1; }

    //s1요소중 s2와 같은값은 같은인덱스arr에 포함하지않음으로 표시
    for( int i=0; i<size_s1; i++ ){
        for( int j=0; j<size_s2; j++ ){
            if( s1[i] == s2[j] ){
                arr[i] = 0;
                break;
            }
        }
    }

    //s2와 겹치는걸제거한 배열의 크기를 arr를 보고 계산
    retSize = 0;
    for( int i=0; i<size_s1; i++ ){
        retSize += arr[i];
    }

    //계산한 크기만큼 배열할당
    int *res = new int[retSize];
    //인덱스 0부터 살아남은 s1값만 추가
    int cnt = 0;
    for( int i=0; i<size_s1; i++ ){
        if( arr[i] == 1 ){
            res[cnt] = s1[i];
            cnt += 1;
        }
    }

    return res;
}







// 아래 코드 수정 불가
int main() {
	int size1, size2;

	// 첫 번째 배열에 대해 할당 받고 데이타를 입력 받는다.
	int *x = ArrayUtility2::create(size1);

	// 두 번째 배열에 대해 할당 받고 데이타를 입력 받는다.
	int *y = ArrayUtility2::create(size2);

	// x[], y[] 두 배열을 합친다.
	int *p = ArrayUtility2::concat(x, y, size1, size2);

	// 합친 정수 배열 p[]를 출력한다
	cout << "concat(x, y, " << size1 << ", " << size2 << "):" << endl;
	ArrayUtility2::print(p, size1+size2);

	//배열 x[]에서 y[]를 뺀다;
	int retSize;
	int *q = ArrayUtility2::remove(x, y, size1, size2, retSize);

	//배열 x[]에서 y[]를 뺀 결과를 출력한다;
	cout << "remove(x, y, " << size1 << ", " << size2 << ", " << retSize << "):" << endl;
	ArrayUtility2::print(q, retSize);

	delete [] p;
	delete [] q;
	delete [] x;
	delete [] y;
}

/*
(출력)Enter number of integer : (입력)5
(출력)Enter 5 integer(s) : (입력)1 2 4 5 6
(출력)Enter number of integer : (입력)7
(출력)Enter 7 integer(s) : (입력)2 4 6 7 9 0 10
(출력)concat(x, y, 5, 7):
(출력)1 2 4 5 6 2 4 6 7 9 0 10 
(출력)remove(x, y, 5, 7, 2):
(출력)1 5 
*/
