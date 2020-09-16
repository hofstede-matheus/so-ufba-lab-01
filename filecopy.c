#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){

	fd = open(filename,O_RDONLY,0);
	if(fd<0) {
	 	printf("Unable to open %s: %s\n",filename,strerror(errno));
		 exit(1);
	}
	return 0;

}
