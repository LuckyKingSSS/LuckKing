#include "stdafx.h"
#include "propertysettingwnd.h"
#include "settingtitle.h"
#include "externalapi.h"
#include "inc_MediaPlayerView\meidaplayerview.h"
#include "propertysettingctl.h"
#include "comboboxitem.h"
#include "comboboxdelegate.h"

#define  LHT_SYNCCLIENT_EN_FILE "translate_En_CN.qm"
#define  LHT_SYNCCLIENT_ZH_FILE "translate_Zh_CN.qm"
PropertySettingWnd::PropertySettingWnd(QWidget *parent)
	: QWidget(parent)
{
	initUI();
	initData();
	initConnections();
	//固定窗口大小
	resize(687, 672);
	setObjectName("PropertySettingWnd");
	//注意需要使用公共控件的样式
	//如何在对象中使用setStyleSheet 设置样式，则以该样式为准
	//setStyleSheet("background-color: rgb(113,200,209)");
	QString strStyle = gGetCommonLibStyles() + getPropertySettingStyles();
	setStyleSheet(strStyle);
}

PropertySettingWnd::~PropertySettingWnd()
{

}

void PropertySettingWnd::initUI()
{
	m_Title = new SettingTitle(this);
	m_Title->setGeometry(0, 0, width(), 35);

	m_TmpFolder = new QLabel(this);
	m_TmpFolder->setObjectName("tmpFolderLabel");
	m_TmpFolder->setText(tr("YouTube temporary folder"));

	m_TmpFolderEdit = new QLineEdit(this);
	m_TmpFolderEdit->setObjectName("tmpFolderEdit");

	m_FindTmpFolderBtn = new QPushButton(this);
	m_FindTmpFolderBtn->setText(tr("FindTargrt"));
	m_FindTmpFolderBtn->setObjectName("tmpFolderBtn");

	m_CaptureFileFolder = new QLabel(this);
	m_CaptureFileFolder->setText(tr("Cpatured files folder"));
	m_CaptureFileFolder->setObjectName("captureFileFolderLabel");

	m_CaptureFileEdit = new QLineEdit(this);
	m_CaptureFileEdit->setObjectName("CaptureFileEdit");

	m_FindCaptureFolderBtn = new QPushButton(this);
	m_FindCaptureFolderBtn->setText(tr("FindTargrt"));
	m_FindCaptureFolderBtn->setObjectName("FindCaptureFolderBtn");

	m_Language = new QLabel(this);
	m_Language->setText(tr("Language"));
	m_Language->setObjectName("LanguageLabel");

	m_TwoLevelLanguageLabel = new QLabel(this);
	m_TwoLevelLanguageLabel->setText(tr("Language"));
	m_TwoLevelLanguageLabel->setObjectName("TwoLevelLanguageLabel");

	m_LanguageCombobox = new QComboBox(this);
	m_LanguageCombobox->setObjectName("LanguageCombobox");

	m_UpdateSettinglabel = new QLabel(this);
	m_UpdateSettinglabel->setText(tr("Auto Update"));
	m_UpdateSettinglabel->setObjectName("UpdateSettinglabel");

	m_SecondLevelUpdateLabel = new QLabel(this);
	m_SecondLevelUpdateLabel->setText("Check for upgrades automatically:");
	m_SecondLevelUpdateLabel->setObjectName("SecondLevelUpdateLabel");

	m_UpadatSettingCombobox = new QComboBox(this);
	m_UpadatSettingCombobox->setObjectName("UpadatSettingCombobox");

	m_Gpu = new QLabel(this);
	m_Gpu->setText(tr("GPU"));
	m_Gpu->setObjectName("GpuLabel");

	m_GpuTips = new QLabel(this);
	m_GpuTips->setText(tr("Enable GPU Acceleration"));
	m_GpuTips->setObjectName("GpuTipsLabel");

	m_GpuCheckBox = new QCheckBox(this);
	m_GpuCheckBox->setObjectName("GpuCheckBox");

	m_GpuPicture = new QLabel(this);
	m_GpuCheckBox->setObjectName("GpuPicLabel");

	m_Link = new QLabel(this);
	m_Link->setText(tr("Learn more..."));
	m_Link->setObjectName("LinkLabel");

	m_MessageCenter = new QLabel(this);
	m_MessageCenter->setText(tr("Message Center"));
	m_MessageCenter->setObjectName("MessageCenterLabel");

	m_MessageCenterTips = new QLabel(this);
	m_MessageCenterTips->setText(tr("Don't show MessageBox automaticaly"));
	m_MessageCenterTips->setObjectName("MessageCenterTipsLabel");

	m_MessageCenterCheckbox = new QCheckBox(this);
	m_MessageCenterCheckbox->setObjectName("MessageCenterCheckbox");

	m_Reset = new QLabel(this);
	m_Reset->setText(tr("Reset"));
	m_Reset->setObjectName("ResetLabel");

	m_ResetTips = new QLabel(this);
	m_ResetTips->setText(tr("Show all the notifacation messagees"));
	m_ResetTips->setObjectName("ResetTipsLabel");

	m_ResetBtn = new QPushButton(this);
	m_ResetBtn->setText(tr("Reset"));
	m_ResetBtn->setObjectName("ResetButton");

	m_DefaultBtn = new QPushButton(this);
	m_DefaultBtn->setText(tr("Default"));
	m_DefaultBtn->setObjectName("DefaultBtn");

	m_OkBtn = new QPushButton(this);
	m_OkBtn->setText(tr("OK"));
	m_OkBtn->setObjectName("OkBtn");

	m_CancleBtn = new QPushButton(this);
	m_CancleBtn->setText(tr("Cancle"));
	m_CancleBtn->setObjectName("CancleBtn");
	//定义contorl
	m_PropertySettingCtl = new PropertySettingCtl(nullptr);
}

