#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//leetcode 有效括号相关题
bool isValid(char* s) {
    char arr[5000] = { 0 };
    int i = 0, j = 0, num = 0;
    while (*(s + i) == '(' || *(s + i) == '[' || *(s + i) == '{' || *(s + i) == ')' || *(s + i) == ']' || *(s + i) == '}')
    {
        num++;
        i++;
    }
    for (i = 0; i <num ; i++)
    {
        if (*(s + i) == '(' || *(s + i) == '[' || *(s + i) == '{')
        {
            arr[j] = *(s + i);
            j++;
        }
        else
        {
            j--;
            if (j < 0)
            {
                return false;
            }
            else if ((arr[j] == '(' && *(s + i) == ')') || (arr[j] == '[' && *(s + i) == ']') || (arr[j] == '{' && *(s + i) == '}'))
            {

            }
            else
            {
                return false;
            }
        }
    }
    if (j == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    char arr[2] = { "()" };
    
    printf("%d\n", isValid(arr));
}
