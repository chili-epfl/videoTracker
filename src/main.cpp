#include "VideoTracker.h"

int main(int argc, char *argv[]) {
	videoTracker::VideoTracker tracker("config/");
	tracker.init();
	tracker.process();
}
