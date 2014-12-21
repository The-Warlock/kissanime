#include <stdio.h>
#include <curl/curl.h>
#include <string.h>
#include <stdlib.h>

#include "downloader.h"



/*
*   private functions
*/


static size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream)
{
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

static size_t write_data2(const char *buffer, size_t size, size_t nmemb, char *userp)
{
    //need to dynamically extend the array via realloc()

    size_t len;
    len = size * nmemb;
    strncat(userp, buffer,len); 
    return len;
}

/*
*   public functions
*/

void DownloadVideo(char* url, char* savePath) //todo provide savePath and filename separately
{
    CURL* curl;
    FILE* fp;
    CURLcode res;
    char* outfilename = savePath;
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

int DownloadHtml(char* url, char* vp)
{
    CURL* curl;
    CURLcode res;
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data2);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, vp);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
        struct curl_slist* headers = NULL;
        headers = curl_slist_append(headers,"User-Agent: Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/39.0.2171.71 Safari/537.36");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
    return res;
}
