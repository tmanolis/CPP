#include "Replace.hpp"

/**
 * @brief Check if the FileName given in argument is a directory
 * 
 * This will set the fail bit if fileName is a directory,
 * (or do nothing if it is already set.
 * 
 * @return true if it is a directory and false if it's not.
 * 
 * Useful link : 
 * https://stackoverflow.com/questions/29310166/check-if-a-fstream-is-either-a-file-or-directory
 */

bool	is_a_directory(std::string FileName)
{
	std::ifstream	ifs(FileName);
  	
	ifs.seekg(0, std::ios::end);
	if (!ifs.good())
	{
		ifs.close();
		return (true);
	}
	ifs.close();
	return (false);
}

int	check_args(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "Usage : ./replace <FileName> <StringToReplace> <StringToReplaceWith>" << std::endl;
		return (1);
	}
	if (is_a_directory(argv[1]) == true)
	{
		std::cout << "FileName is a directory" << std::endl;
		return (1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	if (check_args(argc, argv))
		return (1);
	
	Replace	Replace((std::string)argv[1], (std::string)argv[2], (std::string)argv[3]);

	if (Replace.RetrieveFileContent() == false)
	{
		std::cout << "File error encountered" << std::endl;
		return (1);
	}
	Replace.ReplaceContent();
	Replace.PutContentIntoNewFile();

	return (0);
}