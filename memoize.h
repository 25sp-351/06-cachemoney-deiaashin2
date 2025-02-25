#ifndef MEMOIZE_H
#define MEMOIZE_H

#define MEMOIZATION 150000

char* get_memoized_value(int cents);
void set_memoized_value(int cents, const char *value);
void free_memoization();

#endif
