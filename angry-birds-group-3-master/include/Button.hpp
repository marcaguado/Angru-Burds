#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

/**
 * @brief A clickable button
 * 
 */
class Button:public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Button(QString name, QGraphicsItem* parent=NULL);
    ~Button() {}
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
signals:
    void clicked();
private:
    QGraphicsTextItem* text;
};

#endif