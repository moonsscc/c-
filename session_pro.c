#include<stdio.h>
#include<unistd.h> 
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/fcntl.h>
#include<pthread.h>
#include<signal.h>
#include<fcntl.h>

int main(void){

  pid_t pid;
  int i=0;
 for(i=0;i<3;i++){

  pid=fork();
  if(pid==0){
  break;
  }
}
 if(pid==0){
   if(i==0){
   printf("sun pid:%d ppid:%d gid:%d sid:%d\n",getpid(),getppid(),getpgrp(),getsid(getpid()));
   }else if(i==1){
    printf("sun pid:%d ppid:%d gid:%d sid:%d\n",getpid(),getppid(),getpgrp(),getsid(getpid()));
   }else if(i==2){
    printf("sun pid:%d ppid:%d gid:%d sid:%d\n",getpid(),getppid(),getpgrp(),getsid(getpid()));
    sleep(5);
    setpgid(getpid(),getpid());// setsid();这是创建会话的方式

    printf("3 new group pid:%d ppid:%d gid: %d sid :%d\n",getpid(),getppid(),getpgrp(),getsid(getpid()));
    
   }
   while(1)
   sleep(1);

 }else if(pid>0){
  printf("pid:%d ppid:%d gid:%d sid:%d\n",getpid(),getppid(),getpgrp(),getsid(getpid()));
   while(1)
  sleep(1);


}else{
  perror("fork failed:");
  exit(0);
}


return 0;
}

