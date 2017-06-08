#ifndef DRAG_H
#define DRAG_H

#include <QMainWindow>

class QDragEnterEvent;
class QDropEvent;
class QString;
class QTextEdit;
class drag : public QMainWindow
{
	Q_OBJECT

public:
	drag(QWidget *parent = 0);
	~drag();

protected:
	void dragEnterEvent(QDragEnterEvent *event);
	void dropEvent(QDropEvent* event);
	//响应键盘的事件
	void keyPressEvent(QKeyEvent *event);
	void keyReleaseEvent(QKeyEvent *event);

private:
	bool readFile(const QString &filename);
	bool writeFile(const QString &filename);
	QTextEdit *textEdit;
	QString  fileContent;
	QString  strFilePath;
};

#endif // DRAG_H