void PropertySettingWnd::initConnections()
{
	connect(m_LanguageCombobox, &QComboBox::currentTextChanged, this, &PropertySettingWnd::slotTranslate);
}

void PropertySettingWnd::initData()
{
	m_LanguageListWidget = new QListView(this);
	//m_LanguageCombobox->setModel(m_LanguageListWidget->model());
	m_LanguageCombobox->setView(m_LanguageListWidget);
	//m_LanguageCombobox->setEditable(true);
	//m_LanguageCombobox->setItemDelegate(new ComboBoxDelegate(nullptr));
	QList<QString>* allListItems;
	allListItems = m_PropertySettingCtl->getLanguageList();
	m_LanguageCombobox->addItems(*allListItems);
	//for (int i = 0; i < allListItems->length(); ++i)
	//{
	//	ComboboxItem* item = new ComboboxItem(this);
	//	//设置当前项对应的序号
	//	item->setCurrentIndex(i);
	//	item->setLabelContent(allListItems->at(i));
	//	QListWidgetItem* widgetItem = new QListWidgetItem(m_LanguageListWidget);
	//	connect(item, &ComboboxItem::singalChooseAccount, this, &PropertySettingWnd::slotOnChooseAccount);
	//	//如果是语言切换了则需要做翻译操作
	//	connect(item, &ComboboxItem::signalCurrentIndexChanged, this, &PropertySettingWnd::slotChangeLanguage);
	//	m_LanguageListWidget->setItemWidget(widgetItem, item);
	//}
}

QPoint PropertySettingWnd::getTextWidthAndHeight(QString strText)
{
	QPoint pos(0, 0);
	QFont font("aaa", 12);//设置所使用的字体类型和字体大小
	QFontMetrics metric(font);
	pos.setX(metric.width(strText));
	pos.setY(metric.height());
	return pos;
}

QPoint PropertySettingWnd::getTextWidthAndHeight(QFont& font, QString strText)
{
	QPoint pos(0, 0);
	QFont Curfont(font);//设置所使用的字体类型和字体大小
	QFontMetrics metric(Curfont);
	pos.setX(metric.width(strText));
	pos.setY(metric.height());
	return pos;
}

QString PropertySettingWnd::getPropertySettingStyles()
{
	QFile qss(":/css/Resources/css/property.css");
	qss.open(QFile::ReadOnly|QFile::Text);
	QString strText = qss.readAll();
	qss.close();
	return strText;
}

QString PropertySettingWnd::getLanguageByIndex(int iIndex)
{
	QString strLanguage = "en";
	switch (iIndex)
	{
	case 0:
	{
		strLanguage = "en";
		break;
	}
	case 1:
	{
		strLanguage = "zh";
		break;
	}
	default:
		break;
	}
	return strLanguage;
}

