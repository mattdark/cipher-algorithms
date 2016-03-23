#include <stdio.h>
#include <string.h>

int caesar(char message[], char abc[], int x);
void main(void)
 {
  int x = 3;
  char message[11] = "hello world";
  char abc[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  printf("Mensaje original: %s", message);
  caesar(message, abc, x);
  printf("\nMensaje cifrado: %s", message);
 }
int caesar(char message[], char abc[], int x)
 {
  int i, n = 0, r;
  int b = 0;
  for(i = 0; i < strlen(message); i++)
   {
    b = 0;
    n = 0;
    while(n < 26 && !b)
     {
      if(message[i] == abc[n])
       {
        if((n+x) >= 26)
         {
          r = (n+x) - 26;
          message[i] = abc[r];
         }
        else
         {
          message[i] = abc[n+x];
         }
        b = 1;
       }
      n = n + 1;
     }
   }
 }
