#include<stdio.h>
int main()
{
	int i=0;
	char x[]="Code";
	char y[]="code";
	for(i=0;x[i]&&y[i];i++)
	{
		if(x[i]!=y[i])
			break;
	}
	if(x[i]<y[i])
		printf("\nY string is longer");
	else if(x[i]>y[i])
		printf("\nX string is longer");
	else
		printf("\nBoth strings are same");
}

