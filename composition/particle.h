#ifndef PARTICLE_H
#define PARTICLE_H

#define DEFAULT_PARTICLE 0

class Particle;

#include <cstdint>

class Particle
{
public:
    Particle();

    uint16_t m_Id;
    
};

#endif // PARTICLE_H
