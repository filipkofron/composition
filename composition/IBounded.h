#ifndef IBOUNDED_H
#define IBOUNDED_H

class IBounded;

#include "box.h

class IBounded
{
public:
	const Box &getWholeBoundingBox();
	const std::vector<Box> &getAllBoundingBoxes();
};

#endif
