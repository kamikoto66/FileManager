#pragma once
#include <string>
#include <unordered_map>

class File;
using FileMgrMap = std::unordered_map<std::string, File*>;

class FileManager
{
	FileMgrMap *_Files;

public:
	FileManager();
	~FileManager();

	void Init();
	void Load(std::string filename);
	void SetData(std::string file, std::string tag, std::string value);
	std::string GetData(std::string file, std::string tag);
};

