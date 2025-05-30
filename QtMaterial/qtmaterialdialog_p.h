#ifndef QTMATERIALDIALOG_P_H
#define QTMATERIALDIALOG_P_H

#include <QtGlobal>
#include <lib/qtmaterialglobal.h>

class QStateMachine;

class QtMaterialDialog;

class QStackedLayout;

class QtMaterialDialogWindow;

class QtMaterialDialogProxy;

class MATERIAL_EXPORT QtMaterialDialogPrivate
{
	Q_DISABLE_COPY(QtMaterialDialogPrivate)
	
	Q_DECLARE_PUBLIC(QtMaterialDialog)

public:
	QtMaterialDialogPrivate(QtMaterialDialog *q);
	
	~QtMaterialDialogPrivate();
	
	void init();
	
	QtMaterialDialog *const q_ptr;
	QtMaterialDialogWindow *dialogWindow;
	QStackedLayout *proxyStack;
	QStateMachine *stateMachine;
	QtMaterialDialogProxy *proxy;
};

#endif // QTMATERIALDIALOG_P_H
