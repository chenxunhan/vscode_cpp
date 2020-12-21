#include<bits/stdc++.h>

using namespace std;

int main(){
	
	char str[105];
	scanf("%s",str);
	char b=str[0]; 
	for(int i=1;str[i]!=0;++i){
		if(str[i]>='1'&&str[i]<='9'){
			int num=str[i]-'0';
			while(num--){
				putchar(b);
			}
		}else if(!(b>='0'&&b<='9')){
			putchar(b);
		}
		
		b=str[i];
	}
	
	return 0;
}
