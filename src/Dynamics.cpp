#include "Dynamics.h"

#include <cmath>

Dynamics::Dynamics()
    : g( -9.81f ),
      lp( 0.8f ),
      mp( 1.0f ),
      mc( 1.0f ),
      mt( mp + mc ),
      fp( 0.1f ),
      fc( 2.0f )
{
}

StateDot Dynamics::solve( const State& s, const float u ) const
{
    float sinTheta = sin( s.getTheta() );
    float cosTheta = cos( s.getTheta() );
    float m_l_sinTheta = mp * lp * sinTheta;
    float omega_squared = s.getOmega() * s.getOmega();
    float M_plus_mSinSquaredTheta = mc + ( mp * sinTheta * sinTheta );

    StateDot sDot;

    // linear velocity of pendulum and cart on x
    sDot.v( s.getV() );

    // angular velocity of pendulum about pin
    sDot.omega( s.getOmega() );

    // linear acceleration on x
    //
    //     mlsin(theta) * w^2 + mgsin(theta)cos(theta) - dv + (b/l)wcos(theta) + u
    // a = ------------------------------------------------------------------------
    //                              M + msin^2(theta)
    //
    sDot.a( ( m_l_sinTheta * omega_squared
              + mp * g * sinTheta * cosTheta
              + ( fp / lp ) * s.getOmega() * cosTheta
              - fc * s.getV()
              + u
            ) / M_plus_mSinSquaredTheta );

    // angular acceleration of pendulum about pin
    //
    //         mlsin(theta)cos(theta) * w^2 - ucos(theta) + dvcos(theta) - (1 + M/m)(b/l)w - (M + m)gsin(theta)
    // alpha = ------------------------------------------------------------------------------------------------
    //                                          l[M + msin(theta)]
    //
    sDot.alpha( ( -m_l_sinTheta * cosTheta * omega_squared
                  - u * cosTheta
                  + fc * s.getV() * cosTheta
                  - ( 1 + mc / mp ) * ( fp / lp ) * s.getOmega()
                  - mt * g * sinTheta
                  ) / ( lp * M_plus_mSinSquaredTheta ) );

    return sDot;
}
