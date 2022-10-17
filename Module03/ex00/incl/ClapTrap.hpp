class ClapTrap
{
private:
	/* data */
public:
	ClapTrap();
	ClapTrap(ClapTrap const & src);
	~ClapTrap();

	ClapTrap & operator=(ClapTrap const & rhs);
};

ClapTrap::ClapTrap(/* args */)
{
}

ClapTrap::~ClapTrap()
{
}
