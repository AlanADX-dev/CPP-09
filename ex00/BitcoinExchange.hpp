#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <vector>
#include <cstdlib>

class Btc
{
	private:
		std::map<std::string, float> data;
		int readFlag;

	protected:

	public:
		Btc();
		~Btc();
		Btc &operator=(Btc const &copy);
		Btc(Btc const &src);

		void setData(std::string date, float value);

		void readInput(std::string inputPath);

		std::map<std::string, float> getData();
		std::vector<std::string> splitString(std::string str, char delimiter);
};

#endif
