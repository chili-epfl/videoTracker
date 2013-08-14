/*
 * TagData.h
 *
 *  Created on: Aug 5, 2013
 *      Author: zufferey
 */

#ifndef TAGDATA_H_
#define TAGDATA_H_

#include <vector>

namespace videoTracker {

struct pt2f {
    float x,y;
    pt2f():x(0),y(0){}
    pt2f(float _x, float _y):x(_x),y(_y){}
};

struct tagData_t {
	int id;
	bool detected;
	pt2f p0, p1;
	tagData_t(int _id) :
			id(_id), detected(false) {
	}
};

struct tagEvents_t {
	std::vector<tagData_t> added, moved, removed;
	std::vector<tagData_t> detected;
};

}

#endif /* TAGDATA_H_ */
