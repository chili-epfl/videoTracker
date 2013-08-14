/*
 * VideoReader.cpp
 *
 *  Created on: Aug 5, 2013
 *      Author: zufferey
 */

#include "VideoReader.h"

namespace videoTracker {

VideoReader::VideoReader(const std::string &file) :
		m_video(file) {
}

VideoReader::~VideoReader() {
}

bool VideoReader::isReady() const {
	return m_video.isOpened();
}

int VideoReader::width() {
	return m_video.get(CV_CAP_PROP_FRAME_WIDTH);
}

int VideoReader::height() {
	return m_video.get(CV_CAP_PROP_FRAME_HEIGHT);
}

bool VideoReader::read(cv::Mat &frame) {
	return m_video.read(frame);
}

} /* namespace videoTracker */
