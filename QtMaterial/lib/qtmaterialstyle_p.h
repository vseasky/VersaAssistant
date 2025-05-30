#ifndef QTMATERIALSTYLE_P_H
#define QTMATERIALSTYLE_P_H

#include <QtGlobal>
#include <lib/qtmaterialglobal.h>

class QtMaterialStyle;

class QtMaterialTheme;

class MATERIAL_EXPORT QtMaterialStylePrivate
{
	Q_DISABLE_COPY(QtMaterialStylePrivate)
	
	Q_DECLARE_PUBLIC(QtMaterialStyle)

public:
	QtMaterialStylePrivate(QtMaterialStyle *q);
	
	~QtMaterialStylePrivate();
	
	void init();
	
	QtMaterialStyle *const q_ptr;
	QtMaterialTheme *theme;
};

#endif // QTMATERIALSTYLE_P_H
