#include <iostream>

#include "context/player.h"

int main()
{
    dps::player* p = new dps::player();
    p->play();
    p->lock();
    p->lock();
    p->play();
    p->play();
    for(int i = 0; i < 11; i++)
    {
        p->next();
    }
    p->next();
    p->previous();
    delete p;
    return 0;
}