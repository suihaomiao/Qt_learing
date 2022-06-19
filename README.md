# Qt_learing

## 控件学习

### 1、学习QLineEdit

QLineEdit部分内置信号与槽

signal：

```C++
// 输入框中text变化时，发送该信号。text表示当前输入框的内容
void  textChanged(const QString &text); 
void  textEdited(const QString &text);

```

slot：

```C++

void clear();						// 清空该输入框
void copy() const;					// 拷贝当前输入框的内容
void cut();							// 剪切
void paste();						// 粘贴
void redo();						// 重复上一次操作（取决于一个开关）
void selectAll();					// 选择输入框的所有内容
void setText(const QString &);		// 给输入框设置text
void undo();						// 撤销当前输入

```







### 2、布局管理器

常用的布局管理器有三种，水平、垂直和格子管理器，分别功能为：

水平：控件在水平方向保持一致。

垂直：控件在垂直方向保持一致。

格子：在一个网格下，控制嵌入其中。



其中水平和垂直管理器均较简单，直接添加即可。

网格管理器，需要制定填入网格的坐标；一般以0，0为起点，row（行），col（列）作为数字填入即可

简单代码如下：

```C++
    // 创建垂水平布局器， 账号和密码
    QHBoxLayout *account = new QHBoxLayout();
    account->addWidget(ui->accountLable);
    account->addWidget(ui->account);

    QHBoxLayout *passwd = new QHBoxLayout();
    passwd->addWidget(ui->passwdLable);
    passwd->addWidget(ui->password);

    // 创建一个垂直布局器，账号和密码
    QVBoxLayout *qhbox1 = new QVBoxLayout();
    // 将登陆和注册按钮放在该布局器中
    qhbox1->addLayout(account);
    qhbox1->addLayout(passwd);

    // 创建水平布局器，包含登陆和注册
    QVBoxLayout *button = new QVBoxLayout();
    button->addWidget(ui->logIn);
    button->addWidget(ui->registers);

    out << "debug";
    QGridLayout *grid = new QGridLayout(this->centralWidget());
    grid->addWidget(ui->welcome,0 ,0 );
    grid->addLayout(qhbox1, 1, 0);
    grid->addLayout(button, 2, 0);

    setLayout(grid);
```

