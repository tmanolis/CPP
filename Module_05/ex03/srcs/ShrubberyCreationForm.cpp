#include "ShrubberyCreationForm.hpp"

static void	writeTrees(std::string name)
{
	std::string	FileName = name + "_shrubbery";
	std::ofstream ofs(FileName.c_str());

	if (ofs.fail())
	{
		std::cout << "File Error Occured" << std::endl;
		return ;
	}
	ofs << "				,@@@@@@@," << std::endl;
	ofs << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
	ofs << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o"<< std::endl;
	ofs << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
	ofs << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'"<< std::endl;
	ofs << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
	ofs << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
	ofs << "       |o|        | |         | |" << std::endl;
	ofs << "       |.|        | |         | |"<< std::endl;
	ofs << "_\\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_"  << std::endl;
	
	ofs.close();
}

/* Constructors & Destructor */

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137), _Target("Default")
{
	std::cout << "[ShrubberyCreationForm] Default Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : Form(src)
{
	std::cout << "[ShrubberyCreationForm] Copy Constructor called" << std::endl;
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "[ShrubberyCreationForm] Destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137), _Target(target)
{
	std::cout << "[ShrubberyCreationForm] Parametric Constructor called" << std::endl;
}

/* Operator Overload */

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	if (this != &rhs)
		this->_Target = rhs.getTarget();
	return (*this);
}

/* Accessors */

std::string	ShrubberyCreationForm::getTarget() const
{
	return (this->_Target);
}

/* Public Member Functions */

void	ShrubberyCreationForm::execute() const
{
	writeTrees(this->_Target);
}
