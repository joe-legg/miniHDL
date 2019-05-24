#include <iostream>
#include <algorithm>
#include <fstream>
#include "grammar.h"
#include "error.hpp"

char *getCmdOption(char **begin, char **end, const std::string &option);
bool cmdOptionExists(char **begin, char **end, const std::string &option);
void compile(const char *filename, const char *outFilename, const char *dumpAst);

// Help
const char *help = "Usage: bool-logic [options] file...\n"
                   "Options:\n"
                   "    -h                 Display this help menu.\n"
                   "    -o <file>          Place the output into <file>.\n"
                   "    --dump-ast <file>  Dump the generated AST (abstract syntax tree) into <file>.\n\n";

// Main function
int main(int argc, char *argv[])
{
    // Get source files
    std::vector<const char *> sourceFiles;
    for (int i = 1; i < argc; i++)
        if (argv[i][0] != '-' && argv[i - 1][0] != '-')
            sourceFiles.push_back(argv[i]);

    if (sourceFiles.size() < 1)
    {
        error("Error: No source files given.");
        exit(0);
    }
    else
    {
        const char *outFilename = "out.v";
        const char *dumpAstFile = "";
        if (cmdOptionExists(argv, argv + argc, "-h")) // Display help
            std::cout << help;

        if (cmdOptionExists(argv, argv + argc, "-o")) // Output file
            outFilename = getCmdOption(argv, argv + argc, "-o");
        
        if (cmdOptionExists(argv, argv + argc, "--dump-ast")) // Dump ast
            dumpAstFile = getCmdOption(argv, argv + argc, "--dump-ast");

        { // Clear files
            std::ofstream empty(outFilename, std::ofstream::trunc);
            empty.close();
            empty.open(outFilename, std::ofstream::trunc);
            empty.close();
        }
        
        for (int i = 0; i < sourceFiles.size(); i++)
            compile(sourceFiles[i], outFilename, dumpAstFile);
    }

    return 0;
}

void compile(const char *filename, const char *outFilename, const char *dumpAst)
{
    Node *ast = parse(filename); // Parse the file
    
    // Create the output file
    std::ofstream outFile(outFilename, std::ios::app);
    outFile << ast->codeGen();
    outFile.close();

    // Dump the ast
    if (dumpAst != "")
    {
        std::ofstream astFile(dumpAst, std::ios::app);
        astFile << ast->getString();
        astFile.close();
    }
    delete ast;
}

// Command line argument parsing

// Taken from https://stackoverflow.com/a/868894/8099902
bool cmdOptionExists(char **begin, char **end, const std::string &option)
{
    return std::find(begin, end, option) != end;
}

// Taken from https://stackoverflow.com/a/868894/8099902
char *getCmdOption(char **begin, char **end, const std::string &option)
{
    char **itr = std::find(begin, end, option);
    if (itr != end && ++itr != end)
    {
        return *itr;
    }

    return 0;
}

