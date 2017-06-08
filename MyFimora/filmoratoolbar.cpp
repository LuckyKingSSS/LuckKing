#include "stdafx.h"
#include <QMenu>
#include "filmoratoolbar.h"
#include "TopLevelWindowTitleBar.h"
#include "CommonWidgets.h"
#include "..\include\inc_CommonLib\externalapi.h"
#include "selectwindowskin.h"
#include "propertysettingwnd.h"


FilmoraToolbar::FilmoraToolbar(QWidget* parent) : TopLevelWindowTitleBar(parent)
{
	initToolBar();
	initConnections();
	setObjectName("FilmoraToolBarWnd");
	setAttribute(Qt::WA_StyledBackground);
	//todo: 为什么设置背景不起作用？
	//setStyleSheet("background-color:rgb(173,202,232)");
}

FilmoraToolbar::~FilmoraToolbar()
{

}

void FilmoraToolbar::loadStyleSheet(QString strFileName)
{
	QFile qss(strFileName);
	qss.open(QFile::ReadOnly);
	qApp->setStyleSheet(qss.readAll());
	qss.close();
}

void FilmoraToolbar::initConnections()
{
	
}

void FilmoraToolbar::refreshUI()
{
	m_FileMenu->setTitle(tr("FILE"));
	m_ExitAction->setText(tr("Exit"));
	m_EditMenu->setTitle(tr("Edit"));
	m_ExportMenu->setTitle(tr("Export"));

	m_RegisterMenu->setTitle(tr("Register"));
	m_HelpMenu->setTitle(tr("Help"));
}

void FilmoraToolbar::initActions()
{
	m_ExitAction = new QAction(tr("Exit"),this);
	m_ExitAction->setStatusTip(tr("this is exit action"));
	connect(m_ExitAction, &QAction::triggered, this, [&](){
		qDebug() << "Exit action called";
	});
}

void FilmoraToolbar::changeSkin()
{
	SelectWindowSkin* wnd = new SelectWindowSkin(nullptr);
	wnd->show();
}

void FilmoraToolbar::slotChangeLanguage()
{
	m_ProSettingWnd = new PropertySettingWnd(nullptr);
	m_ProSettingWnd->setTranslator(m_Translator);
	m_ProSettingWnd->show();
	connect(m_ProSettingWnd, &PropertySettingWnd::signalChangeLanguage, [&, this](){
		refreshUI();
		emit signalChangeLanguage(); });
}

void FilmoraToolbar::resizeEvent(QResizeEvent * event)
{
	const int iSpace = 2;
	const int iBtnWidth = 20;
	const int iBtnHeight = 20;
	int iLeft = iSpace;
	int iTop = 0;
	const int iButtonSize = 3;
	const int iButtonWidth = iButtonSize * (iBtnWidth + iSpace) + 5;

	m_icon->setGeometry(iSpace, iTop, iBtnWidth, iBtnHeight);
	iLeft = m_icon->geometry().right() + iSpace;
	const int iMenuBarWidth = 320;
	m_menuBar->setGeometry(iLeft, iTop, iMenuBarWidth* gGetDevicePixelRatio(), height());
	iLeft = m_menuBar->geometry().right() + iSpace;
	//设置换肤工具栏的位置
	m_ChangeSkin->setGeometry(width() - 140, iTop, 50, height());
	//m_icon->raise();

	m_PropertySetting->setGeometry(width() - 195, iTop, 50, height());
	//需要调用父类的resizeEvent
	TopLevelWindowTitleBar::resizeEvent(event);
}

void FilmoraToolbar::initToolBar()
{
	setObjectName("NLEPreviewTitleBar");
	setAttribute(Qt::WA_StyledBackground);
	setAttribute(Qt::WA_TransparentForMouseEvents);
	initActions();

	m_icon = new BaseButton(0,"NLEPreviewTitleBar_TitleIcon",this);
	m_menuBar = new QMenuBar(this);
	m_menuBar->setObjectName("NLEPreviewTitleBar_MenuBar");
	m_menuBar->resize(500, 30);
	//file Menu
	m_FileMenu = m_menuBar->addMenu(tr("FILE"));
    m_FileMenu->addAction(m_ExitAction);

	//edit menu
	m_EditMenu = m_menuBar->addMenu(tr("Edit"));
	m_EditMenu->addAction(tr("copy"));
	m_EditMenu->addAction(tr("paste"));
	m_EditMenu->addAction(tr("cut"));
	//export menu
	m_ExportMenu = m_menuBar->addMenu(tr("Export"));
	m_ExportMenu->addAction(tr("1"));
	m_ExportMenu->addAction(tr("2"));
	m_ExportMenu->addAction(tr("3"));

	m_RegisterMenu = m_menuBar->addMenu(tr("Register"));
	m_RegisterMenu->addAction(tr("1"));
	m_RegisterMenu->addAction(tr("2"));
	m_RegisterMenu->addAction(tr("3"));

	m_HelpMenu = m_menuBar->addMenu(tr("Help"));
	m_HelpMenu->addAction(tr("1"));
	m_HelpMenu->addAction(tr("2"));
	m_HelpMenu->addAction(tr("3"));

	//添加工具栏
	m_ChangeSkin = new QToolBar(this);
	m_ChangeSkin->setObjectName(tr("MYFIMORA_SKIN"));
	m_ChangeSkin->resize(50, 30);
	QAction* changeSkin = new QAction(tr("skin"),this);
	changeSkin->setToolTip(tr("click to change window skin"));
	QIcon* icon = new QIcon(":/MyFimora/Resources/time.jpg");
	changeSkin->setIcon(*icon);
	m_ChangeSkin->addAction(changeSkin);
	connect(changeSkin, SIGNAL(triggered()), this, SLOT(changeSkin()));

	m_PropertySetting = new QToolBar(this);
	m_PropertySetting->setObjectName(tr("propertySetting"));
	m_PropertySetting->resize(50, 30);
	QAction* propertySetting = new QAction(tr("Setting"), this);
	propertySetting->setToolTip(tr("click to set property"));
	icon = new QIcon(":/MyFimora/Resources/skin.png");
	propertySetting->setIcon(*icon);
	m_PropertySetting->addAction(propertySetting);
	connect(propertySetting, &QAction::triggered, this, &FilmoraToolbar::slotChangeLanguage);
	setStyleSheet("QWidget#NLEPreviewTitleBar{ background-color: rgb(240,240,240);}"
	"QMenuBar#NLEPreviewTitleBar_MenuBar{background-color:rgb(240,240,240);}"
	"QMenuBar#NLEPreviewTitleBar_MenuBar::item{background: transparent;}"
	"BaseButton#NLEPreviewTitleBar_TitleIcon {border-image:url(:/MyFimora/Resources/TitleBar_TitleIcon.png);background-position: center; background-repeat:no-repeat;}"
	);

	/*setStyleSheet("QWidget#NLEPreviewTitleBar{ background-color: rgb(250,250,250);}"
		"QMenuBar#NLEPreviewTitleBar_MenuBar{background-color:white;}"
		"QMenuBar#NLEPreviewTitleBar_MenuBar::item{background: transparent;}"
		"BaseButton#NLEPreviewTitleBar_TitleIcon {background-image:url(:/MyFimora/Resources/TitleBar_TitleIcon.png);background-position: center; background-repeat:no-repeat;}"
		);*/
	//setStyleSheet("BaseButton#NLEPreviewTitleBar_TitleIcon {background-image:url(:/MyFimora/C:/Users/Public/Pictures/Sample Pictures/Penguins.jpg);background-position: center; background-repeat:no-repeat;}");
}
