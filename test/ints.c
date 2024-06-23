// ints.c
// know thy data types

#include<stdio.h>

int main(void)
{
	printf("size of int: %i (%i bits)\n", sizeof(int), sizeof(int) * 8);
	printf("size of long: %i (%i bits)\n", sizeof(long), sizeof(long) * 8);
	printf("size of char: %i (%i bits)\n", sizeof(char), sizeof(char) * 8);
	printf("size of pointer: %i (%i bits)\n", sizeof(void*), sizeof(void*) * 8);
	printf("size of float: %i (%i bits)\n", sizeof(float), sizeof(float) * 8);
	printf("size of double: %i (%i bits)\n", sizeof(double), sizeof(double) * 8);
	return 0;
}

