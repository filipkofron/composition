#include "block.h"

Block::Block()
{
}

Block::Node::Node()
{
    for(int i = 0; i < 8; i++)
    {
        nodes[i] = nullptr;
    }
}

Block::Node::~Node()
{
    for(int i = 0; i < 8; i++)
    {
        delete nodes[i];
    }
}

void Block::set(const Box &box, const bool &inclusive)
{
	root.set(box, inclusive);
}

void Block::clear()
{
	root = Node();
}
