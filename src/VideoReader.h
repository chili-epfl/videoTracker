/*
 * VideoReader.h
 *
 *  Created on: Aug 5, 2013
 *      Author: zufferey
 */

#ifndef VIDEOREADER_H_
#define VIDEOREADER_H_

#include <opencv2/opencv.hpp>

namespace videoTracker {

class VideoReader {
public:
	VideoReader(const std::string &file);
	virtual ~VideoReader();

	bool isReady() const;
	int width();
	int height();

	bool read(cv::Mat &frame);

private:
	cv::VideoCapture m_video;
};

} /* namespace videoTracker */
#endif /* VIDEOREADER_H_ */
