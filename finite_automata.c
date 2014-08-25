#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char ch,str[100];
	int init,m,state,len,i,j,final[10],matrix[10][10],temp,column;
	FILE *fp;
	fp=fopen("file_automata.txt","r");
	if(fp==NULL)
	{
		printf("file error\n");
		exit(1);
	}
	fscanf(fp,"%d",&init);
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
	j=temp;
	printf("enter the string : ");
	fgets(str,100,stdin);
	len=strlen(str)-1;
	state=init+1;
	for(i=0;i<len;i++)
	{
		for(column=0;column<j;column++)
		{
			if(matrix[0][column]==(str[i]-48))
			{
				break;
			}
		}
		state=matrix[state][column]+1;
		if((state-1)==-1)
		{
			printf("\nstring not accepted\n\n");
			exit(1);
		}
		
		if(i==len-1)
		{	
			for(j=0;j<m;j++)
			{	
				if(final[j]==state-1)
				{
					printf("\nstring accepted\n\n");
					exit(1);
				}
			}
		}
	}
	printf("\nstring not accepted\n\n");
	return 0;
}
