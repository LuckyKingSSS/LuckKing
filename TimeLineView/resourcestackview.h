#ifndef RESOURCESTACKVIEW_H
#define RESOURCESTACKVIEW_H
#include <Qwidget>
#include <QButtonGroup>


#define DEFAULT_PLAY_FPS 25.00   //������Ĭ��ʹ�õĲ���֡���� 25.00fps
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
	//��ȡ��ǰ��ѡ�е�����rect
	void getAllSelectRect();
	void setTimeline(NLETimeline* timeline){ m_ComplexTimeline = timeline; };
	void doSplitAction();
	
Q_SIGNALS:
	//�α�ͷ�ƶ��ź�
	void frameHanlerChange(QPointF newPos);
	//�α����ƶ��ź�
	void frameLineChange(QPointF newPos);
	//seek ����
	void signalSeekToFrame(int iFrame);
	//�ڴ��ʱ���������Сʱ���ߵ��ź�
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
	//�ı��α�ͷ���α��ߵĲۺ���
	void FramePosChange(QPointF point);
	//void signalManualSeekFrame(QPoint point);

private:
	void initData();
	void initConnections();
	void createHeadPixMap(headType type, int iIndex, QPainter& picPainter);
	bool canDrag(QPoint newPos);
	//��ȡ��ǰ�����ڵ�stack����ʼy����
	int  getYPosInStack(QPoint pos);
	FilmoraMediaType getMediaType(QString strFileName);
	headType getHeadType(QString strFileName);
	headType getHeadTypeByMediaType(FilmoraMediaType type);
	int getCurrentStackIndex(QPoint point, headType stacktype);//��ȡ�ض��ĵ����ڵ�stack ����ţ���Ŵ�1��ʼ������
	void reSetStackList();
	bool isRecCollision(DragClip* m_currentDragClip);
	void changeStackNum(headType type);
	void unSelectAllClips();
	//�жϵ�ǰ�����λ���Ƿ񿿽���ѡ�е�rect����������
	bool isMousePosNearToRect(QPoint pos);
	//���вü�����
	void doClipAction(DragClip* clip, QPoint clipPos, bool bIsTouchLeft, bool bIsTouchRight);
	//�ӵ�ǰ�������ȡ��Ӧ��Ƶ��֡��
	int getFrameFromPos(QPointF pos);
	//�ж�trim �����Ƿ��ܹ�trim��posλ��
	bool canTrimToPos(DragClip* clip ,QPoint  pos);
		
private:
	int m_OffsetLen; //��ֱ�߸�����ߴ��ڵľ���
	int m_firstDistance;//��Ƶ�ļ�����ĸ߶�
	int m_Distance;     //�������� �������� ���ֵȹ���ĸ߶�
	int m_initalHeight;
	int m_CurrentGridHeight;
	QMap<int, DragClip*> m_AllClipInfo;//�û���ק����ƵƬ����Ϣ
	DragClip* m_currentDragClip;
	bool m_bIsleftMousePress;
	QPoint m_SpinLinePos;
	TimeRuler* m_Ruler;
	NLETimeline* m_NewTimeline;

	QVector<headType> m_StackList;//��ǰ��ͼ����Ĺ���б�
	int m_iMovieStackNum;//��Ƶ�������Ŀ
	int m_iEffectStackNum;//effect�������Ŀ
	int m_iMusicStackNum;//��Ƶ�������Ŀ
	QVector<DragClip*> m_AllSecletedClips;//���б�ѡ�е�clip�ļ���
	bool m_bIsTouchleftline; //����Ƿ�Ӵ־�������������
	bool m_bIsTouchRightline;//����Ƿ�Ӵ�����������ұ���
	bool m_bIsSplitting; //��ǰ�Ƿ����ڲü���
	QPoint m_PressPoint;//�û��������ʱ��λ��
	QRect m_PressRecLocate; //�����ʱ��ǰrect���ڵ�λ��
	QUndoStack m_UndoStack; 
	NLETimeline* m_ComplexTimeline;
};
#endif // RESOURCESTACKVIEW_H
