#include<stdio.h>
#include<string.h>
int fun(int,int);
void main()
{
	int rem[10],did[10],div[10];
	int n,m,mul,i,j;
	printf("enter a no:");
	scanf("%d",&n);
	printf("enter a dataword:");
	for(i = 0;i < n;i++)
	{
		scanf("%d",&did[i]);
	}
	printf("enter a no:");
	scanf("%d",&m);
	printf("enter a generator:");
	for(j = 0;j < m;j++)
	{
		scanf("%d",&div[j]);
		rem[j]= did[j];
	}
	for(i = n;i < m + n - 1;i++)
	{
		did[i] = 0;
	}
	mul = did[0];
	for(i = m;i < n + m;i++)
	{

		for(j = 0;j < m - 1;j++)
		{
			rem[j] = fun(rem[j + 1],(div[j  + 1] * mul));
		}
		if(i == n + m -1)
			rem[j] = fun(did[n-1],(div[j  + 1] * mul));
		else
			rem[j] = did[i];
		mul = rem[0];
	}
	
for(i = n;i < m + n - 1;i++)
	{
		did[i] = rem[i-n];
	}
	printf("\n");
	for(j = 0;j < n + m - 1;j++)
	{
		printf("%d",did[j]);
	}
	printf("\n");
}
int fun(int i,int j)
{
	if(i == j)
		return 0;
	else
		return 1;
}

/*
12

1

0
1
1
1
1
0
1
0
1
0
1

4

1

0
1
1
*/