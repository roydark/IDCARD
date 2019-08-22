#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "txt_deal.h"

char id_card[19] = { 0 };

//int read_file();

int id_check()
{
  char check_num[22] = { '1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2', 
		   '1', '0', 'x' , '9', '8', '7', '6', '5', '4', '3', '2',};
  int weight_value[17] = { 7,9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
  int sum = 0;
  int i = 0;

  //char id_card[19] = { 0 };

  printf("please input the ID Card Number: ");
  while(!(scanf("%s", id_card))||(strlen(id_card)!=18))
  {
    printf("please input the ID Card Number: ");
  }

 // for(i=0;i<17;i++)
   // printf("i:%d %d\n",i, weight_value[i]);

  for(i=0;i<17;i++)
  {
	sum += (id_card[i] - '0')*weight_value[i];
	//printf("%d * %d = %d\n", id_card[i]-'0', weight_value[i], (id_card[i]-'0') * weight_value[i]);
	if(i == 16 && ((id_card[i]-'0')&0x01)==1)
	{
		printf("he is a male!\n");
	}
	else if(i == 16 && ((id_card[i]-'0')&0x01)==0)
	{
		printf("she is a female!\n");
	}
  }
#if 0
  printf("sum:%d\n", sum);
  printf("id_card[%d]:%c, %d\n",i, id_card[i], sum%11);
#endif

  if(check_num[sum%11] == id_card[i]|| check_num[sum%11+11] == id_card[i])
    printf("the ID_CARD number check success!\n");
  else
    printf("The ID_CARD number check failure!\n");
  //system("pause");
  return 0;
}

int place_check()
{
    int i = 0, j = info_count;
    while(!(i-j == 1 || i-j ==2))
    {
        if(strncmp(g_provice_info[i].provice_id, id_card, 6)==0)
        {
            printf("your place you born is %s !\n", g_provice_info[i].provice_name);
            break;
        }
        if(strncmp(g_provice_info[j].provice_id, id_card, 6)==0)
        {
            printf("your place you born is %s !\n", g_provice_info[j].provice_name);
            break;
        }
        i++;
        j--;
    }
    return 0;
}
int main()
{
    id_check();
    read_file();
    place_check();
    system("pause");
}
