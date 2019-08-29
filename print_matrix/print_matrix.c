/*
 * MIT License
 *
 * Copyright (c) 2019 Ismael Filipe Mesquita Ribeiro - nakinx
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 0
#define FALSE -1

#define ELEMENTS 10
#define STRLEN 10
#define BUFFERLEN 1024
#define HEIGHTLEN 5

void printer(const char * buffer,
             const int len) {
    fprintf(stdout, "\n\nPrinting (%d) elements...\n", len);
    for (int i = 0; i < len; i++) {
        fprintf(stdout, "0x%02X ", buffer[i]);
    }
    fprintf(stdout, "\nPrinting finished.\n\n");
}

int main(int argc,
         char * argv[]) {
    int lh_count = 1;
    int hm = 1;
    char line[BUFFERLEN + 1];
    char matrix[ELEMENTS][STRLEN + 1] = { "###  #####\0", "####  ####\0", "########  \0", "  ########\0", "######  ##\0",
                                          "###  #####\0", "####  ####\0", "########  \0", "  ########\0", "######  ##\0" };
    int enable_heigth_test = FALSE;

    if (enable_heigth_test == TRUE) {
        char hMatrixTester[3][10 + 1] = { "ABCDEFGHIJ\0" , "KLMNOPRSTU\0", "VXZWX12345\0" };

        printf("Heigth: (%d)\n", HEIGHTLEN);

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 10; j+=HEIGHTLEN) {
                int h = j + HEIGHTLEN;

                if (h > 10)
                    h -= h - 10;

                for (; h > j ; h--) {
                    fprintf(stdout, "i(%d) j(%d) h-1(%d) (%c)\n", i, j, (h-1), hMatrixTester[i][h-1]);
                }
                fprintf(stdout, "\n");
            }
            fprintf(stdout, "\n");
        }
        return 0;
    }

    memset(line, 0, sizeof(line));

    for (int i = 0; i < ELEMENTS; i++)
        fprintf(stdout, "%s\n", matrix[i]);

    printf("Elements: (%d)\nHeight: (%d)\n", ELEMENTS, HEIGHTLEN);

    for (int i = 0; i < ELEMENTS; i++) {
        for (int j = 0; j < STRLEN; j+=HEIGHTLEN) {
            int h = j + HEIGHTLEN;

            if (h > STRLEN)
                h -= h - STRLEN;

            for (; h > j ; h--) {
                fprintf(stdout, "matrix[%d][%d] = %c\n", i, h-1, matrix[i][h-1]);
                if (matrix[i][h-1] == '#') {
                    fprintf(stdout, "matrix[%d][%d] - line: 0x%02X mult: 0x%02X result: 0x%02X\n",i ,j , line[h], hm, (line[h] | hm));
                    line[h] = line[h] | hm;
                }
            }
        }

        printf("\n");

        if (lh_count < HEIGHTLEN) {
            lh_count++;
            hm *= 2;
            continue;
        }

        printer(line, STRLEN);
        lh_count = 1;
        hm = 1;
        memset(line, 0, sizeof(line));
    }

    return 0;
}
