#include<stdio.h>
int climbStairs(int n) {
    int f1 = 1, f2 = 2, f3 = 2;
    if (n == 1)
    {
        return f1;
    }
    while (n > 2)
    {
        f3 = f1 + f2;
        f1 = f2;
        f2 = f3;
        n--;
    }
    return f3;

}
int main()
{
    int n = 0;
    scanf_s("%d", &n);
   int x=  climbStairs(n);
   printf("%d \n",x);
   return 0;
}