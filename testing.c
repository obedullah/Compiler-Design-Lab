#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char table[10][10],str[100],current[100],var[100];
int m=0,input=0,g;

char first_find(char ch){
	int t,count,r;
	if(ch >= 97 || ch <= 122){
		return ch;
	}
	t=0;
	while(table[t][0]!=ch){
		t++;
	}
	count=t;
	while(table[count][0]==ch){
		count++;
	}
	for(r=t;r<count;r++){
		first_find(table[r][1]);
	}
}

int find(char a, char b){
	if(b>=65 && b<=122){
		
		if(a==first_find(b)){
			return 1;
		}
		else{
			return 0;
		}
	}
	else{
		if(a==b){
			return 1;
		}
		else{
			return 0;
		}
	}
}

int func(char ch){
	int t=0,count,i,r,v,flag=0;
	while(table[t][0]!=ch){
		t++;
	}
	count=t;
	while(table[count][0]==ch){
		count++;
		flag=1;
	}
	for(r=t;r<count;r++){
		if(find(str[input], table[r][1])){
			for(v=g+1;v<m;v++){
				var[v]=current[v];
			}
			m=g;
			for(i=2;table[r][i]!='0';i++){
				current[m++]=table[r][i];
			}
			for(i=g+1;i<=v;i++){
				current[m++]=var[i];
			}
			current[m]='\0';
			g--;
			return flag;
		}
	}
	for(i=t;i<count;i++){
			if(table[i][1]=='$'){
				flag=2;
			}
	}
	return flag;
}

int main(){	
	char ch;
	int i,j,row,col,len,temp,t,r,count,flag=0;
	FILE *fp;
	//opening and reading file into 2-D matrix as a table
	fp=fopen("file","r");
	if(fp==NULL){
		printf("file read error\n");
		exit(1);
	}
	i=0;j=0;
	while(!feof(fp)){
		fscanf(fp,"%c",&ch);
		if(ch=='\n' || ch=='|'){
			// zero is used to indentify that here our grammar symbol is finished
			table[i][j]='0';
			i++;
			j=0;
			if(ch=='|'){
				table[i][j++]=table[i-1][0];
			}
		}
		else if(ch!='-' && ch!='>'){
			table[i][j++]=ch;
			temp=j;
		}
	}
	i-=2;
	table[i++][temp]='0';
	row=i;
	
	//printing the table where our grammar is stored
	printf("table of grammar is :\n");
	for(r=0;r<row;r++){
		for(col=0;table[r][col]!='0';col++){
			printf("%c",table[r][col]);
		}
		printf("\n");
	}
	//taking input string
	printf("enter the input string : ");
	scanf("%s",str);
	len=strlen(str);
	
	//finding starting grammar S->derives means which one will be used
	t=0;
	while(table[t][0]!='S'){
		t++;
	}
	count=t;
	while(table[count][0]=='S'){
		count++;
	}
	for(r=t;r<count;r++){
		if(find(str[0],table[r][1])){
			flag=1;
			break;
		}
	}
	//if starting symbol is different means not acceptable
	if(flag==0){
		printf("string is not accepted\n");
		exit(1);
	}
	
	//we find the grammar which will be executed and saving it into current string
	m=0;
	for(t=2;table[r][t]!='0';t++){
		current[m++]=table[r][t];
	}
	current[m]='\0';
	
	//input is an integer used to increase the input string index
	input=1;
	
	//g integer is used to hold currently grammar symbol is executed
	for(g=0;g<m;g++){
	
		//here we find if current grammar symbol is variable or terminal in else if block below
		if((current[g] >= 65) && (current[g] <=91)){
		
			//func finds if input string is matched according to grammar or not if match then increase input index
			if(func(current[g])==1){
				input++;
			}
			
			//here if func returns 2 means input symbol not matched but grammar symbol derives epsilon '$'
			//so input string index is not increased here
			else if(func(current[g])!=2){
				printf("string is not accepted case func\n");
				exit(1);
			}
		}
		
		//if current grammar symbol is not variable means it is terminal so we simply compare it with input string
		else if((current[i] >= 97) && (current[i] <=122)){
			if(current[g]==str[input]){
				input++;
			}
			else{
				printf("string is not accepted case func input\n");
				exit(1);
			}
		}
	}
	
	//if length of input string and index input reaches to equal means string is accepted
	if(len==input){
		printf("string is accepted\n");
	}
	else{
		printf("string is not accepted\n");
	}
	return 0;
}
