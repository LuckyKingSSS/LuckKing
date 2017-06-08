#ifndef MYFIMORA_H
#define MYFIMORA_H

#include <QtWidgets/QWidget>



class MyFimoraPrivate;
class FilmoraToolbar;
class MyFimora : public QWidget
{
	Q_OBJECT
public:
	MyFimora(QWidget *parent = 0);
	~MyFimora();
	void initUI();
	void initConnections();
	void setTranslator(QTranslator* qTranslator);

protected:
	void resizeEvent(QResizeEvent *event)override;
	
private:
	MyFimoraPrivate* m_InnerData;
	FilmoraToolbar* m_Toolbar;
	QTranslator* m_Translator;
};

#endif // MYFIMORA_H
