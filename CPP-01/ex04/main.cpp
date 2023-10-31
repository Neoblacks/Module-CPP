/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:44:19 by amugnier          #+#    #+#             */
/*   Updated: 2023/10/31 16:00:14 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>

void	sedStr(std::string s1, std::string s2, std::ifstream& file, std::ofstream& file2)
{
	std::string line;

	int i;
	while (std::getline(file, line))
	{
		i = 0;
		while (i != -1)
		{
			i = line.find(s1, i);
			if (i != -1)
			{
				line.erase(i, s1.length());
				line.insert(i, s2);
				i += s2.length();
			}
		}
		file2 << line << std::endl;
	}
}


int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "usage : ./sed <filename> <string1> <string2>" << std::endl;
		return (1);
	}

	std::ifstream file(argv[1]); //input
	if (!file.is_open())
	{
		std::cout << "You cannot open this file: " << argv[1] << std::endl;
		return (1);
	}
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (s1.empty() || s2.empty())
	{
		std::cout << "Be careful you have one empty string" << std::endl;
		return (1);
	}

	std::string re_file_name = std::string(argv[1]) + ".replace";
	std::ofstream file2(re_file_name.c_str(), std::ios::trunc); //output
	if (!file2.is_open())
	{
		std::cout << "You cannot open this file: " << re_file_name << std::endl;
		return (1);
	}

	sedStr(s1, s2, file, file2);
	file.close();
	file2.close();
	return 0;
}
