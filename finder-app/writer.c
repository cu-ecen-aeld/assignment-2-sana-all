#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <syslog.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char *argv[]){
	// const char *filename = "non-existing-file.txt";
	// FILE *file = fopen(filename, "rb");
	// if(file==NULL){
	// 	fprintf(stderr, "lati lati %s: %d\n", filename, errno);
	// 	perror("perror returned");
	// 	fprintf(stderr, "lati lati part 2 %s: %s\n", filename, sterror(errno));
	// }
	// else{
	// 	fclose(file);
	// }
	// return 0;

	openlog(NULL, 0, LOG_USER);

	if (argc > 3){
		syslog(LOG_ERR, "unexpected error occured, 3 or more aguments");
		closelog();
	}


	const char *writefile = argv[1];
	const char *writestr = argv[2];

	int fd = open(writefile, O_WRONLY, 0644); //should be O_WRONLY | O_CREAT
	// but guaranteed there is a file.
	// if( fd < 0 ) // we also dont do this because it is guaranteed

	syslog(LOG_DEBUG, writestr, writefile);

	close(fd);
	closelog();

	return 0;
}
