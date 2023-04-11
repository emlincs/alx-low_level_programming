/**
 * flip_bits - A function that calculates the number of bits needed to flip
 * and convert one number to another
 * @n: The first number of flips needed to equal m for n
 * @m: The second number to set the other equal
 *
 * Return: The number of bits that need to be flipped
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
unsigned int flick = 0;
unsigned long int discrt = n ^ m;
unsigned long int abs_val = 1;

	while (abs_val > 0 && abs_val <= discrt)
	{
		if (discrt & abs_val)
		{
		++flick;
		abs_val <<= 1;
		}
		return (flick);
	}
}
