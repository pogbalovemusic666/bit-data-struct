
#include<stdio.h>


long long Factorial(size_t N)
{
	return N < 2 ? N : Factorial(N - 1) * N;
}
//long long Fibonacci(size_t N)
//{
//	return N < 2 ? N : Fibonacci(N - 1) + Fibonacci(N - 2);
//}

int missingNumber(int* nums, int numsSize) {

	int sum = 0;
	for (int i = 0; i < numsSize ; i++)
	{
		sum ^= i+1;
		sum ^=  *(nums + i);
		//printf("%d", *(nums + i));
	}
	return sum;

}

int* singleNumbers(int* nums, int numsSize, int* returnSize) {
	
	int num=0;
	int i;
	for ( i = 0; i < numsSize; i++)
	{
		num ^= *(nums + i);

	}
	int flag;
	for (flag = 0; flag < 32; flag++)
	{
		if (((num >> flag)&1) == 1)
		{
			break;

		}
	}
	//printf("%d", flag);
	int ret[2] = {0};
	
	for ( i = 0; i < numsSize; i++)
	{
		if (((*(nums +i) >> flag) &1)== 1)
		{
			ret[0] ^= *(nums + i);
			//printf("标志为1：%d", *nums + i);
		}
		else
		{
			ret[1] ^= *(nums + i);

		}

	}
	*returnSize = 2;
	return ret;
}
int main()
{

	
	int a[9] = { 1, 2, 10, 4, 1, 4, 3, 3 };
	int *ret = {0};
	int num = 0;
	ret=singleNumbers(a, 8,&num);
printf("\n%d\t %d", ret[0],ret[1]);

}