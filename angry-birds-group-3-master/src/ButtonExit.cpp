#include "ButtonExit.hpp"

/**
 * @brief Construct a new Button Exit:: Button Exit object
 * 
 * @param parent QGraphicsItem parent
 */
ButtonExit::ButtonExit(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    // Sets the original button image
    setPixmap(QPixmap("graphics/QuitButton.png"));

    // Allows Hovering
    setAcceptHoverEvents(true);
}

/**
 * @brief Tracks if button is clicked
 * 
 * @param event mouse event
 */
void ButtonExit::mousePressEvent(QGraphicsSceneMouseEvent *event){
    emit clicked();
}

/**
 * @brief Alters button's graphical image when mouse is hovered over it
 * 
 * @param event mouse event
 */
void ButtonExit::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    // Sets the button image when mouse is hovering the button
    setPixmap(QPixmap("graphics/QuitButtontHover.png"));
}

/**
 * @brief Alters button's graphical image when mouse is no longer hovered over it
 * 
 * @param event mouse event
 */
void ButtonExit::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    // Sets the original button once it stops hovering
    setPixmap(QPixmap("graphics/QuitButton.png"));
}