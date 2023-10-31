#include <stdio.h>

/**
 * main - Starting point to get header of ELF file
 * @argx: No. of arguments
 * @argz: Pointer to array 
 * Return: 1 on success, err on failure
 */
int main(int argx, char *argz[])
{
	printf("argx:%d, argz:%p\n", argx, (void *)*argz);
	return (1);
}

