// The starting data of this project 29 April 2020 at the time of corona virus, Ending date is 6.
#include <stdio.h>

#include <conio.h>

#include <windows.h>

#include <stdlib.h>

#include <time.h>

#include <stdbool.h>

// Here will be store all the user's and computer and player two inputs.
// 3x3 2D array.
char _tic_Tac_Toe_Data[3][3] = {
    {// First row.
     '1',
     '2',
     '3'},
    {// Second row.
     '4',
     '5',
     '6'},
    {// Third row.
     '7',
     '8',
     '9'}};

int _non_Accesable_Block[9] = {
    [0 ... 8] = 0};

int highest_Score;

// Function prototype.
void gotoxy(int, int);
int _heading(void);
int _player_Choosing(void);
void _loading_Animation(void);
void _tic_Tac_Toe_Structure(void);
int _data_Viwer(void);
int _computer();
int play_Again(void);
int _tic_Tac_Toe_Reseting(void);
int _data_Enter_For_Two_Player(void);
int _player_One_And_Two_Data_taker(int);

int main(void)
{
    // Initial heading.
    _heading();

    int _wich_Player;
    _wich_Player = _player_Choosing();
    system("cls");

    if (_wich_Player == 1)
    {
        // Block for player 1.

        // Animation.
        _heading();
        _loading_Animation();

        // User message.
        gotoxy(29, 4);
        printf("PLAYER 1 = X AND COMPUTER = Y, [PRESS ANY KEY FOR GO FURTHER]");
        getch();
        system("cls");
        _heading();

        // Tic tac toe structure.
        _tic_Tac_Toe_Structure();
        _data_Viwer();
        _data_Enter();
    }
    else
    {
        // Block for player 2.

        // Animation.
        _heading();
        _loading_Animation();

        // User message.
        gotoxy(29, 4);
        printf("PLAYER 1 = X AND PLAYER 2 = O, [PRESS ANY KEY FOR GO FURTHER]");
        getch();
        system("cls");
        _heading();

        // Tic tac toe structure.
        _tic_Tac_Toe_Structure();

        _data_Viwer();
        _data_Enter_For_Two_Player();
        getch();
    }

    return 0;
}

// Player vs computer---------------------------------------------------------------------

// Function definition of functions.

void gotoxy(int _x_Cordinate, int _y_Cordinate)
{
    COORD _coordinate;
    _coordinate.X = _x_Cordinate;
    _coordinate.Y = _y_Cordinate;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), _coordinate);
}

int _heading(void)
{
    gotoxy(34, 1);
    system("COLOR 2");
    printf("HI, AND WELCOME TO THE 1980\'S VIRTUAL \'TIC TAC TOE\'\n");
    gotoxy(31, 2);
    printf("--------------------------------------------------------");
    //Beep(1200, 1000);
    return 0;
}

int _player_Choosing(void)
{
    // Player choosing.
    gotoxy(34, 4);
    printf("ENTER THAT PLAYER 1 OR PLAYER 2: ");
    int _choosen_Option;
    fflush(stdin);
    scanf("%d", &_choosen_Option);
    //gotoxy(35, 5);

    if (_choosen_Option == 1)
    {
        return 1;
    }
    else if (_choosen_Option == 2)
    {
        return 2;
    }
    else
    {
        system("cls");
        gotoxy(34, 4);
        _heading();
        _player_Choosing();
    }
}

void _loading_Animation(void)
{
    gotoxy(46, 4);
    printf("LOADING: ");
    for (int _times = 1; _times <= 12; _times++)
    {
        Beep(0, 200);
        printf("%c", 177);
    }
}

void _tic_Tac_Toe_Structure(void)
{
    for (int _time = 1; _time <= 17; _time++)
    {
        gotoxy(52, 10 + _time);
        printf("|");
    }

    for (int _time = 1; _time <= 17; _time++)
    {
        gotoxy(64, 10 + _time);
        printf("|");
    }

    gotoxy(43, 15);
    printf("_______________________________");

    gotoxy(43, 22);
    printf("_______________________________");
}

