#include <stdio.h>

void imul(char *s, int n){
   int carry=0;
   
   while(*s){
      carry+=(*s-'0')*n;
      *s=carry%10+'0';
      carry/=10;
      s++;
      }
   while(carry){
      *s=carry%10+'0';
      carry/=10;
      s++;
      }
   *s='\0';
   }
   
int digitsum(char *s){
   int result=0;

   while(*s) result+=*(s++)-'0';
   return result;
   }
   
int main(){
   int a,b;
   char s[256];
   int d,best;
   
   best=0;
   for(a=2;a<100;a++){
      s[0]='1';
      s[1]='\0';
      for(b=1;b<100;b++){
         imul(s,a);
         d=digitsum(s);
         /* printf("%d %d %s %d\n",a,b,s,d);*/
         if(d>best) best=d;
         }
      }
   printf("%d\n",best);
   return 0;
   }