#include "Replace.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "Usage : ./replace <FileName> <StringToReplace> <StringToReplaceWith>" << std::endl;
		return (1);
	}

	Replace	Replace((std::string)argv[1], (std::string)argv[2], (std::string)argv[3]);

	if (Replace.RetrieveFileContent() == false)
	{
		std::cout << "Error with the file" << std::endl;
		return (-1);
	}
	Replace.PutContentIntoNewFile();
	return (0);
}