#ifndef CACHEBOUNDED_H
#define CACHEBOUNDED_H

class CacheBounded;

#include "IBounded.h"

class CacheBounded : public IBounded
{
private:
	Box wholeBoundBox;
	std::vector<Box> boundBoxes;
	bool dirty;
protected:
	const virtual void onUpdateWholeBoundBox(Box &box) = 0;
	const virtual void onUpdateAllBoundBox(std::vector<Box> &boxes) = 0;
public:
	const virtual Box &getWholeBoundBox();
	const virtual std::vector<Box> &getAllBoundBoxes();

	void markDirty();
	void update();
};

#endif
