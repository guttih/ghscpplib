#include <GhsCppLib/Hello.h>
#include <GhsCppLib/Version.h>
#include <iostream>

int main()
{
    hello();
    Version ver( "1.1" );
    ver.IncrementBuild();
    std::cout << "Version: " << ver.c_str() << std::endl;
    return 0;
}