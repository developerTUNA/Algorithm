#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int Problem02667(void)
{
    int num;
    int **arr;
    char *str;
    char str_temp[2];
    int count = 1;
    int *stack;
    int *stack_count;
    int stack_top = -1;
    scanf("%d", &num);
    arr = (int **)malloc(sizeof(int*)*(num + 2));
    for (int i = 0; i < num + 2; i++)
    {
        arr[i] = (int *)malloc(sizeof(int)*(num + 2));
        memset(arr[i], 0, sizeof(int)*(num + 2));
    }

    stack = (int *)malloc(sizeof(int)*(num + 2)*(num + 2));
    stack_count = (int *)malloc(sizeof(int)*(num + 2)*(num + 2));

    str = (char*)malloc(sizeof(char)*(num + 2));
    for (int i = 1; i <= num; i++)
    {
        memset(str, 0, sizeof(char)*(num + 2));
        scanf("%s", str);
        for (int j = 1; j <= num; j++)
        {
            memset(str_temp, 0, 2);
            strncpy(str_temp, str + j - 1, 1);
            arr[i][j] = atoi(str_temp);
        }
    }

    for (int i = 1; i <= num; i++)
    {
        for (int j = 1; j <= num; j++)
        {
            if (arr[i][j] == 1)
            {
                int flag = 1;
                count++;
                arr[i][j] = count;
                stack_count[count] = 1;
                stack[++stack_top] = i*(num + 2) + j;
                int p = i;
                int q = j;
                while (flag)
                {
                    if (arr[p - 1][q] == 1)
                    {
                        p--;
                        stack[++stack_top] = p*(num + 2) + q;
                        arr[p][q] = count;
                        stack_count[count]++;
                    }
                    else if (arr[p + 1][q] == 1)
                    {
                        p++;
                        stack[++stack_top] = p*(num + 2) + q;
                        arr[p][q] = count;
                        stack_count[count]++;
                    }
                    else if (arr[p][q - 1] == 1)
                    {
                        q--;
                        stack[++stack_top] = p*(num + 2) + q;
                        arr[p][q] = count;
                        stack_count[count]++;
                    }
                    else if (arr[p][q + 1] == 1)
                    {
                        q++;
                        stack[++stack_top] = p*(num + 2) + q;
                        arr[p][q] = count;
                        stack_count[count]++;
                    }
                    else
                    {
                        if ((--stack_top) == -1)
                        {
                            flag = 0;
                        }
                        p = stack[stack_top] / (num + 2);
                        q = stack[stack_top] % (num + 2);
                    }
                }
            }
        }
    }


    //for (int i = 1; i <= num; i++)
    //{
    //    for (int j = 1; j <= num; j++)
    //    {
    //        printf("%d ", arr[i][j]);
    //    }
    //    printf("\n");
    //}

    for (int i = 2; i <= count; i++)
    {
        int min = stack_count[i];
        int min_index = i;
        for (int j = i; j <= count; j++)
        {
            if (min > stack_count[j])
            {
                min = stack_count[j];
                min_index = j;
            }
        }
        int temp = stack_count[i];
        stack_count[i] = min;
        stack_count[min_index] = temp;
    }

    printf("%d\n", count - 1);
    for (int i = 2; i <= count; i++)
    {
        printf("%d\n", stack_count[i]);
    }
    return 0;
}