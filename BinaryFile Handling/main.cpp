/*
하나의 파일과 분할 크기를 입력받아 그 크기만큼 파일을 분할하는 코드
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main() {
	string fileName;
	int fileSize;
	cout << "Input file name" << endl;
	cin >> fileName;
	cout << "file size" << endl;
	cin >> fileSize;
	ifstream inputFile(fileName,ios::binary);
	inputFile.seekg(0, ios::end);
	long totalSize = inputFile.tellg();
	inputFile.seekg(0, ios::beg);
	for (int i = 0; i*fileSize <= totalSize;i++) {
		char *buffer = new char[fileSize];
		string temp;
		temp.push_back(i+48);
		temp.append(".txt");
		ofstream divideFile(temp, ios::binary);
		int size = fileSize;
		if ((i+1)*fileSize>totalSize) {
			size = totalSize - i*fileSize;
		}
		inputFile.read(buffer, size);
		divideFile.write(buffer, size);
		inputFile.seekg((i+1)*fileSize);
		delete[] buffer;
		divideFile.close();
	}
	inputFile.close();
	return 0;
}