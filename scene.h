#ifndef SCENE_H
#define SCENE_H
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QApplication>
#include <QKeyEvent>
#include <Qtimer>
#include <time.h>
#include"btn.h"


class Scene:public QGraphicsScene
{
    Q_OBJECT

public:
    Scene();
    void Button();
    void GameStart();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    void keyPressEvent(QKeyEvent *event);
    //void scorequit();



    Btn *startbtn;
    Btn *exitbtn;
    Btn *returnbtn;
    Btn *replay;



    int screenMode;







};




#endif // SCENE_H
