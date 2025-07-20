#include "Button.hpp"
#include <QGraphicsTextItem>
#include <QBrush>

/**
 * @brief Construct a new Button:: Button object
 * 
 * @param name Name of the button
 * @param parent QGraphicsItem parent
 */
Button::Button(QString name, QGraphicsItem *parent): QGraphicsRectItem(parent){
    // draw the rect
    setRect(0,0,200,50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkCyan);
    setBrush(brush);

    // draw the text
    text = new QGraphicsTextItem(name,this);
    int xPos = rect().width()/2 - text->boundingRect().width()/2;
    int yPos = rect().height()/2 - text->boundingRect().height()/2;
    text->setPos(xPos,yPos);

    // allow responding to hover events
    setAcceptHoverEvents(true);
}

/**
 * @brief Tracks if button is clicked
 * 
 * @param event mouse event
 */
void Button::mousePressEvent(QGraphicsSceneMouseEvent *event){
    emit clicked();
}

/**
 * @brief Tracks if mouse is being hovered over the button.
 *        Changes the color of the button.
 * 
 * @param event 
 */
void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    // change color to cyan
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::cyan);
    setBrush(brush);
}

/**
 * @brief Changes the color back to dark cyan when mouse no longer
 *        hovers over button. 
 * 
 * @param event 
 */
void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    // change color to dark cyan
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkCyan);
    setBrush(brush);
}