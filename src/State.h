#ifndef STATE_H
#define STATE_H

#include "StateDot.h"

class State
{
public:
    State();
    State( const State &that );

    State& operator=( const State& rhs );
    State operator+( const StateDot& rhs ) const;
    State operator*( const float d ) const;

    inline float getX() const { return x; }
    inline float getV() const { return v; }
    inline float getTheta() const { return theta; }
    inline float getOmega() const { return omega; }

    inline void setX( const float x ) { this->x = x; }
    inline void setV( const float v ) { this->v = v; }
    inline void setTheta( const float theta )  { this->theta = theta; }
    inline void setOmega( const float omega ) { this->omega = omega; }

private:
    float x;
    float v;
    float theta;
    float omega;
};

#endif // STATE_H