#include <iostream>
#include <cmath>
#include "bmplib.h"

using namespace std;

// global variable. bad style but ok for this assignment
unsigned char image[SIZE][SIZE];

// Fill in this function:
void draw_rectangle(int top, int left, int height, int width) 
{
  for (int i=0; i < width; i++) {
    if ((i + left < SIZE) && (i + left >= 0) && (top >= 0) && (top < SIZE)) {
      image[top][i + left] = 0;
    }
    if ((top + height - 1 < SIZE) && (i + left >= 0) && (i + left < SIZE) && (top + height - 1 >= 0)) {
      image[top + height - 1][left + i] = 0;
    }
  }
    
  for (int j=0; j < height; j++) {
    if ((j + top < SIZE) && (j + top >= 0) && (left >= 0) && (left < SIZE)) {
      image[j + top][left] = 0;
    }
    if ((left + height - 1 < SIZE) && (top + j >= 0) && (j + top < SIZE) && (left + width - 1 >= 0)) {
      image[j + top][left + width - 1] = 0;
    }
  }

}

// Fill in this function:
void draw_ellipse(int cr, int cc, int height, int width) 
{
  for (double theta = 0.0; theta < (2 * M_PI); theta += .01) {
    
    double x = cos(theta) * (width/2.0) + cc; 
    double y = sin(theta) * (height/2.0) + cr;

    if (x < 0 || x > SIZE || y < 0 || y > SIZE) { // not within bounds
      continue;
    }

    else {
    image[(int)y][(int)x] = 0;
    }
  }
}

// Complete
void print_menu()
{
   cout << "To draw a rectangle, enter: 0 top left height width" << endl;
   cout << "To draw an ellipse, enter: 1 cy cx height width" << endl;
   cout << "To save your drawing as 'output.bmp' and quit, enter: 2" << endl;   
}

int main() 
{

   // initialization
   int userInput;
   int top, left, height, width;
   int cr, cc;

   // Main program loop here
   cin >> userInput;

   print_menu();

   // turning the pixels from black to a white background
   for (int i=0; i < SIZE; i++) {
      for (int j=0; j < SIZE; j++) {
         image[i][j] = 255;
      }
   }
   
   while (userInput != 2) {
      if (userInput == 0) {
        cin >> top >> left >> height >> width;
        draw_rectangle(top, left, height, width);
      }
      else if (userInput == 1) {
        cin >> cr >> cc >> height >> width;
        draw_ellipse(cr, cc, height, width);
      }
      cin >> userInput;
   }
   
   // Write the resulting image to the .bmp file
   if (userInput == 2) {
   writeGSBMP("output.bmp", image);
   }
   return 0;
}