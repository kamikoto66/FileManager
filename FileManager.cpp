#include "FileManager.h"
#include "File.h"

FileManager::FileManager()
{
}

FileManager::~FileManager()
{
	for (auto file : *_Files)
	{
		file.second->Save();
	}
	_Files->clear();
	delete _Files;
}

void FileManager::Init()
{
	_Files = new FileMgrMap();
}

void FileManager::Load(std::string filename)
{
	File* file = new File();
	file->Load(filename);
	_Files->insert(std::make_pair(file->GetFileName(), file));
}

void FileManager::SetData(std::string file, std::string tag, std::string value)
{
	auto data = _Files->find(file);

	if (data != _Files->end())
	{
		data->second->SetData(tag, value);
	}
}

std::string FileManager::GetData(std::string file, std::string tag)
{
	std::string returndata = "";
	auto data = _Files->find(file);

	if (data != _Files->end())
	{
		data->second->GetData(tag, returndata);
	}

	return returndata;
}
