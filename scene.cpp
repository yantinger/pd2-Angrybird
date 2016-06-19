#include "scene.h"
#include <QGraphicsSceneMouseEvent>
#include <iostream>


using namespace std;

Scene::Scene()
{
    screenMode =0;

}


void Scene::Button()
{



    startbtn = new Btn();
    QPixmap sb;
    sb.load(":/egg.png");
    sb=sb.scaled(100,100,Qt::KeepAspectRatio);
    startbtn->setPixmap(sb);
    startbtn->setPos(410,275);
    addItem(startbtn);

    exitbtn=new Btn();
    QPixmap eb;
    eb.load(":/exit.png");
    eb=eb.scaled(100,100,Qt::KeepAspectRatio);
    exitbtn->setPixmap(eb);
    exitbtn->setPos(180,270);
    addItem(exitbtn);


}


 void Scene::GameStart()
 {

     /*connect*/
    // dis = 0;
     /*change background*/
     QImage bg;
     bg.load(":/bk2.jpg");
     bg = bg.scaled(610,410);
     this->setBackgroundBrush(bg);

     /*remove button*/

     this->removeItem(startbtn);
     this->removeItem(exitbtn);


     returnbtn = new Btn();
     QPixmap rb;
     rb.load(":/exit.png");
     rb=rb.scaled(50,50,Qt::KeepAspectRatio);
     returnbtn->setPixmap(rb);
     returnbtn->setPos(600,10);
     addItem(returnbtn);

     replay = new Btn();
     QPixmap rp;
     rp.load(":/restart.png");
     rp=rp.scaled(50,50,Qt::KeepAspectRatio);
     replay->setPixmap(rp);
     replay->setPos(650,10);
     addItem(replay);




 }


 void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
     if(screenMode ==0)
     {
        if(event->scenePos().x() > startbtn->pos().x() && event->scenePos().x() <= startbtn->pos().x()+75)
        {
            if(event->scenePos().y() > startbtn->pos().y() && event->scenePos().y() <= startbtn->pos().y()+95)
            {
                GameStart();
                cout<<"Start"<<endl;

                screenMode = 1;



            }
        }

        if(event->scenePos().x() > exitbtn->pos().x() && event->scenePos().x() <= exitbtn->pos().x()+140)
        {
            if(event->scenePos().y() > exitbtn->pos().y() && event->scenePos().y() <= exitbtn->pos().y()+90)
            {
                cout<<"exit"<<endl;
                QApplication::exit();

            }
        }
     }
     if(screenMode==1)
     {
         if(event->scenePos().x()>returnbtn->pos().x()&&event->scenePos().x()<returnbtn->pos().x()+45)
             if(event->scenePos().y()>returnbtn->pos().y()+10&&event->scenePos().y()<returnbtn->pos().y()+40)
             {

                 removeItem(returnbtn);
                 removeItem(replay);
                 QImage bg;
                 bg.load(":/startgamebk.png");
                 bg = bg.scaled(610,410);
                 this->setBackgroundBrush(bg);
                 Button();
                 screenMode = 0;



             }
       if(event->scenePos().x()>replay->pos().x()&&event->scenePos().x()<replay->pos().x()+45)
             if(event->scenePos().y()>replay->pos().y()+10&&event->scenePos().y()<replay->pos().y()+40)
             {

                 removeItem(returnbtn);
                 removeItem(replay);
                 Button();
                 screenMode = 0;


             }

     }

   /*  if(screenMode ==2)
     {
        if(event->scenePos().x() > again->pos().x() && event->scenePos().x() <= again->pos().x()+400)
        {
            if(event->scenePos().y() > again->pos().y() && event->scenePos().y() <= again->pos().y()+150)
            {
                removeItem(feet);
                removeItem(leftface);
                removeItem(rightface);
                removeItem(returnbtn);
                removeItem(rule);
                removeItem(again);
                removeItem(finalpic);
                removeItem(score1);

                for(int i=0;i<num_ball;i++)
                {
                    removeItem(ball_list[i]);
                }
                Button();
                screenMode = 0;
                ballrun();
                ball_list.clear();
                rand_list.clear();
                number=0;
                num_ball=0;
                score1->score=0;




            }
        }


     }*/
}

 void Scene::keyPressEvent(QKeyEvent *event)
 {

    if(screenMode==0)
    {
        if(event->key()==Qt::Key_Enter)
        {
            GameStart();
            screenMode = 1;


        }

        if(event->key()==Qt::Key_Escape)
        {
             QApplication::exit();

        }


     }
   /* if(screenMode==1)
    {
        if(event->key()==Qt::Key_Space)
        {


            removeItem(returnbtn);
            removeItem(replay);


            Button();
            screenMode = 0;


        }


     }*/


    /* if(screenMode==2)
     {
         if(event->key()==Qt::Key_Space)
         {

             removeItem(feet);
             removeItem(leftface);
             removeItem(rightface);
             removeItem(returnbtn);
             removeItem(rule);
             removeItem(again);
             removeItem(finalpic);
             removeItem(score1);

             for(int i=0;i<num_ball;i++)
             {
                 removeItem(ball_list[i]);
             }
             Button();
             screenMode = 0;
             ballrun();
             ball_list.clear();
             rand_list.clear();
             number=0;
             num_ball=0;
             score1->score=0;


         }


      }*/

 }




 /*void Scene::scorequit()
 {

     if(cnt==0)
     {

         removeItem(feet);
         removeItem(leftface);
         removeItem(rightface);
         removeItem(returnbtn);
         removeItem(rule);
         for(int i=0;i<num_ball;i++)
         {
             removeItem(ball_list[i]);
         }

         screenMode = 2;//切成2
         ballrun();
         ball_list.clear();
         rand_list.clear();
         number=0;
         num_ball=0;

         again = new Btn();
         QPixmap ag;
         ag.load(":/images/again.png");
         ag=ag.scaled(400,400,Qt::KeepAspectRatio);
         again->setPixmap(ag);
         again->setPos(150,200);
         addItem(again);



     }


 }*/






