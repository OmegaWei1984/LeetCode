#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PUZZLE_LEN 7

int cmpchar(const void* pa, const void* pb)
{
    const char* a = (const char*)pa;
    const char* b = (const char*)pb;
    return a - b;
}

int main(void)
{
    char *my_words[] = {"aaaa","asas","able","ability","actt","actor","access"};
    char *my_puzzles[] = {"aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"};

    char **words = my_words;
    int wordsSize = 7, puzzlesSize = 6, *returnSize;
    char ** puzzles = my_puzzles;

    // {"apple","pleas","please"}
    // {"aelwxyz","aelpxyz","aelpsxy","saelpxy","xaelpsy"}

    int *ans = malloc(sizeof(int) * puzzlesSize);
    memset(ans, 0, puzzlesSize * sizeof(int));
    char *initTab = (char *)malloc(sizeof(char) * puzzlesSize);
    memset(initTab, '0', puzzlesSize);
    for (int i = 0; i < puzzlesSize; i++)
    {
        initTab[i] = puzzles[i][0]; 
    }

    for (int i = 0; i < puzzlesSize; i++)
    {
        size_t colLen = (sizeof(puzzles[i]) / sizeof(puzzles[i][0])) - 1;
        size_t eSize = sizeof(char *);
        qsort(puzzles[i], colLen, eSize, cmpchar);
        for (int j = 0; j < wordsSize; j++)
        {
            if (words[j][0] != initTab[i]) continue;
            int count = 0, find = 0;
            for (int k = 0; words[j][k] != '\0'; k++)
            {
                char *f = strchr(puzzles[i], (int)words[j][k]);
                if (f != NULL) find++;
                count++;
            }
            if (count == find) ans[i]++;
        }
    }

    for(int i = 0; i < puzzlesSize; i++)
        printf("ans[%d]:%d ", i,ans[i]);

    return 0;
}
