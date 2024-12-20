﻿/** 
 * @License      : All interpretation rights of this software belong to the author, and operations such as reprinting and
 * @			   sharing are prohibited without permission.
 * @Author       : Copyright (c), vseasky.liu vseasky@yeah.net.
 * @Github       : https://github.com/vseasky
 * @Date         : 2024-06-02 23:53:05
 * @FilePath     : \VersaAssistant\Frameless\QFramelessHelper.h
 * @Description  : 
 */
#ifndef QFRAMELESSHELPER_H
#define QFRAMELESSHELPER_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QPointer>


class QDrawShadowHelper;

class QFramelessHelper : public QObject
{
Q_OBJECT
public:
	explicit QFramelessHelper(QWidget *w,
	                          bool resizeEnable = true,
	                          bool shadowBorder = true,
	                          bool winNativeEvent = true,
	                          QObject *parent = nullptr);
	
	~QFramelessHelper();

protected:
	//窗体显示的时候触发
	void doShowEvent(QEvent *event);
	//事件过滤器识别拖动拉伸等
	void doWindowStateChange(QEvent *event);
	void doResizeEvent(QEvent *event);
	bool eventFilter(QObject *watched, QEvent *event);
	//更新自绘阴影边框显示状态
	void updateDrawShadowState();
public:
	//拦截系统事件用于修复系统休眠后唤醒程序的BUG
#if (QT_VERSION >= QT_VERSION_CHECK(6, 0, 0))
	bool nativeEvent(const QByteArray &eventType, void *message, qintptr *result);
#else
	bool nativeEvent(const QByteArray &eventType, void *message, long *result);
#endif
	void paintEvent(QPaintEvent *e);

private:
	QPointer<QWidget> m_widget = nullptr;
	//边距+可移动+可拉伸+阴影边框
	int m_padding;
	bool m_moveEnable;
	bool m_resizeEnable;
	bool m_shadowBorder;
	//通过边框进行resize
	bool m_borderResizeEnable;
	
	//标题栏控件
	QPointer<QWidget> m_titleBar = nullptr;
	
	//鼠标是否按下+按下坐标+按下时窗体区域
	bool m_mousePressed;
	QPoint m_mouseGlobalPoint;
	QRect m_mouseRect;
	
	//鼠标是否按下某个区域+按下区域的大小
	//依次为 左侧+右侧+上侧+下侧+左上侧+右上侧+左下侧+右下侧
	QList<bool> m_pressedArea;
	QList<QRect> m_pressedRect;
	
	//记录是否最小化
	bool m_isMin;
	//存储窗体默认的属性
	Qt::WindowFlags m_flags;
	
	//windows是否采用NativeEvent进行Resize、阴影边框，linux下该值为false
	bool m_winNativeEvent;
	
	//自绘制阴影边框
	QPointer<QDrawShadowHelper> m_drawShadow;

public:
	//设置边距+可拖动+可拉伸
	void setPadding(int padding);
	void setMoveEnable(bool moveEnable);
	void setResizeEnable(bool resizeEnable);
	
	//设置标题栏窗体
	void setTitleBar(QWidget *titleBar);
	bool isMaximized();
public slots:
	void showMinimized();
	void showMaximized();
	void showNormal();
	void switchMaximizedNormal();
signals:
	void maximizedChanged(bool max);
};

#endif // QFRAMELESSHELPER_H
