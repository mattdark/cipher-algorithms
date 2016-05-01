#include <stdio.h>
#include <string.h>

int vigenere(char message[], char abc[], char key[]);
void main(void)
 {
  setvbuf(stdout, NULL, _IONBF, 0);
  
  char message[] = "usa software libre";
  char key[] = "casa";
  
  char abc[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  
  printf("Mensaje original: %s", message);
  vigenere(message, abc, key);
  printf("\nMensaje cifrado: %s", message);
 }
int vigenere(char message[], char abc[], char key[])
 {
  int b = 0, i, n = 0, r, s, t, x = 0;
  for(i = 0; i < strlen(message); i++)
   {
    b = 0;
    n = 0;
    while(n < 26 && !b)
     {
      if(message[i] == abc[n])
       {
        s = n;
        b = 1;
       }
      n = n + 1;
     }
    b = 0;
    n = 0;
    while(n < 26 && !b)
     {
      if(message[i] != ' ')
       {
       	if(x == strlen(key))
       	 {
       	  x = 0;
       	 }
        if(key[x] == abc[n])
         {
          t = n + s;
          x = x + 1;
          b = 1;
         }
       }
      n = n + 1;
     }
    if(message[i] != ' ')
     {
      if(t >= 26)
       {
        r = t - 26;
        message[i] = abc[r];
       }
      else
       {
       	message[i] = abc[t];
       }
     }
   }
 }
