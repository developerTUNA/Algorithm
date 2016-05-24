#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>

int Problem09012(void)
{
    int nCount = 0;
    size_t llnBracketLen = 0;
    int nBracketStack = 0;
    char szBracket[51] = {0,};

    scanf("%d", &nCount);
    for(int i = 0; i < nCount; i++)
    {
        nBracketStack = 0;
        memset(szBracket, 0, sizeof(szBracket));
        
        scanf("%s", szBracket);
        llnBracketLen = strlen(szBracket);
        for(int j = 0; j < llnBracketLen; j++)
        {
            if(szBracket[j] == '(')
            {
                nBracketStack++;
            }
            else if(szBracket[j] == ')')
            {
                nBracketStack--;
            }
            if(nBracketStack<0)
            {
                break;
            }
        }
        if(nBracketStack == 0)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}