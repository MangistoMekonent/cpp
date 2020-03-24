#ifndef _PHONETICFINDER_HPP_
#define _PHONETICFINDER_HPP_
#include <cstring>
#include <string>
#include <vector>
using namespace std;	
namespace phonetic
{
	vector<string> split(string str, char delimiter);
	string findWord(string s, string toFind);
	string find(string s, string toFind);
	
}

#endif


