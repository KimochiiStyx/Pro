#include<stdio.h>
#include<stdlib.h>
#include"wave.h"
#include"screen.h"
#include<signal.h>
#include<sys/wait.h>

int main(int argc, char *argv[])
{
	WAVHDR h;
	FILE *fp;  //file handler of wave file.
	int ans, ret;
	short int sa[SAMPLE_RATE];
	while(1)
	{
		ret=system("arecord -r16000 -c1 -d1 -f S16_LE -q data.wav");
		if(WIFSIGNALED(ret) && WTERMSIG(ret)==SIGINT) break;
		clearScreen();// makes a fresh screen.
		fp=fopen("data.wav", "r");
		fread(&h, sizeof(h), 1, fp);	//read the wav header
		dispWAVHDR(h);  //dilay the wav header info
		fread(&sa, sizeof(short int), SAMPLE_RATE, fp);
		dispWAVdata(sa);
		fclose(fp);
	}
/*	if(argc<2)
	{
		printf("Usage: %s wav_file\n", argv[0]);
		return -1;
	}
	fp=fopen(argv[1], "r");  // open the wav file in read-only
	if(fp==NULL)
	{
		printf("Cannot open wav fil%s\n", argv[1]);
		return -1;
	}
	fread(&h, sizeof(h), 1, fp);
	dispWAVHDR(h);
	fclose(fp);*/
	printf("Do you want to generate a testtone?(1:yes, 0:no) ");
	scanf("%d", &ans);
	if(ans==1)
		testTone(1000, 5);
}
