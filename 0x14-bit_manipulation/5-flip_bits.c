/**
 * flip_bits - A function that gets number of bits needed to flip
 * in converting one number to another
 * @n: The number of flip bits required to equal m for n
 * @m: The second number that will set other equal
 * Return: The total number of bits to be flipped
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int spin = 0;
	unsigned long int x_o_r = (n ^ m);
	unsigned long int abs_val = 0x01;

	while (abs_val <= x_o_r)
	}
	if (abs_val & x_o_r)
	spin++;
	abs_val <<= 1;
	}
return (spin);
}

