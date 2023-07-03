/*
//#1
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;
using std::uint32_t;

struct File
{
	string name;
	uint32_t size;
};

struct Directory
{
public:
	vector<shared_ptr<File>> files;
	vector<shared_ptr<Directory>> directories;
	string name;
	shared_ptr<Directory> parent;

	uint32_t getFileSize()
	{
		uint32_t result = 0;
		for (auto file : files)
		{
			result += file->size;
		}

		for (auto dir : directories)
		{
			result += dir->getFileSize();
		}

		return result;
	}

	bool directoryExists(std::string& name) {
		for (auto dir : directories) {
			if (dir->name == name)
				return true;
		}
		return false;
	};

	std::shared_ptr<Directory> getDirectory(std::string& name) {
		for (auto dir : directories) {
			if (dir->name == name)
				return dir;
		}

		return nullptr;
	};

	Directory(string name, shared_ptr<Directory> parent = nullptr) : name(name), parent(parent) {};

	friend bool operator<(Directory& lhs, Directory& rhs)
	{
		return lhs.getFileSize() < rhs.getFileSize();
	}

	friend bool operator>(Directory& lhs, Directory& rhs)
	{
		return rhs < lhs;
	}

	friend bool operator<=(Directory& lhs, Directory& rhs)
	{
		return !(lhs > rhs);
	}

	friend bool operator>=(Directory& lhs, Directory& rhs)
	{
		return !(lhs < rhs);
	}
};

Directory root("root", nullptr);

shared_ptr<Directory> current(&root);

void processCommand(std::string& cmd)
{
	stringstream ss(cmd);
	string input;
	ss.ignore(2, ' ');
	bool change = false;
	while (getline(ss, input, ' '))
	{
		if (input == "ls")
			break;

		if (!change && input == "cd")
		{
			change = true;
			continue;
		}


		if (input == "..")
			current = current->parent;
		else
			if (current->directoryExists(input))
				current = current->getDirectory(input);
	}
}

void createFile(string& name, uint32_t size)
{
	auto file = shared_ptr<File>(new File);
	file->name = name;
	file->size = size;
	current->files.push_back(file);
}

void createDirectory(string& name)
{
	auto dir = shared_ptr<Directory>(new Directory(name, current));
	current->directories.push_back(dir);
}

void checkDirectorySize(shared_ptr<Directory> directory, vector<shared_ptr<Directory>>& list, uint32_t maxSize = 100000)
{
	if (directory->getFileSize() <= maxSize)
	{
		list.push_back(directory);
	}

	for (auto dir : directory->directories)
	{
		checkDirectorySize(dir, list, maxSize);
	}
}

void compareDirectorySize(shared_ptr<Directory> dir, uint32_t& current, uint32_t requiredSpace = 100000)
{
	if (dir->getFileSize() >= requiredSpace)
		if (dir->getFileSize() < current)
			current = dir->getFileSize();

	for (auto dir : dir->directories)
		compareDirectorySize(dir, current, requiredSpace);
}

int main()
{
	ifstream o("AdventOfCode//2022//File_txt//07-12-2022.txt");

	std::string str;
	uint32_t counter = 0;

	o.ignore(LONG_MAX, '\n');

	while (std::getline(o, str))
	{
		std::stringstream lineReader(str);
		std::string token;

		bool isName = false;
		bool isDir = false;
		uint32_t fileSize = 0;

		while (std::getline(lineReader, token, ' '))
		{
			if (token == "$")
			{
				processCommand(str);
				break;
			}

			if (isName)
			{
				if (isDir)
					createDirectory(token);
				else
					createFile(token, fileSize);

				break;
			}

			if (!isName && token == "dir")
			{
				isName = isDir = true;
				continue;
			}

			fileSize = static_cast<uint32_t>(std::stoul(token));
			isName = true;
		}
	}

	o.close();

	uint32_t maxSize = 100000;

	std::vector<std::shared_ptr<Directory>> criterion;
	auto base = std::make_shared<Directory>(root);
	checkDirectorySize(base, criterion, maxSize);

	uint32_t result = 0;
	for (auto dir : criterion)
	{
		result += dir->getFileSize();
	}

	cout << result << endl;

	system("PAUSE");
	return 0;
}
*/