int _data_Viwer(void)
{
    // First block.
    gotoxy(47, 12);
    printf("%c", _tic_Tac_Toe_Data[0][0]);

    // Second block.
    gotoxy(58, 12);
    printf("%c", _tic_Tac_Toe_Data[0][1]);

    // Third block.
    gotoxy(69, 12);
    printf("%c", _tic_Tac_Toe_Data[0][2]);

    // Fourth block.
    gotoxy(47, 19);
    printf("%c", _tic_Tac_Toe_Data[1][0]);

    // Fifth block.
    gotoxy(58, 19);
    printf("%c", _tic_Tac_Toe_Data[1][1]);

    // Sixth block.
    gotoxy(69, 19);
    printf("%c", _tic_Tac_Toe_Data[1][2]);

    // Seventh block.
    gotoxy(47, 25);
    printf("%c", _tic_Tac_Toe_Data[2][0]);

    // Eighth block.
    gotoxy(58, 25);
    printf("%c", _tic_Tac_Toe_Data[2][1]);

    // Nine block.
    gotoxy(69, 25);
    printf("%c", _tic_Tac_Toe_Data[2][2]);
}

int _random(void)
{
    int _random_Number;
    srand(time(0));
    _random_Number = rand() % 10;
    _random_Number -= 1;
    if (_random_Number < 0)
    {
        _random_Number *= -1;
    }

    return _random_Number;
}

int _win(void)
{
    // Horizontal checking.
    for (int _row = 0; _row < 3; _row++)
        if (_tic_Tac_Toe_Data[_row][0] == _tic_Tac_Toe_Data[_row][1] && _tic_Tac_Toe_Data[_row][1] == _tic_Tac_Toe_Data[_row][2])
        {
            gotoxy(52, 32);
            if (_tic_Tac_Toe_Data[_row][0] == 'O' || _tic_Tac_Toe_Data[_row][0] == 'o')
            {
                printf("PLAYER 2 IS WIN.");
                getch();
            }
            else
            {
                printf("COMPUTER IS WIN.");
                getch();
            }
            play_Again();
            return 0;
        }

    // Vertical checking.
    for (int _column = 0; _column < 3; _column++)
        if (_tic_Tac_Toe_Data[0][_column] == _tic_Tac_Toe_Data[1][_column] && _tic_Tac_Toe_Data[1][_column] == _tic_Tac_Toe_Data[2][_column])
        {
            gotoxy(52, 32);
            if (_tic_Tac_Toe_Data[1][_column] == 'O' || _tic_Tac_Toe_Data[1][_column] == 'o')
            {
                printf("PLAYER 2 IS WIN.");
                getch();
            }
            else
            {
                printf("COMPUTER IS WIN.");
                getch();
            }
            play_Again();
            return 0;
        }

    // Diagonal checking.
    if ((_tic_Tac_Toe_Data[0][0] == _tic_Tac_Toe_Data[1][1] && _tic_Tac_Toe_Data[1][1] == _tic_Tac_Toe_Data[2][2]) || (_tic_Tac_Toe_Data[0][2] == _tic_Tac_Toe_Data[1][1] && _tic_Tac_Toe_Data[1][1] == _tic_Tac_Toe_Data[2][0]))
    {

        gotoxy(52, 32);
        if (_tic_Tac_Toe_Data[0][0] == 'O' || _tic_Tac_Toe_Data[0][0] == 'o')
        {
            printf("PLAYER 2 IS WIN.");
            getch();
        }
        else
        {
            printf("COMPUTER IS WIN.");
            getch();
        }
        play_Again();
        return 0;
    }
    return -1;
}

int _data_Enter()
{
    int _round = 1;
    while (_round != 6)
    {

        _computer();
        system("cls");
        _heading();
        _tic_Tac_Toe_Structure();
        _data_Viwer();
        if (_win() == 0)
        {
            return 0;
        }

        if (_round != 5)
        {
            _user();
            system("cls");
            _heading();
            _tic_Tac_Toe_Structure();
            _data_Viwer();
            _win();
            if (_win() == 0)
            {
                return 0;
            }
        }

        _round++;
    }
    if (_win() == -1 && _round == 6)
    {
        gotoxy(50, 30);
        printf("MATCH IS DRAW.");
        play_Again();
    }
    return 0;
}
int _computer()
{
    int _random_Number_Reciver;
    while (1)
    {

        _random_Number_Reciver = _random();

        if (_non_Accesable_Block[_random_Number_Reciver] != -1)
        {
            _non_Accesable_Block[_random_Number_Reciver] = -1;

            if (_random_Number_Reciver >= 0 && _random_Number_Reciver <= 2)
            {
                //Here indicate 0 - 2 row.
                _tic_Tac_Toe_Data[0][_random_Number_Reciver] = 'Y';
                break;
            }
            else if (_random_Number_Reciver <= 5)
            {
                //Here indicate 3 - 5 row.
                _tic_Tac_Toe_Data[1][_random_Number_Reciver - 3] = 'Y';
                break;
            }
            else
            {
                //Here indicate 6 - 9 row.
                _tic_Tac_Toe_Data[2][_random_Number_Reciver - 6] = 'Y';
                break;
            }
        }
    }
}

