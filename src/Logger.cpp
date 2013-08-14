#include "Logger.h"
#include <chrono>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <ctime>

using namespace std;

namespace videoTracker {

Logger::Logger(const std::string &name) :
		m_filename(getFilename(name)), m_file(m_filename) {
}

Logger::~Logger() {
	cout << "Logger: closing file " << m_filename << "." << endl;
	m_file.close();
}

bool Logger::isReady() const {
	return m_file.is_open();
}

void Logger::log(const std::string &txt) {
	m_file << timestamp() << "," << txt << endl;
}

std::string Logger::getFilename(const std::string &base,
		const std::string &directory) {
	using namespace std::chrono;
	auto currentTime = std::chrono::system_clock::now();
	stringstream name;
	std::time_t now_c = system_clock::to_time_t(currentTime);
	auto time = localtime(&now_c);
	name << "resources/logs/";
	if (!directory.empty()) {
		name << directory << "/";
	}
	name << "2013" << time->tm_mon << time->tm_mday << "-" << time->tm_hour
			<< "-" << time->tm_min << "-" << time->tm_sec << "_" << base
			<< ".txt";
	return name.str();
}

std::string Logger::timestamp() {
	using namespace std::chrono;
	auto now = system_clock::now();
	std::time_t now_c = system_clock::to_time_t(now);
	auto time = localtime(&now_c);
	stringstream ts;
	// timestamp hh-mm-ss
	ts << time->tm_hour << "-" << time->tm_min << "-" << time->tm_sec;
	// timestamp ms since epoch
	auto duration = now.time_since_epoch();
	auto millis = duration_cast<milliseconds>(duration).count();
	ts << "," << millis;
	return ts.str();
}

}
