#ifndef BLOCK_H
#define BLOCK_H

class Block;

#include "particle.h"
#include "box.h"

#include <vector>

#define BLOCK_MAX_DIVISION_DEPTH 6

/**
 * @brief The Block class represents a large collection of particles
 * encapsulated in octree.
 */
class Block
{
private:
    /**
     * @brief The Node struct represents a dividable space.
     */
    struct Node
    {
        Node();
        ~Node();

        Node *nodes[8];
        Particle particle;
        bool full;

		void set(const Box &box, const bool &inclusive);
    };

    Node root;
	Box wholeBoundBox;
	std::vector<Box> boundingBoxes;

	void set(const Box &box, const bool &inclusive);
	void clear();
public:
    Block();
};

#endif // BLOCK_H
