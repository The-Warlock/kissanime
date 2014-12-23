#include <stdlib.h>
#include <regex.h>
#include <stdio.h>

#include <string.h>

int parse_videolink (char *string, char *regex, char** buffer) {
        int begin, end, len;
        int i,w=0;
        regex_t rgT;
        regmatch_t match[2];

        regcomp(&rgT,regex,REG_EXTENDED);
        if ((regexec(&rgT,string,2,match,0)) == 0) {
                begin = (int)match[1].rm_so;
                end = (int)match[1].rm_eo;
                len = end-begin+1;
                *buffer = realloc(*buffer,len*sizeof(char));
                for (i=begin; i<end; i++) {
                        *(*buffer+w) = string[i];
                        w++;
                }
                *(*buffer+w)='\0';


                regfree(&rgT);
        }
        return 0;
}

