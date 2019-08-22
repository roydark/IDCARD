#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUMBER 3468
#define ID 7
#define PLACE 78
#define ALL_LENGTH (ID+PLACE)
#define R_FILENAME "provice_original.txt"
#define W_FILENAME "provice_deal.txt"

typedef struct _str_provice_six
{
    char *provice_id;
    char *provice_name;
}Str_provice_six, *Pprovice_six;

Pprovice_six g_provice_info = NULL;
int info_count = 0;

int read_file()
{
    char provice_string[ALL_LENGTH ] = {0};
    //char filename[30] = {0};
    char filename[30] = R_FILENAME;
    //char token = 0;
    const char *token = "=";
    //Str_provice_six provice_info[NUMBER ] = {0};
    Pprovice_six provice_info = NULL;
    int i = 0;
    int max_length = 0;
    int temp = 0;

#if 0
    printf("please input the filename: ");
    scanf("%s", filename);
    printf("please input the txt delim: ");
    fflush(stdin);
    scanf("%s", &token);
#endif

    g_provice_info = (Pprovice_six)calloc(sizeof(Str_provice_six), NUMBER);
    if(g_provice_info == NULL)
        {
            printf("g_provice_info calloc failure!\n");
            system("pause");
            exit(1);
        }
    provice_info = g_provice_info;
    for(i = 0;i<NUMBER;i++)
    {
        provice_info[i].provice_id = (char*)calloc(sizeof(char), ID);
        if(provice_info[i].provice_id == NULL)
        {
            printf("provice_info[%d].provice_id calloc failure!\n", i);
            system("pause");
            exit(1);
        }
        provice_info[i].provice_name = (char*)calloc(sizeof(char), PLACE);
        if(provice_info[i].provice_name == NULL)
        {
            printf("provice_info[%d].provice_name calloc failure!\n", i);
            system("pause");
            exit(1);
        }
    }

    FILE *fp = fopen(filename, "r");
    if(!fp)
    {
        printf("open file failure!\n");
        system("pause");
        exit(1);
    }
    
    printf("start read file!\n");
    i = 0;
    //循环读取文件
    while(1)
    {
        fscanf(fp, "%s", provice_string);
        if(provice_string[0]==0)
        //if(i == 3000)
        {
            printf("over!\n");
            break;
        }
        strncpy(provice_info[i].provice_id, strtok(provice_string, token), ID-1);//最后一位进行保护
        strncpy(provice_info[i].provice_name, strtok(NULL, token), PLACE-1);
        //provice_info[i].provice_id = strtok(provice_string, token);
        //provice_info[i].provice_name = strtok(NULL, token);
        temp = strlen(provice_info[i].provice_name);
        if(temp>=max_length)
            max_length = temp;
        printf("[%d] %s", i, provice_info[i].provice_name);
        printf("[%s]", provice_info[i].provice_id );
        memset(provice_string, 0, ALL_LENGTH );
        i++;
    }

    info_count = i;
    printf("max:%d\n", max_length);
    printf("read over, the number of the provice_info is %d. \n", i);
    fclose(fp);
    system("pause");
    return 0;
}

int write_file()
{
    char *filename = W_FILENAME;
    int i = 0;
    int count = info_count;

    FILE *fp = fopen(filename, "w");
    if(!fp)
    {
        printf("open file failure!\n");
        system("pause");
        exit(1);
    }

    printf("start write file!\n");
    while(i<count)
    {
        fprintf(fp, "%s=%s\n", g_provice_info[i].provice_id, g_provice_info[i].provice_name);
        i++;
    }

    printf("write file over!\n");
    fclose(fp);
    return 0;
}

int main()
{
    read_file();
    write_file();
}