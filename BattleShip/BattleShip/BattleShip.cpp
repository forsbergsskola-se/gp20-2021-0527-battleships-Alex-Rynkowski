#include <iostream>
#include <thread>
using namespace std;

const int rows = 10;
const int columns = 10;
int maxShips = 5;
int gridP1[rows][columns];
int gridP2[rows][columns];

void ClearGrid(){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            gridP1[i][j] = 0;
            gridP2[i][j] = 0;
        }
    }
}

void DisplayGrid(int grid[rows][columns]){
    for (int i = 0; i < rows; i++){
        if (i == 0){
            cout << "   ";
        }
        else{
            cout << (char)(i + 97) << "| ";
        }
        for (int k = 0; k < columns; k++){
            if (i != 0)
                break;

            cout << k << " ";
            if (k == columns - 1){
                cout << endl;
                cout << (char)(i + 97) << "| ";
            }


        }
        for (int j = 0; j < columns; j++){
            cout << grid[i][j] << " ";
        }

        cout << endl;
    }
}

void PlaceOutShipsForPlayer(int grid[rows][columns]){
    int s = 0;
    srand(time(nullptr));
    while (s < maxShips){
        int x = rand() % rows;
        int y = rand() % columns;
        if (grid[x][y] != 1){
            s++;
            grid[x][y] = 1;
        }
    }
}

int AmountOfShipsLeft(int grid[rows][columns]){
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

bool SuccessfulAttack(int x, int y, int grid[rows][columns]){
    if (grid[x][y] == 1){
        cout << "Hit!" << endl;
        grid[x][y] = 2;
        return true;
    }
    cout << "Miss!" << endl;
    return false;
}

void PlaceShips(){
    ClearGrid();
    PlaceOutShipsForPlayer(gridP1);
    std::chrono::milliseconds timespan(1000);
    std::this_thread::sleep_for(timespan);
    PlaceOutShipsForPlayer(gridP2);
}

bool IsValidInput(string playerInput){
    if (playerInput.length() > 2)
        return false;

    if (tolower(playerInput[0]) < 97 || tolower(playerInput[0]) > 106)
        return false;
    return true;

}

string WaitForInput(){
    string input;
    while (true){
        cin >> input;
        if (IsValidInput(input))
            return input;
        cout << "Invalid input, try again" << endl;
    }
}

int main(){
    PlaceShips();
    DisplayGrid(gridP1);
    cout << endl;
    cout << endl;
    DisplayGrid(gridP2);
    string input;
    int x = 0;
    int y = 0;
    while (true){
        cout << "Player 1, do your thing!" << endl;

        input = WaitForInput();
        x = tolower(input[0]) - 97;
        y = (int)input[1] - 48;
        if (SuccessfulAttack(x, y, gridP1) && AmountOfShipsLeft(gridP1) <= 0){
            cout << "Player 1 is victorious!" << endl;
            break;
        }

        cout << "Player 2, do your thing!" << endl;
        input = WaitForInput();
        
        x = tolower(input[0]) - 97;
        y = (int)input[1] - 48;
        if (SuccessfulAttack(x, y, gridP2) && AmountOfShipsLeft(gridP2) <= 0){
            cout << "Player 2 is victorious!" << endl;
            break;
        }

    }
    return 0;
}
