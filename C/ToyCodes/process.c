/*
  Tutorial

*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>

int main(){ 
  pid_t pidfils=0, pere=1;
  int i;
  for(i=0;i<5 && pere;i++){ 
      pidfils=fork(); pere=pidfils;
      if(pidfils==0)printf("je suis le fils %d et mon PID est : %d\n",i+1,getpid());
     }
return 0;
}
