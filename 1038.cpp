#include<cstdio>
int hashTable[110]={0};

int main()
{
	int N,K,score;
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
	{
		scanf("%d",&score);
		hashTable[score]++;
	}
	scanf("%d",&K);
	for(int i = 0;i < K; i++)
	{
		scanf("%d", &score);
		printf("%d", hashTable[score]);
		if(i < K - 1) {
            printf(" ");
        }
	}
	return 0;
}