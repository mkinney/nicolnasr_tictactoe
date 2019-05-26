/* Tic Tac Toe Game:
 * - Two players take turns picking a spot on the board.
 * - When one player gets three squares in a row (across, down or diagonally), they win.
 * - If all spots are taken and no one has three in a row, then it is a DRAW (or tie).
 *
 */
#include <stdio.h>

#ifdef WINDOWS
#include <conio.h>
#endif

#include "minunit.h"

#include <stdlib.h>
#include <string.h>

int tests_run = 0;

char num[10] = {'0' , '1' , '2' , '3' , '4' , '5' , '6' , '7' , '8' , '9'};

/* p1 is player 1 piece */
char p1 = 'X';
/* p2 is player 2 piece */
char p2 = '0';

/* Print the board */
void board()
{
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

/* Determine whose turn it is */
int turn(int i)
{

  if (i % 2 == 0)
    return 2;
  else
    return 1;
}

/* Determine if there is a winner.
 * Return 0 if there is no winner (a tie)
 * Return 1 if there there is a winner
 * Return 2 if all positions are not in the initial state and there was yet not a winner
 * 
 */
int win()
{

  if (num[1] == num[2] && num[2] == num[3])
    return 1;
  else
    if (num[4] == num[5] && num[5] == num[6])
      return 1;
    else
      if (num[7] == num[8] && num[8] == num[9])
        return 1;
      else
        if (num[1] == num[4] && num[4] == num[7])
          return 1;
        else
          if (num[2] == num[5] && num[5] == num[8])
            return 1;
          else
            if (num[3] == num[6] && num[6] == num[9])
              return 1;
            else
              if (num[1] == num[5] && num[5] == num[9])
                return 1;
              else
                if (num[3] == num[5] && num[5] == num[7])
                  return 1;
                else
                  if (num[1] != '1' && num[2] != '2' && num[3] != '3' && num[4] != '4' && num[5] != '5' && num[6] != '6' && num[7] != '7' && num[8] != '8' && num[9] != '9')
                    return 0;
                  else
                    return 2;
}

/* helper function to reset the board back initial values */
void reset_board() {
  int i;
  for (i = 0; i < 11; i++) {
    num[i] = '0' + i;
  }
}

static char * test_reset_board() {
  reset_board();
  mu_assert("num[0] should be '0'", num[0] == '0');
  mu_assert("num[1] should be '1'", num[1] == '1');
  mu_assert("num[2] should be '2'", num[2] == '2');
  mu_assert("num[3] should be '3'", num[3] == '3');
  mu_assert("num[4] should be '4'", num[4] == '4');
  mu_assert("num[5] should be '5'", num[1] == '5');
  mu_assert("num[6] should be '6'", num[6] == '6');
  mu_assert("num[7] should be '7'", num[7] == '7');
  mu_assert("num[8] should be '8'", num[8] == '8');
  mu_assert("num[9] should be '9'", num[1] == '9');
  return 0;
}

/* Test the turn() function */
static char * test_turn() {
  mu_assert("turn(0) should return 2", turn(0) == 2);
  mu_assert("turn(1) should return 1", turn(1) == 1);
  return 0;
}

/* Test the win() function */
static char * test_win() {
  char save_num[10];
  memcpy(save_num, num, sizeof(num));

  reset_board();
  mu_assert("win() on initial board should be 0", win() == 2);

  /* player 1 win testing */
  reset_board();
  num[1] = p1;
  num[2] = p1;
  num[3] = p1;
  mu_assert("win() on with player1 in top row", win() == 1);

  reset_board();
  num[4] = p1;
  num[5] = p1;
  num[6] = p1;
  mu_assert("win() on with player1 in middle row", win() == 1);

  reset_board();
  num[7] = p1;
  num[8] = p1;
  num[9] = p1;
  mu_assert("win() on with player1 in bottom row", win() == 1);

  reset_board();
  num[1] = p1;
  num[4] = p1;
  num[7] = p1;
  mu_assert("win() on with player1 in first column", win() == 1);

  reset_board();
  num[2] = p1;
  num[5] = p1;
  num[8] = p1;
  mu_assert("win() on with player1 in middle column", win() == 1);

  reset_board();
  num[3] = p1;
  num[6] = p1;
  num[9] = p1;
  mu_assert("win() on with player1 in middle column", win() == 1);

  reset_board();
  num[1] = p1;
  num[5] = p1;
  num[9] = p1;
  mu_assert("win() on with player1 in diagonal in top left corner", win() == 1);

  reset_board();
  num[3] = p1;
  num[5] = p1;
  num[7] = p1;
  mu_assert("win() on with player1 in diagonal from top right corner", win() == 1);

  /* player 2 win testing */
  reset_board();
  num[1] = p2;
  num[2] = p2;
  num[3] = p2;
  mu_assert("win() on with player2 in top row", win() == 1);

  reset_board();
  num[4] = p2;
  num[5] = p2;
  num[6] = p2;
  mu_assert("win() on with player2 in middle row", win() == 1);

  reset_board();
  num[7] = p2;
  num[8] = p2;
  num[9] = p2;
  mu_assert("win() on with player2 in bottom row", win() == 1);

  reset_board();
  num[1] = p2;
  num[4] = p2;
  num[7] = p2;
  mu_assert("win() on with player2 in first column", win() == 1);

  reset_board();
  num[2] = p2;
  num[5] = p2;
  num[8] = p2;
  mu_assert("win() on with player2 in middle column", win() == 1);

  reset_board();
  num[3] = p2;
  num[6] = p2;
  num[9] = p2;
  mu_assert("win() on with player2 in middle column", win() == 1);

  reset_board();
  num[1] = p2;
  num[5] = p2;
  num[9] = p2;
  mu_assert("win() on with player2 in diagonal in top left corner", win() == 1);

  reset_board();
  num[3] = p2;
  num[5] = p2;
  num[7] = p2;
  mu_assert("win() on with player2 in diagonal from top right corner", win() == 1);

  /* reset the global num variable */
  memcpy(num, save_num, sizeof(num));
  return 0;
}

/* Run all tests */
static char * all_tests() {
  mu_run_test(test_turn);
  mu_run_test(test_win);
  return 0;
}

/* Main function */
int main()
{

#ifdef WINDOWS
  system("cls");
#else
  system("clear");
#endif

  char *result = all_tests();
  if (result != 0) {
    printf("%s\n", result);
  }
  else {
    printf("ALL TESTS PASSED\n");
  }
  printf("Tests run: %d\n", tests_run);

  /* if we do not pass all tests, do not play the game */
  if (result != 0)
  {
    return(0);
  }

  int pos, i = 1, a;
  char eo;

  do
    {
      board();
      printf("player %d turn: ",turn(i));
      do
      {
        scanf("%d", &pos);
      } while (pos <= 0 || pos > 9);

      if (turn(i) == 1)
        eo = p1;
      else
        if (turn(i) == 2)
          eo = p2;

      if (pos == 1 && num[1] == '1')
        num[1] = eo;
      else
        if (pos == 2 && num[2] == '2')
          num[2] = eo;
        else
          if (pos == 3 && num[3] == '3')
            num[3] = eo;
          else
            if (pos == 4 && num[4] == '4')
              num[4] = eo;
            else
              if (pos == 5 && num[5] == '5')
                num[5] = eo;
              else
                if (pos == 6 && num[6] == '6')
                  num[6] = eo;
                else
                  if (pos == 7 && num[7] == '7')
                    num[7] = eo;
                  else
                    if (pos == 8 && num[8] == '8')
                      num[8] = eo;
                    else
                      if (pos == 9 && num[9] == '9')
                        num[9] = eo;
                      else
                      {
                        printf("INVALID MOVE!!");
                        getchar();
                        i--;
                      }

      board();
      i++;
      if (win() == 0 || win() == 1)
        break;
    } while (win() != 0 || win() != 1);
  board();

  if (win() == 1)
    printf("\tplayer %d won!!\n", turn(i-1));
  else
    if (win() == 0)
      printf("\tDRAW!!\n");
  getchar();
}
