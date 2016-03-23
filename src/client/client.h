#ifndef CLIENT_H
#define CLIENT_H

#include <QtWidgets/QDialog>
#include "ui_client.h"

#include "frmBase.h"

class client : public frmBase
{
	Q_OBJECT

public:
	client(QWidget *parent = 0);
	~client();

private slots:
	void onClose();

private:
	Ui::clientClass ui;
};

#endif // CLIENT_H
