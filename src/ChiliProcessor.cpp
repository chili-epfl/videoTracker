/*
 * ChiliProcessor.cpp
 *
 *  Created on: Aug 5, 2013
 *      Author: zufferey
 */

#include "ChiliProcessor.h"
#include "VideoReader.h"
#include "ChiliTracker.h"
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

namespace videoTracker {

ChiliProcessor::ChiliProcessor() :
		m_windowName("chiliTracker") {
	cv::namedWindow(m_windowName, 0);
}

ChiliProcessor::~ChiliProcessor() {
}

void ChiliProcessor::process(VideoReader &reader, ChiliTracker &tracker) {
	cv::Mat frame, grayFrame;
	int frameNumber = 0;
	while (reader.read(frame)) {
		cv::cvtColor(frame, grayFrame, CV_RGB2GRAY);
		auto events = tracker.track(grayFrame);
		if (!events.added.empty()) {
			cout << "Frame: " << frameNumber << endl;
			for (const auto &tag : events.added) {
				cout << "-> tag " << tag.id << endl;	
			}
		}
		drawTags(events, frame);
		cv::imshow(m_windowName, frame);
		cv::waitKey(10);
		frameNumber++;
	}
}

void ChiliProcessor::drawTags(const tagEvents_t &events, cv::Mat &frame) {
	for (const auto &tag : events.detected) {
		drawTag(tag, frame);
	}
}

void ChiliProcessor::drawTag(const tagData_t &tag, cv::Mat &frame) {
	cv::line(frame, cv::Point2f(tag.p0.x, tag.p0.y),
			cv::Point2f(tag.p1.x, tag.p1.y), CV_RGB(0,255,0), 5);
}

} /* namespace videoTracker */
