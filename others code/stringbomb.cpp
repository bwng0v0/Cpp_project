#include <iostream>
#include <string>

using namespace std;
//나랑 다른부분
//erase대신 resize채용
//erase가 부분삭제라 시간을많이먹는데 뒤를 자르면되기때문에 resize씀

//substr대신에 직접선형탐색함
//substr도 빠른연산은 아니라 영향을 많이준듯

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    string str, bomb;
    cin >> str >> bomb;

    int bomb_last = bomb.size() - 1;
    int top = 0;
    for (int i = 0; i < str.size(); i++, top++)
    {
        str[top] = str[i];//부분삭제를 안함ㄷ
        if (top >= bomb_last && str[top] == bomb[bomb_last])
        {
            bool found = true;
            for (int j = 0; j < bomb.size(); j++)
            {
                if (str[top - j] != bomb[bomb_last - j])
                {
                    found = false;
                    break;
                }
            }
            if (found)
                top -= bomb.size();
        }
    }
    cout << ((top == 0) ? "FRULA" : str.substr(0, top));

    return 0;
}