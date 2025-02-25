#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "money_converter.h"

// Helping arrays for conversion
const char *ones[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
const char *teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
const char *tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
const char *hundreds = "hundred";
const char *thousand = "thousand";

// Add blank space in between words
void add_space(char *output, const char *text) {
    if (strlen(output) > 0) {
        strcat(output, " ");
    }
    strcat(output, text);
}

// Converts number into text representation
void number_text(int number, char *output) {
    if (number >= 1000) {
        number_text(number / 1000, output);
        add_space(output, thousand);
        number %= 1000;
    }
    if (number >= 100) {
        add_space(output, ones[number / 100]);
        add_space(output, hundreds);
        number %= 100;
    }
    if (number >= 20) {
        add_space(output, tens[number / 10]);
        number %= 10;
    }
    if (number >= 10) {
        add_space(output, teens[number - 10]);
        return;
    }
    if (number > 0) {
        add_space(output, ones[number]);
    }
}

void money_to_text(int cents, char *output) {
    int dollars = cents / 100;
    int cents_remaining = cents % 100;

    // Changes dollars to text
    char dollars_text[512] = "";
    if (dollars > 0) {
        number_text(dollars, dollars_text);
        sprintf(output, "%s dollars", dollars_text);
    } else {
        strcpy(output, "zero dollars");
    }

    // Changes cents to text
    if (cents_remaining > 0) {
        char cents_text[512] = "";
        number_text(cents_remaining, cents_text);
        sprintf(output + strlen(output), " and %s cents", cents_text);
    }
}
