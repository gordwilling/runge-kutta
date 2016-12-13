#ifndef DYNAMICS_H
#define DYNAMICS_H

#include "State.h"
#include "StateDot.h"

class Dynamics
{
public:
    const float g;
    const float lp;
    const float mp;
    const float mc;
    const float mt;
    const float fp;
    const float fc;

    Dynamics();

    StateDot solve( const State& s, const float u ) const;
};

#endif // DYNAMICS_H
