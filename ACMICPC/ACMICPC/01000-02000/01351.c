#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node01351_
{
    long long llnPoz;
    long long llnNum;
    struct Node01351_ *NodeNext;
}Node01351;

long long FindNode01351(Node01351 *NodeHead, long long llnPoz)
{
    while(1)
    {
        if(NodeHead == NULL)
        {
            return -1;
        }
        if(NodeHead->llnPoz == llnPoz)
        {
            return NodeHead->llnNum;
        }
        NodeHead = NodeHead->NodeNext;
    }
}
long long NodeAdd01351(Node01351 *NodeHead, long long llnPoz, long long llnNum)
{
    Node01351 *NodeNew = NULL;
    while(1)
    {
        if(NodeHead->NodeNext == NULL)
        {
            break;
        }
        NodeHead = NodeHead->NodeNext;
    }
    NodeNew = malloc(sizeof(Node01351));
    memset(NodeNew, 0, sizeof(Node01351));
    NodeNew->llnPoz = llnPoz;
    NodeNew->llnNum = llnNum;
    NodeNew->NodeNext = NULL;
    NodeHead->NodeNext = NodeNew;
    return 0;
}
int NodeFree01351(Node01351 *NodeHead)
{
    Node01351 *NodeTemp;

    while(1)
    {
        if(NodeHead == NULL)
        {
            break;
        }
        NodeTemp = NodeHead->NodeNext;
        free(NodeHead);
        NodeHead = NodeTemp;
    }
}
long long GO_DP(long long llnI, long long llnN, long long llnP, long long llnQ, Node01351 *NodeHead)
{
    long long llnPoz = 0;
    long long llnNum = 0;
    long long llnMemorize = 0;
    long long llnResult_NP = 0;
    long long llnResult_NQ = 0;
    if(llnI == 0)
        return 1;
    llnMemorize = FindNode01351(NodeHead, llnI);
    if(0<llnMemorize)
    {
        return llnMemorize;
    }
    else
    {
        llnResult_NP = GO_DP(llnI / llnP, llnN, llnP, llnQ, NodeHead);
        llnResult_NQ = GO_DP(llnI / llnQ, llnN, llnP, llnQ, NodeHead);
        NodeAdd01351(NodeHead, llnI, llnResult_NP + llnResult_NQ);
        return llnResult_NP + llnResult_NQ;
    }
}
int Problem01351(void)
{
    long long llnN = 0;
    long long llnP = 0;
    long long llnQ = 0;
    long long llnResult = 0;
    Node01351 *NodeHead = NULL;
    scanf("%lld %lld %lld", &llnN, &llnP, &llnQ);
    NodeHead = malloc(sizeof(Node01351));
    NodeHead->llnPoz = 0;
    NodeHead->llnNum = 1;
    NodeHead->NodeNext = NULL;
    llnResult = GO_DP(llnN, llnN, llnP, llnQ, NodeHead);
    printf("%lld\n", llnResult);
    NodeFree01351(NodeHead);
    return 0;
}