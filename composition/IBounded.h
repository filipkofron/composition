#ifndef IBOUNDED_H
#define IBOUNDED_H

class IBounded;

#include "box.h"

#include <vector>

class IBounded
{
public:
	const virtual Box &getWholeBoundBox() = 0;
	const virtual std::vector<Box> &getAllBoundBoxes() = 0;
};

#endif
