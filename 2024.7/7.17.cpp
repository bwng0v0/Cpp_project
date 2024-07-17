// https://www.acmicpc.net/problem/21599 아이템 배치하기
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int main(){
fastio
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n,greater());

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0 && res < i + arr[i])
            res = (n > i + arr[i] ? i + arr[i] : n);
    }
    cout << res;

    return 0;
}