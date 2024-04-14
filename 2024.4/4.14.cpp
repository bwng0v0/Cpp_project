//https://www.acmicpc.net/problem/1043 거짓말
//이거는 다른사람풀이좀 많이 봐야겠는데 ㅋㅋㅋ
#include <bits/stdc++.h>
using namespace std;

int main(){
ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

int n,party; cin>>n>>party;
int pp[n+1] {}; // 1 ~ n+1
//감염되었으면 1 아니면 0

queue<int> Q[n+1];
//각 사람은 만났던 사람들 저장해놔야함

int know; cin>>know;
for( int i=0; i<know; i++ ){
    int num;cin>>num;
    pp[num] = 1;
}

//파티입력
//0 = 인원수
int arr[party][n+1] {};
for( int p=0; p<party; p++ ){
    cin>>arr[p][0];
    for( int i=1; i<arr[p][0]+1; i++ ){
        cin>>arr[p][i];
    }

    //만난사람끼리 서로를 큐에 저장
    for( int i=1; i<arr[p][0]+1; i++ ){
        for( int j=1; j<arr[p][0]+1; j++ ){
            //일단 본인도 넣고 나중에 pop으로 빼든하자
            Q[arr[p][i]].push(arr[p][j]);//와 진짜몰랐다 ㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋ
        }
    }
}


queue<int> BFS;
//모든 파티를 탐색하면서 BFS
for( int p=0; p<party; p++ ){
    for( int i=1; i<arr[p][0]+1; i++ ){
        int num = arr[p][i];
        if( pp[num] == 1 ){//감염자를 찾았다면 감염시작 만났던사람들
            //만났던 사람들을 감염자가 아닌사람들 모두 감염시키고 푸시
            while( !Q[num].empty() ){
                int num2 = Q[num].front();
                if( pp[num2] == 0 ){
                pp[num2] = 1;
                BFS.push(num2);
                }
                Q[num].pop(); //큐 두개를 서로 헷갈림
            }

            
            while( !BFS.empty() ){
                int cur = BFS.front();
                BFS.pop();
                //cur이 만난사람중 비감염자 모두감염/푸시
                while( !Q[cur].empty() ){
                    int num3 = Q[cur].front();
                    if( pp[num3] == 0 ){
                        pp[num3] = 1;
                        BFS.push(num3);
                    }

                    Q[cur].pop();
                }
            }

        }
    }
}

//모든 파티를 돌면서 총합이 0이면 res +=1;
int res{0};
for( int p=0; p<party; p++ ){
    int sum = 0;
    for( int i=1; i<arr[p][0]+1; i++ ){
        sum += pp[arr[p][i]];
    }
    if( sum == 0 )
    res += 1;
}

cout<<res;

    return 0;
}