#include "main.h"

/**
 * flip_bits - This function fetches the number of bits needed to flip
 * @n: at extention, the bit flips needed to equal m for n
 * @m: This is the number to fix other equal
 * Return: Results to the number of fliped bits
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int toss = 0;
	unsigned long int xor = (n ^ m);
	unsigned long int grt = 0x01;

	while (grt <= xor)
	{
		if (grt & xor)
			toss++;
		grt <<= 1;
	}
	return (toss);
}
