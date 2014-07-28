#include "block.h"

Block::Block()
{
}

Block::Node::Node()
{
    for(int i = 0; i < 8; i++)
    {
        m_Nodes[i] = nullptr;
    }
}

Block::Node::~Node()
{
    for(int i = 0; i < 8; i++)
    {
        delete m_Nodes[i];
    }
}

static Box nodeBox(Vec3(-0.5, -0.5, -0.5), Vec3(0.5, 0.5, 0.5));

void Block::Node::set(const Box &box, const bool &inclusive, const Particle &particle)
{
    if(box.contains(nodeBox))
    {
        m_Full = true;
        m_Particle = particle;
    }
    else
    {
        m_Full = false;
        m_Particle = Particle();

        //
    }
}

void Block::Node::clear()
{
    for(int i = 0; i < 8; i++)
    {
        delete m_Nodes[i];
        m_Nodes[i] = NULL;
    }
}

void Block::set(const Box &box, const bool &inclusive, const Particle &particle)
{
    m_Root.set(box, inclusive, particle);
}

void Block::clear()
{
    m_Root = Node();
}

void Block::onUpdateWholeBoundBox(Box &box)
{

}

void Block::onUpdateAllBoundBox(std::vector<Box> &boxes)
{

}

