#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"mydialog.h"
#include <QPoint>
#include <QRect>
#include<QDebug>
#include <QMenu>
#include<QMessageBox>
#include<QFileDialog>
#include<QStringList>
#include<QFontDialog>
#include<QColorDialog>
#include<QColor>
#include<QPainter>
#include<QBrush>
#include<QPixmap>
#include<QInputDialog>
#include<QProgressDialog>
#include<QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //值得注意的是QWidget可以被任何子类继承 所有的控件类 例如QDialog   QmainWindow等都可以直接使用它的API


    //设置窗口的最大尺寸
    //setMaximumSize(600,300);
    //设置窗口的最小尺寸
    //setMinimumSize(300,300);
    //设置窗口的固定尺寸
    //setFixedSize(500,500);
    //设置窗口标题
    setWindowTitle("Hello QT");
    //给显示窗口设置图标
    setWindowIcon(QIcon("D:\\素材！！！！！！！！！！！！\\1 (67).jpg"));

    //最大和最小尺寸表示可以在这个尺寸内进行拉伸 不能大于也不能小于 这个尺寸是不包含标题栏的
    //最大最小尺寸和固定尺寸是冲突的 固定尺寸是无法拉伸的 选择一个即可

    //我们下面通过按钮 信号槽的方式演示了其他方法

    //图标发生变化时发射此信号&MainWindow::windowTitleChanged       函数的参数是因为会返回新标题的名字
    connect(this,&MainWindow::windowTitleChanged,this,[=](const QString &title)
    {
        qDebug()<<"新的标题:"<<title;
    });
    //窗口发生变化的时候发射此信号                        返回的图标类型是QIcon
    connect(this,&MainWindow::windowIconChanged,this,[=](const QIcon &icon)
    {
        qDebug()<<"当前图标被修改了...";
    });

    //声明右键菜单的策略   右击的时候就会发射出信号
    setContextMenuPolicy(Qt::CustomContextMenu);//https://doc.qt.io/qt-5/qt.html#ContextMenuPolicy-enum     对其传入参数有介绍
    connect(this,&MainWindow::customContextMenuRequested,this,[=](const QPoint &pos)//此信号会返回一个Qpoint类型 也就是一个坐标
    {
        //创建菜单对象 推荐菜单项
        QMenu menu;
        menu.addAction("西红柿");
        menu.addAction("黄瓜");
        menu.addAction("茄子");
        //默认情况菜单不显示 我们需要调用exec方法 它的参数就是我们当前光标所在的位置
        menu.exec(QCursor::pos());
    });
