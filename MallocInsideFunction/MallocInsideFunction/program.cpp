#include <stdio.h>
#include <stdlib.h>  // malloc, free
#include <string.h>  // strcpy
#include <conio.h>

void create_message(char ** pp);
void destroy_message(char ** pp);

int main()
{
	char * msg_ptr = NULL;

	// Create dynamic message
	create_message(&msg_ptr);

	// do something with buf_ptr
	printf("Printing dynamic message: %s\n", msg_ptr);

	// Destroy the dynamic message: free msg_ptr
	destroy_message(&msg_ptr);

	_getch();

	return 0;
}


void create_message(char ** pp)
{
	// 256 bytes
	const int BUFFER_SIZE = 256;

	char * m = (char *)malloc(BUFFER_SIZE);   // m will go out of scope when function ends! So copy to *pp
	
	// Fill the entire buffer with zeros just to be safe!
	//memset(m, 0, BUFFER_SIZE);

	//m[0] = 'H';
	//m[1] = 'e';
	//m[2] = 'l';
	
	strcpy_s(m, BUFFER_SIZE - 1, "Hello World!");  // strcpy_s() null terminates
	
	*pp = m;  // i.e. in main(): msg_ptr = m 
}

void destroy_message(char ** pp)
{
	free(*pp);   // i.e. in main(): free(msg_ptr)

	*pp = NULL;  // i.e. in main(): msg_ptr = NULL 
}
