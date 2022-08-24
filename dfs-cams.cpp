#include <bits/stdc++.h>
using namespace std;
#define MAXN 35

// Problem from OBI 2022:
// with the map of a room, the dimensions and where are the ideals security cams
// output if have a way not secure between the entry and the exit of the room
// entry: room[1][1]
// exit: room[N][M]

int room[MAXN][MAXN];
int N, M, K;
// K = num of cam

bool way(int posi, int posj){ // verify if exists a way to the entry for exit
    if(posi == N && posj == M) return true;
    if(room[posi][posj] == 1) return false;
    room[posi][posj] = 2;

    if(room[posi][posj+1] == 0 && posj + 1 <= M)
        if(way(posi, posj+1)) return true;
    if(room[posi][posj-1] == 0 && posj - 1 > 0)
        if(way(posi, posj-1)) return true;
    if(room[posi+1][posj] == 0 && posi + 1 <= N)
        if(way(posi+1, posj)) return true;
    if(room[posi-1][posj] == 0 && posi - 1 > 0)
        if(way(posi-1, posj)) return true;    

    return false;
} // its a dfs algorithm!!!


void inputcam(int posi, int posj, char dir){
    
    if(dir == 'O'){

        for(int i = posi ; i > 0 ; i--){
            room[i][posj] = 1;
        }
    }
    
    if(dir == 'L'){

        for(int i = posi ; i <= N ; i++){
            room[i][posj] = 1;
        }
    }

    if(dir == 'N'){

        for(int j = posj ; j > 0 ; j--){
            room[posi][j] = 1;
        }
    }

    if(dir == 'S'){

        for(int j = posj ; j <= M ; j++){
            room[posi][j] = 1;
        }
    }
}

int main(){

    cin >> N >> M >> K;
    
    for(int i = 0 ; i < K ; i++){
        int cami, camj;
        char dir;
        cin >> cami >> camj >> dir;
        inputcam(cami, camj, dir);
    }

    if(way(1, 1)) cout << "S\n";
    else cout << "N\n";

    return 0;
}