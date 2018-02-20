#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <unordered_map>

const std::string FilePath = "Resource\\Data\\";

using FileMap = std::unordered_map<std::string, std::string>;

class File
{
	FileMap *m_data;
	std::string m_FileName;
	std::ifstream m_InputStream;
	std::ofstream m_OutputStream;

public:
	File();
	~File();

	void Load(std::string FileName);
	void SetData(std::string tag, std::string value);
	void Save();

	std::string GetData(std::string tag, std::string& t);
	std::string GetFileName() const { return m_FileName; }
};

