
#include<stdio.h>
int removeElement(int* nums, int numsSize, int val) {

	int* p = nums;
	int* q = nums;
	for (int i = 0; i < numsSize; i++)
	{
		if (*p == val)
		{
			p++;
			
		}
		else
		{
			*q = *p;
			p++;
			q++;
		}



	}

	return int(q - nums);
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
	int i;
	for ( i = 0; i < n; i++)
	{
		*(nums1 + i + m) = *(nums2 + i);

	}
	int tmp;
	for (i = 0; i < m + n; i++)
	{

		for (int j = 0; j < m + n - i-1; j++)
		{
			if (*(nums1 + j) > *(nums1 + j + 1))
			{
				tmp = *(nums1 + j );
				
				*(nums1 + j) = *(nums1 + j + 1);
				*(nums1 + j + 1) = tmp;
			
			}

		}
	}
}

int main()
{
	int	nums[10] = { 0, 1, 2, 2, 3, 0, 4, 2 };
	int val = 2;
	//int len = removeElement(nums, 8,val);
	//printf("len:%d", len);
	// 在函数里修改输入数组对于调用者是可见的。
// 根据你的函数返回的长度, 它会打印出数组中 该长度范围内 的所有元素。




	int nums1[10] = {1, 2, 3, 0, 0, 0};
	int m = 3; 
	int nums2[10] = {2, 5, 6};
	int n = 3;

	merge( nums1, 6, m, nums2, 3, n);
	int len = 6;
	for (int i = 0; i < len; i++) {
		printf("%d",nums1[i]);
	}

}