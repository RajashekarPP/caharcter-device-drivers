#include"cheaders.h"

int main()
{
	int choice ,fd, mode ;
	static int readmode , writemode ;
	char msg[100] = "hello raja thanks for the application";
	char msgbuf[100]={0}; //making th buffer to be empty

	while(1)
	{
		puts(" enter your choice");
		puts(" 1.open\n 2.read\n 3.write\n 4.close\n 5.exit");
		__fpurge(stdin);
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 :
				puts("In which mode should I open the file");
				puts("enter 1. Read_Mode 2. Write_Mode ");
				__fpurge(stdin);
				scanf("%d",&mode);
				switch(mode)
				{
					case 1:if((fd = open("./MyCharDev" , O_RDONLY)) < 0)
					       {
						       puts("unable to open file in read mode");break;
					       }
					       printf("%d\n",fd);
					       readmode=1;
					       break;
					case 2:fd = open("./MyCharDev" , O_WRONLY);
					       printf("%d\n",fd);
					       if(fd <0)
					       {
						       puts("unable to open file in write mode");break;		
					       }
					       writemode = 1;
					       break;
					default : puts("Invalid choice file not opened");
				}
				break;
			case 2 :
				if(readmode == 1)
				{
					if(read(fd , msgbuf ,100) < 0)
					{	
						puts("unable to read data");break;
					}
					printf("msg read is \n%s\n",msgbuf);
				}
				else
				{
					puts("file not opened in readmode");
				}
				break;
			case 3 :
				if(writemode == 1)
				{	
					if(write(fd , msg , 100) < 0)
					{
						puts("unable to write data");break;
					}
					puts("msg has been written");
				}
				else
				{
					puts("file not opened in writemode");
				}				
				break;
			case 4:
				close(fd);
				readmode=writemode=0;
				break;
			case 5:
				puts("exiting from process");
				exit(0);
			default : puts("Invalid choice"); break;

		}//end of switch case
	}//end of while loop
}//end of main
