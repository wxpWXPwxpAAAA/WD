#include"help.h"


//暴力求解  O(n^3)  O(1)
int FindShortestDist(int s1[], int n1, int s2[], int n2, int s3[], int n3)
{
	int min_dist = INT_MAX;
	int a, b, c;
	for(int i=0; i<n1; ++i)
	{
		for(int j=0; j<n2; ++j)
		{
			for(int k=0; k<n3; ++k)
			{
				//               a  -  b            b  -  c           c   -  a
				int dist = abs(s1[i]-s2[j]) + abs(s2[j]-s3[k]) + abs(s3[k]-s1[i]);
				if(dist < min_dist)
				{
					min_dist = dist;
					a = s1[i];
					b = s2[j];
					c = s3[k];
				}
			}
		}
	}
	printf("(%d, %d, %d)\n", a, b, c);
	return min_dist;
}

//用来判断a是否为三数中的最小值
int is_min_data(int a, int b, int c)
{
	if(a<=b && a<=c)
		return 1;
	return 0;
}

//O(n) O(1)
int FindShortestDist_1(int s1[], int n1, int s2[], int n2, int s3[], int n3)
{
	int min_dist = INT_MAX;
	int i=0, j=0, k=0;
	int a, b, c;
	while(i<n1 && j<n2 && k<n3)
	{
		int dist = abs(s1[i]-s2[j]) + abs(s2[j]-s3[k]) + abs(s3[k]-s1[i]);
		if(dist < min_dist)
		{
			min_dist = dist;
			a = s1[i];
			b = s2[j];
			c = s3[k];
		}

		if(is_min_data(s1[i], s2[j], s3[k]))
			i++;
		else if(is_min_data(s2[j], s3[k], s1[i]))
			j++;
		else
			k++;
	}

	printf("(%d, %d, %d)\n", a, b, c);
	return min_dist;
}