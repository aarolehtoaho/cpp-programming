#include "RGBA/png.h"
#include "RGBA/rgbapixel.h"

#include <cstdint>
#include <string>
#include <cmath>

void rotate(const std::string & inputFile, const std::string & outputFile) {
	PNG pic(inputFile);
	// Your code here
	size_t height = pic.height();
	size_t width = pic.width();
	PNG rotatedPic(height, width);
	for (size_t y = 0; y < height; y++) {
		for (size_t x = 0; x < width; x++) {
			RGBAPixel & pixel = pic(x, y);
			RGBAPixel & rotatedPixel = rotatedPic(y, width - 1 - x);
			rotatedPixel = pixel;
		}
	}
	
	rotatedPic.writeToFile(outputFile);
}

PNG myArt(unsigned int width, unsigned int height) {
	PNG png(width, height);
	// Your code here

	unsigned int midX = width / 2;
	unsigned int midY = height / 2;
	unsigned int outRadius = std::min(midX, midY);
	outRadius -= outRadius / 10;
	unsigned int inRadius = outRadius - (outRadius / 5);
	unsigned int mouthOutRadius = inRadius - (inRadius / 6);
	unsigned int mouthInRadius = mouthOutRadius - (mouthOutRadius / 5);
	unsigned int leftEyeX = midX - (width / 7);
	unsigned int rightEyeX = midX + (width / 7);
	unsigned int eyeY = midY - (width / 6);
	unsigned int eyeRadius = width / 20;

	for (unsigned int x = 0; x < width; x++) {
		for (unsigned int y = 0; y < height; y++) {
			uint8_t red = x * 2 + y;
			uint8_t green = x + y * 2;
			uint8_t blue = 255;

			int dMidX = (int)x - midX;
			int dMidY = (int)y - midY;
			unsigned int distanceToMid2 = dMidX * dMidX + dMidY * dMidY;

			int dLeftEyeX = (int)x - leftEyeX;
			int dRightEyeX = (int)x - rightEyeX;
			int dEyeX = std::min(std::abs(dLeftEyeX), std::abs(dRightEyeX));
			int dEyeY = (int)y - eyeY;
			unsigned int distanceToEye2 = dEyeX * dEyeX + dEyeY * dEyeY;

			bool pixelInCircle = distanceToMid2 > inRadius * inRadius && distanceToMid2 < outRadius * outRadius;
			bool pixelInMouth = distanceToMid2 > mouthInRadius * mouthInRadius && distanceToMid2 < mouthOutRadius * mouthOutRadius && dMidY > 0;
			bool pixelInEye = distanceToEye2 < eyeRadius * eyeRadius;

			if (pixelInCircle || pixelInMouth || pixelInEye) {
				red += x + y * 2;
				green = x * 2 + y;
				blue -= 20;
			}

			RGBAPixel coloredPixel(red, green, blue);
			RGBAPixel & pixel = png(x, y);
			pixel = coloredPixel;
		}
	}

	return png;
}
