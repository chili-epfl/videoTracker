/*
 * ChiliTracker.h
 *
 *  Created on: Aug 5, 2013
 *      Author: zufferey
 */

#ifndef CHILITRACKER_H_
#define CHILITRACKER_H_

#include "TagData.h"
#include <memory>
#include <opencv2/opencv.hpp>

namespace chilitags {
class DetectChilitags;
}

namespace videoTracker {

class VideoReader;

class ChiliTracker {
public:
	ChiliTracker(float width, float height);
	virtual ~ChiliTracker();

	tagEvents_t track(const cv::Mat &frame);

private:
	cv::Mat m_frame;
	IplImage *m_img;
	std::shared_ptr<chilitags::DetectChilitags> m_tracker;
};

} /* namespace videoTracker */
#endif /* CHILITRACKER_H_ */
