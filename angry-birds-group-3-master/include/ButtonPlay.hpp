#ifndef BUTTONPLAY_HPP
#define BUTTONPLAY_HPP

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsPixmapItem>

/**
 * @brief A play button to start the game.
 * 
 */
class ButtonPlay:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    ButtonPlay(QGraphicsItem* parent=NULL);
    ~ButtonPlay() {}
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
signals:
    void clicked();
private:
    QGraphicsTextItem* text;
};

#endif