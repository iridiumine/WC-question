#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 10

int counts_letters = 0, counts_words = 0, counts_lines = 0;
int counts_null_lines = 0, counts_code_lines = 0, counts_comment_lines = 0;

void Counts_lines(FILE *fp) {
    char ch = fgetc(fp);
    
    while (ch != EOF) {
        if (ch == '\n') {
            counts_lines++;
        }
        
        ch = fgetc(fp);
    }
}

void Counts_words(FILE *fp) {
    char ch = fgetc(fp);
    int flag = 0;
    
    while (ch != EOF) {
        if (flag == 1) {
            if (ch < 'A' || (ch > 'Z' && ch < 'a') || ch > 'z') {
                flag = 0;
            }
        }
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
            if (flag == 0) {
                flag = 1;
                counts_words++;
            }
        }
        
        ch = fgetc(fp);
    }
}

void Counts_letters(FILE *fp) {
    char ch = fgetc(fp);
    
    while (ch != EOF) {
        if (ch >= '!' && ch <= '~') {
            counts_letters++;
        }
        
        ch = fgetc(fp);
    }
}

void Counts_lines_details(FILE *fp) {
    char ch = fgetc(fp);
    int flag = 0, present_words = 0, slash = 0;
    
    while (ch != EOF) {
        if (ch == '\n') {
            flag = 1;
            if (present_words >= 2 && slash < 2) {
                counts_code_lines++;
            }
            if (present_words <= 1) {
                counts_null_lines++;
            }
        }
        if (flag == 0) {
            if (present_words <= 2 && ch == '/') {
                slash++;
            }
            if (ch >= '!' && ch <= '~') {
                present_words++;
            }
            if (present_words == 1 && slash == 1) {
                if (ch == '/') {
                    counts_comment_lines++;
                }
            }
            if (present_words == 2 && slash == 1) {
                if (ch == '/') {
                    counts_comment_lines++;
                }
            }
        }
        else if (flag == 1) {
            present_words = 0;
            slash = 0;
            flag = 0;
        }
        
        ch = fgetc(fp);
    }
}

int main(int argc, char const *argv[]) {
    FILE *fp = NULL;
    char *parameter = (char *)malloc(MAXSIZE * sizeof(char));
    char *file_name = (char *)malloc(MAXSIZE * sizeof(char));
    
    scanf("%s", parameter);
    scanf("%s", file_name);
    
    if ((fp = fopen(file_name, "r")) == NULL) {
        printf("Open file failed!\n");
        exit(0);
    }
    
    if (strcmp("-c", parameter) == 0) {
        Counts_letters(fp);
        printf("The total number of letters are %d.\n", counts_letters);
    }
    if (strcmp("-w", parameter) == 0) {
        Counts_words(fp);
        printf("The total number of words are %d.\n", counts_words);
    }
    if (strcmp("-l", parameter) == 0) {
        Counts_lines(fp);
        printf("The total number of lines are %d.\n", counts_lines);
    }
    if (strcmp("-a", parameter) == 0) {
        Counts_lines_details(fp);
        printf("The total number of code lines are %d.\n", counts_code_lines);
        printf("The total number of null lines are %d.\n", counts_null_lines);
        printf("The total number of comment lines are %d.\n", counts_comment_lines);
    }
    
    fclose(fp);
    
    return 0;
}
