#include"help.h"

int main()
{
	int s1[] = { -1, 0, 9 };
	int s2[] = { -25, -10, 10, 11 };
	int s3[] = { 2, 9, 17, 30, 41 };
	int n1 = sizeof(s1) / sizeof(s1[0]);
	int n2 = sizeof(s2) / sizeof(s2[0]);
	int n3 = sizeof(s3) / sizeof(s3[0]);


	int ans = FindShortestDist_1(s1, n1, s2, n2, s3, n3);
	int ans = FindShortestDist(s1, n1, s2, n2, s3, n3);
	printf("ans = %d\n", ans);

	return 0;
}