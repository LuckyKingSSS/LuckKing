#pragma once
/*
*Author:		zhy
*Date:			2016.09.30
*Description:	���㴰�ڱ�������Ĭ���Դ���С����󣬹رհ�ť��֧����ק��˫��ȫ������
				����ʱ���ݶ��㴰��ָ�룬֧�ֶ��㴰����ק��С��
				��չ���̳�TopLevelWindowTitleBar����չ��������������
				ע�⣺ʹ�ô˱��⣬���㴰����Ҫ�����ô�С���磺resize()/setFixedSize��
*/
#include "inc_CommonLib/commonlib_global.h"

#include <QtWidgets/QWidget>
#include <QtCore/QString>
#include <QtWidgets/QLabel>

class BaseButton;
class TopLevelWindowTitleBar_p;
class TopLevelWindowTitleBarResizeMoveControl;

class COMMONLIB_EXPORT TopLevelWindowTitleBar : public QWidget
{
	Q_OBJECT
public:
	enum Button{
		None = 0x1,
		Minimized = 0x2,
		Normal = 0x4,
		Maximized = 0x8,
		Close = 0x10,
	};
public:
	TopLevelWindowTitleBar(QWidget *parent);
	// ��ʼ�����������/��С����ť���״��������㴰����󻯲���Ϊtrue,��֮Ϊfalse
	void InitWindowMaximumButtonState(bool maximum);
	// ���ñ�����������������
	void SetTitleName(QString name);
	QString GetTitleName();
	void SetTitleNameBold(bool enable);
	void SetTitleNameSize(int size);
	void SetTitleNameAlign(Qt::Alignment flag);
	QLabel* GetTitleLabel();

	// ���㴰���Ƿ�����ק��С
	void SetResizeble(bool enable);
	// ���㴰����ק����Ļ���Ϸ��Ƿ�������
	void SetDragMaximum(bool enable);

	void SetTitleBarColor(QColor color);
	// ������ʾ�İ�ť
	void SetButtons(int button);
	
	// ���ð�ť�Ŀ�
	void SetButtonWidth(int width);

	// ������ק������ɫ
	void SetDashlineColor(QColor color);
	// ����رհ�ť�رմ���
	void SetAutoCloseWindow(bool enable);
	// ����ͼ��
	void SetTitleIcon(QPixmap pixmap);

	bool IsMaximized();
	void ShowMaximized();
	void ShowNormal();
	void ShowMinimized();
	void CloseWindow();

	// �ұ����Ӱ�ť
	void AddSuffixButton(QWidget *btn);
	void AddSuffixSpace(int space);

	// ʹ��ϵͳ�߿�,false:ʹ���Ի�߿�
	void SetSystemBorderVisible(bool visible);
	bool GetSystemBorderVisible();
	void SetSystemMenuEnabled(bool enabled);

	BaseButton* GetButton(int id);

	TopLevelWindowTitleBarResizeMoveControl* GetControl();
Q_SIGNALS:
	// ��ť�ź�
	void ButtonClick(Button id);

private:
	TopLevelWindowTitleBar_p *m_p;
};


/*
	��������������������ʹ��SetControlWidget����������Ͷ��㴰��ָ�룬
	�ɻ���ƶ����ڣ���ק���ڴ�С����
*/
class COMMONLIB_EXPORT TopLevelWindowTitleBarResizeMoveControl : public QObject
{
	Q_OBJECT
public:
	static TopLevelWindowTitleBarResizeMoveControl* CreateControl();

	// ����Ҫ���Ƶı������Ͷ��㴰��
	virtual void SetControlWidget(QWidget *titleBar, QWidget *toplevelWindow) = 0;
	// �Ƿ����ק��С
	virtual void SetResizeble(bool enable) = 0;
	// ��ק����Ļ���Ϸ��Ƿ��Զ�ȫ��
	virtual void SetDragMaximum(bool enable) = 0;
	// ������ק������ɫ
	virtual void SetDashlineColor(QColor color) = 0;
	virtual void SetBorderColor(QColor color) = 0;
	virtual void SetBorderWidth(int width) = 0;
	virtual void SetSystemBorderVisible(bool visible) = 0;
	virtual bool GetSystemBorderVisible() = 0;

	virtual bool IsMaximized() = 0;
	virtual void ShowMaximized() = 0;
	virtual void ShowNormal() = 0;
	virtual void ShowMinimized() = 0;
	virtual void CloseWindow() = 0;

};