/*
//#2
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;
using std::uint32_t;

struct File
{
	string name;
	uint32_t size;
};

struct Directory
{
public:
	vector<shared_ptr<File>> files;
	vector<shared_ptr<Directory>> directories;
	string name;
	shared_ptr<Directory> parent;

	uint32_t getFileSize()
	{
		uint32_t result = 0;
		for (auto file : files)
		{
			result += file->size;
		}

		for (auto dir : directories)
		{
			result += dir->getFileSize();
		}

		return result;
	}

	bool directoryExists(std::string& name) {
		for (auto dir : directories) {
			if (dir->name == name)
				return true;
		}
		return false;
	};

	std::shared_ptr<Directory> getDirectory(std::string& name) {
		for (auto dir : directories) {
			if (dir->name == name)
				return dir;
		}

		return nullptr;
	};

	Directory(string name, shared_ptr<Directory> parent = nullptr) : name(name), parent(parent) {};

	friend bool operator<(Directory& lhs, Directory& rhs)
	{
		return lhs.getFileSize() < rhs.getFileSize();
	}

	friend bool operator>(Directory& lhs, Directory& rhs)
	{
		return rhs < lhs;
	}

	friend bool operator<=(Directory& lhs, Directory& rhs)
	{
		return !(lhs > rhs);
	}

	friend bool operator>=(Directory& lhs, Directory& rhs)
	{
		return !(lhs < rhs);
	}
};

Directory root("root", nullptr);

shared_ptr<Directory> current(&root);

void processCommand(std::string& cmd)
{
	stringstream ss(cmd);
	string input;
	ss.ignore(2, ' ');
	bool change = false;
	while (getline(ss, input, ' '))
	{
		if (input == "ls")
			break;

		if (!change && input == "cd")
		{
			change = true;
			continue;
		}


		if (input == "..")
			current = current->parent;
		else
			if (current->directoryExists(input))
				current = current->getDirectory(input);
	}
}

void createFile(string& name, uint32_t size)
{
	auto file = shared_ptr<File>(new File);
	file->name = name;
	file->size = size;
	current->files.push_back(file);
}

void createDirectory(string& name)
{
	auto dir = shared_ptr<Directory>(new Directory(name, current));
	current->directories.push_back(dir);
}

void checkDirectorySize(shared_ptr<Directory> directory, vector<shared_ptr<Directory>>& list, uint32_t maxSize = 100000)
{
	if (directory->getFileSize() <= maxSize)
	{
		list.push_back(directory);
	}

	for (auto dir : directory->directories)
	{
		checkDirectorySize(dir, list, maxSize);
	}
}

void checkDirectorySize1(shared_ptr<Directory> directory, vector<shared_ptr<Directory>>& list, uint32_t minSize)
{
	if (directory->getFileSize() >= minSize)
	{
		list.push_back(directory);
	}

	for (auto dir : directory->directories)
	{
		checkDirectorySize1(dir, list, minSize);
	}
}

void compareDirectorySize(shared_ptr<Directory> dir, uint32_t& current, uint32_t requiredSpace = 100000)
{
	if (dir->getFileSize() >= requiredSpace)
		if (dir->getFileSize() < current)
			current = dir->getFileSize();

	for (auto dir : dir->directories)
		compareDirectorySize(dir, current, requiredSpace);
}

int main()
{
	ifstream o("AdventOfCode//2022//File_txt//07-12-2022.txt");

	std::string str;
	uint32_t counter = 0;

	o.ignore(LONG_MAX, '\n');

	while (std::getline(o, str))
	{
		std::stringstream lineReader(str);
		std::string token;

		bool isName = false;
		bool isDir = false;
		uint32_t fileSize = 0;

		while (std::getline(lineReader, token, ' '))
		{
			if (token == "$")
			{
				processCommand(str);
				break;
			}

			if (isName)
			{
				if (isDir)
					createDirectory(token);
				else
					createFile(token, fileSize);

				break;
			}

			if (!isName && token == "dir")
			{
				isName = isDir = true;
				continue;
			}

			fileSize = static_cast<uint32_t>(std::stoul(token));
			isName = true;
		}
	}

	o.close();

	uint32_t size = 70000000;

	std::vector<std::shared_ptr<Directory>> criterion;
	auto base = std::make_shared<Directory>(root);
	checkDirectorySize(base, criterion, size);

	uint32_t space = size - criterion[0]->getFileSize();
	uint32_t requiredSpace = 30000000;
	uint32_t needDeleted = requiredSpace - space;
	criterion.clear();
	checkDirectorySize1(base, criterion, needDeleted);

	uint32_t result = criterion[0]->getFileSize();
	for (auto dir : criterion)
	{
		if(dir->getFileSize() < result)
			result = dir->getFileSize();
	}

	cout << result << endl;

	system("PAUSE");
	return 0;
}
*/