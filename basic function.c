#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 10

int main(int argc, char const *argv[]) {
    FILE *fp = NULL;
    int counts_letters = 0, counts_words = 0, counts_lines = 0, flag = 0;   //flag标志是否有新单词记录
    char *parameter = (char *)malloc(MAXSIZE * sizeof(char));
    char *file_name = (char *)malloc(MAXSIZE * sizeof(char));
    
    scanf("%s", parameter);
    scanf("%s", file_name);
    
    if ((fp = fopen(file_name, "r")) == NULL) {
        printf("Open file failed!\n");
        exit(0);
    }
    
    char ch = fgetc(fp);
    while (ch != EOF) {
        if (ch >= '!' && ch <= '~') {
            counts_letters++;
        }                             //计数字符
        if (flag == 1) {              //存在一个新单词后
            if (ch < 'A' || (ch > 'Z' && ch < 'a') || ch > 'z') {
                flag = 0;                 //新单词结束
            }
        }
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
            if (flag == 0) {            //没有新单词时
                flag = 1;
                counts_words++;
            }                           //出现新单词的时候，单词数+1
        }
        if (ch == '\n') {
            counts_lines++;             //计数行数
        }
        ch = fgetc(fp);
    }
    
    if (strcmp("-c", parameter) == 0) {
        printf("The total number of letters are %d.\n", counts_letters);
    }
    if (strcmp("-w", parameter) == 0) {
        printf("The total number of words are %d.\n", counts_words);
    }
    if (strcmp("-l", parameter) == 0) {
        printf("The total number of lines are %d.\n", counts_lines);
    }
    
    fclose(fp);
    
    return 0;
}
