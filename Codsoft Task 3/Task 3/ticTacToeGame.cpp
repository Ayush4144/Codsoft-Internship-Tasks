#include <iostream>
using namespace std;

int currentPlayer;
int currentSign;
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

void drawBoard()
{
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "\n";
    cout << "---|---|---\n";
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "\n";
    cout << "---|---|---\n";
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n";
}

bool placesign(int slot)
{
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (board[row][col] != 'x' && board[row][col] != 'o')
    {
        board[row][col] = currentSign;
        return true;
    }
    else
    {
        return false;
    }
}

int winner()
{
    // check row
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return currentPlayer;
    }
    // check column
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return currentPlayer;
    }
    // check diagonal
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        return currentPlayer;
    }
    // check diagonal
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        return currentPlayer;
    }
    return 0;
}

void swapPlayerAndSign()
{
    if (currentSign == 'x')
    {
        currentSign = 'o';
    }
    else
    {
        currentSign = 'x';
    }
    if (currentPlayer == 1)
    {
        currentPlayer = 2;
    }
    else
    {
        currentPlayer = 1;
    }
}

void initializeBoard()
{
    char nums = '1';
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            board[i][j] = nums++;
        }
    }
}

void game()
{
    cout << "Player1 choose your sign-> x or o : ";
    char sign1;
    cin >> sign1;

    currentPlayer = 1;
    currentSign = sign1;
    drawBoard();
    int playerWon;
    for (int i = 0; i < 9; i++)
    {
        cout << "Its player" << currentPlayer << " turn Enter your slot : ";
        int slot;
        cin >> slot;

        if (slot < 1 || slot > 9)
        {
            cout << "It is not a valid slot, you may try again\n";
            i--;
            continue;
        }
        if (!placesign(slot))
        {
            cout << "slot occupied! try again \n";
            i--;
            continue;
        }
        drawBoard();
        playerWon = winner();

        if (playerWon == 1)
        {
            cout << "Player 1 wins\n";
            break;
        }
        if (playerWon == 2)
        {
            cout << "Player 2 wins\n";
            break;
        }
        swapPlayerAndSign();
        if (playerWon = 0)
        {
            cout << "Match Tie";
        }
    }
}

int main()
{
    char choice;
    do
    {
        initializeBoard();
        game();
        cout << "Play again? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "Thanks for Playing" << endl;

    return 0;
}