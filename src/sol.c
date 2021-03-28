#include <stdlib.h>
#include <stdio.h>
#include<string.h>
#include "header.h"

info_t* arr;
int read_array(char *file_name)
{
   arr=malloc(4*sizeof(info_t));
   FILE *file=fopen(file_name,"r");
    if(!file)
    {
        printf("error in opening file");
        return 0;
    } 
    char buff[1024];
    int row_count=0;
    int field_count=0;
    int i=0;
    while(fgets(buff,1024,file))
    {
        field_count=0;
        row_count++;
        if(row_count==1)
        {
            continue;
        }
        char* token = strtok(buff, ",");
        int j=0;
        while( token != NULL ) {
        if(j==0)
        {
            strcpy((arr+i)->name,token);
        }
        if(j==1)
        {
           strcpy((arr+i)->mail_id,token);
           
        }
        if(j==2)
        {   strcpy((arr+i)->git_link,token);
          
        }
        j++;
        token = strtok(NULL, ",");
        }       
        i=i+1;       
      }
   fclose(file);
   return 1;
}

int compare(const void* p, const void* q)
{
    return strcmp(((info_t*)p)->name,
                  ((info_t*)q)->name);
}
int sort(info_t *temp)
{
    if(temp==NULL)
    {
        return 0;
    }
    qsort(temp, 4, sizeof(info_t), compare);
    for (int i = 0; i < 3; i++) {
        printf("%s\n",(temp+i)->name);
        printf("%s\n",(temp+i)->mail_id);
        printf("%s\n",(temp+i)->git_link);
    }
    return 1;
}

int display(info_t *temp)
{
    if(temp==NULL)
    {
        return 0;
    }
    for(int i=0;i<3;i++)
    {
        printf("Name = %s\n",(temp+i)->name);
        printf("Mail-id = %s\n",(temp+i)->mail_id);
        printf("Git-link = %s\n",(temp+i)->git_link);
    }
    return 1;
}
