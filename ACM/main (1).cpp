#include <bits/stdc++.h>
using namespace std;

const int Maxd = 1e9;
#define MOD 1000000007
typedef long long LL;
int N,M;
const int startX = 0;
const int startY = 0;
int a[1000][1000];
int X[] = {0,0,-1,1};
int Y[] = {1,-1,0,0};

void nhap(){
    for(int i=0; i < N;i++){
        for(int j=0;j<M;j++)
            cin >> a[i][j];
    }
}
bool valid(int x,int y){
    return x >= 0 && x < N && y >= 0 && y < M;
}

bool visit[1000][1000];


int cnt = 0;
void DFSForArray(int x,int y){
    ++cnt;
    visit[x][y] = true;

    for(int i = 0;i < 4;i++){
        int fx = x + X[i];
        int fy = y + Y[i];

        if (valid(fx,fy) && !visit[fx][fy] && a[fx][fy] == 0){
            DFSForArray(fx,fy);
        }
    }
}
int main(){
    cin >> N >> M;
    nhap();
    DFSForArray(startX,startY);
    if(visit[N-1][M-1])
        cout<<"YES";
    else
        cout<<"NO";
}
