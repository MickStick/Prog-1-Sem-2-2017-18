#include <stdio.h>
#include <conio.h>

int main() {
    char opt;

    printf("Enter a character: ");
    scanf("%c", &opt);

    printf("Value: %d", (opt + '0'));

    return 0;
}
