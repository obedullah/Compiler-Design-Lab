#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	FILE *fp;
	char ch,str[100];
	int matrix[10][10],i=0,j=0,temp,init,m,n,len,st,output[100][100],state[100][100],result[100];
	fp=fopen("filemealy.txt","r");
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
	//separating states
	for(m=0;m<i;m++)
	{
		temp=0;
		for(n=0;n<j/2;n++)
		{
			state[m][n]=matrix[m][temp];
			temp+=2;
		}
	}
	//separating outputs
	for(m=0;m<i;m++)
	{
		temp=0;
		for(n=0;n<j/2;n++)
		{
			temp++;
			output[m][n]=matrix[m][temp];
			temp++;
		}
	}

	printf("enter the input string : ");
	fgets(str,100,stdin);
	len=strlen(str)-1;
	//logic for mealy machine
	m=0;
	st=init-1;
	for(i=0;i<len;i++)
	{
		temp=state[st][str[i]-48];
		if(st==-1)
		{
			printf("input string is not acceptable\n");
			exit(1);
		}
		result[m++]=output[st][str[i]-48];
		st=temp;
	}
	//printing final results
	printf("\nthe final output string is : ");
	for(i=0;i<m;i++)
	{
		printf("%d",result[i]);
	}
	printf("\n\n");
	return 0;
}
