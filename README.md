# ghscpplib

My library functions
The minimum branch

## Sources

###  CMake Library Tutorial

Information on how I learned to setup this library. 
  - Creating the library - [CMake Library Tutorial - Episode 1](https://www.youtube.com/watch?v=5i6uLMP5VcY)
  - Using the library - [CMake Library Tutorial - Episode 3](https://www.youtube.com/watch?v=kntGxpNOOQM)

## Using the library

These instructions are written when installing and using this library on a
Rocky linux operating system using Visual Studio Code with the [CMake extension](https://marketplace.visualstudio.com/items?itemName=twxs.cmake) installed.  The process should be similar on other systems.

### Install the library on Linux

1. Open this project in Visual Studio Code 
2. On the bottom bar select Release configuration *CMake: [Release]*
3. Click Build
4. Open a terminal and cd into the build folder, make and install the library by
   giving the following commands:
   ```shell
   cd build
   make
   make install
   ```

### Use the library

Now when the library is installed let's create a hello world project which 
uses the library, link, build and then run it.

1. Create a new directory called hello and open it in Visual Studio Code
2. create two files in that directory named `Main.cpp` and `CMakeLists.txt`.
3. Add the following content to the file `Main.cpp`
    ```cpp
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
    ```
    3. Add the following content to the file `CMakeLists.txt`
    ```cmake
    cmake_minimum_required(VERSION "3.5")
    project("Hello")

    add_executable("${PROJECT_NAME}" "Main.cpp")

    find_package("GhsCppLib" REQUIRED)

    target_link_libraries("${PROJECT_NAME}" PRIVATE "GhsCppLib::GhsCppLib")

    ```
4. Configure, build and run the hello project
   1. reload the vscode window `shift+ctrl+p` and select **Reload window**
   2. Select active kit if asked
   3. Click Build on the bottom bar
   4. click Play (Launch the selected target button) to execute the 
      Hello application you've just created in the build directory.