#include "Replace.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "Usage : ./replace <FileName> <StringToReplace> <StringToReplaceWith>" << std::endl;
		return (1);
	}

	Replace	Replace((std::string)argv[1], (std::string)argv[2], (std::string)argv[3]);

	// ! Check de dossier fait bug
	// https://stackoverflow.com/questions/29310166/check-if-a-fstream-is-either-a-file-or-directory
	// std::ifstream		ifs(this->_FileName);
	// This will set the fail bit if fileName is a directory (or do nothing if it is already set) 
	// ifs.seekg(0, std::ios::end);
	// if(!ifs.good())
	// {
	// 	ifs.close();
	// 	return (false);
	// }
	//
	if (Replace.RetrieveFileContent() == false)
	{
		std::cout << "File error encountered" << std::endl;
		return (-1);
	}
	Replace.ReplaceContent();
	Replace.PutContentIntoNewFile();
	
	return (0);
}