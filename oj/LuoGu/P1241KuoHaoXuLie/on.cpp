#include<bits/stdc++.h>
using namespace std;
const int MAXSIZE=100+5;

int alen;
char a[MAXSIZE];
bool fix[MAXSIZE];//a[i]�費��Ҫ����

int s[MAXSIZE],top=-1;


int main(){
    scanf("%s",a);
    alen=strlen(a);

    for(int i=0;i<alen;++i){
        //������λ�ý�ջ
        if(a[i]=='(' or a[i]=='['){
            s[++top]=i;
            fix[i]=1;//������Ҫ����
        }else{//����������
            //�ж�����������ƥ��
            if(top==-1/*�ǿ�ջ*/ or a[s[top]]!=(a[i]==')'?'(':'[')/*ƥ�䲻��*/){
                fix[i]=1;//����
            }else{//ƥ�����
                fix[s[top]]=0;//ƥ����Ǹ����ò�������
                --top;//��ƥ���˵������ų�ջ
                // fix[i]=0;����������
            }
        }
    }    
    for(int i=0;i<alen;++i){
        if(a[i]=='(' or a[i]=='['){
            printf("%c",a[i]);
            fix[i] and printf("%c",a[i]=='('?')':']');
        }else{
            fix[i] and printf("%c",a[i]==')'?'(':'[');
            printf("%c",a[i]);
        }
    }
    
    return 0;
}