#include <iostream>

int main(int argc, char **argv)
{
	if (argc < 2)
		std::cout << "LOUD AND UNBEARABLE FEEDBACK NOISE" << std::endl;
	else
	{
		int	i = 1;
		int	j;

		while (argv[i] != NULL)
		{
			j = 0;
			while (argv[i][j] != '\0')
			{
				argv[i][j] = std::toupper(argv[i][j]);
				j++;
			}
			std::cout << argv[i];
			i++;
		}
		std::cout << std::endl;
	}
	return (0);
}