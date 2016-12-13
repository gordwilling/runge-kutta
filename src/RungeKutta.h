#ifndef RUNGEKUTTA_H
#define RUNGEKUTTA_H

#include "State.h"
#include "Dynamics.h"

class RungeKutta
{
public:
    RungeKutta( float h );

    State solve( const Dynamics& d, const State& s, const float u ) const;

private:
    float h;
};

#endif // RUNGEKUTTA_H
