#include <stdio.h>
#include <stdlib.h>

char* decimal_to_binary(int number) {
    int number_copy = number;
    int iterator = 0;
    while (number_copy != 0) {
        iterator++;
        number_copy /= 2;
    }

    char* get_digits = malloc((iterator + 1) * sizeof(char));
    if (get_digits == NULL) return NULL;
    iterator = 0;
    while (number != 0) {
        if (number % 2 == 0) get_digits[iterator] = '0';
        if (number % 2 != 0) get_digits[iterator] = '1';
        iterator++;
        number /= 2;
    }

    get_digits[iterator] = '\0';

    char* result = malloc((iterator + 1) * sizeof(char));
    if (result == NULL) return NULL;
    int size = iterator;
    for (int i = 0; i < size; i++) {
        result[i] = get_digits[size - i - 1];
    }
    result[iterator] = '\0';

    return result;
}

int main() {
    int number = 20;
    char* get_decimal_to_binary = decimal_to_binary(number);

    if (get_decimal_to_binary != NULL) {
        printf("%s\n", get_decimal_to_binary);
        free(get_decimal_to_binary);
    }
    return 0;
}