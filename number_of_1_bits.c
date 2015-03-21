#include <stdio.h>

int num_of_1bits(unsigned int n)
{
	int i = 0;
	int count = 0;
	for (i = 0; i < sizeof(n)*8; ++i)
	{
		((1<<i)&n) ? count++ : count;
	}
	return count;
}

int main(int argc, char *argv[])
{
	int n = num_of_1bits(0xffef);
	printf("n:%d\n",n);
	return 0;
}
