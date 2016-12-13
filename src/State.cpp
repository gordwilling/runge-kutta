#include "State.h"

State::State()
    : x( 0 ),
      v( 0 ),
      theta( 0 ),
      omega( 0 )
{
}

State::State( const State& that )
    : x( that.x ),
      v( that.v ),
      theta( that.theta ),
      omega( that.omega )
{
}

State& State::operator=( const State& rhs )
{
    if ( &rhs == this )
    {
        return *this;
    }

    this->x = rhs.x;
    this->v = rhs.v;
    this->theta = rhs.theta;
    this->omega = rhs.omega;

    return *this;
}

State State::operator+( const StateDot& sDot ) const
{
    State result( *this );

    result.x += sDot.v();
    result.v += sDot.a();
    result.theta += sDot.omega();
    result.omega += sDot.alpha();

    return result;
}

State State::operator*( const float d ) const
{
    State result( *this );

    result.x *= d;
    result.v *= d;
    result.theta *= d;
    result.omega *= d;

    return result;
}
