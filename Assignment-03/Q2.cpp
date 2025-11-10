#include <iostream>
using namespace std;

int tile[128][128]; 
int tileID = 1;

void tromino(int n, int x, int y, int missingX, int missingY) {
    if(n == 2) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(x+i != missingX || y+j != missingY)
                    tile[x+i][y+j] = tileID;
            }
        }
        tileID++;
        return;
    }

    int mid = n/2;
    int mx = x+mid, my = y+mid;

   
    int quad = 0;
    if(missingX < mx && missingY < my) quad = 1; // top-left
    else if(missingX < mx && missingY >= my) quad = 2; // top-right
    else if(missingX >= mx && missingY < my) quad = 3; // bottom-left
    else quad = 4; 


    if(quad != 1) tile[mx-1][my-1] = tileID;
    if(quad != 2) tile[mx-1][my] = tileID;
    if(quad != 3) tile[mx][my-1] = tileID;
    if(quad != 4) tile[mx][my] = tileID;
    tileID++;


    tromino(mid, x, y, (quad==1)?missingX:mx-1, (quad==1)?missingY:my-1);
    tromino(mid, x, my, (quad==2)?missingX:mx-1, (quad==2)?missingY:my);
    tromino(mid, mx, y, (quad==3)?missingX:mx, (quad==3)?missingY:my-1);
    tromino(mid, mx, my, (quad==4)?missingX:mx, (quad==4)?missingY:my);
}

int main() {
    int n, missingX, missingY;
    cout << "Enter board size (power of 2): ";
    cin >> n;
    cout << "Enter missing cell coordinates (x y): ";
    cin >> missingX >> missingY;

    tromino(n, 0, 0, missingX, missingY);

    cout << "Tiled Board:" << endl;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cout << tile[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}
