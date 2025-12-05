# include <iostream>
# include <random>

using namespace std;

void showBoard(char board[6][7]);
bool insert_to_board(char board[6][7], char player, int col);
bool board_is_full(char board[6][7]);
bool gameIsOver(char board [6][7]);
string rowSubArr(char board [6][7], int row, int start, int end);
string colSubArr(char board [6][7], int col, int start, int end);
bool hasDiagonalFour(char board[6][7]);
int generate_random();
void two_player();
void single_player();

int main() {
    cout << "Welcome to my C++ Connect 4, Enter 1 for single player mode and 2 for two player mode: " << endl;
    int n;
    cin >> n;
    
    switch (n)
    {
    case 1:
        single_player();
        break;
    case 2:
        two_player();
        break;
    
    default:
        cout << "Invalid input, try again!" << endl;
        break;
    }
    return 0;

}


void showBoard(char board [6][7]) {
    
    cout << "    ";
    for(int i = 1; i <= 7; i++)
        cout << i << "  ";
    cout << "\n------------------------------" << endl;
    for(int i = 0; i < 6; i++) {
        cout << " : ";
        for(int j = 0; j < 7; j++) {
            cout << ' ' << board[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "------------------------------" << endl;
}

bool insert_to_board(char board[6][7], char player, int col) { 
    col--;
    int i = 5;
    while(i >= 0) {
        if(board[i][col] != '-') {
            i--;
        }
        else {
            board[i][col] = player;
            return true;
        }
    }
    return false;
}

bool board_is_full(char board[6][7]) {
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 7; j++) {
            if(board[i][j] == '-') {
                return false;
            }
        }
    }
    return true;
}

bool gameIsOver(char board[6][7]) {
    string player_R = "RRRR";
    string player_Y = "YYYY";
    for(int r = 0; r < 6; r++) {
        for(int c = 0; c < 4; c++) {
            if(rowSubArr(board, r, c, c+3) == player_R || rowSubArr(board, r, c, c+3) == player_Y) {
                return true;
            }
        }
    }

    for(int c = 0; c < 7; c++) {
        for(int r = 0; r < 3; r++) {
            if(colSubArr(board, c, r, r + 3) == player_R || colSubArr(board, c, r, r + 3)== player_Y) {
                return true;
            }
        }
    }
    
    return hasDiagonalFour(board);
    
}

string rowSubArr(char board [6][7], int row, int start, int end) { 
    string sub = "";
    for(int i = start; i <= end; i++) {
        sub += board[row][i];
    }
    return sub;
}

string colSubArr(char board [6][7], int col, int start, int end) { 
    string sub = "";
    for(int i = start; i <= end; i++) {
        sub += board[i][col];
    }
    return sub;
}

bool hasDiagonalFour(char board[6][7]) {
    for(int i = 0; i < 3; i++) {
        string diagonal = "";
        diagonal = diagonal + board[i][i] + board[i+1][i+1] + board[i+2][i+2] + board[i+3][i+3];
        if (diagonal == "RRRR" || diagonal == "YYYY") {
            return true;
        }
    }
    for(int i = 1; i < 3; i++) {
        string diagonal = "";
        diagonal = diagonal + board[i][i - 1] + board[i+1][i] + board[i+2][i+1] + board[i+3][i+2];
        if (diagonal == "RRRR" || diagonal == "YYYY") {
            return true;
        }
    }
    for(int i = 1; i < 4; i++) {
        string diagonal = "";
        diagonal = diagonal + board[i-1][i] + board[i][i+1] + board[i+1][i+2] + board[i+2][i+3];
        if (diagonal == "RRRR" || diagonal == "YYYY") {
            return true;
        }
    }
    for(int i = 2; i < 4; i++) {
        string diagonal = "";
        diagonal = diagonal + board[i-2][i] + board[i-1][i+1] + board[i][i+2] + board[i+1][i+3];
        if (diagonal == "RRRR" || diagonal == "YYYY") {
            return true;
        }
    }

    string diagonal = "";
    diagonal = diagonal + board[2][0] + board[3][1] + board[4][2] + board[5][3];
    if (diagonal == "RRRR" || diagonal == "YYYY") {
            return true;
        }

    diagonal = "";
    diagonal = diagonal + board[0][3] + board[1][4] + board[2][5] + board[3][6];
    if (diagonal == "RRRR" || diagonal == "YYYY") {
            return true;
        }
    
    for(int i = 0; i < 3; i++) {
        string diagonal = "";
        int n = 7;
        diagonal = diagonal + board[i][n - 1 - i] + board[i+1][n - 1 - (i+1)] + board[i+2][n - 1 - (i+2)] + board[i+3][n - 1 - (i+3)];
        if (diagonal == "RRRR" || diagonal == "YYYY") {
            return true;
        }
    }
    for(int i = 1; i < 3; i++) {
        string diagonal = "";
        int n = 7;
        diagonal = diagonal + board[i][n - 1 - (i-1)] + board[i+1][n - 1 - i] + board[i+2][n - 1 - (i+1)] + board[i+3][n - 1 - (i+2)];
        if (diagonal == "RRRR" || diagonal == "YYYY") {
            return true;
        }
    }

    for(int i = 0; i < 3; i++) {
        string diagonal = "";
        int n = 6;
        diagonal = diagonal + board[i][n - 1 - i] + board[i+1][n - 1 - (i+1)] + board[i+2][n - 1 - (i+2)] + board[i+3][n - 1 - (i+3)];
        if (diagonal == "RRRR" || diagonal == "YYYY") {
            return true;
        }
    }
    
    for(int i = 0; i < 2; i++) {
        string diagonal = "";
        int n = 5;
        diagonal = diagonal + board[i][n - 1 - i] + board[i+1][n - 1 - (i+1)] + board[i+2][n - 1 - (i+2)] + board[i+3][n - 1 - (i+3)];
        if (diagonal == "RRRR" || diagonal == "YYYY") {
            return true;
        }
    }
    

    diagonal = "";
    diagonal = diagonal + board[3][0] + board[2][1] + board[1][2] + board[0][3];
    if (diagonal == "RRRR" || diagonal == "YYYY") {
            return true;
        }
    diagonal = "";
    diagonal = diagonal + board[5][3] + board[4][4] + board[3][5] + board[2][6];
    if (diagonal == "RRRR" || diagonal == "YYYY") {
            return true;
        }
    

    return false;
}

int generate_random()
{
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<> dist(1, 7);


    return dist(gen);
}

void single_player() {

    cout << "Welcome to Connect4 single player mode" << endl;
    cout << "You're always Red(R)" << endl;
    char board [6][7];
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 7; j++) {
            board[i][j] = '-';
        }
    }
    int col;
    char player = 'R';
    bool gameover = false;
    while (!gameover) {
        if(board_is_full(board)) {
            cout << "Draw, board is full and neither player R nor player Y has won!" << endl;
            break;
        }
        //Computer's turn
        if(player == 'Y') {
            bool computer = insert_to_board(board, player, generate_random());
            while(!computer) {
                computer = insert_to_board(board, player, generate_random());
            }
        }
        //Player's turn
        else {
        cout << "Player: " << player << ", enter the column in where to insert your piece: " << endl; showBoard(board);
        
        cin >> col;
        while(col < 1 || col > 7) {
            cout << player << ": Invalid, choice for column! please re-enter:" << endl; showBoard(board);
            cin >> col;
        }

        bool insert_success = insert_to_board(board, player, col);
        while(!insert_success) {
            cout << player << ": The column you chose is full, please select another: " << endl;
            cin >> col;
            insert_success = insert_to_board(board, player, col);
        }
    }

        gameover = gameIsOver(board);
        if(!gameover) {
            player = (player == 'R') ? 'Y' : 'R';
        }
        else {
            showBoard(board);
            cout << "Game Over, player: " << player << " has won." << endl;
            cout << "Run the code again to play again!" << endl;
        }
    }

}

void two_player() {
    cout << "Welcome to Connect4 2 player mode!" << endl;
    char board [6][7];
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 7; j++) {
            board[i][j] = '-';
        }
    }
    int col;
    char player = 'R';
    bool gameover = false;
    while (!gameover) {
        if(board_is_full(board)) {
            cout << "Draw, board is full and neither player R nor player Y has won!" << endl;
            break;
        }
        cout << "Player: " << player << ", enter the column in where to insert your piece: " << endl; showBoard(board);
        
        cin >> col;
        while(col < 1 || col > 7){
            cout << player << ": Invalid, choice for column! please re-enter:" << endl; showBoard(board);
            cin >> col;
        }

        bool insert_success = insert_to_board(board, player, col);
        while(!insert_success) {
            cout << player << ": The column you chose is full, please select another: " << endl;
            cin >> col;
            insert_success = insert_to_board(board, player, col);
        }

        gameover = gameIsOver(board);
        if(!gameover) {
            player = (player == 'R') ? 'Y' : 'R';
        }
        else {
            showBoard(board);
            cout << "Game Over, player: " << player << " has won." << endl;
            cout << "Run the code again to play again!" << endl;
        }
    }
    
}