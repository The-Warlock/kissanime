#include <stdlib.h>
#include <stdio.h>

void db_read(char *fname,char **buffer){
        FILE *fp = fopen(fname,"r");
        char ch; 
        int i;
        if (fp==NULL) printf("error");
        i=0;
        while((ch = fgetc(fp))!=EOF){
                i++;
        }   
        i++;
        *buffer = realloc(*buffer,i*sizeof(char));
        i=0;
        rewind(fp);
        while((ch = fgetc(fp))!=EOF){
                (*buffer)[i]=ch;
                i++;
        }   
        (*buffer)[i]='\0';
        fclose(fp);
}

