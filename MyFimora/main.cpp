#include "stdafx.h"
#include "myfimora.h"
#include <QtWidgets/QApplication>
#include "inc_CommonLib/CommonWidgets.h"
#include "settingtitle.h"
#include "propertysettingwnd.h"
#include "comboboxitem.h"


int main(int argc, char *argv[])
{
	//如何让程序显示中文?
	//raise 什么情况下需要使用
	//边修改边看样式            lua脚本
	//QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
	QApplication a(argc, argv);
	//MyFimora w;
	//w.show();
	//QWidget * wnd = new QWidget();

#if 1
	//程序启动的时候需要安装翻译器
	QTranslator*  qTranslator = new QTranslator;
	a.installTranslator(qTranslator); 
	MyFimora w;
	w.setTranslator(qTranslator);
	w.show();
#endif // 0


#if 0
    ComboboxItem* item = new ComboboxItem(nullptr);
	item->setLabelContent("12344");
	item->show();
#endif

	return a.exec();
}
