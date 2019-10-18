#include "iostream"
#include "vector"
#include "strtk.h"

/// string start here ///
namespace strtk
{
  //Find all locations of the delimiter in the string
  std::vector<int> find(std::string str, char delimiter)
  {
    std::vector<int> locations;

    for(int i = 0; i < str.size(); i++)
    {
      if(str[i] == delimiter)
      {
        locations.push_back(i);
      }
    }
    return locations;
  }

  //Get sub-string from location to location
  std::string getSubstring(std::string str, int from, int to)
  {
    if(str != "")
    {
      std::string tmp = "";
      for(int i = from; i < to; i++)
      {
        tmp += str[i];
      }
      return tmp;
    }
    return "";
  }

  std::string removeCharater(std::string str, char delemiter)
  {
    for(int i = 0; i<str.size(); i++)
    {
      if(str[i] == delemiter)
      {
        str.erase(i,1);
      }
    }
    return str;
  }

  //Split string by delimiter
  std::vector<std::string> split(std::string str, char delimiter)
  {
    std::vector<int> locations = strtk::find(str,delimiter); //Find all the delimiter locations
    std::vector<std::string> splitedStr;

    locations.insert(locations.begin(),0);  //Initial location
    locations.push_back(str.size());  //Last location

    //Get sub-string from locations vector
    for(int i = 0; i < locations.size()-1; i++)
    {
      std::string tmp = strtk::getSubstring(str,locations.at(i),locations.at(i+1));  //Get sub-string from the locations
      tmp = strtk::removeCharater(tmp,' ');  //Remove white-space
      splitedStr.push_back(tmp);  //Push splited string to vector
      std::cout << splitedStr.size();
    }
    return splitedStr;
  }
}
/// string end here ///

///Test area
/*int main()
{
  std::string str = "1 2 3 4 5";
  std::vector<int> whiteSpaceLocations = string::find(str,' ');
  std::vector<std::string> splitedStr = string::split(str,' ');

  std::cout << "Locations: ";
  for (int i = 0; i < whiteSpaceLocations.size(); i++) {
    std::cout << whiteSpaceLocations.at(i) << "\t";
  }

  std::cout << "\n\nStrings: \n";
  for (int i = 0; i < splitedStr.size(); i++) {
    std::cout << splitedStr.at(i) << '\n';
  }
  return 1;
}*/
