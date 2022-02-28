#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int N, M;
struct Ex{
    int i,j;
};

int di[4] = {-1,0,1,0};
int dj[4] = {0,1,0,-1};
Ex R, B, H;
char map[10][10];
int ans = 99;

void collision(Ex r, Ex b, int d){
    if(d == 0){
        if(r.i > b.i)   R.i -= di[d];
        else            B.i -= di[d];
    }
    if(d == 1){
        if(r.j < b.j)   R.j -= dj[d];
        else            B.j -= dj[d];
    }
    if(d == 2){
        if(r.i < b.i)   R.i -= di[d];
        else            B.i -= di[d];
    }
    if(d == 3){
        if(r.j > b.j)   R.j -= dj[d];
        else            B.j -= dj[d];
    }
}

void move(int de){
    if(de > 10)     return;
    if(de >= ans)    return;
    if(B.i == H.i) if(B.j == H.j) return;
    if(R.i == H.i) if(R.j == H.j) {
        ans = de;
        return;
    }
    Ex r=R, b=B;

    for(int d=0;d<4;d++){
        R=r;B=b;
        while(1){
            R.i += di[d];
            R.j += dj[d];
            if(map[R.i][R.j] == '#')
            {
                R.i -= di[d];
                R.j -= dj[d];
                break;
            }
            if(map[R.i][R.j] == 'O')
                break;
        }
        while(1){
            B.i += di[d];
            B.j += dj[d];
            if(map[B.i][B.j] == '#')
            {
                B.i -= di[d];
                B.j -= dj[d];
                break;
            }
            if(map[B.i][B.j] == 'O')
                break;
        }
        if(R.i == B.i)
            if(R.j == B.j)
                if((R.i != H.i) || R.j != H.j)
                    collision(r, b, d);
                    
        move(de+1);
    }
}
int game(){
    move(0);
    if(ans <=10)  return ans;
    return -1;
}
int main(){
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
#endif
    cin >> N >> M;
    for(int i =0;i<N;i++)
        for(int j=0;j<M;j++)
            {
                cin >> map[i][j];
                if(map[i][j] == 'R')
                {
                    R.i = i;
                    R.j = j;
                    map[i][j] = '.';
                }
                if(map[i][j] == 'B')
                {
                    B.i = i;
                    B.j = j;
                    map[i][j] = '.';
                }
                if(map[i][j] == 'O')
                {
                    H.i = i;
                    H.j = j;
                }
            }
            
    cout << game() << endl;
    return 0;
}