int _user(void)
{

    int _user_Entered_Block_Number;
    gotoxy(35, 30);
    printf("ENTER THE BLOCK NUMBER WERE YOU WANT TO ENTER \'O\':");
    fflush(stdin);
    scanf("%d", &_user_Entered_Block_Number);
    _user_Entered_Block_Number -= 1;

    // Check that which block number user enter can its empty.
    if (_user_Entered_Block_Number >= 0 && _user_Entered_Block_Number <= 8)
    {
        if (_non_Accesable_Block[_user_Entered_Block_Number] != -1)
        {
            _non_Accesable_Block[_user_Entered_Block_Number] = -1;
            if (_user_Entered_Block_Number >= 0 && _user_Entered_Block_Number <= 2)
            {
                //Here indicate 0 - 2 row.

                _tic_Tac_Toe_Data[0][_user_Entered_Block_Number] = 'O';
                // break;
            }
            else if (_user_Entered_Block_Number <= 5)
            {
                //Here indicate 3 - 5 row.

                _tic_Tac_Toe_Data[1][_user_Entered_Block_Number - 3] = 'O';
                //break;
            }
            else
            {
                //Here indicate 6 - 8 row.

                _tic_Tac_Toe_Data[2][_user_Entered_Block_Number - 6] = 'O';
                //break;
            }
        }
        else
        {
            gotoxy(7, 30);
            printf("BLOCK %d ALREADY CONTAIN A VALUE, YOU MAUST ME ENTER ANOTHER BLOCK, PRESS ANY KEY FOR ENTER AGAIN.", _user_Entered_Block_Number + 1);
            getch();
            system("cls");
            _heading();
            _tic_Tac_Toe_Structure();
            _data_Viwer();
            _user();
        }
    }
    else
    {
        system("cls");
        _heading();
        _tic_Tac_Toe_Structure();
        _data_Viwer();
        gotoxy(17, 30);
        printf("NUMBER MUST BE CONTAIN THE RANGE OF 1-9, PRESS A KEY FOR ENTER A SUTABLE NUMBER.");
        getch();
        system("cls");
        _heading();
        _tic_Tac_Toe_Structure();
        _data_Viwer();
        _user();
    }

    return 0;
}
int play_Again(void)
{
    int _choice;
    gotoxy(25, 32);
    printf("IF YOU WANT TO PLAY AGAIN THEN ENTER PREES \'1\' AND FOR EXIT PREES \'2\': ");
    scanf("%d", &_choice);
    if (_choice == 1)
    {
        system("cls");

        // Reset the TIC-TAC-TOE data.
        _tic_Tac_Toe_Reseting();

        _tic_Tac_Toe_Structure();
        _data_Viwer();
        _data_Enter();
    }
    else if (_choice == 2)
    {
        system("cls");
        exit(1);
    }
    else
    {
        gotoxy(50, 33);
        printf("YOU ENTERED A WRONG VALUE.");
        system("cls");
        _heading();
        _tic_Tac_Toe_Structure();
        _data_Viwer();

        play_Again();
    }
}
int _tic_Tac_Toe_Reseting(void)
{
    int reset_Data = 49;
    for (int _row = 0; _row < 3; _row++)
    {
        for (int _column = 0; _column < 3; _column++)
        {
            *(*(_tic_Tac_Toe_Data + _row) + _column) = reset_Data;
            reset_Data++;
        }
    }
    // Resting indirectly same data.
    for (int _index = 0; _index < 9; _index++)
    {
        *(_non_Accesable_Block + _index) = 0;
    }
}

