#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>

typedef struct {
	int S;
	int A;
} Score;

typedef struct Result {
	int minEValue;
	int maxEValue;
} Result;

int getEValue(Score *sp, int k)
{
	double w;
	if(sp[k].S == 0 && sp[k].A == 0)
		return 0;
	w = pow(sp[k].S, 2) / (pow(sp[k].S, 2) + pow(sp[k].A, 2));
	return (int)(1000 * w);
}

int getMaxEValue(Score *sList, int n) {
	int i;
	int val = 0, max = INT_MIN;

	for (i = 1; i <= n; i++) {
		val = getEValue(sList, i);
		if (max < val)
			max = val;
	}
	return max;
}

int getMinEValue(Score *sList, int n) {
	int i;
	int val, min = INT_MAX;

	for (i = 1; i <= n; i++) {
		val = getEValue(sList, i);
		if (min > val)
			min = val;
	}
	return min;
}
/*
void clrsList(Score *sList, int n)
{
	int i;
	for (i = 1; i <= n; i++) {
		sList[i].S = 0;
		sList[i].A = 0;
	}
	return;
}
*/
int main(void)
{
	int i, j;
	int t, n, m, a, b, p, q;

	Score sList[1001] = {0};
	Result rList[1001] = {0};

	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		scanf("%d %d", &n, &m);
		for (j = 0; j < m; j++) {
			scanf("%d %d %d %d", &a, &b, &p, &q);
			sList[a].S += p;
			sList[a].A += q;
			sList[b].S += q;
			sList[b].A += p;
		}
		rList[i].maxEValue = getMaxEValue(sList, n);
		rList[i].minEValue = getMinEValue(sList, n);
		memset(sList, 0, sizeof(sList));	//clrsList(sList, n);
	}

	for (i = 0; i < t; i++) {
		printf("%d\n%d\n", rList[i].maxEValue, rList[i].minEValue);
	}
}
