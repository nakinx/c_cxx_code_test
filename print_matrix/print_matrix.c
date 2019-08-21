#include <stdio.h>
#include <stdlib.h>

#define ELEMENTS 10
#define STRLEN 10
#define BUFFERLEN 1024
#define HEIGHTLEN 2

void printer(const char * buffer,
             const int len) {
    fprintf(stdout, "\nPrinting (%d) elements...\n", len);
    for (int i = 0; i < len; i++) {
        fprintf(stdout, "0x%02X ", buffer[i]);
        //fprintf(stdout, "%c ", buffer[i]);
    }
    fprintf(stdout, "\nPrinting finished.\n");
}

int main(int argc, 
         char * argv[]) {
    int lh_count = 1;
    int hm = 1;
    char line[BUFFERLEN + 1];
    char matrix[ELEMENTS][STRLEN + 1] = { "###  #####\0", "####  ####\0", "########  \0", "  ########\0", "######  ##\0",
                                          "###  #####\0", "####  ####\0", "########  \0", "  ########\0", "######  ##\0" };

    memset(line, 0, sizeof(line));

    for (int i = 0; i < ELEMENTS; i++)
        fprintf(stdout, "%s\n", matrix[i]);

    for (int i = 0; i < ELEMENTS; i++) {        
        for (int j = 0; j < STRLEN; j++) {
            if (matrix[i][j] == '#') {
                fprintf(stdout, "%d %d # line: 0x%02X mult: 0x%02X result: 0x%02X\n",i ,j , line[j], hm, (line[j] | hm));
                line[j] = line[j] | hm;                
            }            
        }

        printf("\n");

        if (lh_count < HEIGHTLEN) {
            lh_count++;  
            hm*=2;          
            continue;
        }            
        
        printer(line, STRLEN);        
        lh_count = 1;
        hm = 1;
        memset(line, 0, sizeof(line));
    }

    return 0;
}