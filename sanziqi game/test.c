#include"game.h"
void menu()
{
	printf("************************************\n");
	printf("******** 1 . play   0 . exit *******\n");
	printf("************************************\n");
}
void game()
{
	char board[ROW][COL] = { 0 };
	InitBoard(board, ROW, COL);
	DisplayBoard(board, ROW, COL);
	char ret = 0;
	while (1)
	{

		playermove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);

		ret = iswin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		computermove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);

		ret = iswin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
		if (ret == '*')
		{
			printf("���Ӯ\n");
		}
		else if (ret == '#')
		{
			printf("����Ӯ\n");
		}
		else
			printf("ƽ��\n");
	
}
void test()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��:1 or 0\n");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
				break;
		case 0:
			    printf("�˳���Ϸ\n");
			    break;
		default:
			printf("����������\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}