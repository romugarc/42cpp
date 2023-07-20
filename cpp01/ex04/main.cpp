#include "sed.hpp"

int	main(int argc, char **argv)
{
	if (error_handler(argc, argv) == 0)
	{
		std::ifstream	ifs(argv[1]);
		
		if (!ifs.is_open())
			return (error_notexist(ifs, argv[1]));
		
		std::string		newf = argv[1];
		std::ofstream	ofs(newf.append(".replace").c_str());
		std::string		reads;
		std::size_t		start;
		int				len;
		bool			done;

		if (!ofs.is_open())
			return (error_fstream(ifs, ofs, newf));
		len = std::char_traits<char>::length(argv[2]);
		while (ifs.eof() == false)
		{
			std::getline(ifs, reads);
			done = false;
			while (!done)
			{
				start = reads.find(argv[2]);
				if (start != std::string::npos)
				{
					reads.erase(start, len);
					reads.insert(start, argv[3]);
				}
				else
					done = true;
			}
			ofs << reads << std::endl;
		}
		ifs.close();
		ofs.flush();
		ofs.close();
	}
	else
		std::cout << "Bad arguments" << std::endl;
	return (0);
}