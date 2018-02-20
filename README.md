# FileManager

FileManager in C++ programming language.

Usage example
-------------
<pre><code>
#include <iostream>
#include "FileManager.h"

using namespace std;

int main()
{
	FileManager fm;
	fm.Init();
	fm.Load("Data");
	fm.Load("Test");

	fm.SetData("Data", "Data", std::to_string(150));
	fm.SetData("Data", "Score", std::to_string(150));

	//cout << fm.GetData("Data", "Data") << endl;
	//cout << fm.GetData("Data", "Score") << endl;

    return 0;
}
</code></pre>

