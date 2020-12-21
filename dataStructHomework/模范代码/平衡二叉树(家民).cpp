#include <iostream>
#define MaxSize 1000            // �������ջ����

using namespace std;

typedef int KeyType;            // ����ؼ��ֵ���������

typedef struct ANode
{
	KeyType key;
	int fac;
	ANode *lchild, *rchild;
} AVLNode;

/* ����ڵ�*/
bool Insert(AVLNode*& a, KeyType k)
{
	if (a == NULL)
	{
		a = new AVLNode;
		a->key = k;
		a->lchild = a->rchild = NULL;
		a->fac = 0;
		return true;
	}
	else if (k < a->key)
		return Insert(a->lchild, k);
	else if (k > a->key)
		return Insert(a->rchild, k);
	return false;           // ����k==a->key������false�������ʧ��
}

/* ���ӣ����ĸ߶� */
int height(AVLNode* a)
{
	if (a == NULL)
		return 0;
	int lheight = height(a->lchild);
	int rheight = height(a->rchild);
	return lheight > rheight ? (lheight + 1) : (rheight + 1);
}

/* ������ڵ��ƽ�����ӣ������������ */
void count(AVLNode* a)
{
	if (a == NULL)
		return;
	a->fac = height(a->lchild) - height(a->rchild);         // �������߶� - �������߶Ⱦ���ƽ������
	
	count(a->lchild);                                       // �������ӵ�ƽ������
	count(a->rchild);                                       // �����Һ��ӵ�ƽ������
}

/* ���AVL�� (���������) */
void DispTree(AVLNode* a)
{
	if (a == NULL)
		return;
		
	cout << a->key;
	
	if (a->lchild || a->rchild)                             // ������һ������
	{
		cout << '(';

		DispTree(a->lchild);

		if (a->rchild)                                      // ������Һ��ӣ���ô���,
		{
			cout << ',';
			DispTree(a->rchild);
		}
		
		cout << ')';
	}
}

/* ������ڵ�ƽ������ */
void DispFac(AVLNode* a)
{
	if (a == NULL)
		return;
	
	cout << a->fac;

	if (a->lchild || a->rchild)
	{
		cout << '(';

		DispFac(a->lchild);

		if (a->rchild)
		{
			cout << ',';
			DispFac(a->rchild);
		}

		cout << ')';
	}
}

/* LL���� ������ֻ�С�LL�����ٸ���Ҷ�Ӽ��Һ��ӣ�*/
void LL(AVLNode*& a)
{
	AVLNode* root = a;                  // ��¼�ɵĸ��ڵ�
	a = a->lchild;                      // ������µĸ��ڵ�
	
	root->lchild = a->rchild;           // ���ݽ̲ĵ����ӣ������ʵ�����ӣ���֪���ĸ��ڵ��Ӧ�ĸ��ڵ���
	
	a->rchild = root;
}

/* RR���� ����LLͬ��*/
void RR(AVLNode*& a)
{
	AVLNode* root = a;
	a = a->rchild;
	
	root->rchild = a->lchild;
	
	a->lchild = root;
}

/* LR���� ������ֻ�С�LR�����ٸ����еĽڵ㲹�����Һ��ӣ�*/
void LR(AVLNode*& a)
{
	AVLNode* root = a;                  // ��¼ԭ���ĸ��ڵ�
	a = a->lchild->rchild;              // ������µĸ��ڵ�
	
	root->lchild->rchild = a->lchild;   // ����ʵ�����ӻ��߽̲ģ��Ϳ���֪����ô����������ֻ˵һ������������ϵ���
	a->lchild = root->lchild;
	
	root->lchild = a->rchild;
	a->rchild = root;
}

/* RL���� ����LRͬ������lchild �� rchild ������ */
void RL(AVLNode*& a)
{
	AVLNode* root = a;
	a = a->rchild->lchild;
	
	root->rchild->lchild = a->rchild;
	a->rchild = root->rchild;
	
	root->rchild = a->lchild;
	a->lchild = root;
}

/* �������ƺ�������ķ������ж���һ��������ڵ���Զ����Ҫ�����Ľڵ� */
bool adj(AVLNode*& a)
{
	bool lres, rres;            // �ֱ��¼���������Ƿ�����ɹ���false������Ҫ������
	if (a == NULL)
		return false;

 	lres = adj(a->lchild);      // �ȷ����������������ж�
	rres = adj(a->rchild);      // �ٷ����������������ж�
	
	if (lres || rres)           // �����/�����������ɹ�����ֱ�ӷ���true��������ɹ�
		return true;

	if (a->fac == 2)            // ��������ýڵ���Ҫ����Lx���������ж�����һ������
	{
		if (a->lchild->fac == 1 || a->lchild->fac == 0)             // LL���������
		{
			cout << endl << "�ڵ�" << a->key << "ʧ�⣬����LL�͵���..." << endl;
			LL(a);
		}
		else if (a->lchild->fac == -1)                              // LR�����
		{
			cout << endl << "�ڵ�" << a->key << "ʧ�⣬����LR�͵���..." << endl;
			LR(a);
		}
		
		return true;                                                // ����true����������ɹ�
	}
	
	if (a->fac == -2)           // ���������Ҫ����Rx������������ж�����һ������
	{
		if (a->rchild->fac == -1 || a->rchild->fac == 0)            // ͬ��RRҲ���������
		{
			cout << endl << "�ڵ�" << a->key << "ʧ�⣬����RR�͵���..." << endl;
			RR(a);
		}
		else if (a->rchild->fac == 1)
		{
			cout << endl << "�ڵ�" << a->key << "ʧ�⣬����RL�͵���..." << endl;
			RL(a);
		}
		
		return true;
	}
	
	return false;               // ���򣬸ýڵ㲻��Ҫ����������false
}

