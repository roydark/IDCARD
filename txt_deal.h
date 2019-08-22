#ifndef _TXT_DEAL_H_
#define _TXT_DEAL_H_

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

#endif