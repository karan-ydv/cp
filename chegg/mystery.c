#include <stdio.h>
#include <stdlib.h>

int main()
{
	unsigned int M1, M2;
	unsigned int NUM =1457654 ; // Put your NUM here

	int j, k;
	// system("dir");
	// printf("\nxx = %d\n", (NUM % 255) & 0xfe);
	for (j=1; j<255; j++) {
		// Generate pseudo-random 'info' bits
		// M1 = (NUM * (j+2)) ^ NUM;
		// Reduce the number of bits in data and set LSB to zero
		// M2 = M1 & 0xffff;
		// M1 >>= 16;
		// M1 += M2;
		// M1 &= 0xfffe;
		M1 = j;
		// START mystery block -----------------------------
		M2 = M1;
		// printf("0x%d\n",M2);
		for (k=15; k>0; k--)
			M2 = M2 ^ (M1 >> k);
		// printf("0x%d\n",M2);
		M2 = M2 & 1;
		// END mystery block -------------------------------
		M2 = M1 | M2;
		if((M2 - M1) & 1)
		printf("%d,",M1);
		// printf("----\n");
	}
	return 0;
}