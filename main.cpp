// FileManager.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include <iostream>
#include "FileManager.h"

using namespace std;

int main()
{
	FileManager fm;
	fm.Init();
	fm.Load("Data1");
	//fm.Load("Test");

	//fm.SetData("Data", "Data", std::to_string(150));
	//fm.SetData("Data", "Score", std::to_string(150));
	//fm.SetData("Test", "Score", std::to_string(150));

	//cout << fm.GetData("Data", "Data").c_str() << endl;
	//cout << fm.GetData("Data", "Score") << endl;

    return 0;
}