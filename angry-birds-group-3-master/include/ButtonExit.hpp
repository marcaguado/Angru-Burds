#ifndef BUTTONEXIT_HPP
#define BUTTONEXIT_HPP

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsPixmapItem>

/**
 * @brief An exit button
 * 
 */
class ButtonExit:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    ButtonExit(QGraphicsItem* parent=NULL);
    ~ButtonExit() {}
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
signals:
    void clicked();
private:
    QGraphicsTextItem* text;
};

#endif