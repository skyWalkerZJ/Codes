#include <malloc.h>
#include <string.h>
#include <stdio.h>
char *dstStr;
int main()
{
    int arr[]={1,2,3,4};
    int *arr1=arr;
    printf("%d",arr1[10]);
    char str[]="123456789";
    if(dstStr==NULL) printf("str is NULL");
}