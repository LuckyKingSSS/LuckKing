#include "stdafx.h"
#include <QHBoxLayout>
#include <QMessageBox>
#include <QMouseEvent>
#include <QApplication>
#include <QDrag>
#include <QMimeData>
#include "toolbar.h"

#define TOOLBAR_HEIGHT 40


ToolBar::ToolBar(QWidget *parent)
	: QWidget(parent)
{
	initControls();
	initConnections();
	
}

ToolBar::~ToolBar()
{

}

//动态生成一个标签
QLabel* ToolBar::createNewLabel(QString picturePath)
{
	QPixmap picMap = QPixmap();
	picMap.load(picturePath);
    picMap = picMap.scaled(24, 24, Qt::KeepAspectRatioByExpanding);
	if (picMap.save("1.png"))
		qDebug("aaa2jpg success");
	else
	{
		qDebug("failed");
	}
	QLabel *label = new QLabel(this);
	label->setPixmap(picMap);
	label->show();
	return label;
}



//一般习惯使用resizeEvent中设置布局，不适用布局，
//因为布局会自适应大小，而通常控件更多的是固定大小的
void ToolBar::resizeEvent(QResizeEvent * event)
{
	int left = 0;
	int top = 0;
	const int btnw = 35;
	QList<QLabel*>::iterator iter;
	int i = 0;
	for (iter = m_toolBar.begin(); iter != m_toolBar.end(); ++iter)
	{
		(*iter)->setMargin(0);
		//(*iter)->resize(width() / 2 / 5 * (i + 1), height());
		//(*iter)->setGeometry()
		left += btnw;    
		//设置控件的背景色
		/*	QPalette palette;
			palette.setColor(QPalette::Window, Qt::red);
			(*i)->setPalette(palette);*/

		//使用样式表修改背景
		//(*i)->setStyleSheet("color:red");//文本颜色
		//(*iter)->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
		//(*i)->setBackgroundRole(QPalette::Window);
		//(*iter)->setStyleSheet("background-color:red");//背景色
		//(*iter)->setGeometry((width() / 10)* i++, 0, width() / 10, height());
		(*iter)->move((i++)*btnw, 0);
	}
	//获取当前窗口的大小
	int iwidth = width();
	m_ZoomSlider->setGeometry(width() - 150, (height() - 25)/2, 130, 25);
	//m_ZoomSlider->move(iwidth - 20 - 130, 0);
}

void ToolBar::dragEnterEvent(QDragEnterEvent * event)
{
	//event->acceptProposedAction();
	ToolBar *label = qobject_cast<ToolBar*> (event->source());
	if (label && label != this)
	{
		event->setDropAction(Qt::CopyAction);
		event->accept();
	}
}

void ToolBar::dragMoveEvent(QDragMoveEvent *event)
{
	ToolBar *label = qobject_cast<ToolBar*> (event->source());
	if (label && label != this)
	{
		event->setDropAction(Qt::CopyAction);
		event->accept();
	}
}

void ToolBar::dropEvent(QDropEvent *event)
{
	ToolBar *label = qobject_cast<ToolBar*> (event->source());
	if (label && label != this)
	{
		event->setDropAction(Qt::CopyAction);
		event->accept();
	}
}


void ToolBar::mouseMoveEvent(QMouseEvent *event)
{
	if (event->buttons() & Qt::LeftButton)
	{
		int distance = (event->pos() - m_StartPos).manhattanLength();
		if (distance >= QApplication::startDragDistance())
		{
			performDrag();
		}
	}
}


void ToolBar::mousePressEvent(QMouseEvent * event)
{
	m_StartPos = event->pos();
}

//执行具体的拖放操作
void ToolBar::performDrag()
{
	QDrag* drag = new QDrag(this);
	drag->setPixmap(QPixmap(":/drag/Resources/normal/TimelineView_Crop_h.png"));
	//设置MIME数据
	QMimeData* mimeData = new QMimeData;
	mimeData->setText("holyhigh");
	drag->setMimeData(mimeData);
	drag->exec();
}

//鼠标双击事件响应函数
void ToolBar::mouseDoubleClickEvent(QMouseEvent * event)
{
	if (event->button() == Qt::LeftButton)
	{
		QPoint iPos = event->pos();
		int iType = -1;
		if (0 == iPos.y() / TOOLBAR_HEIGHT)
		{
			iType = iPos.x() / 40;
		}
		switch (iType)
		{
		case 0:
		{
			emit clicked(A_TYPE);
			break;
			return;
		}
		case 1:
		{
			emit clicked(B_TYPR);
			break;
		}
		case 2:
		{
			emit clicked(C_TYPE);
			break;
		}
		case 3:
		{
			emit clicked(D_TYPE);
			break;
		}
		case 4:
		{
			emit clicked(E_TYPE);
			break;
		}
		default:
			break;
		}
	}
}


//初始化所有的子控件
void ToolBar::initControls()
{
	m_toolBar << createNewLabel(":/drag/Resources/normal/TimelineView_Redo_h.png");
	m_toolBar << createNewLabel(":/drag/Resources/normal/TimelineView_Crop_h.png");
	m_toolBar << createNewLabel(":/drag/Resources/normal/TimelineView_Cut_h.png");
	m_toolBar << createNewLabel(":/drag/Resources/normal/TimelineView_Delete_h.png");
	m_toolBar << createNewLabel(":/drag/Resources/normal/TimelineView_Undo_h.png");


	//调整位置
	//this->setFixedSize(800, 500);
	m_ZoomSlider = new QSlider(this);
	m_ZoomSlider->setRange(0, 100);
	m_ZoomSlider->setOrientation(Qt::Horizontal);
	//m_ZoomSlider->setFixedSize(130, 25);

	//使用布局布置子控件
	//QHBoxLayout* layout = new QHBoxLayout;
	//QList<QLabel*>::iterator iter = m_toolBar.begin();
	//for (iter; iter != m_toolBar.end();++iter)
	//{
	//	(*iter)->setStyleSheet("background-color:red");//背景色
	//	layout->addWidget(*iter);
	//}
	//layout->addStretch();
	//layout->addWidget(m_ZoomSlider,1,Qt::AlignTop);
	//layout->addSpacing(20);
	//layout->setContentsMargins(20,0,0,0);
	//layout->setSpacing(10);
	//this->setLayout(layout);
}

void ToolBar::initConnections()
{
	connect(this, &ToolBar::clicked, this, [&](btnType type){
		QMessageBox* box = new QMessageBox(QMessageBox::Information, "title", QString::number(type));
		box->setModal(true);
		box->show();
	});
}
