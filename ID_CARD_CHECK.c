#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
  char check_num[22] = { '1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2', 
		   '1', '0', 'x' , '9', '8', '7', '6', '5', '4', '3', '2',};
  int weight_value[17] = { 7,9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
  int sum = 0;
  int i = 0;

  char id_card[19] = { 0 };

  printf("please input the ID Card Number: ");
  while(!(scanf("%s", id_card))||(strlen(id_card)!=18))
  {
    printf("please input the ID Card Number: ");
  }
  for(i=0;i<17;i++)
    printf("i:%d %d\n",i, weight_value[i]);
  for(i=0;i<17;i++)
  {
	sum += (id_card[i] - '0')*weight_value[i];
	printf("%d * %d = %d\n", id_card[i]-'0', weight_value[i], (id_card[i]-'0') * weight_value[i]);
	if(i == 16 && ((id_card[i]-'0')&0x01)==1)
	{
		printf("he is a male!\n");
	}
	else if(i == 16 && ((id_card[i]-'0')&0x01)==0)
	{
		printf("she is a female!\n");
	}
  }
  printf("sum:%d\n", sum);
  printf("id_card[%d]:%c, %d\n",i, id_card[i], sum%11);
  if(check_num[sum%11] == id_card[i]|| check_num[sum%11+11] == id_card[i])
    printf("the ID_CARD number check success!\n");
  else
    printf("The ID_CARD number check failure!\n");
  system("pause");
  return 0;
}
