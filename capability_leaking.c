// cap_leak.c
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

void main()
{  
    int fd;  char *v[2];  
    /* Assume that /etc/zzz is an important system file, 
	and it is owned by root with permission 0644. 
	Before running this program, you should create 
	the file /etc/zzz first. */  

    fd = open("/etc/zzz", O_RDWR | O_APPEND);

    // Print out the file descriptor value  
    printf("fd is %d\n", fd);    
    if (fd == -1) 
    {     
        printf("Cannot open /etc/zzz\n");     
        exit(0);  
    }  
    // Permanently disable the privilege by making the  
    // effective uid the same as the real uid  
    printf("BEFORE Real user id is %d\n", getuid());    
    printf("BEFORE Effective user id is %d\n", geteuid());  
    setuid(getuid()); 
    printf("AFTER Real user id is %d\n", getuid());    
    printf("AFTER Effective user id is %d\n", geteuid());    

    // Execute /bin/sh  
    v[0] = "/bin/sh"; v[1] = 0;  
    execve(v[0], v, 0);        
}
