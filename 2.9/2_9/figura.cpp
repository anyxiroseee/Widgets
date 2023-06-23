#include <math.h>
#include "figura.h"

void Figura::move(float Alpha,QPainter *Painter)
{
     dx=halfLen*cos(Alpha);
     dy=halfLen*sin(Alpha);
     draw(Painter);
}

void MyLine::draw(QPainter *Painter)
{
    Painter->drawLine(x+dx,y+dy,x-dx,y-dy);
}

void MyRect::draw(QPainter *Painter)
{
    Painter->drawLine(x+dx,y+dy,x+dy,y-dx);
    Painter->drawLine(x+dy,y-dx,x-dx,y-dy);
    Painter->drawLine(x-dx,y-dy,x-dy,y+dx);
    Painter->drawLine(x-dy,y+dx,x+dx,y+dy);
}
