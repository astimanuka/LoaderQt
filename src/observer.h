#ifndef OBSERVER_H
#define OBSERVER_H
#include <iostream>
#include "files.h"

using namespace std;

class Observer {

protected:
    Observer() { }

public:
    /*virtual void atach() = 0;

    virtual void detach() = 0;*/

    virtual void update(Files file) = 0;

    virtual ~Observer()=0;
};

#endif // OBSERVER_H
