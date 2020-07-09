#include<stdio.h>
#include<stdlib.h>
#define size 26
int main()
{
	int i,j;
	int h[size]={0};
	char s[]="fired";
	char s1[]="fird";
	for(i=0;s[i]!='\0';i++)
		h[s[i]-97]++;
	for(i=0;s1[i]!='\0';i++)
	{
		if(h[s1[i]-97]==0)
		{
			printf("Not anagram");
			exit(0);
		}
		h[s1[i]-97]--;
	}
	for(i=0;i<size;i++)
	{
		if(h[i]!=0)
		{
			printf("Not anagram");
			exit(0);
		}
	}
	printf("Anagram");
}
