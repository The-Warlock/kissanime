// gcc -lcurl -Wall test.c libraries/*.c -o ../a.out

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#include "libraries/downloader.h"
#include "libraries/parser.h"

int main(){


/*
*   DownloadVideo test
*
    char* url="https://redirector.googlevideo.com/videoplayback?requiressl=yes&shardbypass=yes&cmbypass=yes&id=adb7fee0a75a8307&itag=18&source=picasa&cmo=secure_transport=yes&ip=0.0.0.0&ipbits=0&expire=1421676958&sparams=requiressl,shardbypass,cmbypass,id,itag,source,ip,ipbits,expire&signature=DA6A35FF66D2974C0677FB0E113A0F4DB733D972.415164ABBB4794AF36E7739D8AECCA24743911FA&key=lh1";
    DownloadVideo(url,"../test.mp4");
*
*
*/


/*
*   DownloadHtml test
*
    char *buffer = malloc(500000*sizeof(char));
    int status;
    status = DownloadHtml("http://kissanime.com/Anime/Naruto-Shippuuden/Episode-388?id=82776",buffer);
    char html_data[strlen(buffer)];
    strcpy(html_data,buffer);
    free(buffer);
    printf("%lu",strlen(html_data));
    printf("%s",html_data);
*
*
*/


/*
*   parse_videolink | DownloadHTML -> parse_videolink
*/
    char *buffer = malloc(500000*sizeof(char));
    int status;
    status = DownloadHtml("http://kissanime.com/Anime/Naruto-Shippuuden/Episode-388?id=82776",buffer);
    char html_data[strlen(buffer)];
    strcpy(html_data,buffer);
    free(buffer);

    char* regex = "...): <a target=\"_blank\" href=\"([^\"]+)";
    char* buffer2 = NULL;
    status = parse_videolink(html_data,regex,&buffer2);
    printf("%s\n",buffer2);
    free(buffer2);
    return 0;

/*
*
*/





return 0;
}
