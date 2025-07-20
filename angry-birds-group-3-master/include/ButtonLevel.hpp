#ifndef BUTTONLEVEL_HPP
#define BUTTONLEVEL_HPP

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsPixmapItem>

/**
 * @brief A level button to start the level.
 * 
 */
class ButtonLevel:public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    ButtonLevel(int levelslot, QGraphicsItem* parent=NULL);
    ~ButtonLevel() {}
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
signals:
    void clicked();
    void scrolled();
private:
    QGraphicsTextItem* text;
    int slot;
};

#endif