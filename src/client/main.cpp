#include "client.h"
#include <QtWidgets/QApplication>

#include "iconhelper.h"
#include "myhelper.h"

#include "frmBase.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	myHelper::SetUTF8Code();
	myHelper::SetStyle("black");//��ɫ���
	//myHelper::SetStyle("blue");//��ɫ���
	//myHelper::SetStyle("gray");//��ɫ���
	//myHelper::SetStyle("navy");//����ɫ���
	myHelper::SetChinese();

	//frmBase w;
	//w.show();

	client w;
	w.show();
	return a.exec();
}
