#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	FILE *fp;
	char ch,str[100];
	int matrix[10][10],i=0,j=0,temp,init,m,len,st,result[100],column,t,flag;
	fp=fopen("filemoore.txt","r");
	if(fp==NULL)
	{
		printf("file error read\n");
		exit(1);
	}
	
	fscanf(fp,"%d",&init);
	fscanf(fp,"%c",&ch);
	//reading from file
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
	
	printf("enter the input string : ");
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
	
	//logic for moore machine
	m=0;
	st=init+1;
	for(i=0;i<len;i++)
	{
		column=0;
		for(column=0;column<j-1;column++)
		{
			if(matrix[0][column]==(str[i]-48))
			{
				break;
			}
		}
		st=matrix[st][column]+1;
		if((st-1)==-1)
		{
			printf("input string is not acceptable\n");
			exit(1);
		}
		result[m++]=matrix[st][j-1];
	}
	//printing final results
	printf("\nthe final output string is : ");
	printf("%d",matrix[1][j-1]);
	for(i=0;i<m;i++)
	{
		printf("%d",result[i]);
	}
	printf("\n\nthe final output string also may be following : ");
	for(i=0;i<m;i++)
	{
		printf("%d",result[i]);
	}
	printf("\n\n");
	return 0;
}
