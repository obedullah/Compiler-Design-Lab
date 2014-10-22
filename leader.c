#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int array[20],n=0;

void addleader(int num){
    array[n++]=num;
}

int main(){
    char str[50];
    int i,len,num,k,line=100,new[20],m,j,temp;
    FILE *fp;
    fp=fopen("file_tac","r");
    if(fp==NULL){
        printf("can't open file\n");
        exit(1);
    }
    addleader(line);
    while(!feof(fp)){
        fscanf(fp," %[^\n]",str);
        len=strlen(str);
        for(i=0;i<len;i++){
            if(str[i]=='g'){
                if(str[i+1]=='o'){
                    if(str[i+2]=='t'){
                        if(str[i+3]=='o'){
                            i+=5;
                            num=0;
                            for(k=i;k<len;k++){
                                num*=10;
                                num+=str[k]-48;
                            }
                            addleader(num);
                            addleader(line+1);
                        }
                    }
                }
            }
        }
        line++;
    }
    //to remove duplicate leaders first sort it and ...
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(array[i] > array[j]){
                temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
    }
    //putting unique elements into new array
    m=0;
    for(i=0;i<n-1;i++){
    	temp=array[i];
    	j=i+1;
        while(temp==array[j] && j<n-1){
            j++;
        }
        new[m++]=temp;
        i=j-1;
    }	
    if(array[n-1]!=array[n-2]){
    	new[m++]=array[n-1];
    }
    printf("\nleaders are :\n");
    for(i=0;i<m;i++){
        printf("%d\t",new[i]);
    }
    printf("\n");
    return 0;
}
