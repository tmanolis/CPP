#include "Replace.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "Usage : ./replace <FileName> <StringToReplace> <StringToReplaceWith>" << std::endl;
		return (1);
	}
	
	Replace	Replace(argv[1], (std::string)argv[2], (std::string)argv[3]);

	if (Replace.RetrieveFileContent() == false)
	{
		std::cout << "File error encountered" << std::endl;
		return (1);
	}
	Replace.ReplaceContent();
	Replace.PutContentIntoNewFile();

	return (0);
}