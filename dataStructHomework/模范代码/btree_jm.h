using namespace std;

typedef char ElemType;

typedef struct node {
	ElemType data;
	node *lchild, *rchild;
} BTNode;

/* �ݹ齨��������
 * ԭ�򣺽����ɹ�ͣ���ڸ��������һ��λ�ã�����ͣ�������λ���ϵ����һ��λ��(��','ǰ�� �� ')'ǰ��)
 */
void CreateBTree(BTNode*& b, char*& s)
{
	if (*s == ',' || *s == ')')             // �ֱ��Ӧû����������û�������������
	{
		--s;                                // ָ����ǰ�ƣ��õݹ���øú�������������������
		return;
	}

	b = new BTNode;                         // ����������֤��if�������������������һ�����ڵ㣬���ν����ڵ㡢��ֵ
	b->lchild = b->rchild = NULL;
	b->data = *s;

	++s;                                    // ���ڵ㽨����ϣ�ָ��ָ����һ��λ��
	if (*s != '(')                          // ������λ�ò���'('��֤���˽ڵ�û����������
	{
		--s;                                // ͬ��ָ����ǰ��
		return;
	}

	++s;                                    // if����������'('��ָ������ƶ�
	CreateBTree(b->lchild, s);              // ������������û�еĻ��ᱻ�ʼ���Ǹ�if����

	++s;                                    // ָ��ָ����һ��λ��
	if (*s == ',')
		++s; 							   // �����һ���ַ���','��֤��������������������Ҫ�ƶ�һ���ַ�

	CreateBTree(b->rchild, s);              // ����������
	++s;                                    // ������ָ��ָ���������һ��λ��
}

/* ���ҽڵ� */
BTNode* FindNode(BTNode* b, ElemType e)
{
	if (NULL == b)                  // �ݹ���ֹ����
		return NULL;
	if (e == b->data)               // �ҵ���ֵ���ͷ��ؽڵ�ָ��
		return b;
	BTNode* lFind = FindNode(b->lchild, e);     // ����������������
	BTNode* rFind = FindNode(b->rchild, e);     // ������������

	return lFind ? lFind : rFind;               // �ҵõ��Ͳ�ΪNULL���ͻ᷵�ؽڵ�ָ��
}

/* ��������ĸ߶� */
int BTHeight(BTNode* b)
{
	if (NULL == b)
		return 0;
	int lchildh = BTHeight(b->lchild);          // �����������ĸ߶�
	int rchildh = BTHeight(b->rchild);          // �����������ĸ߶�
	return lchildh > rchildh ? lchildh + 1 : rchildh + 1;   // ��ô��bΪ���ڵ�����ĸ߶Ⱦ������߽ϴ�ֵ+1
}

/* ����������Ľڵ���� */
int CountNode(BTNode* b)
{
	if (NULL == b)
		return 0;
	int l = CountNode(b->lchild);           // ���������������нڵ���
	int r = CountNode(b->rchild);           // ���������������нڵ���
	return 1 + l + r;                       // ��ô��bΪ���ڵ���������нڵ�������1�����ڵ㣩+���������Ľڵ���
}

/* ����������е���֧�ڵ�ĸ��� */
int CountSNode(BTNode* b)
{
	if (NULL == b)
		return 0;
	int l = CountSNode(b->lchild);
	int r = CountSNode(b->rchild);
	return l + r +
			(NULL == b->lchild && b->rchild || b->lchild && NULL == b->rchild);
			// ����������������һ��ΪNULL����һ����ΪNULL����ô�������ڵ�ֵΪ1
			// + �����ȼ����� ==
}

/* �����������˫��֧�ڵ�ĸ��� */
int CountDNode(BTNode* b)
{
	if (NULL == b)
		return 0;
	int l = CountDNode(b->lchild);
	int r = CountDNode(b->rchild);
	return l + r + (b->lchild && b->rchild);// ��������������ʱ�������ڵ�ֵΪ1
}

/* �������ö�������ͬʱ���������¼��Ӧ��Ľڵ���� */
int CountithNode(BTNode* b, int i, int cnt[])
{
	if (NULL == b)
		return 0;
	else ++cnt[i];
	
	CountithNode(b->lchild, i + 1, cnt);    // ������¼����������һ��Ľڵ���
	CountithNode(b->rchild, i + 1, cnt);    // ������
}

/* �����������Ҷ�ӽڵ�ĸ��� */
int CountLeafNode(BTNode* b)
{
	if (NULL == b)
		return 0;

	int l = CountLeafNode(b->lchild);
	int r = CountLeafNode(b->rchild);
	return l + r + (NULL == b->lchild && NULL == b->rchild);
					// �ýڵ�û����������ʱ������Ҷ�ӽڵ㣬�����ڵ�ֵ��Ϊ1
}

/* ����Ĺ������� */
/* �ڵ�ֵ����Ψһ ��������һ��Ҫ���������ڵ�/�����ڵ㶼������ */
BTNode* FindLCNode(BTNode* b, ElemType x, ElemType y)
{
	if (NULL == b)
		return NULL;
	if (b->data == x || b->data == y)       // �����ڵ�ΪĿ��ڵ㣬���ظýڵ�ָ�룻��Ϊһ���ڵ�Ҳ����ʱ�����������
		return b;

	BTNode* l = FindLCNode(b->lchild, x, y);    // ������������Ŀ��ڵ�
	BTNode* r = FindLCNode(b->rchild, x, y);    // ������������Ŀ��ڵ�

	if (l != NULL && r != NULL)                 // �������������ҵ��Ľڵ㶼��Ϊ�գ���ô�ýڵ�������ǵ�����Ĺ�������
		return b;                               // ��Ϊ���ȵݹ鵽�ײ㣬�ٲ�㷵�أ��������ϣ����Ե�һ��������������Ĺ�������
	
	return l != NULL ? l : r;                   // ���򷵻������������ҵ����Ǹ��ڵ�ָ�루�Ҳ�������NULL��
}

/* ���ٶ����� */
void DestroyBTree(BTNode*& b)
{
	if (NULL == b)
		return;
	DestroyBTree(b->lchild);                // ������������
	DestroyBTree(b->rchild);
	delete b;                               // ��������ٸ��ڵ�
}
