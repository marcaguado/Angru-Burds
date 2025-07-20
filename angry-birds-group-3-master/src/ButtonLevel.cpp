#include "ButtonLevel.hpp"
#include <QGraphicsTextItem>
#include <QBrush>
#include <QImage>

/**
 * @brief Construct a new Button Level:: Button Level object
 * 
 * @param parent QGraphicsItem parent
 */
ButtonLevel::ButtonLevel(int levelslot, QGraphicsItem *parent): slot(levelslot), QGraphicsPixmapItem(parent){
    // Sets the original button image
    setPixmap(QPixmap("graphics/LevelButton.png"));

    // Allows Hovering
    setAcceptHoverEvents(true);
}

/**
 * @brief Tracks if button is clicked
 * 
 * @param event mouse event
 */
void ButtonLevel::mousePressEvent(QGraphicsSceneMouseEvent *event){
    emit clicked();
}

/**
 * @brief Alters button's graphical image when mouse is hovered over it
 * 
 * @param event mouse event
 */
void ButtonLevel::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    // Sets the button image when mouse is hovering the button
    if(slot == 1){
        setPixmap(QPixmap("graphics/LevelButtonHoverLevel1.png"));
    }
    else if(slot == 2){
        setPixmap(QPixmap("graphics/LevelButtonHoverLevel2.png"));
    }
    else if(slot == 3){
        setPixmap(QPixmap("graphics/LevelButtonHoverLevel3.png"));
    }
}

/**
 * @brief Alters button's graphical image when mouse is no longer hovered over it
 * 
 * @param event mouse event
 */
void ButtonLevel::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    // Sets the original button once it stops hovering
    setPixmap(QPixmap("graphics/LevelButton.png"));
}