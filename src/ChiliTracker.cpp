/*
 * ChiliTracker.cpp
 *
 *  Created on: Aug 5, 2013
 *      Author: zufferey
 */

#include "ChiliTracker.h"
#include <chilitags/DetectChilitags.hpp>
#include <chilitags/Chilitag.hpp>

using namespace std;

namespace videoTracker {

ChiliTracker::ChiliTracker(float width, float height) :
		m_frame(width, height, CV_8UC1), m_img(new IplImage(m_frame)), m_tracker(
				new chilitags::DetectChilitags(&m_img)) {
}

ChiliTracker::~ChiliTracker() {
}

tagEvents_t ChiliTracker::track(const cv::Mat &frame) {
	tagEvents_t events;
	frame.copyTo(m_frame);
	*m_img = frame;
	m_tracker->update();
	for (int tagId = 0; tagId < 1024; ++tagId) {
		chilitags::Chilitag tag(tagId);
		if (tag.isPresent()) {
			cout << "Detected tag: " << tagId << endl;
			chilitags::Quad corners = tag.getCorners();
			tagData_t data(tagId);
			data.detected = true;
			data.p0 = pt2f(corners[0].x,corners[0].y);
			data.p1 = pt2f(corners[1].x,corners[1].y);
			events.detected.push_back(data);
		}
	}

	return events;
}

} /* namespace videoTracker */
