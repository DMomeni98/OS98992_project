#include "types.h"
#include "stat.h"
#include "user.h"
#include "param.h"

int main(void){
    // make a child to have some processes to show
    int first_child=fork();
    // first child process:
    if(first_child==0){
        // allocate memory to process to make processes
        //differ in memory size to show sorting
        char* big_size = malloc(22222* sizeof(char*));
        // to delay the process 
        for(int i=0;i<22222;i++){
            // big_size array should be used to prevent compile error
            //or warning
            big_size[i]= 'd';
        }
        //buy time for system call to detect the process
        while(0<1){
        }
    }
    else if(first_child>0) {
    // make another child to have some processes to show
        int second_child=fork();
        // second child process:
        if(second_child==0){
            // allocate memory to process to make processes
            //differ in memory size to show sorting
            char* another_big_size=malloc(1000000* sizeof(char(*)));
            //to delay the process 
            for(int i=0;i<1000000;i++){
                // big_size array should be used to prevent compile error
                //or warning
                another_big_size[i]='d';
            }
        //buy time for system call to detect the process
            while(0<1){

            }
        }
        // parent process
        else if(second_child>0) {
            // make some delay
            sleep(20);
            //empty process info array that we give to the
            //system call function to fill
            struct proc_info process [NPROC];
            // call the system call
            // to get running and runnable processes info
            getProcessInfo(process);
            for(int i=0;i<NPROC;i++){
                //skip useless fake processes.
                if(process[i].pid==0)
                    break;
                printf(1,"memmory: %d | id: %d\n", process[i].memsize, process[i].pid);

            }
        }
    }

    exit();
}