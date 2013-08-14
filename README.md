videoTracker
============

A c++ application tracking Chilitags in a .avi video and logging their position at each frame. Used as a post-analysis tool for an eye-tracking experiment.

Dependencies
-------------
- Chilitags (https://github.com/chili-epfl/chilitag)
- OpenCV 2
- libconfig++

Build
----
	mkdir build && cd build
	cmake ../src
	make
	
The executable is placed in the bin directory.
You can set the videos to read in the bin/config/config.cfg configuration file.
