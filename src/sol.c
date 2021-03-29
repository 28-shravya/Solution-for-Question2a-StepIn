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
        printf("error in opening file!");
        return 0;
    } 
    char buffer[1024];
    int row=0;
    int column=0;
    int i=0;
    while(fgets(buffer,1024,file))
    {
        column=0;
        row++;
        if(row==1)
        {
            continue;
        }
        char* token = strtok(buffer, ",");
        while( token != NULL ) {
        if(column==0)
        {
            strcpy((arr+i)->name,token);
        }
        if(column==1)
        {
           strcpy((arr+i)->mail_id,token);
           
        }
        if(column==2)
        {   strcpy((arr+i)->git_link,token);
          
        }
        column++;
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
