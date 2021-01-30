 #include <stdio.h>

int main() {
    int t, num, currentCount = 0, maxCount = 0;
    scanf("%d%*c", &t);

    char istr;

    for (int i = 0; i < t; ++i) {
        scanf("%c %d%*c", &istr, &num);

        if (istr == 'E') {
            currentCount += num;
        } else if (istr == 'L') {
            currentCount -= num;

            for (int i = 0; i < num; ++i) {
                scanf("%*d%*c");
            }
        }

        maxCount = currentCount > maxCount ? currentCount : maxCount;
    }

    printf("%d", maxCount);

    return 0;
}