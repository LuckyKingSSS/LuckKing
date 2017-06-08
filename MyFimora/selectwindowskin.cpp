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
	// todo : ��λ�ȡ�ض��ַ���ʹ�õı����ʽ��
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
		//ʹ��������Ҫʹ�� QStringLiteral
		m_LeftTips->setText(QStringLiteral("�տ���Ҳ����ʱ��û�п���Ƥ��Ŷ����@@@"));
	}
	else
	{
		m_LeftTips->setText(QStringLiteral("��") + QString::number(skinListItems->count(), 10)  + QStringLiteral("��Ƥ�����Ͽ������ðɣ�"));
	}
	m_LeftTips->show();
	m_RightTips = new QLabel(this);
	m_RightTips->setText(QStringLiteral("����Ƥ���������ڴ�"));
	m_RightTips->show();
}

void SelectWindowSkin::initConnections()
{
	connect(skinListItems, &SkinListWidget::itemClicked, this, [&](QListWidgetItem* item)
	{
		if (item != nullptr)
		{
			QString strFilePath = skinListItems->getResPath();
			strFilePath.append("\\"); //׷����//
			strFilePath += item->text();
			strFilePath.append(CSS_FILE);
			putOnNewSkin(strFilePath);
		}
	});
}

void SelectWindowSkin::putOnNewSkin(QString strQssFilePath)
{
	//�ı�����Ƥ��
	QFile qss(strQssFilePath);
	qss.open(QFile::ReadOnly);
	//ע��Ҫ�����Ϲ��ÿռ����ʽ
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
