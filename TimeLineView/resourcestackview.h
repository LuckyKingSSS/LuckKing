#ifndef RESOURCESTACKVIEW_H
#define RESOURCESTACKVIEW_H
#include <Qwidget>
#include <QButtonGroup>


#define DEFAULT_PLAY_FPS 25.00   //播放器默认使用的播放帧率是 25.00fps
static const QString TypeFilter[][2] = {
		{ "Video files", "*.wmv *.mov *.mp4 *.avi *.flv *.rmvb *.mkv *3g2 *3gp *dv *flv *m4v *mpg *ts *webm *tp *trp *m2t *m2ts" },
		{ "Audio files", "*.mp3 *.mp2 *.wav *.wma" },
		{ "Image files", "*.bmp *.jpg *.png *.jpeg" },
		{ "All files", "(*.*)" }
};

class DragClip;
class TimeRuler;
class ResourceStackView : public QWidget
{
	Q_OBJECT
	enum headType{TYPE_MOVIE,TYPE_EFFECT,TYPE_MUSIC};
public:
	ResourceStackView(QWidget *parent = nullptr);
	~ResourceStackView();
	int getDrapLipeTopPos(QPoint dragPos);
	void setRuler(TimeRuler* ruler);
	//获取当前被选中的所有rect
	void getAllSelectRect();
	void setTimeline(NLETimeline* timeline){ m_ComplexTimeline = timeline; };
	void doSplitAction();
	
Q_SIGNALS:
	//游标头移动信号
	void frameHanlerChange(QPointF newPos);
	//游标线移动信号
	void frameLineChange(QPointF newPos);
	//seek 操作
	void signalSeekToFrame(int iFrame);
	//在大的时间线上添加小时间线的信号
	void signalAddClipTimeline(NLETimeline* newTimeline,QPointF pos);
	void signalRemoveClipTimeline(NLETimeline* newTimeline);
	void sigalDurationChanged(int iNewValue);
	void signalSyncPlayerSlider(QPointF pos);
	void signalButtonClicked(int iType);
	
protected:
	void resizeEvent(QResizeEvent* event)override;
	void paintEvent(QPaintEvent* event);
	void drawMediaRect(QPainter &painter, QRect &recArea, QMap<int,DragClip*>::iterator iter);
	void dropEvent(QDropEvent* event)override;
	void dragEnterEvent(QDragEnterEvent *evnet);
	void dragMoveEvent(QDragMoveEvent * event);
	void mouseMoveEvent(QMouseEvent * event)override;
	void mousePressEvent(QMouseEvent *evnet)override;
	void mouseReleaseEvent(QMouseEvent * event)override;

	public Q_SLOTS:
	//改变游标头和游标线的槽函数
	void FramePosChange(QPointF point);
	//void signalManualSeekFrame(QPoint point);

private:
	void initData();
	void initConnections();
	void createHeadPixMap(headType type, int iIndex, QPainter& picPainter);
	bool canDrag(QPoint newPos);
	//获取当前点所在的stack的起始y坐标
	int  getYPosInStack(QPoint pos);
	FilmoraMediaType getMediaType(QString strFileName);
	headType getHeadType(QString strFileName);
	headType getHeadTypeByMediaType(FilmoraMediaType type);
	int getCurrentStackIndex(QPoint point, headType stacktype);//获取特定的点所在的stack 的序号（序号从1开始计数）
	void reSetStackList();
	bool isRecCollision(DragClip* m_currentDragClip);
	void changeStackNum(headType type);
	void unSelectAllClips();
	//判断当前的鼠标位置是否靠近在选中的rect的左右两侧
	bool isMousePosNearToRect(QPoint pos);
	//进行裁剪操作
	void doClipAction(DragClip* clip, QPoint clipPos, bool bIsTouchLeft, bool bIsTouchRight);
	//从当前的坐标获取对应视频的帧数
	int getFrameFromPos(QPointF pos);
	//判断trim 操作是否能够trim到pos位置
	bool canTrimToPos(DragClip* clip ,QPoint  pos);
		
private:
	int m_OffsetLen; //竖直线跟最左边窗口的距离
	int m_firstDistance;//视频文件轨道的高度
	int m_Distance;     //其他类型 比如音乐 文字等轨道的高度
	int m_initalHeight;
	int m_CurrentGridHeight;
	QMap<int, DragClip*> m_AllClipInfo;//用户拖拽的视频片段信息
	DragClip* m_currentDragClip;
	bool m_bIsleftMousePress;
	QPoint m_SpinLinePos;
	TimeRuler* m_Ruler;
	NLETimeline* m_NewTimeline;

	QVector<headType> m_StackList;//当前视图区域的轨道列表
	int m_iMovieStackNum;//视频轨道的数目
	int m_iEffectStackNum;//effect轨道的数目
	int m_iMusicStackNum;//音频轨道的数目
	QVector<DragClip*> m_AllSecletedClips;//所有被选中的clip的集合
	bool m_bIsTouchleftline; //鼠标是否接粗矩形区域的左边线
	bool m_bIsTouchRightline;//鼠标是否接触矩形区域的右边线
	bool m_bIsSplitting; //当前是否正在裁剪中
	QPoint m_PressPoint;//用户按下鼠标时的位置
	QRect m_PressRecLocate; //鼠标点击时当前rect所在的位置
	QUndoStack m_UndoStack; 
	NLETimeline* m_ComplexTimeline;
};
#endif // RESOURCESTACKVIEW_H
