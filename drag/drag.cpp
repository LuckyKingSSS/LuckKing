#include "stdafx.h"
#include <QMimeData>
#include <QTextEdit>
#include <QDragEnterEvent>
#include <QTextStream>
#include "drag.h"
using namespace  std;

drag::drag(QWidget *parent)
	: QMainWindow(parent)
{
	setFocusPolicy(Qt::ClickFocus);
	textEdit = new QTextEdit;
	setCentralWidget(textEdit);
	textEdit->setAcceptDrops(false);
	setAcceptDrops(true);
	setWindowTitle(tr("Text Edit"));
}

drag::~drag()
{

}

//窗口拖拽事件
void drag::dragEnterEvent(QDragEnterEvent *event)
{
	if (event->mimeData()->hasFormat("text/uri-list"))
	{
		event->acceptProposedAction();
	}
}

void drag::dropEvent(QDropEvent* event)
{
	QList<QUrl> urls = event->mimeData()->urls();
	if (urls.isEmpty())
	{
		return;
	}
	QString fileName = urls.first().toLocalFile();
	if (fileName.isEmpty())
	{
		return;
	}
	if (readFile(fileName))
	{
		setWindowTitle(tr("%1 - %2").arg(fileName).arg(tr("Drag File")));
		//设置内容
		textEdit->setText(fileContent);
	}
}


//鼠标按下的消息
void drag::keyPressEvent(QKeyEvent *event)
{
	if ((event->modifiers() == Qt::ControlModifier) && (event->key() == Qt::Key_S))
	{
		//保存当前用户的输入
		fileContent = textEdit->toPlainText();
		//将文本写入对应的文件中
		writeFile(strFilePath);
	}
}

///键盘按钮释放的消息
void drag::keyReleaseEvent(QKeyEvent *event)
{

}

bool drag::readFile(const QString &filename)
{
	QFile f(filename);
	strFilePath = filename;
	if (!f.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		return false;
	}
	QTextStream txtInput(&f);
	fileContent;
	while (!txtInput.atEnd())
	{
		fileContent = txtInput.readLine();
	}
	f.close();
	return true;
}


bool drag::writeFile(const QString &filename)
{
	QFile f(filename);
	if (!f.open(QIODevice::WriteOnly | QIODevice::Text))
	{
		return false;
	}
	QTextStream txtInput(&f);
	txtInput << fileContent;
	return true;
}