// Player one vs player  ---------------------------------------------------------
int _play_Again_Two_Player(void)
{
    int _choice;
    gotoxy(25, 32);
    printf("IF YOU WANT TO PLAY AGAIN THEN ENTER PREES \'1\' AND FOR EXIT PREES \'2\': ");
    scanf("%d", &_choice);
    if (_choice == 1)
    {
        system("cls");

        // Reset the TIC-TAC-TOE data.
        _tic_Tac_Toe_Reseting();

        // Tic tac toe structure.
        _tic_Tac_Toe_Structure();

        _heading();
        _data_Viwer();
        _data_Enter_For_Two_Player();
        getch();
    }
    else if (_choice == 2)
    {
        system("cls");
        exit(1);
    }
    else
    {
        gotoxy(50, 33);
        printf("YOU ENTERED A WRONG VALUE.");
        system("cls");
        _heading();
        _tic_Tac_Toe_Structure();
        _data_Viwer();

        _play_Again_Two_Player();
    }
}
int _win_Two_Player()
{

    // Horizontal checking.
    for (int _row = 0; _row < 3; _row++)
        if (_tic_Tac_Toe_Data[_row][0] == _tic_Tac_Toe_Data[_row][1] && _tic_Tac_Toe_Data[_row][1] == _tic_Tac_Toe_Data[_row][2])
        {
            gotoxy(52, 32);
            if (_tic_Tac_Toe_Data[_row][0] == 'O' || _tic_Tac_Toe_Data[_row][0] == 'o')
            {
                printf("PLAYER 2 IS WIN.");
                getch();
                _play_Again_Two_Player();
            }
            else
            {
                printf("PLAYER 1 IS WIN.");
                getch();
                _play_Again_Two_Player();
            }

            return 0;
        }

    // Vertical checking.
    for (int _column = 0; _column < 3; _column++)
        if (_tic_Tac_Toe_Data[0][_column] == _tic_Tac_Toe_Data[1][_column] && _tic_Tac_Toe_Data[1][_column] == _tic_Tac_Toe_Data[2][_column])
        {
            gotoxy(52, 32);
            if (_tic_Tac_Toe_Data[1][_column] == 'O' || _tic_Tac_Toe_Data[1][_column] == 'o')
            {
                printf("PLAYER 2 IS WIN.");
                getch();
                _play_Again_Two_Player();
            }
            else
            {
                printf("PLAYER 1 IS WIN.");
                getch();
                _play_Again_Two_Player();
            }

            return 0;
        }

    // Diagonal checking.
    if ((_tic_Tac_Toe_Data[0][0] == _tic_Tac_Toe_Data[1][1] && _tic_Tac_Toe_Data[1][1] == _tic_Tac_Toe_Data[2][2]) || (_tic_Tac_Toe_Data[0][2] == _tic_Tac_Toe_Data[1][1] && _tic_Tac_Toe_Data[1][1] == _tic_Tac_Toe_Data[2][0]))
    {

        gotoxy(52, 32);
        if (_tic_Tac_Toe_Data[0][0] == 'O' || _tic_Tac_Toe_Data[0][0] == 'o')
        {
            printf("PLAYER 2 IS WIN.");
            getch();
            _play_Again_Two_Player();
            
        }
        else
        {
            printf("PLAYER 1 IS WIN.");
            getch();
            _play_Again_Two_Player();
        }

        return 0;
    }
    return -1;
}

bool _decider_Of_Player_One_Or_Player_Two;

int _data_Enter_For_Two_Player(void)
{
    int _round = 1;

    while (_round != 6)
    {
        // Player one.
        _decider_Of_Player_One_Or_Player_Two = true;
        _player_One_And_Two_Data_taker(_round);
        system("cls");
        _heading();
        _tic_Tac_Toe_Structure();
        _data_Viwer();

        
        if (_win_Two_Player() == 0)
        {
            return 0;
        }
        // Player two.

        _decider_Of_Player_One_Or_Player_Two = false;
        _player_One_And_Two_Data_taker(_round);
        system("cls");
        _heading();
        _tic_Tac_Toe_Structure();
        _data_Viwer();

        if (_win_Two_Player() == 0)
        {
            return 0;
        }

        _round++;

        if (_win_Two_Player() == -1 && _round == 6)
        {
            gotoxy(50, 30);
            printf("MATCH IS DRAW.");
            getch();
            _play_Again_Two_Player();
        }
    }
}

