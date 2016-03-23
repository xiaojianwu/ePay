#include "client.h"

#include "myhelper.h"
client::client(QWidget *parent)
	: frmBase(parent)
{
	initTitle(TITLE_TYPE_FULL);
	ui.setupUi(this);

	//myHelper::FormInCenter(this);
}

client::~client()
{

}

void client::onClose()
{
	qApp->exit();
}
