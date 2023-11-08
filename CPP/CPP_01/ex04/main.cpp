// #include <iostream>
// #include <fstream>

// int main(int argc, char *argv[]) {
// 	if (argc != 4) {
// 		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
// 		return 1;
// 	}

// 	std::string filename = argv[1];
// 	std::string s1 = argv[2];
// 	std::string s2 = argv[3];

// 	if (s1.empty()) {
// 		std::cerr << "Error: s1 cannot be an empty string." << std::endl;
// 		return 1;
// 	}

// 	std::ifstream inputFile(filename.c_str());
// 	if (!inputFile) {
// 		std::cerr << "Error: Failed to open input file." << std::endl;
// 		return 1;

// 	}

// 	std::string outputFilename = filename + ".replace";
// 	std::ofstream outputFile(outputFilename.c_str());
// 	if (!outputFile) {
// 		std::cerr << "Error: Failed to create output file." << std::endl;
// 		return 1;
// 	}

// 	char c;
// 	while (inputFile.get(c)) {
// 		if (c == s1[0]) {
// 			size_t i = 1;
// 			for (; i < s1.size(); i++) {
// 				char nextChar;
// 				if (!inputFile.get(nextChar) || nextChar != s1[i]) {
// 					break;
// 				}
// 			}
// 			if (i == s1.size()) {
// 				outputFile << s2;
// 			} else {
// 				inputFile.seekg(-(long)i, std::ios::cur);
// 				outputFile << c;
// 			}
// 		} else {
// 			outputFile << c;
// 		}
// 	}

// 	inputFile.close();
// 	outputFile.close();

// 	std::cout << "Replacement complete. Output written to " << outputFilename << std::endl;
// 	return 0;
// }

#include <fstream>
#include <iostream>

int	replace(char **argv, std::string str)
{
	std::ofstream	outfile;
	int				pos;

	outfile.open((std::string(argv[1]) + ".replace").c_str());
	if (outfile.fail())
		return (1);
	for (int i = 0; i < (int)str.size(); i++)
	{
		pos = str.find(argv[2], i);
		if (pos != -1 && pos == i)
		{
			outfile << argv[3];
			i += std::string(argv[2]).size() - 1;
		}
		else
			outfile << str[i];
	}
	outfile.close();
	return (0);
}

int	main(int argc, char **argv)
{
	char			c;
	std::ifstream	infile;
	std::string		str;

	if (argc != 4)
	{
		std::cout << "usage: replace <file> old_word new_word" << std::endl;
		return (1);
	}
	infile.open(argv[1]);
	if (infile.fail())
	{
		std::cout << "Error: " << argv[1] << ":" << \
		" no such file or directory" << std::endl;
		return (1);
	}
	while(!infile.eof() && infile >> std::noskipws >> c)
		str += c;
	infile.close();
	return (replace(argv, str));
}
