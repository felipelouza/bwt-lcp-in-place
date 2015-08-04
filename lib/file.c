#include "file.h"

/* Changes to a working directory, where everything will be read
 * from and written to:
 */ 
int file_chdir(char* dir){
	
	char* oldwd = getcwd(NULL,0);
	if (!oldwd) die(__func__);
	if (chdir(dir) == -1) die(__func__);

	free(oldwd);
return 0;
}

/*******************************************************************/

//Open a file and returns a pointer
FILE* file_open(char *c_file, const char * c_mode){
	
	FILE* f_in;
	
	f_in = fopen(c_file, c_mode);
	if (!f_in) perror ("file_open");
	
return f_in;
}


int file_close(FILE* f_in){
	
	fclose(f_in);
	if (!f_in) perror ("file_close");
	
return 0;
}

/*******************************************************************/

int file_size(FILE* f_in){

    fseek(f_in, 0, SEEK_END);
    size_t length = ftell(f_in);
    rewind(f_in);
	
return length;
}

/*******************************************************************/

char* file_load(FILE* f_in) {
	
	size_t len = 0;
	ssize_t size = 0;
 	char *c_aux = NULL;
 	
 	/*Read one line*/
 	size = getline(&c_aux, &len, f_in);
 	if (size == -1) perror("file_load");

 	/*Copy line to c_buffer*/
 	char *c_buffer = (char*) malloc((size+1)*sizeof(char));
    strncpy(c_buffer, c_aux, size);

	c_buffer[size-1] = END_MARKER;
	c_buffer[size] = '\0';

	free(c_aux);

return c_buffer;
}

/* read line by line
 * line i is copied into string R[i]
 */
char** file_load_multiple(FILE* f_in, int n) {
	
	ssize_t size = 0;
	char **c_buffer = (char**) malloc(n*sizeof(char*));

	int i;
 	for(i=0; i<n; i++){

    size_t len = 0;
    c_buffer[i] = NULL;
		
		size = getline(&c_buffer[i], &len, f_in);
    if (size == -1) perror("file_load");

		c_buffer[i][size-1] = 0;
	}

return c_buffer;
}

/*******************************************************************/
