#include <stdio.h>
#include <curl/curl.h>
#include <string.h>

#include "downloader.h"



/*
*   private functions
*/


size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}


/*
*   public functions
*/


void DownloadVideo(char* url, char* savePath){
    CURL* curl;
    FILE* fp;
    CURLcode res;
    char* outfilename = "test.mp4";
    if (strlen(outfilename) > FILENAME_MAX){
        printf("file path/ name too long");
        return;
    }
    curl = curl_easy_init();
    if (curl) {
        fp = fopen(outfilename,"wb");
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        fclose(fp);
    }
    printf("%d",res);
}

char* DownloadHtml(char* url){
    
}

