#ifndef FILMORATOOLBAR_H
#define FILMORATOOLBAR_H

#include "TopLevelWindowTitleBar.h"
class TopLevelWindowTitleBar;
class QMenuBar;
class PropertySettingWnd;
class FilmoraToolbar : public TopLevelWindowTitleBar
{
	Q_OBJECT

public:
	FilmoraToolbar(QWidget *parent);
	~FilmoraToolbar();
	void loadStyleSheet(QString strFileName);
	void setTranslator(QTranslator *translator){ m_Translator = translator; };
	void initConnections();
	void refreshUI();
	void initActions();

Q_SIGNALS:
	void signalChangeLanguage();
public Q_SLOTS:
	void changeSkin();
	void slotChangeLanguage();

protected:
	void resizeEvent(QResizeEvent * event);
	void initToolBar();
private:
	BaseButton * m_icon; //程序的左上角图标
	QMenuBar *m_menuBar; //管理QMenue
	QMenu *m_FileMenu;   //文件菜单
	QMenu * m_EditMenu;  //编辑菜单
	QMenu *m_ExportMenu; //导出菜单
	QMenu *m_RegisterMenu;//注册菜单
	QMenu *m_HelpMenu;     //帮助菜单
	QToolBar *m_ChangeSkin; //换肤
	QToolBar *m_PropertySetting;//属性设置页面
	QTranslator *m_Translator;
	PropertySettingWnd* m_ProSettingWnd;
	QAction* m_ExitAction; //退出
};
#endif // FILMORATOOLBAR_H
