#include <iostream>
#include <sstream>
#include <assert.h>
const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
int calcPair(int majorIdx, int minorIdx)
{
   return majorIdx * 5 + minorIdx;
}
void printConsole(int majorIdx, int minorIdx)
{
    ::std::string output = majorColor[majorIdx];
    char ch = '|';
    output+=ch;
//     std::cout << calcPair(majorIdx, minorIdx) <<ch<< output.append(minorColor[majorIdx] ) << "\n";
   std::cout << calcPair(majorIdx, minorIdx) <<majorColor[majorIdx]<<minorColor[majorIdx]  << "\n";
}

int printColorMap() {
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printConsole(i,j);
        }
    }
    return i * j;
}

int main() {
    int result = printColorMap();
    assert(result == 25);
    std::ostringstream oss;
    std::streambuf* p_cout_streambuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());
    printConsole(0,2);
    std::cout.rdbuf(p_cout_streambuf); // restore
    // test  oss content...
    std::cout << oss.str()<<std::endl;
    assert(oss && oss.str() == "2|White|Green");
    std::cout << "All is well (maybe!)\n";
    return 0;
}
