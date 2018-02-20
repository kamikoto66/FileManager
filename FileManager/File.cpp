#include "File.h"

File::File()
{
}

File::~File()
{
	m_data->clear();
	delete m_data;
}

void File::Load(std::string FileName)
{
	m_data = new FileMap();
	m_FileName = FileName;

	std::string path = FilePath;
	path.append(m_FileName.c_str());
	path.append(".txt");
	
	m_InputStream.open(path.c_str());

	if (m_InputStream.is_open())
	{
		std::string dataline;
		std::string tempdata;
		std::vector<std::string> datas;

		//���� ���� �ƴϸ� �ݺ�
		while (!m_InputStream.eof())
		{
			std::getline(m_InputStream, dataline);

			//������ �ƴϸ�
			if (dataline != "")
			{
				std::stringstream ss;
				ss.str(dataline);

				//���鱸���ؼ� �־���
				while (ss >> tempdata)
				{
					datas.push_back(tempdata);
				}

				m_data->insert(std::make_pair(datas[0], datas[1]));
				//�ʿ� �־����� �ʱ�ȭ
				datas.clear();
			}
		}
	}

}

void File::SetData(std::string tag, std::string value)
{
	auto data = m_data->find(tag);
	//���� ������ ��������
	if (data != m_data->end())
	{
		data->second = value;
	}
	//������ ���θ��� �־���
	else
	{
		m_data->insert(std::make_pair(tag, value));
	}
}

void File::Save()
{
	std::string path = FilePath;
	path.append(m_FileName.c_str());
	path.append(".txt");

	m_OutputStream.open(path.c_str());

	//������ ��� ���θ��� ����
	if (m_OutputStream.is_open())
	{
		for (auto data : *m_data)
		{
			std::string datastring;
			datastring.append(data.first);
			datastring.append("\t");
			datastring.append(data.second);

			m_OutputStream << datastring << "\n";
		}
	}
}

std::string File::GetData(std::string tag, std::string& t)
{
	auto data = m_data->find(tag);

	if (data != m_data->end())
	{
		t = data->second;
	}

	return t;
}