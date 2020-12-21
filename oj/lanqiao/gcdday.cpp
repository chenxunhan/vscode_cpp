#include<bits/stdc++.h>
using namespace std;

int rday[13]={0,31,29,31,30,31,30,31,31,30,31,30,31}; //366
int pday[13]={0,31,28,31,30,31,30,31,31,30,31,30,31}; //365
bool isrun(int y){
	return (y%400==0)||(y%100!=0&&y%4==0);
}

int minfromhour(int hour){
	return hour*60;
}

int hourfromday(int day){
	return day*24;
}

int main(){
	int sum=0;
	sum+=minfromhour(hourfromday(31-23+1));
	for(int i=8;i<=12;++i){
		sum+=minfromhour(hourfromday(pday[i])) ;
	}
	
	//[1922,2019]
	for(int i=1922;i<=2019;++i){
		sum+=minfromhour(hourfromday((isrun(i)?366:365)));	
	}
	
	//[2020.1.1~2020.7.1]
	for(int i=1;i<=6;++i)
	{sum+= minfromhour(hourfromday((isrun(2020)?rday[i]:pday[i]))) ; 
	}
	//wa:7.1 do not need calculate!!!!sum+=minfromhour(hourfromday(1));
	cout<<sum;//52038720
	//right:52038720
	return 0;
}
