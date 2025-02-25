#include <stdio.h>
#include <string.h>
#include "money_converter.h"
#include "memoize.h"

int main() {
    int cents;
    char output[512];

    printf("Enter an amount in cents: ");
    scanf("%d", &cents);

    // Check if the value is already cached
    char *cached_value = get_memoized_value(cents);
    if (cached_value != NULL) {
        strcpy(output, cached_value);
    } else {
        money_to_text(cents, output);
        set_memoized_value(cents, output);
    }

    printf("Amount in words: %s\n", output);

    free_memoization();

    return 0;
}
