#include<stdio.h>
#include<string.h>

int main()
{
	int i;
	double array[8]={0.1, 0.2, 0.3};
	char temp[30], postdata[200]="data=";
	for(i=0;i<8;i++)
	{
		sprintf(temp, "%.2f ", array[i]);
		strcat(postdata, temp);
		printf("%s\n", postdata);
	}
}
