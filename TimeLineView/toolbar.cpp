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

//��̬����һ����ǩ
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

//һ��ϰ��ʹ��resizeEvent�����ò��֣������ò��֣�
//��Ϊ���ֻ�����Ӧ��С����ͨ���ؼ�������ǹ̶���С��
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
		left += btnw;    
		(*iter)->move((i++)*btnw, 0);
	}
	//��ȡ��ǰ���ڵĴ�С
	int iwidth = width();
	m_ZoomSlider->setGeometry(width() - 150, (height() - 25)/2, 130, 25);
}

void ToolBar::dragEnterEvent(QDragEnterEvent * event)
{
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
	if (event->button() == Qt::LeftButton)
	{
		QPoint iPos = event->pos();
		int iType = -1;
		if (0 == iPos.y() / TOOLBAR_HEIGHT)
		{
			iType = iPos.x() / 35;
		}
		switch (iType)
		{
		case 0:
		{
			emit clicked(Type_Redo);
			break;
			return;
		}
		case 1:
		{
			emit clicked(Type_Undo);
			break;
		}
		case 2:
		{
			emit clicked(Type_Cut);
			break;
		}
		case 3:
		{
			emit clicked(Type_Delete);
			break;
		}
		case 4:
		{
			emit clicked(Type_Crop);
			break;
		}
		default:
			break;
		}
	}
}

//ִ�о�����ϷŲ���
void ToolBar::performDrag()
{
	QDrag* drag = new QDrag(this);
	drag->setPixmap(QPixmap(":/images/images/normal/TimelineView_TextEdit_h.png"));
	//����MIME����
	QMimeData* mimeData = new QMimeData;
	mimeData->setText("holyhigh");
	drag->setMimeData(mimeData);
	drag->exec();
}

//��ʼ�����е��ӿؼ�
void ToolBar::initControls()
{
	m_toolBar << createNewLabel(":/images/images/normal/TimelineView_Redo_n.png");
	m_toolBar << createNewLabel(":/images/images/normal/TimelineView_Undo_n.png");
	m_toolBar << createNewLabel(":/images/images/normal/TimelineView_Cut_n.png");
	m_toolBar << createNewLabel(":/images/images/normal/TimelineView_Delete_n.png");
	m_toolBar << createNewLabel(":/images/images/normal/TimelineView_Crop_n.png");
	m_ZoomSlider = new QSlider(this);
	m_ZoomSlider->setRange(0, 100);
	m_ZoomSlider->setOrientation(Qt::Horizontal);
}

void ToolBar::initConnections()
{
	connect(this, &ToolBar::clicked, this, [&](btnType type){
		emit signalButtonClicked(type);
	});
}
