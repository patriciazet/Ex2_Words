#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>
#include <numeric>

int main()

{
    std::ifstream file("zdania.csv");

    if (!file.is_open())
    {
        std::cout << "Cannot open file.";
        return -1;
    }
    else
    {
        return 0;
    }

    std::string str;
    std::vector<std::string> text; 
    std::vector<int> vectSpaces;  
    int space = 0;

    while (std::getline(file, str))
    {
        text.push_back(str); 
        
        for (int i = 0; i <= str.length(); i++)
        {
            if (str[i] == ' ')
            {
                space++;
            }
        }
        int words = space + 1;

        vectSpaces.push_back(words);

        space = 0;
        words = 0;
    }
    file.close();

    
    auto maxElement = std::max_element(vectSpaces.begin(), vectSpaces.end()); 
    int longest = std::distance(vectSpaces.begin(), maxElement) + 1; 
    std::cout << "The longest sentence is: " << longest << std::endl;
    std::cout << text.at(longest) << std::endl << std::endl;

    
    auto minElement = std::min_element(vectSpaces.begin(), vectSpaces.end());
    int shortest = std::distance(vectSpaces.begin(), minElement) + 1;  
    std::cout << "The shortest sentence is: " << shortest << std::endl;
    std::cout << text.at(shortest) << std::endl << std::endl;

    
    int sumofWords = std::accumulate(vectSpaces.begin(), vectSpaces.end(), 0); 
    std::cout << "Sum of words is: " << sumofWords << std::endl;
}
