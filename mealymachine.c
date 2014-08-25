#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	FILE *fp;
	char ch,str[100];
	int matrix[10][10],i=0,j=0,temp,init,m,n,len,st,result[100],column,t,flag;
	fp=fopen("filemealy.txt","r");
	if(fp==NULL)
	{
		printf("file error read\n");
		exit(1);
	}
	
	fscanf(fp,"%d",&init);
	fscanf(fp,"%c",&ch);
	while(fscanf(fp,"%c",&ch)!=EOF)
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
	j=temp;
	fclose(fp);
	printf("\nenter the input string : ");
	fgets(str,100,stdin);
	len=strlen(str)-1;
	
	//this is only for validation that except input symbols if any present then not accepted
	for(i=0;i<len;i++)
	{
		flag=0;
		for(t=0;t<j;t++)
		{
			if(str[i]-48 == matrix[0][t])
			{
				flag=1;
			}
		}
		if(flag==0)
		{
			printf("input string is not acceptable\n");
			exit(1);
		}
	}
	
	m=0;
	st=init+1;
	for(i=0;i<len;i++)
	{
		column=0;
		for(column=0;column<j;column+=2)
		{
			if(matrix[0][column]==(str[i]-48))
			{
				break;
			}
		}
		temp=matrix[st][column]+1;
		if(temp-1==-1)
		{
			printf("\ninput string is not acceptable\n\n");
			exit(1);
		}
		result[m++]=matrix[st][column+1];
		st=temp;
	}
	printf("\nthe final output string is : ");
	for(i=0;i<m;i++)
	{
		printf("%d",result[i]);
	}
	printf("\n\n");
	return 0;
}
