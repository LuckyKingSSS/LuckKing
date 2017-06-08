#ifndef PROPERTYSETTINGWND_H
#define PROPERTYSETTINGWND_H

#include <QWidget>
class SettingTitle;
class PropertySettingCtl;
class PropertySettingWnd : public QWidget
{
	Q_OBJECT

public:
	PropertySettingWnd(QWidget *parent);
	~PropertySettingWnd();
	void initUI();
	void initConnections();
	void initData();
	//特定字体情况下的文字高度和宽度
	QPoint getTextWidthAndHeight(QFont& font ,QString strText);
	//默认情况下的文字高度和宽度
	QPoint getTextWidthAndHeight(QString strText);
	QString getPropertySettingStyles();
	QString getLanguageByIndex(int iIndex);
	void setTranslator(QTranslator* translator){ m_translator = translator; };
	void translateUI();

Q_SIGNALS:
	void signalChangeLanguage();

public Q_SLOTS:
void slotOnChooseAccount(const QString& strText);
void slotChangeLanguage(int iIndex);
void slotTranslate(QString strLanguage);

protected:
	void resizeEvent(QResizeEvent *event)override;
	void paintEvent(QPaintEvent* event)override;

private:
	SettingTitle* m_Title;
	QLabel* m_TmpFolder;
	QLineEdit* m_TmpFolderEdit;
	QPushButton* m_FindTmpFolderBtn;
	QLabel* m_CaptureFileFolder;
	QLineEdit* m_CaptureFileEdit;
	QPushButton* m_FindCaptureFolderBtn;
	QLabel* m_Language;
	QLabel* m_TwoLevelLanguageLabel;
	QComboBox* m_LanguageCombobox;
	QLabel* m_UpdateSettinglabel;
	QLabel* m_SecondLevelUpdateLabel;
	QComboBox* m_UpadatSettingCombobox;
	QLabel* m_Gpu;
	QCheckBox* m_GpuCheckBox;
	QLabel* m_GpuTips;
	QLabel* m_GpuPicture;
	QLabel* m_Link;

	QLabel* m_MessageCenter;
	QLabel* m_MessageCenterTips;
	QCheckBox* m_MessageCenterCheckbox;

	QLabel* m_Reset;
	QLabel* m_ResetTips;
	QPushButton* m_ResetBtn;
	QPushButton* m_DefaultBtn;
	QPushButton* m_OkBtn;
	QPushButton* m_CancleBtn;
	PropertySettingCtl* m_PropertySettingCtl;	
	QListView* m_LanguageListWidget; //
	QTranslator* m_translator;
};

#endif // PROPERTYSETTINGWND_H
