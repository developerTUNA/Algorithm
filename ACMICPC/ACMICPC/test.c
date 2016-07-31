#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int* twoSum(int* nums, int numsSize, int target);
int test()
{
    int nums[3] = {3, 2, 4};
    int target = 6;

    int *result = twoSum(nums, 3, target);
    printf("%d %d", result[0], result[1]);
    return 0;int* twoSum(int* nums, int numsSize, int target)
{
    int *ret = NULL;
    ret = (int*)malloc(sizeof(int) * 2);
    memset(ret, 0, sizeof(int) * 2);
    for(int i = 0; i<numsSize; i++)
    {
        for(int j = i+1; j<numsSize; j++)
        {
            if((nums[i] + nums[j]) == target)
            {
                ret[0] = i;
                ret[1] = j;
                return ret;
            }
        }
    }
}

    return ret;
}