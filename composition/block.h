#ifndef BLOCK_H
#define BLOCK_H

class Block;

#include "particle.h"
#include "box.h"

#include <vector>

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
		void clear();
    };

    Node root;
	Box wholeBoundBox;
	std::vector<Box> boundingBoxes;

    double pos_x, pos_y, pos_z;
    double scale;
public:
    Block();
	const Box &getWholeBoundingBox();
	const std::vector<Box> &getAllBoundingBoxes();
	
};

#endif // BLOCK_H
