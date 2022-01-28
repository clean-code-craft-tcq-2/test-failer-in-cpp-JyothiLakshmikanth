#include <iostream>
#include <sstream>
#include <assert.h>
#include <string>

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

int calcPair(int majorIdx, int minorIdx)
{
   return majorIdx * 5 + minorIdx;
}
::std::string getCombination(int majorIdx, int minorIdx)
{
    ::std::string output = ::std::to_string(calcPair(majorIdx, minorIdx));
        char ch = '|';
    output+=ch;
    output.append(majorColor[majorIdx]);
    output+=ch;
    output.append(minorColor[majorIdx] );
return output;
   
//   std::cout << calcPair(majorIdx, minorIdx) << ch << majorColor[majorIdx] << ch << minorColor[majorIdx]  << "\n";
}
void printOnConsole(::std::string output)
{
    std::cout << output << "\n";
}

int printColorMap() {
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
           ::std::string output = getCombination(i,j);
           printOnConsole(output);
        }
    }
    return i * j;
}

int main() {
    int result = printColorMap();
    assert(result == 25);
    // test 
     std::cout << getCombination(0,2)<<std::endl;
     assert(getCombination(0,2) == "2|White|Blue");
    std::cout << "All is well (maybe!)\n";
    return 0;
}
