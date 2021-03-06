#ifndef QFORMPANEL_H
#define QFORMPANEL_H

#include <QScrollArea>
#include <QMap>
#include <QUndoStack>
#include <QFrame>
#include <QRubberBand>

#define FRAME_SIZE 10

class QAbstractProperty;
class QAbstractHost;
class QAbstractWidgetHost;
class QFormContainer;
class FormResizer;
class SizeHandleRect;
class Selection;

class QFormPanel : public QWidget
{
    Q_OBJECT
public:
    explicit QFormPanel(QAbstractWidgetHost * host,QWidget *parent = 0);
    ~QFormPanel();

    void    select(QAbstractWidgetHost* host);

    QUndoStack *getUndoStack();

    void    setOwner(QWidget* owner);
    QWidget* getOwner();

    bool    enableAction();
public:
    void    sameLeft();
    void    sameTop();
    void    sameRight();
    void    sameBottom();
    void    sameVCenter();
    void    sameHCenter();
    void    sameWidth();
    void    sameHeight();
    void    sameGeometry();

protected:
    void    setHandelVisible(bool visible);

    void    defaultPropertyEdit(QAbstractHost * host);
    void    commonPropertyEdit(QAbstractHost * host,QAbstractProperty * pro);
protected:
    void    installHostEventFilter(QAbstractWidgetHost * host);
    void    removeHostEventFilter(QAbstractWidgetHost * host);

    bool    hostMousePress(QAbstractWidgetHost *host,QMouseEvent *e);
    bool    hostMouseRelease(QAbstractWidgetHost *host,QMouseEvent *e);
    bool    hostMouseMove(QAbstractWidgetHost *host,QMouseEvent *e);
    bool    hostDBMouseClick(QAbstractWidgetHost * host,QMouseEvent *e);

    bool    hostPaintEvent(QAbstractWidgetHost * host);

    bool    hostDragEnterEvent(QAbstractWidgetHost* host,QDragEnterEvent *e);
    bool    hostDropEvent(QAbstractWidgetHost* host,QDropEvent * e);
    bool    hostResizeEvent(QAbstractWidgetHost * host,QEvent * e);

    bool    hostContextMenuEvent(QAbstractWidgetHost * host,QContextMenuEvent *e);
signals:
    void    hostSelected(QAbstractWidgetHost * host);
    void    updateAction();
protected:
    void    paintEvent(QPaintEvent *);
    void    updateGeometry();
    void    resizeEvent(QResizeEvent *);
protected:
    bool    eventFilter(QObject *, QEvent *);
    QAbstractWidgetHost * getHost(QObject * obj);
protected slots:
    void    formResize(const QSize &size);
    void    hostAdded(QAbstractHost* host,int index);
    void    hostRemoved(QAbstractHost * host);

    void    editDefaultProperty();

    void    deleteThis();
    void    deleteSelection();
protected:
    QAbstractWidgetHost * m_host;
    QMap<QObject*,QAbstractWidgetHost*>     m_objectToHost;
    QUndoStack          * m_undoStack;
    QWidget*            m_owner;
    QFrame              *m_frame;
    SizeHandleRect  *m_handles[8];

    QRubberBand         *m_rubberBand;
    QPoint          m_clickPoint;
    QPoint          m_move_point;
    bool            m_click;

    Selection       *m_selection;
};

#endif // QFORMPANEL_H
