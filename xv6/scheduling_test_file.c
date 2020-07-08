#include "types.h"
#include "stat.h"
#include "user.h"
#include "param.h" 
#include "fs.h"

int main(void){
    //syscall return value
    int  result= 0;
    int childPid = 0;
	int waitingTime= 0;
    int runningTime = 0;
	childPid = fork();
	if (childPid == 0)
  	{	
        int timeWaster = 0;
        for (int i = 0; i < 1000; i++) {
			printf(1, " ---->processing <---- ");
            timeWaster= (i+289) * (99-i);
        }
		exit();
    }
  	else if (childPid > 0)
 	{
    	result = scheduling(&waitingTime, &runningTime);
 	}  
 	printf(1, "waiting time = %d\nrunning time = %d\nresult %d \n", waitingTime, runningTime, result); 
 	exit();
}

}