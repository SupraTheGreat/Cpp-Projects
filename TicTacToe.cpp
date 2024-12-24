#include <iostream>
#include <windows.h>
#include "time.h"
using namespace std;

// Prints the grid
void printGrid(char fgrid[3][3]){
    for(int i = 0; i < 3; i++){
        cout << " ";
        cout << i + 1 << " ";
        cout << "[";
        cout << " ";
        for(int j = 0; j < 3; j++){
            cout << fgrid[i][j];
            cout << " ";
        };
        cout << "]";
        cout << endl;
    };
    cout << "     1 2 3" << endl;
};

// Runs each player's turn
void turn(char p, char grid1[3][3], int turnNum){
    int x, y;
    cout << "Player " << turnNum << ", it's your turn.\n" << endl;
    cout << "Enter the X position: ";
    cin >> x;
    cout << "Enter the Y position: ";
    cin >> y;
    x -= 1;
    y -= 1;
    if(grid1[y][x] == ' '){
        grid1[y][x] = p;
        cout << grid1[y][x] << endl;
        printGrid(grid1);
    } else {
        cout << "That point is already occupied." << endl;
        turn(p, grid1, turnNum);
    };
};

// Checks if X is player 1 or 2 and if O is player 1 or 2
string checkPlayer(char o1, char o2, char position){
    if(o1 == position){
        return "Player 1 ";
    } else {
        return "Player 2 ";
    };
};

// Checks if a player wins
string check(char cgrid[3][3], char z1, char z2){
    for(int i = 0; i < 3; i++){
        for(int j = 0; i < 3; i++){
            // Horizontal checking
            if(j == 0 && cgrid[i][j] == cgrid[i][j+1] && cgrid[i][j] == cgrid[i][j+2] && cgrid[i][j] != ' '){
                cout << checkPlayer(z1, z2, cgrid[i][j]) << "won!" << endl;
                return checkPlayer(z1, z2, cgrid[i][j]);
            } else if (j == 1 && cgrid[i][j] == cgrid[i][j+1] && cgrid[i][j] == cgrid[i][j-1] && cgrid[i][j] != ' '){
                cout << checkPlayer(z1, z2, cgrid[i][j]) << "won!" << endl;
                return checkPlayer(z1, z2, cgrid[i][j]);
            } else if (j == 2 && cgrid[i][j] == cgrid[i][j-1] && cgrid[i][j] == cgrid[i][j-2] && cgrid[i][j] != ' '){
                cout << checkPlayer(z1, z2, cgrid[i][j]) << "won!" << endl;
                return checkPlayer(z1, z2, cgrid[i][j]);
            // Vertical checking
            } else if (i == 0 && cgrid[i][j] == cgrid[i+1][j] && cgrid[i][j] == cgrid[i+2][j] && cgrid[i][j] != ' '){
                cout << checkPlayer(z1, z2, cgrid[i][j]) << "won!" << endl;
                return checkPlayer(z1, z2, cgrid[i][j]);
            } else if (i == 1 && cgrid[i][j] == cgrid[i+1][j] && cgrid[i][j] == cgrid[i-1][j] && cgrid[i][j] != ' '){
                cout << checkPlayer(z1, z2, cgrid[i][j]) << "won!" << endl;
                return checkPlayer(z1, z2, cgrid[i][j]);
            } else if (i == 2 && cgrid[i][j] == cgrid[i-1][j] && cgrid[i][j] == cgrid[i-2][j] && cgrid[i][j] != ' '){
                cout << checkPlayer(z1, z2, cgrid[i][j]) << "won!" << endl;
                return checkPlayer(z1, z2, cgrid[i][j]);
            // Diagonal checking
            } else if (cgrid[0][0] == cgrid[1][1] && cgrid[0][0] == cgrid[2][2] && cgrid[0][0] != ' '){
                cout << checkPlayer(z1, z2, cgrid[0][0]) << "won!" << endl;
                return checkPlayer(z1, z2, cgrid[0][0]);
            } else if (cgrid[0][2] == cgrid[2][0] && cgrid[0][2] == cgrid[1][1] && cgrid[0][2] != ' '){
                cout << checkPlayer(z1, z2, cgrid[0][2]) << "won!" << endl;
                return checkPlayer(z1, z2, cgrid[0][2]);
            };
        };
    };
    return "No one won";
};


int main()
{
    bool won = false;
    char playerOne, playerTwo;
    /*
    1: Aqua
    2: Green
    3: Blue
    4: Red
    5: Purple
    6: Yellow
    7: White
    8: Grey
    0: Black
    A: Light Green
    B: Light Aqua
    C: Light Red
    D: Light Purple
    E: Light Yellow
    F: Bright White
    */
    // First background, then text color
	system("Color 07");

	srand((unsigned) time(NULL));
    int decider = 0 + (rand() % 2);

	cout << "Welcome to Tic Tac Toe!\n" << endl;
	// Decides who's X and who's O
	if(decider == 0){
        playerOne = 'X';
        playerTwo = 'O';
	} else {
        playerOne = 'O';
        playerTwo = 'X';
	};
	cout << "Player 1 is " << playerOne << ",";
	cout << " and Player 2 is " << playerTwo << "." << endl;

	// char grid[3][3] = {
    //                     {'A', 'B', 'C'},
    //                     {'D', 'E', 'F'},
    //                     {'I', 'H', 'G'}
    //                   };


    // Creating the grid
    char grid[3][3] = {
                        {' ', ' ', ' '},
                        {' ', ' ', ' '},
                        {' ', ' ', ' '}
                      };

    cout << endl;
    printGrid(grid);
    cout << endl;

    char currentTurn;
    int turnN;
    // Switches turns each time and also runs the check function
    for(int i = 0; i < 9; i++){
        if(i%2 == 0){
            currentTurn = playerOne;
            turnN = 1;
        } else {
            currentTurn = playerTwo;
            turnN = 2;
        };

        if (check(grid, playerOne, playerTwo) == "No one won"){
            check(grid, playerOne, playerTwo);
            turn(currentTurn, grid, turnN);
        } else {
            won = true;
            break;
        };
    };

    if(won == false){
        cout << "No one won." << endl;
    }
	return 0;
}
