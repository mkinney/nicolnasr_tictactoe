#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

char num[10] = {'0' , '1' , '2' , '3' , '4' , '5' , '6' , '7' , '8' , '9'};

int board()
{
  system("cls");

  printf("\tTIC TAC TOE GAME\n\n");
  printf("player1 is X \t    player2 is 0\n\n");

  printf("\t     |     |\n");
  printf("\t  %c  |  %c  |  %c  \n", num[1], num[2], num[3]);
  printf("\t_____|_____|_____\n");
  printf("\t     |     |\n");
  printf("\t  %c  |  %c  |  %c  \n", num[4], num[5], num[6]);
  printf("\t_____|_____|_____\n");
  printf("\t     |     |\n");
  printf("\t  %c  |  %c  |  %c  \n", num[7], num[8], num[9]);
  printf("\t     |     |\n\n");
}

int turn(int i)
{

    if(i % 2 == 0)
      return 2;
    else
      return 1;
    i++;

}

int win()
{

  if(num[1] == num[2] && num[2] == num[3])
    return 1;
  else
  if(num[4] == num[5] && num[5] == num[6])
    return 1;
  else
  if(num[7] == num[8] && num[8] == num[9])
    return 1;
  else
  if(num[1] == num[4] && num[4] == num[7])
    return 1;
  else
  if(num[2] == num[5] && num[5] == num[8])
    return 1;
  else
  if(num[3] == num[6] && num[6] == num[9])
    return 1;
  else
  if(num[1] == num[5] && num[5] == num[9])
    return 1;
  else
  if(num[3] == num[5] && num[5] == num[7])
    return 1;
  else
  if(num[1] != '1' && num[2] != '2' && num[3] != '3' && num[4] != '4' && num[5] != '5' && num[6] != '6' && num[7] != '7' && num[8] != '8' && num[9] != '9')
    return 0;
  else
    return 2;
}

int main()
{
  int pos, i = 1, a;
  char eo;

  do
    {
      board();
      printf("player %d turn: ",turn(i));
      do
      {
        scanf("%d", &pos);
      }while(pos <= 0 || pos > 9);

      if(turn(i) == 1)
        eo = 'X';
      else
        if(turn(i) == 2)
          eo = '0';

    if(pos == 1 && num[1] == '1')
      num[1] = eo;
    else
    if(pos == 2 && num[2] == '2')
      num[2] = eo;
    else
    if(pos == 3 && num[3] == '3')
      num[3] = eo;
    else
    if(pos == 4 && num[4] == '4')
      num[4] = eo;
    else
    if(pos == 5 && num[5] == '5')
      num[5] = eo;
    else
    if(pos == 6 && num[6] == '6')
      num[6] = eo;
    else
    if(pos == 7 && num[7] == '7')
      num[7] = eo;
    else
    if(pos == 8 && num[8] == '8')
      num[8] = eo;
    else
    if(pos == 9 && num[9] == '9')
      num[9] = eo;
    else
      {
        printf("INVALID MOVE!!");
        getch();
        i--;
      }

      board();
      i++;
      if(win() == 0 || win() == 1)
        break;
    }while(win() != 0 || win() != 1);
    board();

    if(win() == 1)
      printf("\tplayer %d won!!", turn(i-1));
    else
    if(win() == 0)
      printf("\tDRAW!!");
    getch();
}
