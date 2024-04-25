//leetcode 最多盛水容器
#include<stdio.h>
#include<string.h>
int maxArea(int* height, int heightSize) {
    int left = 0, right = heightSize - 1;
    int max = 0;
    while (right >= left)
    {
        int min = *(height + right) < *(height + left) ? *(height + right) : *(height + left);
        if (min * (right - left) > max)
        {
            max = min * (right - left);
        }
        if (*(height + right) < *(height + left))
        {
            right--;
        }
        else
        {
            left++;
        }
    }
    return max;
}
int main()
{
	int arr1[9] = { 1,8,6,2,5,4,8,3,7 };
	int arr2[2] = { 1,1 };
    int a = maxArea(arr1, sizeof(arr1)/sizeof(arr1[0]));
    int b = maxArea(arr2, sizeof(arr2) / sizeof(arr2[0]));
    printf("%d\n", a);
    printf("%d\n", b);
    int c = sizeof(arr1) / sizeof(arr1[0]);
    int d = sizeof(arr2) / sizeof(arr2[0]);
    return 0;
}
