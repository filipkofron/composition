#ifndef BLOCK_H
#define BLOCK_H

class Block;

#include "particle.h"
#include "box.h"
#include "CacheBounded.h"

#define BLOCK_MAX_DIVISION_DEPTH 6

/**
 * @brief The Block class represents a large collection of particles
 * encapsulated in octree.
 */
class Block : public CacheBounded
{
private:
    /**
     * @brief The Node struct represents a dividable space.
     */
    struct Node
    {
        Node();
        ~Node();

        Node *m_Nodes[8];
        Particle m_Particle;
        bool m_Full;

        void set(const Box &box, const bool &inclusive, const Particle &particle);
        void clear();
    };

    Node m_Root;

    void set(const Box &box, const bool &inclusive, const Particle &particle);
	void clear();
protected:
    virtual void onUpdateWholeBoundBox(Box &box);
    virtual void onUpdateAllBoundBox(std::vector<Box> &boxes);
public:
    Block();
};

#endif // BLOCK_H
