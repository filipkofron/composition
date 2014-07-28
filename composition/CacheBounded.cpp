#include "CacheBounded.h"

const Box &CacheBounded::getWholeBoundBox()
{
    if (m_Dirty)
	{
		update();
	}
    return m_WholeBoundBox;
}

const std::vector<Box> &CacheBounded::getAllBoundBoxes()
{
    if (m_Dirty)
	{
		update();
	}
    return m_BoundBoxes;
}

void CacheBounded::markDirty()
{
    m_Dirty = true;
}

void CacheBounded::update()
{
	// the dirty flag is clear prior to the actual update so that it can
	// be marked dirty during the update to avoid losing changes
    m_Dirty = false;

    m_WholeBoundBox = Box();
    onUpdateWholeBoundBox(m_WholeBoundBox);

    m_BoundBoxes.clear();
    onUpdateAllBoundBox(m_BoundBoxes);
}
