#include<bits/stdc++.h>
using namespace std;

int jnuminline(char *a){
	int sum=0;
	for(int i=0;a[i]=='#';++i){
		++sum;
	}
	return sum;
}

int main(){
	FILE *yl=fopen("fin1","r");//yuan lai
	FILE *yj=fopen("fin2","r");//has# 
	FILE *ot=fopen("out","w");//out
	
	
	int hangnum=;
	
	char str[1000];
	int jnum[];//hangnum+5
	
	for(int i=1;i<=hangnum;++i){
		fscanf(yj,"%s",str);
		jnum[i]=jnuminline(str);
	}
	
	for(int i=1;i<=hangnum;++i){
		fscanf(yl,"%s",str);
		if(jnum[i]>jnum[i-1]){
			fprintf(ot,"{");
		}
		fprintf(ot,"%s",str);
		if(jnum[i]<jnum[i-1]){
			fprintf(ot,"}");
		}
	}
	 
	return 0;
}
