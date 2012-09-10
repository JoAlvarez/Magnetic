#ifndef __IMAGE_H__
#define __IMAGE_H__

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_opengl.h>
#include <string>
#include "point.h"

using namespace std;

class Image
{
    public:

        Image();
        void setAlias(string alias);
        void setTexture(GLuint texture);

		string getFilename();
        string getAlias();
        GLuint* getTexture();
        void setFile(string file);

    private:

        string alias;
        string filename;
        GLuint glTexture;
};

void LoadImage(Image* image, string filename);

void RenderImage(Image image, double lx, double rx, double ly, double uy);

void RenderImage(Image image, double angle, double lx, double rx, double ly, double uy);

void RenderImage(Image image, Point ul, Point ur, Point ll, Point lr);

void RenderImage(Image image, double angle, Point ul, Point ur, Point ll, Point lr);

void RenderImage(Image image, double lx, double rx, double ly, double uy,
			   double lxTexCoord, double rxTexCoord, double lyTexCoord,
			   double uyTexCoord);

void RenderImage(Image image, double angle, double lx, double rx, double ly, double uy,
			   double lxTexCoord, double rxTexCoord, double lyTexCoord,
			   double uyTexCoord);

void RenderImage(Image image, Point ul, Point ur, Point ll, Point lr,
				 Point ulTexCoord, Point urTexCoord, Point llTexCoord, Point lrTexCoord);

void RenderImage(Image image, double angle, Point ul, Point ur, Point ll, Point lr,
				 Point ulTexCoord, Point urTexCoord, Point llTexCoord, Point lrTexCoord);


#endif