/* ͨ��ջ������������ķ�����ĳ�ڵ��ǰ�� */
void findPre(AVLNode* a, int s[], int &top, int k)
{
	if (a == NULL)
		return;
	if (a->lchild)          // ���������
	{
		findPre(a->lchild, s, top, k);          // ����������������Ҫ�Ľڵ�
		if (a->lchild->key == k) return;        // �������ڵ���Ŀ��ڵ㣬��ô����
	}
		
	s[++top] = a->key;     					   // Ȼ�������ڵ���뵽ջ����
	if (a->key == k) return;    			   // �������ڵ���Ŀ��ڵ㣬��ô����
	
	if (a->rchild)                              // ͬ���������������
	{
		findPre(a->rchild, s, top, k);
		if (a->rchild->key == k) return;
	}
}

/* ɾ���ڵ㣬����root������ʹ�����ݹ麯������ʱ�ҵ��������ĸ��ڵ� */
bool Dele(AVLNode*& root, AVLNode*& a, int k)
{
	bool lres = NULL, rres = NULL;          // ��¼����������ɾ���Ľ��
	int pr;                                 // ��¼ǰ��
	int sta[MaxSize];                       // ջ
	int to;                                 // ջ��ָ��
	if (a == NULL)                          // Ϊ�մ���˴�ɾ��ʧ��
		return false;
		
	if (a->key == k)                        // ����ҵ�������ڵ�
	{
		if (!a->lchild || !a->rchild)       // �ж��Ƿ�Ϊ ��˫��֧�ڵ�
			a = a->lchild ? a->lchild : a->rchild;      // ����ǣ�ֱ���������������Ǽ���
		else    // ����
		{
			to = -1;                        // ջ��ָ���ʼ��
			findPre(root, sta, to, k);      // �ҽڵ��ǰ��
			pr = sta[to - 1];               // ��¼ǰ��
			Dele(root, root, pr);           // ɾ��ǰ�����Ӹ��ڵ����ɾ����
			a->key = pr;                    // ɾ���ɹ����ٸ�ֵ
		}
		return true;                        // ɾ���ɹ�
	}
	else if (k < a->key)                    // ����ɾ��������������¼���
		lres = Dele(root, a->lchild, k);
	else if (k > a->key)
		rres = Dele(root, a->rchild, k);
	return lres || rres;                    // ������һ��ɾ���ɹ����򷵻�true
}

int main()
{
	AVLNode* a1 = NULL;
	
	int k[] = {16, 3, 7, 11, 9, 26, 18, 14, 15};
//	int k[] = {4, 9, 0, 1, 8, 6, 3, 5, 2, 7};
	
	int i, n = sizeof(k) / sizeof(int);

	cout << "(1) ����ƽ�������..." << endl << endl;

	for (i = 0; i < n; ++i)
	{
		cout << "���룺" << k[i] << endl;
		cout << (Insert(a1, k[i]) ? "����ɹ�" : "����ʧ��") << endl;
		
		cout << "���ƽ���������"; DispTree(a1); cout << endl;
		
        count(a1);
        cout << "���ڵ�ƽ������Ϊ��"; DispFac(a1); cout << endl;
        
		if (adj(a1))
		{
			cout << "���ƽ���������"; DispTree(a1); cout << endl;
			
			count(a1);
        	cout << "���ڵ�ƽ������Ϊ��"; DispFac(a1); cout << endl;
		}
		cout << endl;
	}
	
	cout << "(2) ";
	while (cout << "������Ҫɾ���Ľڵ㣨��Ctrl+Z+�س��˳�����" && cin >> i)
	{
		if (Dele(a1, a1, i))
			cout << "ɾ���ɹ���" << endl;
		else
			cout << "ɾ��ʧ�ܣ�" << endl;
			
		cout << "���ƽ���������"; DispTree(a1); cout << endl;

        count(a1);
        cout << "���ڵ�ƽ������Ϊ��"; DispFac(a1); cout << endl;

        if (adj(a1))                                                        // �����Ҫ�������򷵻�true
		{
			cout << "���ƽ���������"; DispTree(a1); cout << endl;

			count(a1);
        	cout << "���ڵ�ƽ������Ϊ��"; DispFac(a1); cout << endl;
		}
			
		cout << endl;
	}
	return 0;
}
