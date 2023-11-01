/**
* get_bit - This function grabs a bit at index
* @n: This is the number to grab bit from
* @index: This is the index where the bit will be grabbed
* Return: The value of the bit or -1 if an error materializes
*/
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int greatest = 0x01;

	greatest <<= index;
	if (greatest == 0)
	return (-1);

	if ((n & greatest))
	return (1);
	else
	return (0);
}