void PropertySettingWnd::translateUI()
{
	m_TmpFolder->setText(tr("YouTube temporary folder"));
	m_FindTmpFolderBtn->setText(tr("FindTargrt"));
	m_CaptureFileFolder->setText(tr("Cpatured files folder"));
	m_CaptureFileEdit->setObjectName("CaptureFileEdit");
	m_FindCaptureFolderBtn->setText(tr("FindTargrt"));
	m_Language->setText(tr("Language"));
	m_TwoLevelLanguageLabel->setText(tr("Language"));
	m_UpdateSettinglabel->setText(tr("Auto Update"));
	m_SecondLevelUpdateLabel->setText(tr("Check for upgrades automatically:"));
	m_Gpu->setText(tr("GPU"));
	m_GpuTips->setText(tr("Enable GPU Acceleration"));
	m_Link->setText(tr("Learn more..."));
	m_MessageCenter->setText(tr("Message Center"));
	m_MessageCenterTips->setText(tr("Don't show MessageBox automaticaly"));
	m_Reset->setText(tr("Reset"));
	m_ResetTips->setText(tr("Show all the notifacation messagees"));
	m_ResetBtn->setText(tr("Reset"));
	m_DefaultBtn->setText(tr("Default"));
	m_OkBtn->setText(tr("OK"));
	m_CancleBtn->setText(tr("Cancle"));
    //设置QComboBox 的语言
	for (int i = 0; i < m_LanguageCombobox->count(); ++i)
	{
		//m_LanguageCombobox->model()->itemData();
		switch (i)
		{
		case 0:
		{
			//m_LanguageListWidget->item(i)->setText(tr("English"));
			m_LanguageCombobox->setItemText(i, tr("English"));
			break;
		}
		case 1:
		{
			//m_LanguageListWidget->item(i)->setText(tr("Chinese"));
			m_LanguageCombobox->setItemText(i, tr("Chinese"));
			break;
		}
		case 2:
		{
			//m_LanguageListWidget->item(i)->setText(tr("Franch"));
			m_LanguageCombobox->setItemText(i, tr("Franch"));
			break;
		}
		default:
			break;
		}
	}
}

void PropertySettingWnd::slotOnChooseAccount(const QString& strText)
{
	//将当前选中的文字设置到QComboBox中
	m_LanguageCombobox->setEditText(strText);
	m_LanguageCombobox->hidePopup();
}

void PropertySettingWnd::slotChangeLanguage(int iIndex)
{
	QString strLanguage = getLanguageByIndex(iIndex);
	if (strLanguage.isEmpty())
	{
		return;
	}
	QString strLanguageFile;
	if (strLanguage.compare("en") == 0)
	{
		strLanguageFile = qApp->applicationDirPath() + QString("/i18n/%1").arg(LHT_SYNCCLIENT_EN_FILE);
	}
	else if (strLanguage.compare("zh") == 0)
	{
		strLanguageFile = qApp->applicationDirPath() + QString("/i18n/%1").arg(LHT_SYNCCLIENT_ZH_FILE);
	}
	if (QFile(strLanguageFile).exists())
	{
		m_translator->load(strLanguageFile);
		translateUI();
		emit signalChangeLanguage();
	}
	else
	{
		qDebug() << "[houqd] authclient language file does not exists ...";
	}
}

void PropertySettingWnd::slotTranslate(QString strLanguage)
{
	QString strLanguageFile = strLanguage;
	if (strLanguage.compare(tr("English")) == 0)
	{
		strLanguageFile = qApp->applicationDirPath() + QString("/i18n/%1").arg(LHT_SYNCCLIENT_EN_FILE);
	}
	else if (strLanguage.compare(tr("Chinese")) == 0)
	{
		strLanguageFile = qApp->applicationDirPath() + QString("/i18n/%1").arg(LHT_SYNCCLIENT_ZH_FILE);
	}
	if (QFile(strLanguageFile).exists())
	{
		m_translator->load(strLanguageFile);
		translateUI();
		emit signalChangeLanguage();
	}
	else
	{
		qDebug() << "[houqd] authclient language file does not exists ...";
	}
}

