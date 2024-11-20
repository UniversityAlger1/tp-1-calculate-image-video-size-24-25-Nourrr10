#include "config/grayScaleImage.h"
// Parameters:
//   w: width of the image
//   h: height of the image
// Return value
//   grayScale size of the image Bitmap (in byte)
float grayScaleImage(int w, int h) {
   return w*h; 
}
//int main (){
//   printf("the size of grayScale image is :%.2f byte",grayScaleImage(300,200));
//}