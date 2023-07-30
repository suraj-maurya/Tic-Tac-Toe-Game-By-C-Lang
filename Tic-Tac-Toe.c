#include <stdio.h>
#include <conio.h>
#include <string.h>

void Player1_play(char n, char param[3][3]);
void Player2_play(char n, char param[3][3]);

int main()
{
     do
    {
    char Num[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    char player1_name[50];
    char player2_name[50];

    char Replay_input[30];
   
        printf("Enter the name of the first player: ");
        fgets(player1_name, 50, stdin);
        player1_name[strcspn(player1_name, "\n")] = '\0';
        printf("Enter the name of the Second player: ");
        fgets(player2_name, 50, stdin);
        player2_name[strcspn(player2_name, "\n")] = '\0';
        printf("The symbol of %s is : X\n", player1_name);
        printf("The symbol of %s is : O\n\n", player2_name);
 do
    {
        // Game structure
        {
            printf("\t  %c  |  %c  |  %c", Num[0][0], Num[0][1], Num[0][2]);
            for (int i = 0; i < 2; i++)
            {
                printf("  ");
                printf("\n\t-----------------");
                printf("\n\t");
                printf("  %c  |  %c  |  %c", Num[i + 1][0], Num[i + 1][1], Num[i + 1][2]);
            }
            printf("\n\n");
        }
        int w;

        //  Code for playing
        for (w = 0; w < 9; w++)
        {
            if (w % 2 == 0)
            {
                char n;
                printf("%s's turns. Choose a number for play!- ", player1_name);
                scanf("%c", &n);
                getchar();
                printf("\n");
                Player1_play(n, Num);
            }
            else
            {
                char p;
                printf("%s's turns. Choose a number for play! - ", player2_name);
                scanf("%c", &p);
                getchar();
                printf("\n");
                Player2_play(p, Num);
            }

            {
                printf("\t  %c  |  %c  |  %c", Num[0][0], Num[0][1], Num[0][2]);
                for (int i = 0; i < 2; i++)
                {
                    printf("  ");
                    printf("\n\t-----------------");
                    printf("\n\t");
                    printf("  %c  |  %c  |  %c", Num[i + 1][0], Num[i + 1][1], Num[i + 1][2]);
                }
                printf("\n");
            }
            printf("\n");

            // Code for decision who wins
            if ((Num[0][0] == Num[0][1] && Num[0][1] == Num[0][2] && Num[0][2] == 'X') || // row 1
                (Num[1][0] == Num[1][1] && Num[1][1] == Num[1][2] && Num[1][2] == 'X') || // row 2
                (Num[2][0] == Num[2][1] && Num[2][1] == Num[2][2] && Num[2][2] == 'X') || // row 3
                (Num[0][0] == Num[1][0] && Num[1][0] == Num[2][0] && Num[2][0] == 'X') || // column 1
                (Num[0][1] == Num[1][1] && Num[1][1] == Num[2][1] && Num[2][1] == 'X') || // column 2
                (Num[0][2] == Num[1][2] && Num[1][2] == Num[2][2] && Num[2][2] == 'X') || // column 3
                (Num[0][0] == Num[1][1] && Num[1][1] == Num[2][2] && Num[2][2] == 'X') || // diagonal 1
                (Num[0][2] == Num[1][1] && Num[1][1] == Num[2][0] && Num[2][0] == 'X'))   // diagonal 2
            {
                printf("%s -->-->-->Win <--<--<--\n", player1_name);
                printf("%s !!!!!!!!Loose!!!!!!!!!\n", player2_name);
                w = 11;
            }
            else if ((Num[0][0] == Num[0][1] && Num[0][1] == Num[0][2] && Num[0][2] == 'O') || // row 1
                     (Num[1][0] == Num[1][1] && Num[1][1] == Num[1][2] && Num[1][2] == 'O') || // row 2
                     (Num[2][0] == Num[2][1] && Num[2][1] == Num[2][2] && Num[2][2] == 'O') || // row 3
                     (Num[0][0] == Num[1][0] && Num[1][0] == Num[2][0] && Num[2][0] == 'O') || // column 1
                     (Num[0][1] == Num[1][1] && Num[1][1] == Num[2][1] && Num[2][1] == 'O') || // column 2
                     (Num[0][2] == Num[1][2] && Num[1][2] == Num[2][2] && Num[2][2] == 'O') || // column 3
                     (Num[0][0] == Num[1][1] && Num[1][1] == Num[2][2] && Num[2][2] == 'O') || // diagonal 1
                     (Num[0][2] == Num[1][1] && Num[1][1] == Num[2][0] && Num[2][0] == 'O'))
            {
                printf("%s -->-->-->Win <--<--<--\n", player2_name);
                printf("%s !!!!!!!!Loose!!!!!!!!!\n", player1_name);
                w = 11;
            };
            printf("\n\n");
        }

        if (w == 9)
        {
            printf(" -->-->-->-->Game Draw<--<--<--<--<--\n\n");
            printf(" -->-->-->-->Gave Over<--<--<--<--<--\n\n");
        };
        printf("For Play again-Type 'Yes'\nFor Reset the game-Type 'Reset'\nFor Exist-type 'Exist'\n");

        int check_value=1;
        do
        {
        fgets(Replay_input, 30, stdin);
        Replay_input[strcspn(Replay_input, "\n")] = '\0';

        if (strcmp(Replay_input, "Yes") == 0 || strcmp(Replay_input, "yes") == 0 || strcmp(Replay_input, "Reset") == 0 || strcmp(Replay_input, "reset") == 0 || strcmp(Replay_input, "Exist") == 0 || strcmp(Replay_input, "exist") == 0)
        {
            check_value=0;
            break;
        }else{
            printf("Invalid Input!\n");
            printf("Prefer [Yes][Reset][Exist] \n");
            continue;
        };
        } while (check_value==1);
        


        if (strcmp(Replay_input, "Yes") == 0 || strcmp(Replay_input, "yes") == 0)
        {
            continue;
                        printf("\n");
        }
        else
        {
            break;
        }
    } while (1);
      if (strcmp(Replay_input, "Reset") == 0 || strcmp(Replay_input, "reset") == 0)
        {
            continue;
            printf("\n");
        }
        else
        {
            break;
        }
    } while (1);
    printf("\n");
    printf("\t\tThanks for playing!!\n\n\n");

    getch();
    return 0;
}

void Player1_play(char n, char param[3][3])
{
    if (n == '1')
    {
        param[0][0] = 'X'; // for 1
    }
    else if (n == '2')
    {
        param[0][1] = 'X';
    }
    else if (n == '3')
    {
        param[0][2] = 'X';
    }
    else if (n == '4')
    {
        param[1][0] = 'X';
    }
    else if (n == '5')
    {
        param[1][1] = 'X';
    }
    else if (n == '6')
    {
        param[1][2] = 'X';
    }
    else if (n == '7')
    {
        param[2][0] = 'X';
    }
    else if (n == '8')
    {
        param[2][1] = 'X';
    }
    else if (n == '9')
    {
        param[2][2] = 'X';
    }
    else
    {

        printf("Invalid Input!!");
    }

    printf("\n");
}
void Player2_play(char n, char param[3][3])
{
    if (n == '1')
    {
        param[0][0] = 'O'; // for 1
    }
    else if (n == '2')
    {
        param[0][1] = 'O';
    }
    else if (n == '3')
    {
        param[0][2] = 'O';
    }
    else if (n == '4')
    {
        param[1][0] = 'O';
    }
    else if (n == '5')
    {
        param[1][1] = 'O';
    }
    else if (n == '6')
    {
        param[1][2] = 'O';
    }
    else if (n == '7')
    {
        param[2][0] = 'O';
    }
    else if (n == '8')
    {
        param[2][1] = 'O';
    }
    else if (n == '9')
    {
        param[2][2] = 'O';
    }
    else
    {
        printf("Invalid Input!!");
    }

    printf("\n");
}
