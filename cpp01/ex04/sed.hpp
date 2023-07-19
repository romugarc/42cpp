#ifndef SED_H
# define SED_H

# include <iostream>
# include <fstream>

int	error_handler(int argc, char **argv);
int	error_fstream(std::ifstream &ifs, std::ofstream &ofs, std::string filename);

#endif