#include<stdio.h>
#define N 7 //גודל לוח המשחק
#define M 4 //תנאי הנצחון

int score[2] = { 0,0 };
int matGame[N][N], str[2] = { '#' ,'@' };
int x, arrj[N] = { 6,6,6,6,6,6,6 };
bool v = 0;
int ni = N, nj = N, k = 0;


int checkIfpossible(int numj) {
	if (numj > N - 1) {

		printf("sorry, the row is not exsist\n");
		printf("\n");
		return 0;
	}
	else
	{
		if (arrj[numj] < 0) {
			printf("sorry, the colmn is full\n");
			printf("\n");
			return 0;
		}

	}
	return 1;
}
int checkWinner() {


	int di1[4] = { 0,-1, -1, 1 }, dj1[4] = { -1,1,-1,0 }, di2[4] = { 0,1,1,10 }, dj2[4] = { 1,-1,1,10 }, cnt = 0, x = 0, y = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 1; j < M; j++)
		{
			x = ni + di1[i] * j;
			y = nj + dj1[i] * j;
			if ((x > N || x < 0 || y <0 || y>N) || matGame[ni][nj] != matGame[x][y] || matGame[ni][nj] == 32)
				break;
			cnt++;
		}
		if (cnt >= 3)
			return matGame[ni][nj];
		else {
			for (int j = 1; j < M; j++)
			{
				x = ni + di2[i] * j;
				y = nj + dj2[i] * j;
				if ((x > N || x < 0 || y <0 || y>N) || matGame[ni][nj] != matGame[x][y] || matGame[ni][nj] == 32)
					break;
				cnt++;
			}
			if (cnt >= 3)
				return matGame[ni][nj];
		}
		cnt = 0;
	}
	return 0;
}
void printGameBord() {
	printf("%3d  ", 1);
	for (int j = 1; j < N; j++)
	{
		printf("%2d  ", j + 1);

	}
	printf("\n");
	for (int i = 0; i < N; i++) {
		printf("|");
		for (int j = 0; j < N; j++)
		{
			printf(" %c ", matGame[i][j]);
			printf("|");
		}
		printf("\n");
	}
	printf("\n");
}
void resetGame() {
	for (int i = 0; i < N; i++) {

		for (int j = 0; j < N; j++)
		{
			matGame[i][j] = 32;
		}
	}
}
int turn() {
	printf("player%d play!\ninsert index of colmn", v + 1);
	printf("\t");
	scanf_s("%d", &x);
	printf("\n");
	x--;
	if (checkIfpossible(x))
	{
		ni = arrj[x];
		nj = x;
		matGame[arrj[x]][x] = str[v];
		v = !v;
		arrj[x]--;
		return 1;
	}
	return 0;
}
void main()
{
	//player1 = #
	//player2 = @
	resetGame();
	while (k < 49) {
		if (turn()) {
			printGameBord();
			printf("\n\n");
			if (checkWinner())
			{
				printf("The winner is player%d! nice!\n", !v + 1);
				printf("\n");
				if (!score[v] + score[!v]) {
					printf("Do you want to continue?\n", !v + 1);//לא = 0   
					scanf_s("%d", &x);
					if (!x)
						k = 50;
				}
				score[!v]++;
			}
			k++;
		}
	}
	printf("The player%d's points is %d! nice!\n", !v + 1, score[!v]);
	printf("The player%d's points is %d! nice!\n", v + 1, score[v]);
}
