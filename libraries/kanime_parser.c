#include <stdlib.h>
#include <regex.h>
#include <stdio.h>

char *parse_videolink (char *string, char *regex, int *begin, int *end) {
        int i, w=0, len;
        char *word = NULL;
        regex_t rgT;
        regmatch_t match[2];
        regcomp(&rgT,regex,REG_EXTENDED);
        if ((regexec(&rgT,string,2,match,0)) == 0) {
                *begin = (int)match[1].rm_so;
                *end = (int)match[1].rm_eo;
                len = *end-*begin;
                word=malloc(len+1);
                regfree(&rgT);
                for (i=*begin; i<*end; i++) {
                        word[w] = string[i];
                        w++; }
                word[w]=0;
        }
        return word;
}

