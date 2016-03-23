#include "frmBase.h"

#include "iconhelper.h"
#include "myhelper.h"

frmBase::frmBase(QWidget *parent) : QDialog(parent)
{
	//设置窗体标题栏隐藏
	setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);
	m_max = false;
	m_mousePressed = false;
}

frmBase::~frmBase()
{
}

void frmBase::initTitle(int type)
{
	m_ui_title.setupUi(this);

	m_ui_title.btnMenu_Min->setVisible(false);
	m_ui_title.btnMenu_Max->setVisible(false);
	m_ui_title.btnMenu_Close->setVisible(false);

	//安装事件监听器,让标题栏识别鼠标双击
	m_ui_title.lab_Title->installEventFilter(this);

	IconHelper::Instance()->SetIcon(m_ui_title.btnMenu_Close, QChar(0xf00d), 10);
	IconHelper::Instance()->SetIcon(m_ui_title.btnMenu_Max, QChar(0xf096), 10);
	IconHelper::Instance()->SetIcon(m_ui_title.btnMenu_Min, QChar(0xf068), 10);
	IconHelper::Instance()->SetIcon(m_ui_title.btnMenu, QChar(0xf0c9), 10);
	IconHelper::Instance()->SetIcon(m_ui_title.lab_Ico, QChar(0xf015), 12);

	if (type == TITLE_TYPE_CLOSE)
	{
		m_ui_title.btnMenu_Close->setVisible(true);
	}
	else if (type == TITLE_TYPE_MIN_CLOSE)
	{
		m_ui_title.btnMenu_Min->setVisible(true);
		m_ui_title.btnMenu_Close->setVisible(true);
	}
	else if (type == TITLE_TYPE_FULL)
	{
		m_ui_title.btnMenu_Min->setVisible(true);
		m_ui_title.btnMenu_Max->setVisible(true);
		m_ui_title.btnMenu_Close->setVisible(true);
	}

	// 加载系统按钮和连接
	connect(m_ui_title.btnMenu_Close, SIGNAL(clicked()), this, SLOT(onClose()));

	// 最大化
	connect(m_ui_title.btnMenu_Max, SIGNAL(clicked()), this, SLOT(onMax()));

	// 最小化
	connect(m_ui_title.btnMenu_Min, SIGNAL(clicked()), this, SLOT(onMin()));
}

bool frmBase::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonDblClick) {
        this->onMax();
        return true;
    }
    return QObject::eventFilter(obj, event);
}

void frmBase::mouseMoveEvent(QMouseEvent *e)
{
    if (m_mousePressed && (e->buttons() && Qt::LeftButton) && !m_max) {
        this->move(e->globalPos() - mousePoint);
        e->accept();
    }
}

void frmBase::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton) {
        m_mousePressed = true;
        mousePoint = e->globalPos() - this->pos();
        e->accept();
    }
}

void frmBase::mouseReleaseEvent(QMouseEvent *)
{
    m_mousePressed = false;
}

void frmBase::onClose()
{
}

void frmBase::onMax()
{
    if (m_max) {
        setGeometry(m_location);
        IconHelper::Instance()->SetIcon(m_ui_title.btnMenu_Max, QChar(0xf096), 10);
        m_ui_title.btnMenu_Max->setToolTip("最大化");
    } else {
        m_location = geometry();
        setGeometry(qApp->desktop()->availableGeometry());
        IconHelper::Instance()->SetIcon(m_ui_title.btnMenu_Max, QChar(0xf079), 10);
        m_ui_title.btnMenu_Max->setToolTip("还原");
    }
    m_max = !m_max;
}

void frmBase::onMin()
{
    showMinimized();
}