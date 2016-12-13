#include "StateDot.h"

StateDot::StateDot()
    : _v( 0 ),
      _a( 0 ),
      _omega( 0 ),
      _alpha( 0 )
{
}

StateDot::StateDot( const StateDot& that )
    : _v( that._v ),
      _a( that._a ),
      _omega( that._omega ),
      _alpha( that._alpha )
{
}

StateDot& StateDot::operator=( const StateDot& rhs )
{
    if ( &rhs == this )
    {
        return *this;
    }

    this->_v = rhs._v;
    this->_a = rhs._a;
    this->_omega = rhs._omega;
    this->_alpha = rhs._alpha;

    return *this;
}

StateDot StateDot::operator+( const StateDot& rhs ) const
{
    StateDot result( *this );

    result._v += rhs._v;
    result._a += rhs._a;
    result._omega += rhs._omega;
    result._alpha += rhs._alpha;

    return result;
}

StateDot StateDot::operator*( float d ) const
{
    StateDot result( *this );

    result._v *= d;
    result._a *= d;
    result._omega *= d;
    result._alpha *= d;

    return result;
}
