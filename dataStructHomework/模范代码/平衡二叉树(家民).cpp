#include <iostream>
#define MaxSize 1000            // 定义最大栈长度

using namespace std;

typedef int KeyType;            // 定义关键字的数据类型

typedef struct ANode
{
	KeyType key;
	int fac;
	ANode *lchild, *rchild;
} AVLNode;

/* 插入节点*/
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
	return false;           // 否则，k==a->key，返回false代表插入失败
}

/* 求（子）树的高度 */
int height(AVLNode* a)
{
	if (a == NULL)
		return 0;
	int lheight = height(a->lchild);
	int rheight = height(a->rchild);
	return lheight > rheight ? (lheight + 1) : (rheight + 1);
}

/* 计算各节点的平衡因子（类先序遍历） */
void count(AVLNode* a)
{
	if (a == NULL)
		return;
	a->fac = height(a->lchild) - height(a->rchild);         // 左子树高度 - 右子树高度就是平衡因子
	
	count(a->lchild);                                       // 计算左孩子的平衡因子
	count(a->rchild);                                       // 计算右孩子的平衡因子
}

/* 输出AVL树 (类先序遍历) */
void DispTree(AVLNode* a)
{
	if (a == NULL)
		return;
		
	cout << a->key;
	
	if (a->lchild || a->rchild)                             // 有至少一个孩子
	{
		cout << '(';

		DispTree(a->lchild);

		if (a->rchild)                                      // 如果有右孩子，那么输出,
		{
			cout << ',';
			DispTree(a->rchild);
		}
		
		cout << ')';
	}
}

/* 输出各节点平衡因子 */
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

/* LL调整 （想象只有“LL”，再给非叶子加右孩子）*/
void LL(AVLNode*& a)
{
	AVLNode* root = a;                  // 记录旧的根节点
	a = a->lchild;                      // 处理好新的根节点
	
	root->lchild = a->rchild;           // 根据教材的例子，或根据实际例子，就知道哪个节点对应哪个节点了
	
	a->rchild = root;
}

/* RR调整 （和LL同理）*/
void RR(AVLNode*& a)
{
	AVLNode* root = a;
	a = a->rchild;
	
	root->rchild = a->lchild;
	
	a->lchild = root;
}

/* LR调整 （想象只有“LR”，再给所有的节点补上左右孩子）*/
void LR(AVLNode*& a)
{
	AVLNode* root = a;                  // 记录原来的根节点
	a = a->lchild->rchild;              // 处理好新的根节点
	
	root->lchild->rchild = a->lchild;   // 根据实际例子或者教材，就可以知道怎么调整，这里只说一下最好由下往上调整
	a->lchild = root->lchild;
	
	root->lchild = a->rchild;
	a->rchild = root;
}

/* RL调整 （与LR同理，至少lchild 和 rchild 互换） */
void RL(AVLNode*& a)
{
	AVLNode* root = a;
	a = a->rchild->lchild;
	
	root->rchild->lchild = a->rchild;
	a->rchild = root->rchild;
	
	root->rchild = a->lchild;
	a->lchild = root;
}

/* 采用类似后序遍历的方法，判断那一个是离根节点最远的需要调整的节点 */
bool adj(AVLNode*& a)
{
	bool lres, rres;            // 分别记录左右子树是否调整成功（false代表不需要调整）
	if (a == NULL)
		return false;

 	lres = adj(a->lchild);      // 先访问左子树，进行判断
	rres = adj(a->rchild);      // 再访问右子树，进行判断
	
	if (lres || rres)           // 如果左/右子树调整成功，则直接返回true代表调整成功
		return true;

	if (a->fac == 2)            // 否则，如果该节点需要进行Lx调整，则判断是哪一种类型
	{
		if (a->lchild->fac == 1 || a->lchild->fac == 0)             // LL有两种情况
		{
			cout << endl << "节点" << a->key << "失衡，进行LL型调整..." << endl;
			LL(a);
		}
		else if (a->lchild->fac == -1)                              // LR的情况
		{
			cout << endl << "节点" << a->key << "失衡，进行LR型调整..." << endl;
			LR(a);
		}
		
		return true;                                                // 返回true，代表调整成功
	}
	
	if (a->fac == -2)           // 否则，如果需要进行Rx调整，则继续判断是哪一种类型
	{
		if (a->rchild->fac == -1 || a->rchild->fac == 0)            // 同理RR也有两种情况
		{
			cout << endl << "节点" << a->key << "失衡，进行RR型调整..." << endl;
			RR(a);
		}
		else if (a->rchild->fac == 1)
		{
			cout << endl << "节点" << a->key << "失衡，进行RL型调整..." << endl;
			RL(a);
		}
		
		return true;
	}
	
	return false;               // 否则，该节点不需要调整，返回false
}

