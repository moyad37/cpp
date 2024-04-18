#include "Replace.hpp"


void Replace::processFiles(const std::string& inputFileName, const std::string& outputFileName, const std::string& s1, const std::string& s2) {
    std::ifstream inputFile(inputFileName.c_str());

    if (!inputFile.is_open()) {
        std::cerr << "Error: cannot open input file: " << inputFileName << std::endl;
        inputFile.close();
        exit(1);
    }
    std::ofstream outputFile(outputFileName.c_str());
    if (!outputFile.is_open()) {
        std::cerr << "Error: cannot open output file: " << outputFileName << std::endl;
        outputFile.close();
        exit(1);
    }
    // if(!inputFile.is_open() || !outputFile.is_open())
    // {
    //     inputFile.close();
    //     outputFile.close();
    //     exit(1);
    // }
    std::string line;
    while (std::getline(inputFile, line)){
        std::string modifiedLine = replaceText(line, s1, s2);
        outputFile << modifiedLine << std::endl;
    }

    if(this->haveC == true)
        std::cout << GREEN << "Fertig " << outputFileName << RESET << std::endl;
}


//./replaceText file.txt "A" "L"

int main(int argc, char* argv[])
{
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <input_file> <string_to_replace> <replacement_string>" << std::endl;
        return 1;
    }
    if(!argv[1] || *argv[1] == '\0')
    {
        std::cout << RED << "I can not finde the file " << RESET << std::endl;
        return 0;
    }
    // else
    // {
    //     std::string inputFileName = argv[1];
    //     std::string outputFileName = inputFileName + ".replace";
    // }
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    Replace replace;
    if(s1 == s2)
    {
        std::cout << RED << "S1 === S2 !!!" << RESET << std::endl;
        return 0;
    }
    std::string inputFileName = argv[1];
    std::string outputFileName = inputFileName + ".replace";
    replace.processFiles(inputFileName, outputFileName, s1, s2);
    if(replace.haveC == false)
        std::cout << RED << "S1 existiert nicht im File " << RESET << std::endl;

    return 0;
}
