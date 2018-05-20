#include <stdio.h>
#include "Singleton.h"


Singleton* Singleton::singleton = NULL;

Singleton* Singleton::GetInstance()
{
    if(singleton == NULL)
        singleton = new Singleton();

    return singleton;
}

void Singleton::show()
{
    printf("Singleton show");
}