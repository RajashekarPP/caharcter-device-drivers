#include"cheaders.h"

int main()
{
	int choice ,fd, mode , fileopen = 0;
	static int readmode , writemode, written_data;
	char writebuf[100] = "hello raja thanks   ";
	char readbuf[100]={0}; //making the buffer to be empty

	while(1)
	{
		puts(" enter your choice");
		puts(" 1.open\n 2.read\n 3.write\n 4.close\n 5.exit");
		__fpurge(stdin);
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 :
				if(fileopen)
				{
					puts("file is already in open state please close the file and then open");break;
				}
				puts("In which mode should I open the file");
				puts("enter 1. Read_Mode 2. Write_Mode ");
				__fpurge(stdin);
				scanf("%d",&mode);
				switch(mode)
				{
					case 1:fd = open("./MyCharDev" , O_RDONLY );
					       perror("open read");
					       printf("%d\n",fd);
					       readmode=1; fileopen = 1;
					       break;
					case 2:fd = open("./MyCharDev" , O_WRONLY);
					       perror("open write");
					       printf("%d\n",fd);
					       writemode = 1; fileopen = 1;
					       break;
					default : puts("Invalid choice file not opened");
				}
				break;
			case 2 :
				if(written_data == 0)
				{
					puts("data is not written to read");break;
				}
				if( (readmode == 1) && (fd >0))
				{
					int bytesread=0;
					if( (bytesread=read(fd , readbuf , 20)) < 0)
					{	
						puts("unable to read data");break;
					}
					printf("msg read is \n%s of length %d\n",readbuf,bytesread);
				}
				else
				{
					puts("file not opened in readmode");
				}
				break;
			case 3 :
				if( (writemode == 1) && (fd >0))
				{	
					int byteswritten=0;
					byteswritten = write(fd , writebuf , strlen(writebuf));
					if(byteswritten < 0)
					{
						puts("unable to write data");break;
					}
					printf("msg of length %d bytes has been written\n",byteswritten);
					written_data = 1;
				}
				else
				{
					puts("file not opened in writemode");
				}				
				break;
			case 4:
				if(fileopen)
				{
					close(fd);
					printf("closed file fd = %d\n",fd);
					fileopen = 0;
					readmode=writemode=0;
				}
				break;
			case 5:
				puts("exiting from process");
				exit(0);
			default : puts("Invalid choice"); break;

		}//end of switch case
	}//end of while loop
}//end of main
