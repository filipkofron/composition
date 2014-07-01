#include "CacheBounded.h"

const Box &CacheBounded::getWholeBoundBox()
{
	if (dirty)
	{
		update();
	}
	return wholeBoundBox;
}

const std::vector<Box> &CacheBounded::getAllBoundBoxes()
{
	if (dirty)
	{
		update();
	}
	return boundBoxes;
}

void CacheBounded::markDirty()
{
	dirty = true;
}

void CacheBounded::update()
{
	// the dirty flag is clear prior to the actual update so that it can
	// be marked dirty during the update to avoid losing changes
	dirty = false;

	wholeBoundBox = Box();
	onUpdateWholeBoundBox(wholeBoundBox);

	boundBoxes.clear();
	onUpdateAllBoundBox(boundBoxes);
}
