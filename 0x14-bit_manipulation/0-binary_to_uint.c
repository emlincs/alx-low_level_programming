#include "main.h"
/**
 * binary_to_uint - A function that converts binary number
 * to an unsigned integer
 * @b: A pointer to binary string
 * Return: unsigned integer converted number
 */
unsigned int binary_to_uint(const char *b)
{
unsigned int base = 1, result = 0, b_len = 0;

if (b == NULL)
return (0);

while (b[b_len])
++b_len;

while (b_len)
{
if (b[b_len - 1] != '0' && b[b_len - 1] != '1')
return (0);

if (b[b_len - 1] == '1')
result += base;

base *= 2;
--b_len;
}

return (result);
}

