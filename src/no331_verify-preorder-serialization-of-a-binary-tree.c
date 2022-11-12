#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isValidSerialization(char* preorder) {
    int n = strlen(preorder);
    int i = 0;
    int slots = 1;
    while (i < n) {
        if (!slots) {
            return false;
        }
        if (preorder[i] == ',') {
            i++;
        } else if (preorder[i] == '#') {
            slots--;
            i++;
        } else {
            // 读一个数字
            while (i < n && preorder[i] != ',') {
                i++;
            }
            slots++;  // slots = slots - 1 + 2
        }
    }
    return !slots;
}

int main(void)
{
    // char *preorder = "1,#";
    char *preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#";
    bool ans = isValidSerialization(preorder);
    printf("ans: %s\n", ans ? "true" : "false");

    return 0;
}