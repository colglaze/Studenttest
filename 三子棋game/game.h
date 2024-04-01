#include<stdio.h>
#define ROW 3
#define COL 3
#include<time.h>
#include<stdlib.h>
void InitBoard(char board[ROW][COL], int row, int col);
void DisplayBoard(char board[ROW][COL],int row,int col);
void playermove(char board[ROW][COL], int row, int col);
void computermove(char board[ROW][COL], int row, int col);
char iswin(char board[ROW][COL], int row, int col);
