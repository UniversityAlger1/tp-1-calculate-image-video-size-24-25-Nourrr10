#include <string.h>
#include "config/video.h"
// Parameters:
//   w: width of the image
//   h: height of the image
//   durationMovie: duration in second of movie (colored image)
//   durationCredits: duration in second of credit (image Black/White)
//   unit: Unit of the output value. It could be 'bt' byte, 'ko' kilobits, 'mo' megabits, 'go' gigabits
// Return value
//   colored video size (based on the unit passed parametter)
float video(int w, int h, int durationMovie, int durationCredits, int fps, char* unit) {
   float tailleColorPhoto=(w*h*3)*durationMovie*fps;
   float tailleBwPhoto=(w*h)*durationCredits*fps;
   float tailleOctect=tailleColorPhoto+ tailleBwPhoto;
    if (unit == NULL || strcmp(unit, "bytes") == 0) {
        return tailleOctect;
    } else if (strcmp(unit, "KB") == 0) {
        return tailleOctect / 1024;
    } else if (strcmp(unit, "MB") == 0) {
        return tailleOctect / (1024 * 1024);
    } else if (strcmp(unit, "GB") == 0) {
        return tailleOctect / (1024*1024*1024);
    } else {
        printf("Invalid unit. Supported units: bytes,KB,MB,GB.\n");
        return -1; 
    }
   return 0;
}

int main(){
 printf("the size is :%f",video(200, 300, 10, 20, 25,"KB"));
}