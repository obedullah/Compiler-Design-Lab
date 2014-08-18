#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char ch,str[100];
	int init,m,state,len,i,j,final[10],matrix[10][10],temp;
	FILE *fp;
	fp=fopen("file.txt","r");
	if(fp==NULL)
	{
		printf("file error\n");
		exit(1);
	}
	
	fscanf(fp,"%c",&ch);
	init=ch-48;
	fscanf(fp,"%c",&ch);
	
	m=0;
	while(1)
	{
		fscanf(fp,"%c",&ch);
		if(ch=='\n')
		{
			break;
		}
		else if(ch!=',')
		{
			final[m++]=ch-48;
		}
	}
	
	i=0;
	j=0;
	while((fscanf(fp,"%c",&ch))!=EOF)
	{
		if(ch=='\n')
		{
			i++;
			temp=j;
			j=0;
		}
		else if(ch!=' ')
		{
			if(ch=='-')
			{
				matrix[i][j++]=-1;
			}
			else
			{
				matrix[i][j++]=ch-48;
			}
		}
	}
	fclose(fp);
	
	printf("enter the string : ");
	fgets(str,100,stdin);
	len=strlen(str)-1;
	
	//checking if string has not other symbols except input symbol to validate
	for(i=0;i<len;i++)
	{
		if(str[i]-48 >= temp)
		{
			printf("string not accepted\n");
			exit(1);
		}
	}
	
	state=1;
	for(i=0;i<len;i++)
	{
		state=matrix[state][str[i]-48];
		if(state==-1)
		{
			printf("string not accepted\n");
			exit(1);
		}
		if(i==len-1)
		{	
			for(j=0;j<m;j++)
			{	
				if(final[j]==state)
				{
					printf("string accepted\n");
					exit(1);
				}
			}
		}
		state+=1;
	}
	printf("string not accepted\n");
	return 0;
}
