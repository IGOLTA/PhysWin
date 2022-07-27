# PhysWin


To build for linux use cmake like normmal:
- Install SDL2 with your package manager, pacman, aptitude, ...;
- Use cmake with appropriates parameters Ex: cmake -G "Unix Makefiles"
- And then the compiler you choose in this case Ex: make

To build for windows: 
- Uncomment the two lat lines of the cmake file
- Comment the two line that were there before
- Use mingw cmake then gcc + ld if on windows or just make if on linux
- You will need some DLLs to run the program:
- - The one in the bin subfolder of the SDL2 folder
- - Some other im too lazy to find (Im working on linux)
