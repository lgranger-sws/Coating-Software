#pragma once

#ifdef IMAGE_CONTRAST_DLL
//#define IMAGE_CONTRAST_DLL extern "C" _declspec(dllexport)
#else
#define IMAGE_CONTRAST_DLL extern "C" _declspec(dllimport)
#endif

#define _IN_
#define _OUT_

/*
*Name:		ImageContrastU8
*Function:	Calculate the relative normalized contrast value in a image with ROI specified; Version of uint_8
*Input:		imageSrc[] is the data chunk of an image with the width of nWidth and the height of nHeight;
*			nTop\nLeft\nBottom\nRight discribed a rectangular ROI where y in [nTop, nBottom) and x in [nLeft, nRight);
*Output:	No output;
*Return:	Contrast value in double, is negative if invalid input;
*/

IMAGE_CONTRAST_DLL double ImageContrastU8(
	_IN_ unsigned char imageSrc[], _IN_ int nWidth, _IN_ int nHeight,
	_IN_ int nTop, _IN_ int nLeft, _IN_ int nBottom, _IN_ int nRight);

/*
*Name:		ImageContrastU16
*Function:	Calculate the relative normalized contrast value in a image with ROI specified; Version of uint_16
*Input:		imageSrc[] is the data chunk of an image with the width of nWidth and the height of nHeight;
*			nTop\nLeft\nBottom\nRight discribed a rectangular ROI where y in [nTop, nBottom) and x in [nLeft, nRight);
*Output:	No output;
*Return:	Contrast value in double, is negative if invalid input;
*/

IMAGE_CONTRAST_DLL double ImageContrastU16(
	_IN_ unsigned short imageSrc[], _IN_ int nWidth, _IN_ int nHeight,
	_IN_ int nTop, _IN_ int nLeft, _IN_ int nBottom, _IN_ int nRight);

/*
*Name:		ImageContrastU32
*Function:	Calculate the relative normalized contrast value in a image with ROI specified; Version of uint_32
*Input:		imageSrc[] is the data chunk of an image with the width of nWidth and the height of nHeight;
*			nTop\nLeft\nBottom\nRight discribed a rectangular ROI where y in [nTop, nBottom) and x in [nLeft, nRight);
*Output:	No output;
*Return:	Contrast value in double, is negative if invalid input;
*/

IMAGE_CONTRAST_DLL double ImageContrastU32(
	_IN_ unsigned int imageSrc[], _IN_ int nWidth, _IN_ int nHeight,
	_IN_ int nTop, _IN_ int nLeft, _IN_ int nBottom, _IN_ int nRight);


/*
*Name:		ImageContrastI8
*Function:	Calculate the relative normalized contrast value in a image with ROI specified; Version of int_8
*Input:		imageSrc[] is the data chunk of an image with the width of nWidth and the height of nHeight;
*			nTop\nLeft\nBottom\nRight discribed a rectangular ROI where y in [nTop, nBottom) and x in [nLeft, nRight);
*Output:	No output;
*Return:	Contrast value in double, is negative if invalid input;
*/

IMAGE_CONTRAST_DLL double ImageContrastI8(
	_IN_ char imageSrc[], _IN_ int nWidth, _IN_ int nHeight,
	_IN_ int nTop, _IN_ int nLeft, _IN_ int nBottom, _IN_ int nRight);

/*
*Name:		ImageContrastI16
*Function:	Calculate the relative normalized contrast value in a image with ROI specified; Version of int_16
*Input:		imageSrc[] is the data chunk of an image with the width of nWidth and the height of nHeight;
*			nTop\nLeft\nBottom\nRight discribed a rectangular ROI where y in [nTop, nBottom) and x in [nLeft, nRight);
*Output:	No output;
*Return:	Contrast value in double, is negative if invalid input;
*/

IMAGE_CONTRAST_DLL double ImageContrastI16(
	_IN_ short imageSrc[], _IN_ int nWidth, _IN_ int nHeight,
	_IN_ int nTop, _IN_ int nLeft, _IN_ int nBottom, _IN_ int nRight);

/*
*Name:		ImageContrastU32
*Function:	Calculate the relative normalized contrast value in a image with ROI specified; Version of int_32
*Input:		imageSrc[] is the data chunk of an image with the width of nWidth and the height of nHeight;
*			nTop\nLeft\nBottom\nRight discribed a rectangular ROI where y in [nTop, nBottom) and x in [nLeft, nRight);
*Output:	No output;
*Return:	Contrast value in double, is negative if invalid input;
*/

IMAGE_CONTRAST_DLL double ImageContrastI32(
	_IN_ int imageSrc[], _IN_ int nWidth, _IN_ int nHeight,
	_IN_ int nTop, _IN_ int nLeft, _IN_ int nBottom, _IN_ int nRight);

