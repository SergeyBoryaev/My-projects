#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void open(int arr[103][103],char pole[103][103],int x,int y,int n,int m){
	int count = 0;
	for (int i = x - 1; i <= x + 1; i++)
		for (int j = y - 1; j <= y + 1; j++)
			if ((arr[i][j] == 10)||(arr[i][j] == 9))
				count++;
	pole[x][y] = count + '0';
    arr[x][y]=1;
	if(count==0)
		for (int i = x - 1; i <= x + 1; i++)
			for (int j = y - 1; j <= y + 1; j++)
				if((i>0) && (j>0) && (i<(n-1)) && (j<(m-1)))
					if(((i==x)&&(j==y))||(arr[i][j]==1));
					else
						open(arr,pole,i,j,n,m);
}
int main() {
	srand(time(0));
	int n, m, k;
	for (;;) {
		printf("Define bombs(x,y,bombs):\n");
		scanf("%d %d %d", &n, &m, &k);
		if ((k <= n * m)||(n>100)||(m>100))
			break;
		printf("Incorrect input. Try again\n");
	}
	n += 2;
	m += 2;
	int arr[103][103];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] = 0;
	char pole[103][103];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			pole[i][j] = '.';
	}
	int xs, ys;
	for (int i = 0; i < k; i++) {
		/*for (;;) {
			printf("from 1 to %d po x ", n - 2);
			printf("from 1 to %d po y\n", m - 2);
			scanf("%d %d", &xs, &ys);
			if ((xs > n - 2) || (ys > m - 2) || (xs < 1) || (ys < 1) || (arr[xs][ys]==10)) {
				printf("Incorrect input. Try again.\n");
			}
			else {
				break;
			}
		}*/
		for(;;){
			xs=((rand()%(n-2))+1);
			ys=((rand()%(n-2))+1);
			if(arr[xs][ys]==0){
				break;
			}
		}
		arr[xs][ys] = 10;
	}
	int kolv = 0;
	int marks = k;
	int score = 0;
	for (;;) {
		if (kolv == k) {
            int wincon=0;
	        for (int t = 1; t < n-1; t++)
		        for (int h = 1; h < m-1; h++)
			        if((arr[t][h] == 1)||(arr[t][h]==9))
                        wincon++;
            if(wincon == ((m-2)*(n-2))){
				printf("You win!\nYour score is:%d\n", score);
				break;
            }
		}
		for (int i = 1; i < n - 1; i++) {
			for (int j = 1; j < m - 1; j++)
				printf("%c ", pole[i][j]);
			printf("\n");
		}
		printf("\n");
		int c;

		printf("Do something(0-end;1-open;2-mark;3-unmark) marks:%d\n", marks);
		scanf("%d", &c);
		if (c == 1) {
			int x, y;
			for (;;) {
				printf("x,y\n");
				scanf("%d %d", &x, &y);
				if ((x > n - 2) || (y > m - 2) || (x < 1) || (y < 1)) {
					printf("Incorrect input. Try again.\n");
					break;
				}
				else {
					break;
				}
			}
			if (arr[x][y] == 10) {
				printf("You lose\n");
				for (int i = 1; i < n - 1; i++) 
					for (int j = 1; j < m - 1; j++)
						if((arr[i][j]==10)||(arr[i][j]==9))
							pole[i][j]='M';
						else
							pole[i][j]='0';
					for (int i = 1; i < n - 1; i++) {
						for (int j = 1; j < m - 1; j++)
							printf("%c ", pole[i][j]);
						printf("\n");
					}
					printf("\n");
				break;
			}
			else if (arr[x][y] == 0) {
				open(arr,pole,x,y,n,m);
			}
			else if (arr[x][y] == 9) {
				printf("You think the bomb is hear, if you dont think so unmark it\n");
			}
		}
		else if (c == 2) {
			int x, y;
			for (;;) {
				printf("x,y\n");
				scanf("%d %d", &x, &y);
				if ((x > n - 2) || (y > m - 2) || (x < 1) || (y < 1)||(pole[x][y]!='.')) {
					printf("Incorrect input. Try again.\n");
					break;
				}
				else {
					break;
				}
			}
			if (marks == 0) {
				printf("Not enough marks\n");
				continue;
			}
			pole[x][y] = '?';
			marks--;
			if (arr[x][y] == 10) {
				kolv++;
				arr[x][y] = 9;
			}
		}
		else if (c == 3) {
			int x, y;
			for (;;) {
				printf("x,y\n");
				scanf("%d %d", &x, &y);
				if ((x > n - 2) || (y > m - 2) || (x < 1) || (y < 1) ||(pole[x][y]=='.')) {
					printf("Incorrect input. Try again.\n");
					break;
				}
				else {
					break;
				}
			}
			if(pole[x][y]=='?'){
				pole[x][y] = '.';
				marks++;
				if(arr[x][y]==1)
					arr[x][y]=0;
				if (arr[x][y] == 9) {
					arr[x][y] = 10;
					kolv--;
				}
			}
			else
				printf("Not marked\n");
		}
		else if (c == 0) {
			printf("You lose\n");
			break;
		}
		score++;
	}
}