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


void parse_episode_links(char *html_data, char *regex, char **buffer){
        int begin, end;
        int w, i;
        int loop_counter;

        regex_t rgT;
        regmatch_t match[2];
        regcomp(&rgT,regex,REG_EXTENDED);

        loop_counter=0;
        char buf[200]="";
        while(strstr(buf,"-001")==NULL){
                if ((regexec(&rgT,html_data,2,match,0)) == 0) {
                        begin = (int)match[1].rm_so;
                        end = (int)match[1].rm_eo;
                        w=0;
                        for (i=begin; i<end; i++) {
                                buf[w] = html_data[i];
                                w++;
                        }
                        buf[w]='\0';
                        strcpy(buffer[loop_counter],buf);
//                        printf("%s\n",buffer[loop_counter]);
                        html_data+=end;
                        loop_counter++;
                }
        }

}
