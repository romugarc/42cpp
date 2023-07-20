#include "sed.hpp"

int	error_handler(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 4)
	{
		while (i < 4)
		{
			if (argv[i] != NULL)
			{
				if (argv[i][0] == '\0')
					return (1);
			}
			else
				return (1);
			i++;
		}
	}
	else
		return (1);
	return (0);
}

int	error_notexist(std::ifstream &ifs, std::string filename)
{
	ifs.close();
	std::cout << "File " << filename << " does not exit" << std::endl;
	return (1);
}

int	error_fstream(std::ifstream &ifs, std::ofstream &ofs, std::string filename)
{
	ifs.close();
	ofs.flush();
	ofs.close();
	std::cout << "Could not open file: " << filename << std::endl;
	return (1);
}