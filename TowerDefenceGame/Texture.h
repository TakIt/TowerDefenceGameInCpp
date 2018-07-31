#pragma once

#include <map>
#include <string>

#include "DxLib.h"

class Texture final {
public:
	Texture() {}
	~Texture() {}

	bool pool(const std::string filename) {
		int handle = LoadGraph(filename.c_str());
		if (handle == -1)return false;
		
		dictionary.insert(std::make_pair(filename, handle));
		return true;
	}
	bool deleteHandle(const std::string filename) {
		if (DeleteGraph(dictionary[filename]) == -1)return false;
		return true;
	}
	int getHandle(const std::string filename) {
		return dictionary[filename];
	}
	
private:
	std::map<std::string,int> dictionary;


};