//    label->setFrameShape (QFrame::Box);
//    label->setStyleSheet("border-width: 1px;border-style: solid;border-color: rgb(255, 170, 0);");

    //菜单栏的信号设置
    connect(ui->save_action,&QAction::triggered,this,[=]()//保存按钮作为发出信号者 发出的信号是triggered this主窗口接收 然后执行lambda
    {
        QMessageBox::information(this,"clicked","你不要调戏我...");
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

//移动窗口
void MainWindow::on_moveBtn_clicked()
{
    QRect rect = this->frameGeometry();//获取当前的坐标
    move(rect.topLeft()+QPoint(10,20));//移动 相当于一直是往右下移动
}

//获取位置信息
void MainWindow::on_positionBtn_clicked()
{
    QRect rect = this->frameGeometry();
    qDebug()<<"左上角:"<<rect.topLeft()
            <<"右上角:"<<rect.topRight()
            <<"左下角:"<<rect.bottomLeft()
            <<"右下角:"<<rect.bottomRight()
            <<"宽度:"<<rect.width()
            <<"高度:"<<rect.height();
}

//修改窗口的位置和尺寸信息(位置随机)
void MainWindow::on_geometryBtn_clicked()
{
    int x = 100+ rand()%500;
    int y= 100+ rand()%500;
    int width=this->width()+10;
    int height=this->height()+10;
    setGeometry(x,y,width,height);
}

//更换标题和图标
void MainWindow::on_pushButton_clicked()
{
    setWindowTitle("你好世界");
    setWindowIcon(QIcon("D:\\素材！！！！！！！！！！！！\\QQ图片20220606103852.jpg"));
}

//显示模态对话框和判断
void MainWindow::on_modalDlg_clicked()
{
    MyDialog dlg;
    connect(&dlg,&MyDialog::finished,this,[=](int res){
        qDebug()<<"resukt:"<<res;
    });
    connect(&dlg,&MyDialog::accepted,this,[=](){
        qDebug()<<"accepted 信号被发射了...";
    });
    connect(&dlg,&MyDialog::rejected,this,[=](){
        qDebug()<<"rejected 信号被发射了...";
    });

    int ret = dlg.exec();//显示模态对话框

    if(ret==QDialog::Accepted)
    {
        qDebug()<<"accept button clicked...";
    }
    else if(ret==QDialog::Rejected)
    {
        qDebug()<<"reject button clicked...";
    }
    else
    {
        qDebug()<<"done button clicked...";
    }
}

//窗口
void MainWindow::on_msgbox_clicked()
{
    QMessageBox::about(this,"about","这是一个简单的消息提示~~");
    QMessageBox::critical(this,"critical","这是一个错误的对话框-critical...");//X号
    //第一个参数是接收者 第二个参数是窗口标题 第三参数是窗口显示的文本 第四个参数是分别表示两个选项 同时点击的话会返回相对应的参数 第五个参数是表示默认焦点在哪个按钮上
    //也可以不写 那么默认第一个按钮
    int ret = QMessageBox::question(this,"question","你要保存修改的文件内容吗???",//?号
                                    QMessageBox::Save | QMessageBox::Cancel,QMessageBox::Cancel);

    if(ret==QMessageBox::Save)
    {
        QMessageBox::information(this,"information","恭喜你保存成功了(*^▽^*)!!!");//!号
    }
    else if(ret ==QMessageBox::Cancel)
    {
        QMessageBox::warning(this,"warning","你放弃了保存o(╥﹏╥)o!!!");//!号
    }
}

//打开目录
void MainWindow::on_filedlg_clicked()
{
#if 0   //第一种 它只能打开目录
    QString dirName = QFileDialog::getExistingDirectory(this,"打开目录","D:\\自用");//默认打开的目录 然后我们可以自己选择
    QMessageBox::information(this,"打开目录","您选择的目录是:"+dirName);//弹窗 显示我们打开的目录
#endif

#if 0   //第二种 它能打开文件
    QString arg("Text files (*.txt)");
    //初始化过滤器 有两种选择 默认是arg的Text    最后返回打开文件的绝对路径
    QString fileName=QFileDialog::getOpenFileName(
                this,tr("OPen FIle"),"D://自用",
                tr("Images9(*.png *.jpg);;Text files (*.txt)"),&arg);
    //打印显示
    QMessageBox::information(this,"打开文件","您选择的文件夹是:"+fileName);
#endif

#if 1   //第三种 它能打开多个文件遍历
    //这里由于于没有创建arg 也就不是没有默认值 而是第一个Images9 同时QStringList相当于有一堆QString的列表
    QStringList fileNames=QFileDialog::getOpenFileNames(//getOpenFileNames和上面那个相比只是多了一个s 但是返回的类型变成了QStringList
                this,tr("OPen FIle"),"D://自用",
                tr("Images9(*.png *.jpg);;Text files (*.txt)"));
    QString names;
    for(int i=0;i<fileNames.size();++i)
    {
        names+=fileNames[i]+"\n";
    }
    QMessageBox::information(this,"打开文件(s)","您选择的文件夹是:"+names);
#endif

#if 0   //第四种 用来覆盖已有文件 或者自己写一个文件 不过这些都是不存在的 这个对话框只是用来找路径的
    QString fileName=QFileDialog::getSaveFileName(this,"保存的文件","D:\\");
    QMessageBox::information(this,"保存文件","您指定的保存数据的文件是:"+fileName);

#endif
}

//选择字体字号大小
void MainWindow::on_fontdlg_clicked()
{
#if 1
    bool ok;
    /*QFontDialog::getFont方法会弹出一个选择字体和字号的窗口让我们自行选择,接收后将会返回选择好的一个QFont对象作为返回值,用于初始化一个Qfont对象 也就是字体对象
    第一个参数是一个bool类型地址 如果字体成功选择确定就会返回true 如果直接退出就是false 第二个参数就是一个字体对象
    (第一第二个参数是默认选择的 第三个参数是字体的粗细 在底层有一个enum Weight枚举决定字体的“重量”)第三个参数是this也就是当前窗口接收 第四个参数是选择字体窗口的名字*/

    QFont ft = QFontDialog::getFont(&ok,QFont("微软雅黑",12,QFont::Bold),this,"选择字体");
    qDebug()<<"pk value is:"<<ok;
#else
    QFont ft = QFontDialog::getFont(nullptr);//这种方式是纯纯调用窗口 然后选择返回赋值给ft去改变 没有默认值也没有标题名啥的
#endif
    //对fontlabel窗口使用setFont方法设置字体 参数是我们选择好的一个QFont对象
    ui->fontlabel->setFont(ft);
}

//设置颜色
void MainWindow::on_colordlg_clicked()
{
    //和之前的选择字体一样是封装好的方法调用窗口用于选择颜色 选择好之后会返回一个QColor对象
    QColor color = QColorDialog::getColor();
    QBrush brush(color);
    QRect rect(0,0,ui->color->width(),ui->color->height());
    QPixmap pix(rect.width(),rect.height());
    QPainter p(&pix);
    p.fillRect(rect,brush);
    //设置Label的颜色
    ui->color->setPixmap(pix);
    //字符串拼接 然后修改Label内容显示出来
    QString text =QString("red: %1,green: %2,blue: %3,透明度: %4")
            .arg(color.red()).arg(color.green()).arg(color.blue()).arg(color.alpha());
    ui->colorlabel->setText(text);
}

//对话框的使用
void MainWindow::on_inputdlg_clicked()
{
#if 0   //int类型的对话框可输入可选择
    //弹出一个int类型对话框选择数字 第二个参数是对话框的标题 第三个参数是显示的提示 第四个参数是默认值 第五个参数是最大范围 第六个参数是使用箭头移动的步长
    int ret =QInputDialog::getInt(this,"年龄","您的当前年龄",10,1,100,2);
    QMessageBox::information(this,"年龄","您的当前年龄:"+QString::number(ret));//打印上面返回的选择参数
#endif

#if 0   //double类型的对话框可输入可选择
    //弹出一个double类型对话框选择数字 第二三个参数和上面一样 第四个参数是默认值 第五个参数是最小值 第六个参数是最大值 第七个参数是精度保留到小数点后两位
    double ret = QInputDialog::getDouble(this,"工资","您的工资:",2000,1000,6000,2);
    QMessageBox::information(this,"工资","您当前工资:"+QString::number(ret));
#endif

#if 0   //自己设置选项选择
    QStringList items;
    items<<"苹果"<<"橙子"<<"橘子"<<"葡萄"<<"香蕉"<<"哈密瓜";
    //倒数第三个参数是下拉列表的选项 倒数第二个参数是默认选择的 最后一个false表示选项不能被修改  然后返回选择的内容
    QString item=QInputDialog::getItem(this,"请选择你最喜欢的水果","你最喜欢的水果:",items,1,false);
    QMessageBox::information(this,"水果","您最喜欢的水果是:"+item);
#endif

#if 0   //手动输入密码
    //最后一个参数是输入框的默认值 倒数第二个是枚举类型enum EchoMode
   /*Normal 0正常显示形式，也就是边输入边显示
    NoEcho 1不会显示任何字符，包括长度
    Password 2//根据平台使用模糊字符代替你实际输入的字符
    PasswordEchoOnEdit 3当你处于输入状态的时候，是正常显示字符输入完毕之后使用Password形式隐藏字符*/
    QString text =QInputDialog::getText(this,"密码","请输入新的密码",QLineEdit::Password,"HelloWord");
    QMessageBox::information(this,"密码","您设置的密码是:"+text);
#endif

#if 1   //对话框 输入多行文本进行回应
    QString info = QInputDialog::getMultiLineText(this,"表白","您最想对漂亮小姐姐说什么呢？","");
    QString temp;
    if(info=="看看腿")
    {
        temp="流氓!!!![○･｀Д´･ ○]";
    }
    else
    {
        temp="你开心就好捏(*^▽^*)";
    }
    int ret=QMessageBox::question(this,"张腿白丝少女","你说:"+info+" "+"她说:"+temp,QMessageBox::Yes | QMessageBox::No,QMessageBox::Yes);

    if(ret==QMessageBox::Yes)
    {
        QMessageBox::information(this,"开心","那就好捏(*^▽^*)!!!");
    }
    else if(ret ==QMessageBox::No)
    {
        QMessageBox::warning(this,"慌乱","咋了不开心吗o(╥﹏╥)o!!!");
    }
#endif
}

//测试自定义对话框
void MainWindow::on_test_clicked()
{
    QMessageBox MBox;
      MBox.setFont(QFont("浪漫至死不渝",12,QFont::Normal));  //设置字体
      MBox.setWindowTitle("QMessageBox自定义对话框");//对话框的标题
      MBox.setText("自定义的对话框捏");              //对话框显示的内容
      MBox.setWindowIcon(QIcon("chilun.ico"));      //设置对话框的小图标
      MBox.setIconPixmap(QPixmap("youxi.png"));     //设置显示的大图标
      QPushButton *agreeBut = MBox.addButton("同意", QMessageBox::AcceptRole);//设置自定义对话框的选项的内容
      MBox.addButton("不同意", QMessageBox::AcceptRole);                       //设置了第二个按钮
      MBox.exec();
      if (MBox.clickedButton() == (QAbstractButton*)agreeBut) {

          QMessageBox MBox;
            MBox.setWindowTitle("开心");           //对话框的标题
            MBox.setText("算你识相");              //对话框显示的内容
            MBox.setWindowIcon(QIcon("chilun.ico"));      //设置对话框的小图标
            MBox.setIconPixmap(QPixmap("dui.png"));       //设置显示的大图标
            MBox.addButton("明白!", QMessageBox::AcceptRole);
            MBox.exec();
      }
      else
      {
          QMessageBox::critical(this,"愤怒","不同意无效！！！",QMessageBox::Yes);

      }
}

//显示进度条
void MainWindow::on_progressdlg_clicked()
{
    //1.创建进度条对话框窗口对象
    QProgressDialog * progress=new QProgressDialog("正在拷贝数据...","取消拷贝",0,100,this);
    //2.初始化并显示进度条窗口 对话框的标题
    progress->setWindowTitle("请稍后");
    //使用show情况下进度条可以被移动 也就表示它不是一个模态对话框
    /*Qt::NonModal 非模态
      Qt::WindowModal 模态+阻塞父窗口
      Qt::ApplicationModal 模态 阻塞应用程序中的所有窗口*/
    progress->setWindowModality(Qt::WindowModal);   //使用模态
    progress->show();   //使用了模态后这里写不写都一样
    //3.更新进度条
    static int value=0; //这里使用static是为了重复调用的时候value不被释放内存
    QTimer *timer=new QTimer;//构造QTimer对象
    connect(timer,&QTimer::timeout,this,[=]()//这个信号槽没什么好说的 它是用timer发射的信号
    {
        progress->setValue(value);
        value++;
        //当value > 最大值的时候
        if(value > progress->maximum())
        {
            timer->stop();//直到调用stop方法才会停止
            value=0;
            delete progress;
            delete timer;
        }
    });
    //用于点击取消后得以退出的信号槽
    connect(progress,&QProgressDialog::canceled,this,[=]()//此信号槽在点击取消按钮的时候触发
    {
     timer->stop();//退出
     value=0;
    });
    timer->start(50);//以msec毫秒的超时间隔启动或重新启动计时器。 这里也就是隔50毫秒

}
