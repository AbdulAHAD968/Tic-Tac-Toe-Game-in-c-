#include<iostream>
#include<iomanip>

using namespace std;


void printBoard(char board[3][3]);
bool checkWin(char board[3][3], char player);
bool isBoardFull(char board[3][3]);

int main(){

    char board[3][3] = { { ' ', ' ', ' ' },
                         { ' ', ' ', ' ' },
                         { ' ', ' ', ' ' }  };

    char player = 'A';

    const int size = 30;
    char* player1 = new char[size];
    cout<<"ENTER PLAYER 1 NAME: ";
    cin.getline(player1, size);

    char* player2 = new char[size];
    cout<<"PLAYER 2 NAME: ";
    cin.getline(player2, size);
    cout<<endl;

    char exit;
    bool yes = true;

    while(yes){

    while(true){
        // Print the current state of the board
        printBoard(board);

        // Get the player's move
        int row, col;

        if(player == 'A'){
            cout<<" PLAYER "<<player1<<"  { "<<player<<" } \n >> ENTER YOUR MOVE [ROW & COLUMN ] \n";
        }else{
            cout<<" PLAYER "<<player2<<" { "<<player<<" } \n >> ENTER YOUR MOVE [ROW & COLUMN ] \n";
        }

        int arr[3][3] = {0};
        int count = 0;
        for(int i=0 ; i<3 ; i++){
            for(int j=0 ; j<3 ; j++){
                cout<<" [ "<<i<<","<<j<<"]    ";
            }
            cout<<endl;
        }
        cout<<"\n\t ENTER THE ROW = "<<endl;
        cin>>row;
        cout<<"\n\t ENTER THE COLUMN = "<<endl;
        cin>>col;

        // Check if the chosen cell is valid
        if(row<0 || row>=3 || col<0 || col>=3 || board[row][col] !=' ') 
        {
            cout<<"\n INVALID MOVE.... ENTER THE CORRECT MOVE. "<< endl;
            continue;
        }

        // Make the move
        board[row][col] = player;    // place the player id to that position.

        // Check for a win
        if (checkWin(board, player)) {
            printBoard(board);
            cout<<"\n  ------------------------";
            cout<<"\n | PLAYER  { "<<player<<" } WINS. |";
            cout<<"\n  ------------------------\n";
            break;
        }

        // Check for a tie
        if(isBoardFull(board))
        {
            printBoard(board);
            cout<<"\n  -------------";
            cout<<"\n | IT'S A TIE. |";
            cout<<"\n  -------------\n";
            break;
        }

        // Switch to the other player
        player = (player == 'A') ? 'B' : 'A';
    }
    cout<<"\n DO YOU WISH TO PLAY AGAIN? (Y/N) ";
    cin>>exit;
        cout<<"--------------------------------"<<endl;

        if(exit == 'Y' || exit == 'y'){         // freeing the whole 3-D array.
            yes = true;

            for(int i=0 ; i<3 ; i++){
                for(int j=0 ; j<3 ; j++){
                    board[i][j] =' ';
                }
            }
        }else{
            yes = false;
        }
    
    }
        // deleting and undangling the memory.
    delete [] player1;
    delete [] player2;
    player1 = NULL;
    player2 = NULL;
    
return 0;
}

///////////////////////////////////*[ DEFINITIONS OF FUNCTIONS. ]*/////////////////////////////////////

// Function to print the Tic-Tac-Toe board
void printBoard(char board[3][3]){

    cout<<"\n\t GAME BOARD ::>> "<<endl;
    for(int i=0 ; i<3 ; ++i){
        for (int j=0 ; j<3 ; ++j){
            cout<<"\t"<<board[i][j]<<"  |  ";
        }
        cout<<endl;
        cout<<"\t----------------------\n";
    }
    cout<<endl;

return;
}

// Function to check if a player has won
bool checkWin(char board[3][3], char player) {
    
    //  CHECKING ROWS AND COLONNS FOR A MATCH.


    for(int i = 0; i<3 ; ++i)
    {
        if((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
            {
                return true;
            }
    }

    // CHECKING FOR DIAGONALS [] LEFT TO RIGHT ... RIGHT TO LEFT ...

    if((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
    (board[0][2] == player && board[1][1] == player && board[2][0] == player))
    {
        return true;
    }

    return false;
}

///////////*[ FUNCTION TO CHECK IF THE BOARD IS FULL. IF FULL ** TIE ** ] * ////////////

bool isBoardFull(char board[3][3])
{
    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            if(board[i][j] == ' ')
            {
                return false;
            }
        }
    }
    return true;
}