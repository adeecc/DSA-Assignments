#include <stdio.h>

int n, found = 0, strIdx = 1, start;

// Recursively Search for "baab"
void substrMatch(int idx) {

    if (strIdx == n + 1) {
        if (!found) printf("NO");
        return;
    }

    char current;
    scanf("%c", &current);

    strIdx++;

    switch (idx)
    {
    case 0:
        if (current == 'b') 
        {
            start = strIdx - 1;
            idx++;
        }

        break;

    case 1:
    case 2:
        if (current == 'a') 
            idx++;
        else {
            idx = 1;
            start = strIdx - 1;
        }
           
        break;

    case 3:
        if (current == 'b') {
            if (!found) {
                printf("YES ");
                found = 1;
            }

            printf("%d ", start);
            start = strIdx - 1;
            
            idx = 1;
        }
            
        else
            idx = 0;
           
        break;

    default:
        break;
    }

    substrMatch(idx);
}

int main() {
    scanf("%d%*c", &n);
    substrMatch(0);
    return 0;
}
