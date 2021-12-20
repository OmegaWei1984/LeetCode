#include <stdio.h>
#include <string.h>

int strStr(char * haystack, char * needle){
    
}

int main(void)
{
    char *haystack = "mississippi";
    char *needle = "issip";
    int ans = strStr(haystack, needle);
    printf("ans: %d\n", ans);

    return 0;
}