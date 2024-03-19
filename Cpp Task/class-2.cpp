#include <iostream>

// Rectangle 클래스 정의
class Rectangle {
private:
    double width;
    double height;

public:
    // 생성자
    Rectangle(double w, double h) : width{w}, height{h} {};
    //Rectangle(double w, double h) : width(w), height(h) {}

    // 멤버 함수 - 사각형의 넓이를 계산하여 반환
    double calculateArea() const {
        return width * height;
    }
    void setWidth(double w) {
        width = w;
    }
    void setHeight(double h) {
        height = h;
    }
};

int main() {
    // Rectangle 객체 생성
    Rectangle rect(5.0, 3.0);

    // 사각형의 넓이 출력
    std::cout << "사각형의 넓이: " << rect.calculateArea() << std::endl;

    // 사각형의 너비와 높이를 변경하고 다시 넓이 출력
    rect.setWidth(7.0);
    rect.setHeight(4.0);
    std::cout << "변경된 사각형의 넓이: " << rect.calculateArea() << std::endl;

    return 0;
}
