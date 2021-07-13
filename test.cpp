
// �߾���ʵ���У�һ�����������󳤶� LEN �ȿ��ܵ�����len*len+10��һЩ
// Ȼ����ȥĩβ�ļ���ѭ��������һ������ʡȥ���ٱ߽�����Ĵ���
static const int LEN = max_len*max_len+10;
//�����λ����λ������
int a[LEN], b[LEN], c[LEN], d[LEN];
//�������
void clear(int a[]) {
    memset(a,0,sizeof(a));
}
//�����ж�ȡ�������ַ�����a[]
void read(int a[]) {
    static char s[LEN + 1];
    scanf("%s", s);
    clear(a);
    for (int i = 0,len = strlen(s); i < len; ++i)
        a[len - i - 1] = s[i] - '0';// ������������ת
    // s[i] - '0' ���� s[i] ����ʾ������
}
//�����λ���������
void print(int a[]) {
    int i;
    for (i = LEN - 1; i >= 1; --i)
        if (a[i] != 0) break;
    for (; i >= 0; --i)
        putchar(a[i] + '0');
    puts("");
}
//c=a+b
void add(int a[], int b[], int c[]) {
    clear(c);
    for (int i = 0; i < LEN - 1; ++i) {
        c[i] += a[i] + b[i];// ����Ӧλ�ϵ��������
        if (c[i] >= 10) {
            ++c[i + 1];// ��λ
            c[i] -= 10;
        }
    }
}
//c=a-b,Ҫ��a>=b
void sub(int a[], int b[], int c[]) {
    clear(c);
    for (int i = 0; i < LEN - 1; ++i) {
        c[i] += a[i] - b[i];// ��λ���
        if (c[i] < 0) {
            --c[i + 1]; // ��λ
            c[i] += 10;
        }
    }
}
//c[]=����a[]*С��b
void mul_short(int a[], int b, int c[]) {
  clear(c);
  for (int i = 0; i < LEN - 1; ++i) {
    // ֱ�Ӱ� a �ĵ� i λ������Գ�����������
    c[i] += a[i] * b;
    if (c[i] >= 10) {
      // �����λ
      // c[i] / 10 ��������������Ϊ��λ������ֵ
      c[i + 1] += c[i] / 10;
      // �� c[i] % 10 ��������������Ϊ�ڵ�ǰλ���µ�ֵ
      c[i] %= 10;
    }
  }
}

//c=a*b ; ����x����
void mul(int a[], int b[], int c[]) {
    clear(c);
    for (int i = 0; i < LEN - 1; ++i) {
    // ����ֱ�Ӽ������еĴӵ͵��ߵ� i λ����һ�������˽�λ
    // �� i ��ѭ��Ϊ c[i] �������������� p + q = i �� a[p] �� b[q] �ĳ˻�֮��
    // ��������Ч����ֱ�ӽ�����ͼ��������������һ���ģ�ֻ�Ǹ��Ӽ�̵�һ��ʵ�ַ�ʽ
        for (int j = 0; j <= i; ++j)
            c[i] += a[j] * b[i - j];

        if (c[i] >= 10) {
            c[i + 1] += c[i] / 10;
            c[i] %= 10;
        }
    }
}
// ������ a ���±� last_dg Ϊ���λ���Ƿ�����ټ�ȥ���� b �����ַǸ�
// len �ǳ��� b �ĳ��ȣ����ⷴ������
inline bool greater_eq(int a[], int b[], int last_dg, int len) {
  // �п��ܱ�����ʣ��Ĳ��ֱȳ�������������������� 1 λ��������жϼ���
  if (a[last_dg + len] != 0) return true;
  // �Ӹ�λ����λ����λ�Ƚ�
  for (int i = len - 1; i >= 0; --i) {
    if (a[last_dg + i] > b[i]) return true;
    if (a[last_dg + i] < b[i]) return false;
  }
  // ��ȵ�������Ҳ�ǿ��е�
  return true;
}

void div(int a[], int b[], int c[], int d[]) {
  clear(c);
  clear(d);

  int la, lb;
  for (la = LEN - 1; la > 0; --la)
    if (a[la - 1] != 0) break;
  for (lb = LEN - 1; lb > 0; --lb)
    if (b[lb - 1] != 0) break;
  if (lb == 0) {
    puts("> <");
    return;
  }  // ��������Ϊ��

  // c ����
  // d �Ǳ�������ʣ�ಿ�֣��㷨��������Ȼ��Ϊ����
  for (int i = 0; i < la; ++i) d[i] = a[i];
  for (int i = la - lb; i >= 0; --i) {
    // �����̵ĵ� i λ
    while (greater_eq(d, b, i, lb)) {
      // �����Լ������
      // ��һ����һ���߾��ȼ���
      for (int j = 0; j < lb; ++j) {
        d[i + j] -= b[j];
        if (d[i + j] < 0) {
          d[i + j + 1] -= 1;
          d[i + j] += 10;
        }
      }
      // ʹ�̵���һλ���� 1
      c[i] += 1;
      // ����ѭ����ͷ�����¼��
    }
  }
}

usage:
    read(a);
    char op[4];
    scanf("%s", op);
    read(b);
    switch (op[0]) {
    case '+':
        add(a, b, c);
        print(c);
        break;
    case '-':
        sub(a, b, c);
        print(c);
        break;
    case '*':
        mul(a, b, c);
        print(c);
        break;
    case '/':
        div(a, b, c, d);
        print(c);
        print(d);
        break;
    default:
        puts("> <");
    }