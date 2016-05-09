#include <iostream>
#include <sstream>

using namespace std;

const int CURSOR_MAX_LENGTH = 10;
const int REFER_MAX_LENGTH = 10000;

/**
	ACM 5 C++
	@author wangk
**/
int main2() {

	int count;
	cin >> count;

	while (count-- > 0) {
		string strCursor;
		string strRefer;
		cin >> strCursor;
		cin >> strRefer;
		int cursorLength = strCursor.length();
		int referlength = strRefer.length();
		if (cursorLength > CURSOR_MAX_LENGTH) {
			strCursor.substr(0, CURSOR_MAX_LENGTH);
		}
		if (referlength > REFER_MAX_LENGTH) {
			strRefer.substr(0,REFER_MAX_LENGTH);
		}

		int showCount = 0;
		int tempCount = 0;
		for (size_t i = 0; i < referlength; i++)
		{
		
			if (i >= cursorLength-1 && strRefer.at(i) == strCursor.at(cursorLength - 1)) {
				bool flag = true;
				for (size_t j = 0; j < cursorLength; j++)
				{
					if (strRefer.at(i-cursorLength+j+1) != strCursor.at(j)) {
						flag = false;
						break;
					}
				}
				if (flag) {
					showCount++;
				}
			}
		}
		cout << showCount << endl;
		
	}
	return 0;
}