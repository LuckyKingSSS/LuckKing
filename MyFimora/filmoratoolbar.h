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
	BaseButton * m_icon; //��������Ͻ�ͼ��
	QMenuBar *m_menuBar; //����QMenue
	QMenu *m_FileMenu;   //�ļ��˵�
	QMenu * m_EditMenu;  //�༭�˵�
	QMenu *m_ExportMenu; //�����˵�
	QMenu *m_RegisterMenu;//ע��˵�
	QMenu *m_HelpMenu;     //�����˵�
	QToolBar *m_ChangeSkin; //����
	QToolBar *m_PropertySetting;//��������ҳ��
	QTranslator *m_Translator;
	PropertySettingWnd* m_ProSettingWnd;
	QAction* m_ExitAction; //�˳�
};
#endif // FILMORATOOLBAR_H
