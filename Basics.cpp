//============================================================================
// Name        : HW0.cpp
// Author      : Ankit Dewan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include "opencv2/imgproc/imgproc.hpp"

using namespace std;
using namespace cv;

int main(int argc, char **argv) {
  Mat inputImage = imread(argv[1], 1);
  int sumNum, subNum, multNum;
  double divNum;
  Mat sum_dst, sub_dst, mult_dst, div_dst, resize_dst;
  if (argc != 2 || !inputImage.data) {
    printf("No image data \n");
    return -1;
  }

  cout << "Enter the number to add to all pixels" << endl;
  cin >> sumNum;
  cout << "Enter the number to subtract from image" << endl;
  cin >> subNum;
  cout << "Enter the number to multiply from image" << endl;
  cin >> multNum;
  cout << "Enter the number to divide from image" << endl;
  cin >> divNum;

  Mat sum_image = inputImage.clone();
  Mat sub_image = inputImage.clone();
  Mat mult_image = inputImage.clone();
  Mat div_image = inputImage.clone();
  Mat resize_image = inputImage.clone();

  add(sum_image, sumNum, sum_dst);
  subtract(sub_image, subNum, sub_dst);
  mult_dst = mult_image * multNum;
  div_dst = div_image / divNum;
  cv::resize(resize_image, resize_dst, cv::Size(), 0.50, 0.50);

  cout << "Process finished" << endl;


  namedWindow("Original Image", WINDOW_AUTOSIZE);
  imshow("Original Image", inputImage);

  namedWindow("Sum Image", WINDOW_AUTOSIZE);
  imshow("Sum Image", sum_dst);

  namedWindow("Sub Image", WINDOW_AUTOSIZE);
  imshow("Sub Image", sub_dst);

  namedWindow("Mult Image", WINDOW_AUTOSIZE);
  imshow("Mult Image", mult_dst);

  imshow("DIV Image", div_dst);

  namedWindow("Resize image", WINDOW_AUTOSIZE);
  imshow("Resize image", resize_dst);

  waitKey();

  return 0;
}
