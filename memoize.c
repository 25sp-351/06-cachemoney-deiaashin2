#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "memoize.h"

char *memoized_values[MEMOIZATION] = {NULL};

char* get_memoized_value(int cents) {
    if (cents < MEMOIZATION && memoized_values[cents] != NULL) {
        return memoized_values[cents];
    }
    return NULL;
}

void set_memoized_value(int cents, const char *value) {
    if (cents < MEMOIZATION) {
        if (memoized_values[cents] != NULL) {
            free(memoized_values[cents]);
        }
        memoized_values[cents] = strdup(value);
    }
}

void free_memoization() {
    for (int i = 0; i < MEMOIZATION; i++) {
        if (memoized_values[i] != NULL) {
            free(memoized_values[i]);
        }
    }
}
