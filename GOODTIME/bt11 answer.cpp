#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

// char arr[12][6];
// bool myvisit[12][6];
// // int instant[10][10];
// // bool myvisit[302][302];
// // bool myvisit2[302][302];
// int dx[4] = {1,0,-1,0};
// int dy[4] = {0,1,0,-1};
// // int dx[8] = {2, 2, 1, 1, -1, -1, -2, -2};
// // int dy[8] = {1, -1, 2, -2, 2, -2, 1, -1};
// int dz[2] = {1, -1};
// vector<pair<int,int>> v;

// void backtrack(int index, int sum)
// {
 
// }
// int V[1000005];
// int Tmp_first[100005];
// int Tmp_second[100005];
// int V_2[1000005];
bool myvisit[12];
vector<int> V;
vector<int> answer;
int N,M;
    
void backtrack(int index)
{
    if(answer.size() == M)
    {
        for(int i = 0; i<M; i++) cout << answer[i] << " ";
        cout << "\n";
        return;
    }
    int Check = 0;
    for(int i = index; i<V.size(); i++)
    {
        if(myvisit[i])
        continue;

        if(Check == V[i]){
            continue;
        }
        else {
            Check = V[i];
        }
    
        answer.push_back(V[i]);
        myvisit[i] = true;
        backtrack(index);
        answer.pop_back();
        myvisit[i] = false;
    }

}

int main() {                           
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for(int i = 0; i<N; i++)
    {
        int x; cin >>x;
        V.push_back(x);
    }
    sort(V.begin(), V.end());
    // V.erase(unique(V.begin(), V.end()), V.end());

    backtrack(0);

    return 0;
}