int _player_One_And_Two_Data_taker(int _round)
{
    int _user_Entered_Block_Number;
    gotoxy(30, 30);
    if (_decider_Of_Player_One_Or_Player_Two != false)
    {

        printf("PLAYER ONE, ENTER THE BLOCK NUMBER WHERE YOU WANT TO ENTER \'X\':");
        fflush(stdin);
        scanf("%d", &_user_Entered_Block_Number);
        _user_Entered_Block_Number -= 1;
        // Check that which block number user enter can its empty.
        if (_user_Entered_Block_Number >= 0 && _user_Entered_Block_Number <= 8)
        {
            if (_non_Accesable_Block[_user_Entered_Block_Number] != -1)
            {
                _non_Accesable_Block[_user_Entered_Block_Number] = -1;
                if (_user_Entered_Block_Number >= 0 && _user_Entered_Block_Number <= 2)
                {
                    //Here indicate 0 - 2 row.

                    _tic_Tac_Toe_Data[0][_user_Entered_Block_Number] = 'X';
                    // break;
                }
                else if (_user_Entered_Block_Number <= 5)
                {
                    //Here indicate 3 - 5 row.

                    _tic_Tac_Toe_Data[1][_user_Entered_Block_Number - 3] = 'X';
                    //break;
                }
                else
                {
                    //Here indicate 6 - 8 row.

                    _tic_Tac_Toe_Data[2][_user_Entered_Block_Number - 6] = 'X';
                    //break;
                }
            }
            else
            {
                gotoxy(7, 30);
                printf("BLOCK %d ALREADY CONTAIN A VALUE, YOU MAUST ME ENTER ANOTHER BLOCK, PRESS ANY KEY FOR ENTER AGAIN.", _user_Entered_Block_Number + 1);
                getch();
                system("cls");
                _heading();
                _tic_Tac_Toe_Structure();
                _data_Viwer();
                _player_One_And_Two_Data_taker(_round);
            }
        }
        else
        {
            system("cls");
            _heading();
            _tic_Tac_Toe_Structure();
            _data_Viwer();
            gotoxy(17, 30);
            printf("NUMBER MUST BE CONTAIN THE RANGE OF 1-9, PRESS A KEY FOR ENTER A SUTABLE NUMBER.");
            getch();
            system("cls");
            _heading();
            _tic_Tac_Toe_Structure();
            _data_Viwer();
            _player_One_And_Two_Data_taker(_round);
        }
    }
    else
    {
        // After got every value terminate this function.
        if (_round == 5)
        {
            return 0;
        }

        printf("PLAYER TWO, ENTER THE BLOCK NUMBER WHERE YOU WANT TO ENTER \'O\':");
        fflush(stdin);
        scanf("%d", &_user_Entered_Block_Number);
        _user_Entered_Block_Number -= 1;
        // Check that which block number user enter can its empty.
        if (_user_Entered_Block_Number >= 0 && _user_Entered_Block_Number <= 8)
        {
            if (_non_Accesable_Block[_user_Entered_Block_Number] != -1)
            {
                _non_Accesable_Block[_user_Entered_Block_Number] = -1;
                if (_user_Entered_Block_Number >= 0 && _user_Entered_Block_Number <= 2)
                {
                    //Here indicate 0 - 2 row.

                    _tic_Tac_Toe_Data[0][_user_Entered_Block_Number] = 'O';
                    // break;
                }
                else if (_user_Entered_Block_Number <= 5)
                {
                    //Here indicate 3 - 5 row.

                    _tic_Tac_Toe_Data[1][_user_Entered_Block_Number - 3] = 'O';
                    //break;
                }
                else
                {
                    //Here indicate 6 - 8 row.

                    _tic_Tac_Toe_Data[2][_user_Entered_Block_Number - 6] = 'O';
                    //break;
                }
            }
            else
            {
                gotoxy(7, 30);
                printf("BLOCK %d ALREADY CONTAIN A VALUE, YOU MAUST ME ENTER ANOTHER BLOCK, PRESS ANY KEY FOR ENTER AGAIN.", _user_Entered_Block_Number + 1);
                getch();
                system("cls");
                _heading();
                _tic_Tac_Toe_Structure();
                _data_Viwer();
                _player_One_And_Two_Data_taker(_round);
            }
        }
        else
        {
            system("cls");
            _heading();
            _tic_Tac_Toe_Structure();
            _data_Viwer();
            gotoxy(17, 30);
            printf("NUMBER MUST BE CONTAIN THE RANGE OF 1-9, PRESS A KEY FOR ENTER A SUTABLE NUMBER.");
            getch();
            system("cls");
            _heading();
            _tic_Tac_Toe_Structure();
            _data_Viwer();
            _player_One_And_Two_Data_taker(_round);
        }
    }
}