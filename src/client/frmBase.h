#ifndef FRMMAIN_H
#define FRMMAIN_H

#include <QDialog>

#include "ui_frmBase.h"

class frmBase : public QDialog
{
    Q_OBJECT

public:
    frmBase(QWidget *parent = 0);
    ~frmBase();

	enum TITLE_TYPE
	{
		TITLE_TYPE_NONE = 0,	// 什么都没
		TITLE_TYPE_CLOSE,		// 只有关闭
		TITLE_TYPE_MIN_CLOSE,	// 最小化和
		TITLE_TYPE_FULL			// 全部有
	};

	void initTitle(int type);

private:
	void InitStyle();

protected:
    bool eventFilter(QObject *obj, QEvent *event);
    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *);

private slots:
    void onClose();

    void onMax();

    void onMin();


private:
    Ui::frmBase m_ui_title;

    QPoint mousePoint;
    bool m_mousePressed;
    bool m_max;
    QRect m_location;
};

#endif // FRMMAIN_H
