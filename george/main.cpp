#include "SDL.h"
#include "window.h"
#include "utils.h"
#include <Windows.h>

int main(int argc, char* argv[]) 
{
	Window window("george", 100, 100, 500, 500, NULL);
	
	Colour white{ 255,255,255,255 };
	for (int w = 0; w < window.Width(); w++) {
		for (int h = 0; h < window.Height(); h++) {
			window.texture[w][h] = white;
		}
	}

	Sleep(10000);
	return 0;
}