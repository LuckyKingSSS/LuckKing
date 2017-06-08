#include "stdafx.h"
#include <QTextCodec>  
#include "selectwindowskin.h"
#include "..\include\inc_CommonLib\externalapi.h"
#include "..\include\inc_MediaPlayerView\meidaplayerview.h"

SelectWindowSkin::SelectWindowSkin(QWidget *parent)
	: QWidget(parent)
{
	setObjectName("SelectWindowSkin");
	initUI();
	initConnections();
	resize(578, 420);
	setCodec();
	setStyleSheet("background-color: rgb(232,241,252)");
}

SelectWindowSkin::~SelectWindowSkin()
{

}

void SelectWindowSkin::initUI()
{
	// todo : 如何获取特定字符所使用的编码格式？
	QTextCodec* codec = QTextCodec::codecForName("ascii");
	m_TitleBar = new SkinTitleBar(this);
	m_TitleBar->show();
	m_LeftTips = new QLabel(this);
	skinListItems = new SkinListWidget(this);
	skinListItems->setResPath(tr("E:\\vs_programeFile\\cplusplus\\qt_study\\dragAndDrop\\drag\\MyFimora\\Resources\\css"));
	skinListItems->loadSkinResource(skinListItems->getResPath());
	skinListItems->show();
	int iCount = skinListItems->count();
	if (skinListItems->count() == 0)
	{
		//使用中文需要使用 QStringLiteral
		m_LeftTips->setText(QStringLiteral("空空如也，暂时还没有可用皮肤哦，亲@@@"));
	}
	else
	{
		m_LeftTips->setText(QStringLiteral("共") + QString::number(skinListItems->count(), 10)  + QStringLiteral("款皮肤，赶快来试用吧！"));
	}
	m_LeftTips->show();
	m_RightTips = new QLabel(this);
	m_RightTips->setText(QStringLiteral("更多皮肤，敬请期待"));
	m_RightTips->show();
}

void SelectWindowSkin::initConnections()
{
	connect(skinListItems, &SkinListWidget::itemClicked, this, [&](QListWidgetItem* item)
	{
		if (item != nullptr)
		{
			QString strFilePath = skinListItems->getResPath();
			strFilePath.append("\\"); //追加上//
			strFilePath += item->text();
			strFilePath.append(CSS_FILE);
			putOnNewSkin(strFilePath);
		}
	});
}

void SelectWindowSkin::putOnNewSkin(QString strQssFilePath)
{
	//改变界面的皮肤
	QFile qss(strQssFilePath);
	qss.open(QFile::ReadOnly);
	//注意要设置上公用空间的样式
	qApp->setStyleSheet(qss.readAll() + gGetCommonLibStyles() + gGetMediaPlayerStyles());
	qss.close();
}

void SelectWindowSkin::resizeEvent(QResizeEvent *event)
{
	m_TitleBar->setGeometry(0, 0, width(), 30);
	m_LeftTips->setGeometry(30, 35, 150, 20);
	m_RightTips->setGeometry(width() - 130, 35, 130, 20);
	skinListItems->setGeometry(0, 55, width(), height() - 75);
}

void SelectWindowSkin::setCodec()
{
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
}
