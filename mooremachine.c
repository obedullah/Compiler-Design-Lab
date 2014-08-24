#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	FILE *fp;
	char ch,str[100];
	int matrix[10][10],i=0,j=0,temp,init,m,n,len,st,output[100],state[10][10],result[100];
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
	//separating states from matrix
	for(m=0;m<i;m++)
	{
		for(n=0;n<j-1;n++)
		{
			state[m][n]=matrix[m][n];
		}
	}
	//separating output from matrix
	for(m=0;m<i;m++)
	{	
		output[m]=matrix[m][j-1];
	}
	
	printf("enter the input string : ");
	fgets(str,100,stdin);
	len=strlen(str)-1;
	//logic for moore machine
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
		result[m++]=output[st];
		st=temp;
	}
	//printing final results
	printf("\nthe final output string is : ");
	for(i=0;i<m;i++)
	{
		printf("%d",result[i]);
	}

	
	printf("\n");
	return 0;
}
