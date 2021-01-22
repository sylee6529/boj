#include <stdio.h>

int main (void)
{
	int i, n, dice1, dice2;	
	int score1 = 100, score2 = 100;
	
	scanf("%d", &n);	//총 게임 회수 입력 
	for(i = 0; i < n; i++)
	{
		scanf("%d %d", &dice1, &dice2);
		//주사위의 눈이 작은 사람의 점수에서 큰 사람의 눈 수만큼 뺀다
		if(dice1 > dice2)
			score2 -= dice1;
		else if(dice1 < dice2)
			score1 -= dice2;
	}
	printf("%d\n", score1);
	printf("%d", score2);
	return 0;
}
