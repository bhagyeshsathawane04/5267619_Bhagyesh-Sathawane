#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

/*
 * To return the string from the function, you should either do static allocation or dynamic allocation
 *
 * For example,
 * char* return_string_using_static_allocation() {
 *     static char s[] = "static allocation of string";
 *
 *     return s;
 * }
 *
 * char* return_string_using_dynamic_allocation() {
 *     char* s = malloc(100 * sizeof(char));
 *
 *     s = "dynamic allocation of string";
 *
 *     return s;
 * }
 *
 */
char* isValid(char* s) {

int freq[26] = {0};

    // for Counting character frequency
    for (int i = 0; s[i] != '\0'; i++) {
        freq[s[i] - 'a']++;
    }

    // Filter out zero frequencies
    int nonZeroFreq[26];
    int k = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            nonZeroFreq[k++] = freq[i];
        }
    }

    // Count frequencies of frequencies
    int fCount[100001] = {0}; // Assuming max frequency won't exceed this
    for (int i = 0; i < k; i++) {
        fCount[nonZeroFreq[i]]++;
    }

    int uniqueFreq = 0;
    int firstFreq = -1, secondFreq = -1;

    // Determine unique frequencies
    for (int i = 1; i < 100001; i++) {
        if (fCount[i] > 0) {
            uniqueFreq++;
            if (firstFreq == -1) {
                firstFreq = i;
            } else if (secondFreq == -1) {
                secondFreq = i;
            }
        }
    }

    if (uniqueFreq == 1) {
        return "YES";
    } else if (uniqueFreq == 2) {
        // Case: One frequency is 1 and appears only once
        if ((fCount[1] == 1) && (firstFreq == 1 || secondFreq == 1)) {
            return "YES";
        }
        // Case: Frequencies differ by 1 and higher frequency appears only once
        if ((abs(firstFreq - secondFreq) == 1) && 
            ((fCount[firstFreq] == 1 && firstFreq > secondFreq) || 
             (fCount[secondFreq] == 1 && secondFreq > firstFreq))) {
            return "YES";
        }
    }
    
    return "NO";
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* s = readline();

    char* result = isValid(s);

    fprintf(fptr, "%s\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}
