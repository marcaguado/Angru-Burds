#include "ButtonPlay.hpp"

/**
 * @brief Construct a new Button Play:: Button Play object
 * 
 * @param parent QGraphicsItem parent
 */
ButtonPlay::ButtonPlay(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    // Sets the original button image
    setPixmap(QPixmap("graphics/PlayButton.png"));

    // Allows Hovering
    setAcceptHoverEvents(true);
}

/**
 * @brief Tracks if button is clicked
 * 
 * @param event mouse event
 */
void ButtonPlay::mousePressEvent(QGraphicsSceneMouseEvent *event){
    emit clicked();
}

/**
 * @brief Alters button's graphical image when mouse is hovered over it
 * 
 * @param event mouse event
 */
void ButtonPlay::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    // Sets the button image when mouse is hovering the button
    setPixmap(QPixmap("graphics/PlayButtonHover.png"));
}

/**
 * @brief Alters button's graphical image when mouse is no longer hovered over it
 * 
 * @param event mouse event
 */
void ButtonPlay::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    // Sets the original button once it stops hovering
    setPixmap(QPixmap("graphics/PlayButton.png"));
}