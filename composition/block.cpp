#include "block.h"

Block::Block()
    : pos_x(0.0), pos_y(0.0), pos_z(0.0), scale(0.0)
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
