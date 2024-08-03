#include <iostream> 
#include <vector> 
using namespace std; 
 
char board[3][3] = {{' ', ' ', ' '}, 
                   {' ', ' ', ' '}, 
                   {' ', ' ', ' '}}; 
 
char currentPlayer = 'X'; 
 
void displayBoard() { 
    cout << "-------------" << endl; 
    for (int i = 0; i < 3; i++) { 
        cout << "| "; 
        for (int j = 0; j < 3; j++) { 
            cout << board[i][j] << " | "; 
        } 
        cout << endl; 
        cout << "-------------" << endl; 
    } 
} 
 
bool isBoardFull() { 
    for (int i = 0; i < 3; i++) { 
        for (int j = 0; j < 3; j++) { 
            if (board[i][j] == ' ') { 
                return false; 
            } 
        } 
    } 
    return true; 
} 
 
bool checkWin(char player) { 
    for (int i = 0; i < 3; i++) { 
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) { 
            return true; 
        } 
    }
    for (int j = 0; j < 3; j++) { 
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) { 
            return true; 
        } 
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) { 
        return true; 
    } 
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) { 
        return true; 
    } 
 
    return false; 
} 
 
void playerMove() { 
    int row, col; 
    cout << "Player " << currentPlayer << ", enter your move (row and column): "; 
    cin >> row >> col; 
    row--; 
    col--; 
 
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') { 
        board[row][col] = currentPlayer; 
    } else { 
        cout << "Invalid move. Try again." << endl; 
        playerMove(); 
    } 
} 
 
int main() { 
    while (true) { 
        displayBoard(); 
 
        if (isBoardFull()) { 
            cout << "The game is a draw!" << endl; 
            break; 
        } 
 
        playerMove(); 
 
        if (checkWin(currentPlayer)) { 
            displayBoard(); 
            cout << "Player " << currentPlayer << " wins!" << endl; 
            break; 
        } 
 
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; 
    } 
 
    return 0; 
}