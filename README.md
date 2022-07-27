# PhysWin
![Mario bros image](https://upload.wikimedia.org/wikipedia/fr/thumb/5/55/Super_Mario_Bros._Logo_%28SVG%29.svg/2560px-Super_Mario_Bros._Logo_%28SVG%29.svg.png)
## A window that move around like mario
### Controls
- A --> Left
- D --> Right
- Space --> Jump

## Build instructions
### Linux 🐧
Install SDL2 with your package manager, pacman, aptitude, ...;
Use cmake with appropriates parameters Ex: cmake -G "Unix Makefiles"
And then the compiler you choose in this case Ex: make

### Windows 🪟
Uncomment the two lat lines of the cmake file
Comment the two line that were there before
Use mingw cmake then gcc + ld if on windows or just make if on linux
You will need some DLLs to run the program:
- The one in the bin subfolder of the SDL2 folder
- Some other im too lazy to find (Im working on linux)
- 
[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)
