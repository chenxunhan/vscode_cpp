#include<bits/stdc++.h>
using namespace std;

char name1[50]="你d�?";
char name2[50];
char name3[50];
int year;
int main(){
//	cin>>name1;
//	cin.get(name1,50).get();
//	cin.get(name2,50).get();
//	cin.get(name3,50).get();
//		cin.getline(name1,sizeof(name1)).getline().getline(name3,sizeof(name3));
	cout<<R"cxh(""\n
	
	()  ()
	)cxh"<<name1<<endl
	<<"name2:"<<name2<<endl
	<<"name3:"<<name3<<endl;

	
	const int a=2;//&a ������const int*
	int b=2,c;//&a ������int*
	const int* p=&a; //*p���ɱ�, ����ʼ����������
	int const *p1=&a;//ditto
	int* const p2=&b;//p2���ɱ�ֻ����&b, ��b�Ǳ���
	p2=&c;//����
    return 0;
}