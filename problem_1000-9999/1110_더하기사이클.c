#include <stdio.h>

int main (void)
{
	int n, sum = 0, temp1 = 0, temp2 = 0, count = 0, newNum = 0;
	
	scanf("%d", &n);
	while(n != newNum) 
	{
		if(!newNum)
			newNum = n;
		temp1 = newNum / 10;
		temp2 = newNum % 10;
		sum = (temp1 + temp2) % 10;
		newNum = temp2 * 10 + sum;
		count++;
	}
	printf("%d", count);
}
