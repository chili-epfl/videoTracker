/*
 * ChiliProcessor.h
 *
 *  Created on: Aug 5, 2013
 *      Author: zufferey
 */

#ifndef CHILIPROCESSOR_H_
#define CHILIPROCESSOR_H_

#include <string>
#include <opencv2/opencv.hpp>
#include "TagData.h"

namespace videoTracker {

class VideoReader;
class ChiliTracker;

class ChiliProcessor {
public:
	ChiliProcessor();
	virtual ~ChiliProcessor();

	void process(VideoReader &reader, ChiliTracker &tracker);

private:
	void drawTags(const tagEvents_t &events, cv::Mat &frame);
	void drawTag(const tagData_t &tag, cv::Mat &frame);

private:
	std::string m_windowName;
};

} /* namespace videoTracker */
#endif /* CHILIPROCESSOR_H_ */
