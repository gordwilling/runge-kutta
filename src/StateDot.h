#ifndef STATEDOT_H
#define STATEDOT_H

class StateDot
{
public:
    StateDot();
    StateDot( const StateDot& that );

    StateDot& operator=( const StateDot& rhs );
    StateDot operator+( const StateDot& rhs ) const;
    StateDot operator*( const float d ) const;

    inline float v() const { return _v; }
    inline float a() const { return _a; }
    inline float omega() const { return _omega; }
    inline float alpha() const { return _alpha; }

    inline void v( const float v ) { this->_v = v; }
    inline void a( const float a ) { this->_a = a; }
    inline void omega( const float omega ) { this->_omega = omega; }
    inline void alpha( const float alpha ) { this->_alpha = alpha; }

private:
    float _v;
    float _a;
    float _omega;
    float _alpha;
};

#endif // STATEDOT_H