/* 通过栈，用中序遍历的方法找某节点的前驱 */
void findPre(AVLNode* a, int s[], int &top, int k)
{
	if (a == NULL)
		return;
	if (a->lchild)          // 如果有左孩子
	{
		findPre(a->lchild, s, top, k);          // 先在左子树中找需要的节点
		if (a->lchild->key == k) return;        // 如果这个节点是目标节点，那么返回
	}
		
	s[++top] = a->key;     					   // 然后把这个节点加入到栈当中
	if (a->key == k) return;    			   // 如果这个节点是目标节点，那么返回
	
	if (a->rchild)                              // 同理继续遍历右子树
	{
		findPre(a->rchild, s, top, k);
		if (a->rchild->key == k) return;
	}
}

/* 删除节点，引入root参数，使整个递归函数能随时找到整棵树的根节点 */
bool Dele(AVLNode*& root, AVLNode*& a, int k)
{
	bool lres = NULL, rres = NULL;          // 记录左右子树中删除的结果
	int pr;                                 // 记录前驱
	int sta[MaxSize];                       // 栈
	int to;                                 // 栈顶指针
	if (a == NULL)                          // 为空代表此处删除失败
		return false;
		
	if (a->key == k)                        // 如果找到了这个节点
	{
		if (!a->lchild || !a->rchild)       // 判断是否为 非双分支节点
			a = a->lchild ? a->lchild : a->rchild;      // 如果是，直接用左右子树覆盖即可
		else    // 否则
		{
			to = -1;                        // 栈顶指针初始化
			findPre(root, sta, to, k);      // 找节点的前驱
			pr = sta[to - 1];               // 记录前驱
			Dele(root, root, pr);           // 删除前驱（从根节点出发删除）
			a->key = pr;                    // 删除成功后再赋值
		}
		return true;                        // 删除成功
	}
	else if (k < a->key)                    // 否则删除左子树，并记录结果
		lres = Dele(root, a->lchild, k);
	else if (k > a->key)
		rres = Dele(root, a->rchild, k);
	return lres || rres;                    // 若其中一个删除成功，则返回true
}

int main()
{
	AVLNode* a1 = NULL;
	
	int k[] = {16, 3, 7, 11, 9, 26, 18, 14, 15};
//	int k[] = {4, 9, 0, 1, 8, 6, 3, 5, 2, 7};
	
	int i, n = sizeof(k) / sizeof(int);

	cout << "(1) 创建平衡二叉树..." << endl << endl;

	for (i = 0; i < n; ++i)
	{
		cout << "插入：" << k[i] << endl;
		cout << (Insert(a1, k[i]) ? "插入成功" : "插入失败") << endl;
		
		cout << "输出平衡二叉树："; DispTree(a1); cout << endl;
		
        count(a1);
        cout << "各节点平衡因子为："; DispFac(a1); cout << endl;
        
		if (adj(a1))
		{
			cout << "输出平衡二叉树："; DispTree(a1); cout << endl;
			
			count(a1);
        	cout << "各节点平衡因子为："; DispFac(a1); cout << endl;
		}
		cout << endl;
	}
	
	cout << "(2) ";
	while (cout << "请输入要删除的节点（按Ctrl+Z+回车退出）：" && cin >> i)
	{
		if (Dele(a1, a1, i))
			cout << "删除成功！" << endl;
		else
			cout << "删除失败！" << endl;
			
		cout << "输出平衡二叉树："; DispTree(a1); cout << endl;

        count(a1);
        cout << "各节点平衡因子为："; DispFac(a1); cout << endl;

        if (adj(a1))                                                        // 如果需要调整，则返回true
		{
			cout << "输出平衡二叉树："; DispTree(a1); cout << endl;

			count(a1);
        	cout << "各节点平衡因子为："; DispFac(a1); cout << endl;
		}
			
		cout << endl;
	}
	return 0;
}
