#include <iostream>
using namespace std;

const int rows = 10;
const int columns = 10;
int maxShips = 10;
int grid[rows][columns];

void ClearGrid(){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            grid[i][j] = 0;
        }
    }
}

void DisplayGrid(){
    for (int i = 0; i < rows; i++){
        if (i == 0){
            cout << "   ";
        }
        else{
            cout << i << "| ";

        }
        for (int k = 0; k < columns; k++){
            if (i != 0)
                break;

            cout << k << " ";
            if (k == columns - 1){
                cout << endl;
                cout << "   ___________________" << endl;
                cout << i << "| ";
            }


        }
        for (int j = 0; j < columns; j++){
            cout << grid[i][j] << " ";
        }

        cout << endl;
    }
}

void PlaceOutShips(){
    int s = 0;
    while (s < maxShips){
        int x = rand() % rows;
        int y = rand() % columns;
        if (grid[x][y] != 1){
            s++;
            grid[x][y] = 1;
        }
    }
}

int AmountOfShipsLeft(){
    int c = 0;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            if (grid[i][j] == 1){
                c++;
            }
        }
    }
    return c;
}

bool SuccessfulAttack(int x, int y){
    if (grid[x][y] == 1){
        grid[x][y] = 2;
        return true;
    }
    return false;
}

int main(){
    ClearGrid();
    DisplayGrid();
    return 0;
}
