/*
 * VideoTracker.h
 *
 *  Created on: Aug 5, 2013
 *      Author: zufferey
 */

#ifndef VIDEOTRACKER_H_
#define VIDEOTRACKER_H_

#include <string>
#include <vector>
#include <map>

namespace videoTracker {

class VideoTracker {
public:
	VideoTracker(const std::string &prefix);
	virtual ~VideoTracker();

	void init();
	void process();

private:
	void processFile(const std::string &file);

private:
	struct tagsData_t {
		std::string type;
		std::string family;
		std::vector<int> ids;
		tagsData_t(const std::string &_type, const std::string &_family) :
				type(_type), family(_family) {
		}
	};
	std::string m_prefix;
	std::vector<std::string> m_videoFiles;
	std::map<std::string, tagsData_t> m_tags; // firts string is the type
};

} /* namespace warehouse */
#endif /* VIDEOTRACKER_H_ */
