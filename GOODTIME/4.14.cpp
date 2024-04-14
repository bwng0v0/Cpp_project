//https://www.acmicpc.net/problem/1043
#include <iostream>
using namespace std;

int res[50];//거짓말해도되면 1 안되면 0

int main(){
ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

int n,party; cin>>n>>party;
int kn; cin>>kn;
int know[kn][n];//아는사람들하고 같은 파티에 온사람들 저장
//0 = 아는사람번호
//1 = 만난사람 수
//2~ = 만난 사람들
for( int i=0; i<kn; i++ ){
    cin>>know[i][0];
    know[i][1] = 0;
}
//파티에 온사람들 저장
int arr[party][n];
// ?번째파티, 0 = 온사람수
// 1~ = 온사람 번호
for( int p=0; p<party; p++ ){
    cin>>arr[p][0];
    for( int i=1; i<arr[p][0]+1; i++ ){
        cin>>arr[p][i];
    }
}

for( int i=0; i<party; i++ ){
    //파티에 아는사람이 없다면 res[i] = 1


    int fine = 1;
    for( int j=1; j<arr[i][0]+1; j++ ){
        for( int k=0; k<kn; k++ ){
            if( arr[i][j] == know[k][0]  ){//i번째 파티에 j번째 사람이 k번째 아는사람과 같으면
                fine = 0;
                break;
            }
        }

        if( fine == 0 )break;
    }

    if( fine == 1 )
    res[i] = 1;
}

int sum = 0;
for( int i=0; i<party; i++ )
sum += res[i];

cout<<sum;


    return 0;
}