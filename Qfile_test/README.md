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



上述代码用纯代码的方式实现了一个登陆界面（很拙劣的一个），在一般的界面设计中，还是用ui来调节会方便很多

### 3、消息盒子

Qt中提供了一些简单消息盒子，例如输入密码错误后，出现一个简单的界面来提示用户；

![image-20220619212620249](pic/messageBox1.png)



```C++

void about(QWidget *parent, const QString &title, const QString &text);

void aboutQt(QWidget *parent, const QString &title = QString());

QMessageBox::StandardButton critical(QWidget *parent, const QString &title, const QString &text, QMessageBox::StandardButtons buttons, QMessageBox::StandardButton defaultButton = NoButton);

int critical(QWidget *parent, const QString &title, const QString &text, QMessageBox::StandardButton button0, QMessageBox::StandardButton button1);

QMessageBox::StandardButton information(QWidget *parent, const QString &title, const QString &text, QMessageBox::StandardButtons buttons, QMessageBox::StandardButton defaultButton = NoButton);

QMessageBox::StandardButton information(QWidget *parent, const QString &title, const QString &text, QMessageBox::StandardButton button0, QMessageBox::StandardButton button1 = NoButton);

QMessageBox::StandardButton question(QWidget *parent, const QString &title, const QString &text, QMessageBox::StandardButtons buttons = ..., QMessageBox::StandardButton defaultButton = NoButton);

int question(QWidget *parent, const QString &title, const QString &text, QMessageBox::StandardButton button0, QMessageBox::StandardButton button1);

QMessageBox::StandardButton warning(QWidget *parent, const QString &title, const QString &text, QMessageBox::StandardButtons buttons, QMessageBox::StandardButton defaultButton = NoButton);

int warning(QWidget *parent, const QString &title, const QString &text, QMessageBox::StandardButton button0, QMessageBox::StandardButton button1);

```

根据Qt官方帮助文档，可以简单分为about，critical，information，question，warning这几种；分别对应这不同消息盒子；

以warning为例，来解释各个参数含义：

```C++
QMessageBox::StandardButton warning(QWidget *parent, const QString &title, const QString &text, QMessageBox::StandardButtons buttons, QMessageBox::StandardButton defaultButton = NoButton);
```

首先，这是个static方法，可以直接通过类名调用；

parent：表示父类。（在Qt中，有父类和子类的概念，当父类析构时，会把该父类的子类全部析构；同时也是窗口显示问题，当选定到某个窗口为父类，则子类会在该父类之上显示）

title：消息盒子的标题。

text：消息盒子的文本内容。

buttons：消息盒子显示的显示的按钮，这里可以提供多个标准按钮在消息盒子上：

![image-20220619212620249](pic/messageBox2.png)

defaultButton：消息盒子打开时，默认选中的按钮。

返回值StandardButton：当消息盒子存在多个按钮时，可以通过返回值来判断用户选择的是哪个按钮（以上图的枚举来判断）

例子：

```C++
void MainWindow::Login()
{
    QString account = ui->account->text();
    QString passwd = ui->password->text();

    // 认证过程
    if (account == "shm" && passwd == "123456") {
        out << "登陆成功";
        QMessageBox::information(this, "登陆成功", "欢迎使用", QMessageBox::Open | QMessageBox::Yes, QMessageBox::Yes);
    } else {
        QMessageBox::warning(this, "账号密码不匹配", "兄弟，开guest吧");
    }
}

```



### 4、对话框

对话框，可以分为Qt内置的和自定义的两种；

Qt内置的对话框有：颜色对话框、字体对话框和文件对话框等；

之前使用的比较多的是文件对话框。

颜色对话框：

```C++

Static QColor getColor(const QColor &initial = Qt::white, QWidget *parent = nullptr, const QString &title = QString(), QColorDialog::ColorDialogOptions options = ...)

```

静态函数，可以直接通过类型调用。

initial：表示打开对话框默认选择的颜色。

parent：父类。

title：标题。

返回值：返回用户选择的颜色。

**如果判断用户是否选择OK还是cancle**

根据返回值QColor中的一个方法：

```C+=
bool QColor::isValid() const
```

如果用户点击了OK，那么该接口返回true，反之返回false；



字体对话框

```C++
QFont getFont(bool *ok, QWidget *parent = nullptr)
```

ok：表示用户是否选择字体；

返回值：用户选择的字体，Qfont。



文件对话框

```C++

QString getOpenFileName(QWidget *parent = nullptr, const QString &caption = QString(), const QString &dir = QString(), const QString &filter = QString(), QString *selectedFilter = nullptr, QFileDialog::Options options = ...)

```

该函数用在需要用户打开文件时，弹出文件对话框，来选择文件使用。

parent：父类。

caption：类似于标题。

dir：打开的默认路径。

filter：过滤的文件，只有符合该参数的文件类型才会被显示，如果想要多个文件类型显示，可以用;;来显示

```C++
  "Images (*.png *.xpm *.jpg);;Text files (*.txt);;XML files (*.xml)"
```

该filter表示只显示images和xml文件，分别对应.png,xpm,jpg和xml格式。

返回值为用户选择的文件的路径，若没有选择，则为null。



