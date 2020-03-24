#include "PhoneticFinder.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>  
#include <stdexcept>

#include <string>
using namespace std;
namespace phonetic
{
 /*
 The split function was taken from https://www.quora.com/How-do-I-split-a-string-by-space-into-an-array-in-c++
 */
vector<string> split(string str, char delimiter) {
  vector<string> internal;
  stringstream ss(str); // Turn the string into a stream.
  string tok;
 
  while(getline(ss, tok, delimiter)) {
    internal.push_back(tok);
  }
 
  return internal;
}

string findWord(string s, string toFind)
{
    	string ans = "";
    	int i;
    for (i = 0; i < toFind.length(); i++)
    {
        if(toFind[i] == ' ')
        {
            throw std::invalid_argument("Nice try; That's not a word dummy ;)");
        }
    }
    if(s.length() == toFind.length())
    {
        if(s.compare(toFind)==0)
        {
            ans = s + " ";
        }
        else
        {
            for (i = 0; i < toFind.size(); i++)
            {
                if(((s[i] == 'v' || s[i] == 'V') && (toFind[i] == 'w' || toFind[i] == 'W')) ||
                    ((toFind[i] == 'v' || toFind[i] == 'V') && (s[i] == 'w' || s[i] == 'W')))
                {   //v or w case
                    ans = s + " ";
    
                }
                if(((s[i] == 'b' || s[i] == 'B') && (toFind[i] == 'f' || toFind[i] == 'F')) ||
                    ((toFind[i] == 'b' || toFind[i] == 'B') && (s[i] == 'f' || s[i] == 'F')) ||
                    ((s[i] == 'p' || s[i] == 'P') && (toFind[i] == 'f' || toFind[i] == 'F')) ||
                    ((toFind[i] == 'p' || toFind[i] == 'P') && (s[i] == 'f' || s[i] == 'F')) ||
                    ((s[i] == 'b' || s[i] == 'B') && (toFind[i] == 'f' || toFind[i] == 'F')) ||
                    ((toFind[i] == 'f' || toFind[i] == 'F') && (s[i] == 'b' || s[i] == 'B')))

                {   //b or f or p case
                    ans = s + " ";
    
                } 
                if(((s[i] == 'g' || s[i] == 'G') && (toFind[i] == 'j' || toFind[i] == 'J')) ||
                    ((toFind[i] == 'g' || toFind[i] == 'G') && (s[i] == 'j' || s[i] == 'J')))
                {   //g or j case
                    ans = s + " ";
    
                    
                } 
                if(((s[i] == 'c' || s[i] == 'C') && (toFind[i] == 'k' || toFind[i] == 'K')) ||
                    ((toFind[i] == 'c' || toFind[i] == 'C') && (s[i] == 'k' || s[i] == 'K')) ||
                    ((s[i] == 'k' || s[i] == 'K') && (toFind[i] == 'q' || toFind[i] == 'Q')) ||
                    ((toFind[i] == 'k' || toFind[i] == 'K') && (s[i] == 'q' || s[i] == 'Q')) ||
                    ((s[i] == 'c' || s[i] == 'C') && (toFind[i] == 'q' || toFind[i] == 'Q')) ||
                    ((toFind[i] == 'c' || toFind[i] == 'c') && (s[i] == 'q' || s[i] == 'Q')))

                {   //c or k or q case
                    ans = s + " ";
    
                    
                }
                if(((s[i] == 's' || s[i] == 'S') && (toFind[i] == 'z' || toFind[i] == 'Z')) ||
                    ((toFind[i] == 's' || toFind[i] == 'S') && (s[i] == 'z' || s[i] == 'Z')))
                {   //s or z case
                    ans = s + " ";
    
                    
                }
                if(((s[i] == 'd' || s[i] == 'D') && (toFind[i] == 't' || toFind[i] == 'T')) ||
                    ((toFind[i] == 'd' || toFind[i] == 'D') && (s[i] == 't' || s[i] == 'T')))
                {   //d or t case
                    ans = s + " ";
    
                    
                }
                if(((s[i] == 'o' || s[i] == 'O') && (toFind[i] == 'u' || toFind[i] == 'U')) ||
                    ((toFind[i] == 'o' || toFind[i] == 'O') && (s[i] == 'u' || s[i] == 'U')))
                {   //o or u case
                    ans = s + " ";
    
                    
                }
                if(((s[i] == 'i' || s[i] == 'I') && (toFind[i] == 'y' || toFind[i] == 'Y')) ||
                    ((toFind[i] == 'i' || toFind[i] == 'I') && (s[i] == 'y' || s[i] == 'Y')))
                {   //i or y case
                    ans = s + " ";
                    
                    
                }
                
            }
        }

        
    }    
    return ans;


}

		string find(string s,string toFind)
		{
    	string ans = "";
    	vector<string> sep = split(s, ' ');
    	int i, length = sep.size();
    	int count = 0,none = 0;
    	string if_many_words[length];
    	for (i = 0; i < length; i++)
    	{
        	if(toFind.size() == sep[i].size())
        	{
            	ans += findWord(sep[i],toFind);
            	if_many_words[count] = sep[i];
            	count++;
        	}
        	else
        	{
            	none++;
        	}
            	
            	
    	}
    	if(count>0)
    	{
        	return if_many_words[0];
    	}
    	if (none == sep.size())
    	{
        	throw std::invalid_argument("The word haven't been found");
    	}
    	else
    	{
        	return ans;
    	}
    	
	}

}
