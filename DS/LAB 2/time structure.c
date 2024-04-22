#include <stdio.h>
#include <stdlib.h>

struct Time {
    int hour,min,sec;
};

void displayTime(struct Time t) {
    printf("%d:%d:%d\n", t.hour, t.min, t.sec);
}

struct Time readTime() {
    struct Time t;
    scanf("%d%d%d", &t.hour,&t.min,&t.sec);
    return t;
}

struct Time addTime(struct Time t1, struct Time t2) {
    struct Time result;

    int totalSecT1 = t1.sec + t1.min * 60 + t1.hour * 3600;
    int totalSecT2 = t2.sec + t2.min * 60 + t2.hour * 3600;
    int totalSeconds = totalSecT1 + totalSecT2;

    result.hour = totalSeconds / 3600;
    int remainingSec = totalSeconds % 3600;
    result.min = remainingSec / 60;
    result.sec = remainingSec % 60;

    return result;
}

struct Time differenceTime(struct Time t1, struct Time t2) {
    struct Time result;

    int totalSecT1 = t1.sec + t1.min * 60 + t1.hour * 3600;
    int totalSecT2 = t2.sec + t2.min * 60 + t2.hour * 3600;
    int diffSeconds = abs(totalSecT1 - totalSecT2);

    result.hour = diffSeconds / 3600;
    int remainingSec = diffSeconds % 3600;
    result.min = remainingSec / 60;
    result.sec = remainingSec % 60;

    return result;
}

int main() {
    struct Time t1, t2;

    printf("Enter first time : ");
    t1 = readTime();

    printf("Enter second time : ");
    t2 = readTime();

    struct Time sum = addTime(t1, t2);
    struct Time diff = differenceTime(t1, t2);

    printf("Sum of times : ");
    displayTime(sum);

    printf("Difference of times : ");
    displayTime(diff);

    return 0;
}

