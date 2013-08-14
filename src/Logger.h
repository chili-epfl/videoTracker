/*
 * Logger.h
 *
 *  Created on: Aug 2, 2013
 *      Author: zufferey
 */

#ifndef LOGGER_H_
#define LOGGER_H_

#include <string>
#include <fstream>

namespace videoTracker {

class Logger {
public:
	Logger(const std::string &name);
	virtual ~Logger();

	bool isReady() const;
	void log(const std::string &txt);

	static std::string getFilename(const std::string &base,
			const std::string &directory = std::string());

private:
	std::string timestamp();

private:
	std::string m_filename;
	std::ofstream m_file;
};

}

#endif /* LOGGER_H_ */
