#pragma once

#include <string>
#include <sstream>
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
	void splitString(const std::string &line, std::vector<std::string> &container, const char delim = ',');


};

// split string by delimiter and store to container
void ILoader::splitString(const std::string &line, std::vector<std::string> &container, const char delim) {
	std::istringstream iss(line);
	std::string str;
	
	while (std::getline(iss,str,delim)) {
		container.push_back(str);
	}
}


class FieldLoader : public ILoader {
public:
	FieldLoader() {}
	~FieldLoader() {}

	template <typename T>
	bool load(std::string filename, std::vector<T> &vec) override;

};

template <typename T>
bool FieldLoader::load(std::string filename, std::vector<T> &vec) {
	write
}

