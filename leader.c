#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int array[20],line=100,n=0;

void addleader(int num){
    int i;
    for(i=0;i<n;i++){
        if(array[i]==num){
            return;
        }
    }
    array[n++]=num;
}

int main(){
    chat str[10];
    int i,len,num;
    FILE *fp;
    fp=fopen("file_tac","r");
    if(fp==NULL){
        printf("can't open file\n");
        exit(1);
    }
    addleader(line);
    line++;
    while(feof(fp)){
        fscanf(fp,"%s",str);
        if(strcmp(str,"goto")==0){
            addleader(line);
            fscanf(fp,"%s",str);
            num=0;
            len=strlen(str);
            for(i=0;i<len;i++){
                num+=(num*10)+str[i]-48;
            }
            addleader(num);
            line++;
        }
    }
    printf("leaders are :\n");
    for(i=0;i<n;i++){
        printf("%d\t",array[i]);
    }
    printf("\n");
    return 0;
}