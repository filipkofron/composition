TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp CacheBounded.h IBounded.h particle.cpp particle.h vec3.cpp vec3.h block.cpp block.h box.cpp box.h CacheBounded.cpp

QMAKE_CXXFLAGS += -std=c++11
