#include <stdio.h>
#include <string.h>

#define MAX_LINE 256

int is_int(char i) {
    if(i == '0' || i == '1' || i == '2' || i == '3' || i == '4' || i == '5' || i == '6' || i == '7' || i == '8' || i == '9'){
        return i - '0';
    }
    return -1;
}

int main() {
    FILE *file;
    char line[MAX_LINE];
    int is_stack = 0;
    int push_count = 0;
    int pop_count = 0;
    int forFunc = 0;
    int forFuncN = 1;
    int inIf = 0;
    int len = 1;
    int new = 0 ;

    file = fopen("..\\code.c", "r");
    if (file == NULL) {
        printf("Could not open file\n");
        return 1;
    }

    while (fgets(line, MAX_LINE, file)) {

        if (strstr(line, "for")) {
           forFunc++;
           char *start;
           char *end;
           if (strstr(line, "<")) {
            start = strstr(line, "<");
            end = start;
            while(is_int(*start) == -1) {
                start++;
                end ++;
            }
            while(is_int(*end) != -1) {
                end++;
            }
            printf("%d len \n", len);
           }
           else if (strstr(line, ">")) {
            start = strstr(line, ">");
            end = strstr(line, ">");
            while(is_int(*start) != -1){
                end++;
            }
           }
           else if (strstr(line, "=")) {
            start = strstr(line, "=");
            end = strstr(line, "=");
            while(is_int(*start) != -1){
                end++;
            }
           }
           end--;
           while(is_int(*end) != -1){
            new += is_int(*end) * len;
            len *= 10;
            end--;
           }

           new += forFuncN;
           printf("%d new \n", new);
           int temp = forFuncN;
           forFuncN = new;
           new = temp;
        }
        if (strstr(line, "if")) {
           inIf = 1;
        }
        if (strstr(line, "}")) {
            if(inIf == 0) {
                forFunc--;
                forFuncN = new;
            } else {
                inIf = 0;
            }
        }
        if (strstr(line, "push(")) {
            push_count += forFuncN ;   
            is_stack = 1;
        }
        if (strstr(line, "pop(")) {
            pop_count += forFuncN ;   
            is_stack = 1;
        }

    }

    fclose(file);

    if (is_stack) {
        printf("The code is implementing a stack.\n");
        printf("Number of push functions: %d\n", push_count);
        printf("Number of pop functions: %d\n", pop_count);
    } else {
        printf("The code is implementing an array or something else.\n");
    }

    return 0;
}
