#ifndef PENDULUMCART_H
#define PENDULUMCART_H

#include "State.h"
#include "windows.h"

class PendulumCart
{
public:
    PendulumCart();    
    void step( unsigned int millis, bool addClassicControl, bool disturb );
    void reset();
    void move( float x );
    float input();
    float disturbance( const float amplitude );
    float minorDisturbance();
    inline const State& state() { return m_state; }

private:
    State m_state;
    float m_moveX;

};

#endif // PENDULUMCART_H    
