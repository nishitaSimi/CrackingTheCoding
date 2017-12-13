#include <iostream>
#include <string>
#include <vector>

bool determinePermutation(std::string str1, std::string str2)
{
    if(str1.empty() || str2.empty() || str1.length() != str2.length())
    {
        return false;
    }
    std::vector<int> keepTrack{256, 0};
    for(int i = 0; i < str1.length(); i++)
    {
        keepTrack[str1.at(i)]++;
    }
    for(int i = 0; i < str2.length(); i++)
    {
        keepTrack[str2.at(i)]++;
    }
    for(int i = 0 ; i < 256 ; i++)
    {
        if(keepTrack[i] % 2 != 0 )
        {
            return false;
        }
    }
    return true;
}
int main()
{
  std::string str1 = "Creation";
  std::string str2 = "ontiCare";
  if(determinePermutation(str1, str2))
  {
      std::cout << "Match Found ! \n ";
  }
  else
  {
    std::cout << "No Match \n";
  }
}
