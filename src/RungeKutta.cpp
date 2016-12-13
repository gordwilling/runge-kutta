#include "RungeKutta.h"

RungeKutta::RungeKutta( float h )
    : h( h )
{
}

State RungeKutta::solve( const Dynamics& d, const State& s, const float u ) const
{
    StateDot k1 = d.solve( s, u );
    StateDot k2 = d.solve( s + ( k1 * ( 0.5f * h ) ), u );
    StateDot k3 = d.solve( s + ( k2 * ( 0.5f * h ) ), u );
    StateDot k4 = d.solve( s + ( k3 * h ), u );

    return s + ( ( k1 + ( k2 * 2.0f ) + ( k3 * 2.0f ) + k4 ) * ( h / 6.0f ) );
}