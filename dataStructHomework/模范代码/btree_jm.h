using namespace std;

typedef char ElemType;

typedef struct node {
	ElemType data;
	node *lchild, *rchild;
} BTNode;

/* 递归建立二叉树
 * 原则：建树成功停留在该树的最后一个位置；否则停留在相对位置上的最后一个位置(如','前面 或 ')'前面)
 */
void CreateBTree(BTNode*& b, char*& s)
{
	if (*s == ',' || *s == ')')             // 分别对应没有左子树和没有右子树的情况
	{
		--s;                                // 指针往前移，让递归调用该函数下面的语句正常进行
		return;
	}

	b = new BTNode;                         // 语句来到这里，证明if不成立，这棵树至少有一个根节点，依次建立节点、赋值
	b->lchild = b->rchild = NULL;
	b->data = *s;

	++s;                                    // 根节点建立完毕，指针指向下一个位置
	if (*s != '(')                          // 如果这个位置不是'('，证明此节点没有左右子树
	{
		--s;                                // 同理指针往前移
		return;
	}

	++s;                                    // if不成立，有'('，指针向后移动
	CreateBTree(b->lchild, s);              // 建立左子树（没有的话会被最开始的那个if处理）

	++s;                                    // 指针指向下一个位置
	if (*s == ',')
		++s; 							   // 如果下一个字符是','，证明有右子树，不过还需要移动一个字符

	CreateBTree(b->rchild, s);              // 建立右子树
	++s;                                    // 建树后指针指向树的最后一个位置
}

/* 查找节点 */
BTNode* FindNode(BTNode* b, ElemType e)
{
	if (NULL == b)                  // 递归终止条件
		return NULL;
	if (e == b->data)               // 找到该值，就返回节点指针
		return b;
	BTNode* lFind = FindNode(b->lchild, e);     // 否则在左子树中找
	BTNode* rFind = FindNode(b->rchild, e);     // 在右子树中找

	return lFind ? lFind : rFind;               // 找得到就不为NULL，就会返回节点指针
}

/* 求二叉树的高度 */
int BTHeight(BTNode* b)
{
	if (NULL == b)
		return 0;
	int lchildh = BTHeight(b->lchild);          // 先求左子树的高度
	int rchildh = BTHeight(b->rchild);          // 再求右子树的高度
	return lchildh > rchildh ? lchildh + 1 : rchildh + 1;   // 那么以b为根节点的树的高度就是两者较大值+1
}

/* 计算二叉树的节点个数 */
int CountNode(BTNode* b)
{
	if (NULL == b)
		return 0;
	int l = CountNode(b->lchild);           // 先求左子树的所有节点数
	int r = CountNode(b->rchild);           // 再求右子树的所有节点数
	return 1 + l + r;                       // 那么以b为根节点的数的所有节点数就是1（根节点）+左右子树的节点数
}

/* 计算二叉树中单分支节点的个数 */
int CountSNode(BTNode* b)
{
	if (NULL == b)
		return 0;
	int l = CountSNode(b->lchild);
	int r = CountSNode(b->rchild);
	return l + r +
			(NULL == b->lchild && b->rchild || b->lchild && NULL == b->rchild);
			// 若左右子树中其中一个为NULL，另一个不为NULL，那么此括号内的值为1
			// + 的优先级高于 ==
}

/* 计算二叉树中双分支节点的个数 */
int CountDNode(BTNode* b)
{
	if (NULL == b)
		return 0;
	int l = CountDNode(b->lchild);
	int r = CountDNode(b->rchild);
	return l + r + (b->lchild && b->rchild);// 左右子树都存在时，括号内的值为1
}

/* 遍历整棵二叉树，同时利用数组记录对应层的节点个数 */
int CountithNode(BTNode* b, int i, int cnt[])
{
	if (NULL == b)
		return 0;
	else ++cnt[i];
	
	CountithNode(b->lchild, i + 1, cnt);    // 继续记录左子树中下一层的节点数
	CountithNode(b->rchild, i + 1, cnt);    // 右子树
}

/* 计算二叉树中叶子节点的个数 */
int CountLeafNode(BTNode* b)
{
	if (NULL == b)
		return 0;

	int l = CountLeafNode(b->lchild);
	int r = CountLeafNode(b->rchild);
	return l + r + (NULL == b->lchild && NULL == b->rchild);
					// 该节点没有左右子树时，才是叶子节点，括号内的值才为1
}

/* 最近的公共祖先 */
/* 节点值必须唯一 二叉树中一定要有这两个节点/两个节点都不存在 */
BTNode* FindLCNode(BTNode* b, ElemType x, ElemType y)
{
	if (NULL == b)
		return NULL;
	if (b->data == x || b->data == y)       // 若根节点为目标节点，返回该节点指针；因为一个节点也可以时它自身的祖先
		return b;

	BTNode* l = FindLCNode(b->lchild, x, y);    // 在左子树中找目标节点
	BTNode* r = FindLCNode(b->rchild, x, y);    // 在右子树中找目标节点

	if (l != NULL && r != NULL)                 // 若两个子树中找到的节点都不为空，那么该节点就是他们的最近的公共祖先
		return b;                               // 因为是先递归到底层，再层层返回，由下往上，所以第一次相遇就是最近的公共祖先
	
	return l != NULL ? l : r;                   // 否则返回左右子树中找到的那个节点指针（找不到就是NULL）
}

/* 销毁二叉树 */
void DestroyBTree(BTNode*& b)
{
	if (NULL == b)
		return;
	DestroyBTree(b->lchild);                // 先销毁左子树
	DestroyBTree(b->rchild);
	delete b;                               // 最后再销毁根节点
}
