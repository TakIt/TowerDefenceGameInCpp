#pragma once

#include <string>
#include <vector>
#include <fstream>


class ILoader {
public:
	ILoader() {}
	virtual ~ILoader() {}

	template <typename T>
	virtual bool load(std::string filename, std::vector<T> &vec) = 0;

protected:
	// split string by delimiter and store to container
	void splitString(const std::string &line, std::vector<std::string> &container, const char delimiter = ',');


};

// split string by delimiter and store to container
void ILoader::splitString(const std::string &line, std::vector<std::string> &container, const char delimiter) {
	
	while (true) {

	}

}

