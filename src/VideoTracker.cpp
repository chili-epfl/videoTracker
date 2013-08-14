/*
 * VideoTracker.cpp
 *
 *  Created on: Aug 5, 2013
 *      Author: zufferey
 */

#include "VideoTracker.h"
#include "VideoReader.h"
#include "ChiliTracker.h"
#include "ChiliProcessor.h"
#include <libconfig.h++>
#include <iostream>

using namespace std;
using namespace libconfig;

namespace videoTracker {

VideoTracker::VideoTracker(const std::string &prefix) :
		m_prefix(prefix) {
}

VideoTracker::~VideoTracker() {
}

void VideoTracker::init() {
	Config config;
	string file = string(m_prefix).append("config.cfg");
	config.readFile(file.c_str());

	// video files
	Setting &videoFiles = config.lookup("files");
	int nFiles = videoFiles.getLength();
	for (int i = 0; i < nFiles; ++i) {
		m_videoFiles.push_back(videoFiles[i]);
	}

	// tags
	Setting &tags = config.lookup("tags");
	int nGroups = tags.getLength();
	for (int i = 0; i < nGroups; ++i) {
		Setting &group = tags[i];
		tagsData_t data(group["type"], group["family"]);
		if (group.exists("id_range")) {
			Setting &ids = group["id_range"];
			for (int i = (int) ids[0]; i < (int) ids[1]; ++i) {
				data.ids.push_back(i);
			}
		} else {
			Setting &ids = group["ids"];
			for (int i = 0; i < ids.getLength(); ++i) {
				data.ids.push_back(ids[i]);
			}
		}
		string type = group["type"];
		m_tags.insert(make_pair(type, data));
	}
}

void VideoTracker::process() {
	for (const auto &file : m_videoFiles) {
		cout << "Processing file " << file << endl;
		processFile(file);
	}
}

void VideoTracker::processFile(const std::string &file) {
	VideoReader reader(file);
	if (reader.isReady()) {
		cout << "Video opened: " << file << endl;
		cout << "Video size: " << reader.width() << " " << reader.height()
				<< endl;
		float width = reader.width();
		float height = reader.height();
		// chilitags
		ChiliTracker tracker(width, height);
		ChiliProcessor processor;
		processor.process(reader,tracker);
	} else {
		cout << "WARNING: Failed to open video: " << file << endl;
	}
}

} /* namespace warehouse */
