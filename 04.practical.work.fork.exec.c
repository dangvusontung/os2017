#include<stdio.h>
#include<unistd.h>
int main()
{ 
	printf("Main before fork() ");
	int pid=fork();		
	if (pid == 0)
	{	
		printf("child after folk(), lauching ps -ef");
		char* args[]={"/bin/ps", "-ef", NULL};
		execvp("/bin/ps", args);
		printf("Finish ps -ef");
	else 
		printf("Parent after fork(), child is %d", pid);
		
	pid = fork();

	if ( pid == 0){
		printf(" child after folk(), lauching free -h");
		char* args[]={"free", "-h", NULL};
		execvp("free", args);
		printf("Finished free -h");
}	
	else printf(" Parent, child is %d", pid);
	return 0;
		


}

