#include "Library.h"
#include "Vocabdict.h"
#include <iostream>
namespace Ame
{
    VocabDict::VocabDict() : Dictionary()
    {
    }
    void VocabDict::test()
    {
        std::cout << UTF8Doc << std::endl;
    }
}