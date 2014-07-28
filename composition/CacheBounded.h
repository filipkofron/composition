#ifndef CACHEBOUNDED_H
#define CACHEBOUNDED_H

class CacheBounded;

#include "IBounded.h"

class CacheBounded : public IBounded
{
private:
    Box m_WholeBoundBox;
    std::vector<Box> m_BoundBoxes;
    bool m_Dirty;
protected:
    virtual void onUpdateWholeBoundBox(Box &box) = 0;
    virtual void onUpdateAllBoundBox(std::vector<Box> &boxes) = 0;
public:
	const virtual Box &getWholeBoundBox();
	const virtual std::vector<Box> &getAllBoundBoxes();

	void markDirty();
	void update();
};

#endif
