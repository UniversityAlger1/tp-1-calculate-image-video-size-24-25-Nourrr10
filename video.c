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
   float tailleOctect=((w*h*3)*durationMovie*fps)+((w*h)*durationCredits*fps);
    if (unit == NULL || strcmp(unit, "bt") == 0) {
        return tailleOctect;
    } else if (strcmp(unit, "ko") == 0) {
        return tailleOctect / 1024;
    } else if (strcmp(unit, "mo") == 0) {
        return tailleOctect / (1024 * 1024);
    } else if (strcmp(unit, "go") == 0) {
        return tailleOctect / (1024*1024*1024);
    } else {
        printf("Invalid unit. Supported units: bytes,KB,MB,GB.\n");
        return -1; 
    }
}

//int main(){
// printf("the size is :%.2f",video(200, 300, 10, 20, 25,"ko"));
//}