void PropertySettingWnd::resizeEvent(QResizeEvent *event)
{
	m_Title->setGeometry(0, 0, width(), 34);
	QFont fontQFont("Calibri", 12);
	QFontMetrics fontMetric(fontQFont);
	int iWidth = fontMetric.width(tr("YouTube temporary folder"));
	int iHeight = fontMetric.height();
	m_TmpFolder->setGeometry(20, 50, iWidth, iHeight);

	m_TmpFolderEdit->setGeometry(30, 70, 520, 22);
	m_FindTmpFolderBtn->setGeometry(width() - 130, 65, 115, 30);

	iWidth = getTextWidthAndHeight(QFont("Calibri", 12), tr("Captured files folder")).x();
	iHeight = getTextWidthAndHeight(QFont("Calibri", 12), tr("Captured files folder")).y();
	//todo: 为什么通过计算结果不正确？
	m_CaptureFileFolder->setGeometry(20, 115, 165, iHeight);

	m_CaptureFileEdit->setGeometry(30, 138, 520, 22);
	m_FindCaptureFolderBtn->setGeometry(width() - 130, 132, 115, 30);

	iWidth = getTextWidthAndHeight(QFont("Calibri", 10.5), tr("Language")).x();
	iHeight = getTextWidthAndHeight(QFont("Calibri", 10.5), tr("Language")).y();
	m_Language->setGeometry(30, 185, iWidth, iHeight);

	iWidth = getTextWidthAndHeight(QFont("Calibri", 12), tr("Language")).x();
	iHeight = getTextWidthAndHeight(QFont("Calibri", 12), tr("Language")).y();
	m_TwoLevelLanguageLabel->setGeometry(35, 210, iWidth, iHeight);
	m_LanguageCombobox->setGeometry(360, 205, 202, 22);

	iWidth = getTextWidthAndHeight(QFont("Calibri", 12), tr("Auto Update")).x();
	iHeight = getTextWidthAndHeight(QFont("Calibri", 12), tr("Auto Update")).y();
	m_UpdateSettinglabel->setGeometry(20, 255, iWidth, iHeight);
	iWidth = getTextWidthAndHeight(QFont("Calibri", 12), tr("Check for upgrades automatically:")).x();
	iHeight = getTextWidthAndHeight(QFont("Calibri", 12), tr("Check for upgrades automatically:")).y();
	m_SecondLevelUpdateLabel->setGeometry(35, 280, iWidth, iHeight);
	m_UpadatSettingCombobox->setGeometry(360, 275, 200, 22);

	iWidth = getTextWidthAndHeight(QFont("Calibri", 12), tr("Gpu")).x();
	iHeight = getTextWidthAndHeight(QFont("Calibri", 12), tr("Gpu")).y();
	m_Gpu->setGeometry(20, 325, iWidth, iHeight);
	iWidth = getTextWidthAndHeight(QFont("Calibri", 12), tr("Enable Gpu Acceleration")).x();
	iHeight = getTextWidthAndHeight(QFont("Calibri", 12), tr("Enable Gpu Acceleration")).y();
	m_GpuTips->setGeometry(55, 350, iWidth, iHeight);
	m_GpuCheckBox->setGeometry(35, 347, 17, 17);
	iWidth = getTextWidthAndHeight(QFont("Calibri", 12), tr("learn more...")).x();
	iHeight = getTextWidthAndHeight(QFont("Calibri", 12), tr("Learn more...")).y();
	m_Link->setGeometry(300, 415, iWidth, iHeight);

	iWidth = getTextWidthAndHeight(QFont("Calibri", 12), tr("Message Center")).x();
	iHeight = getTextWidthAndHeight(QFont("Calibri", 12), tr("Message Center")).y();
	m_MessageCenter->setGeometry(20, 475, iWidth, iHeight);
	iWidth = getTextWidthAndHeight(QFont("Calibri", 12), tr("Don't show Messagees automaticaly")).x();
	iHeight = getTextWidthAndHeight(QFont("Calibri", 12), tr("Don't show Messagees automaticaly")).y();
	m_MessageCenterTips->setGeometry(55, 500, iWidth, iHeight);
	m_MessageCenterCheckbox->setGeometry(35, 500, 17, 17);

	iWidth = getTextWidthAndHeight(QFont("Calibri", 12), tr("Reset")).x();
	iHeight = getTextWidthAndHeight(QFont("Calibri", 12), tr("Reset")).y();
	m_Reset->setGeometry(20, 550, iWidth, iHeight);

	iWidth = getTextWidthAndHeight(QFont("Calibri", 12), tr("Show me all the notifacation messages")).x();
	iHeight = getTextWidthAndHeight(QFont("Calibri", 12), tr("Show me all the notifacation messages")).y();
	m_ResetTips->setGeometry(35, 573, iWidth, iHeight);
	m_ResetBtn->setGeometry(556, 560, 110, 30);
	//m_ResetBtn->setStyleSheet("background-color: black");

	m_DefaultBtn->setGeometry(15, 638, 110, 25);
	m_OkBtn->setGeometry(515, 635, 70, 23);
	m_CancleBtn->setGeometry(600, 635, 70, 23);
}

void PropertySettingWnd::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	//设置临时画布
	QPixmap*  CanvasTmp = new QPixmap(QSize(205, 55));
	CanvasTmp->fill(Qt::red);
	painter.begin(CanvasTmp);
	QPixmap intelGpuPic;
	intelGpuPic.load(":/MyFimora/Resources/1.png");
	QPixmap amdGpuPic;
	amdGpuPic.load(":/MyFimora/Resources/2.png");
	QPixmap nvidiaPic;
	nvidiaPic.load(":/MyFimora/Resources/3.png");
	painter.drawPixmap(35, 375, intelGpuPic);
	painter.drawPixmap(110, 375, amdGpuPic);
	painter.drawPixmap(185, 375, nvidiaPic);
	painter.end();
	painter.drawPixmap(35, 375, *CanvasTmp);
}
