#include <stdio.h>

int main()
{
	char str[100], ch = 0;
	int n = 0, k = 3;
	while(ch != '!')
	{
		ch = getchar();
		str[n++] = ch;
	}
	str[n] = '\0';
	printf("Cipher Text:\n%s\n", str);
	printf("Encrypted Text:\n");
	for(int i = 0; i < n; i++)
	{
		if('A' <= str[i] && str[i] <= 'Z')
			ch = 'A' + (str[i] - 'A' + k) % 26;
		else
			ch = str[i];
		printf("%c", ch);
		i++;
	}
}