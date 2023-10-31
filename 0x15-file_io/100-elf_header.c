#include <stdio.h>

/**
 * main - Starting point to get header of ELF file
 * @argcm: No. of arguments
 * @argvr: Pointer to array 
 * Return: 1 on success, 0 on failure
 */
int main(int argcm, char *argvr[])
{
	printf("argcm:%d, argvr:%p\n", argcm, (void *)*argvr);
	return (1);
}

