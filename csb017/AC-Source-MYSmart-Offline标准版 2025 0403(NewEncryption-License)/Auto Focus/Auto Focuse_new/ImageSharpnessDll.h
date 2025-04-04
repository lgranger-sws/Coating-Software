#pragma once

#ifdef IMAGE_SHARPNESS_DLL
//#define IMAGE_SHARPNESS_DLL extern "C" _declspec(dllexport)
#else
#define IMAGE_SHARPNESS_DLL extern "C" _declspec(dllimport)
#endif

#define _IN_
#define _OUT_

/*
*Name:		ImageSharpnessSMD_U8/U16/U32/I8/I16/I32
*Function:	Calculate the relative normalized sharpness value using SMD function in an image with ROI specified;
*			Functions support image data type of uint_8/uint_16/uint_32/int8/int16/int32
*Input:		imageSrc[] is the data chunk of an image with the width of nWidth and the height of nHeight;
*			nTop\nLeft\nBottom\nRight discribed a rectangular ROI where y in [nTop, nBottom) and x in [nLeft, nRight);
*Output:	No output;
*Return:	Sharpness value in double, is negative if invalid input;
*/
IMAGE_SHARPNESS_DLL double ImageSharpnessSMD_U8(
	_IN_ unsigned char imageSrc[], _IN_ int nWidth, _IN_ int nHeight,
	_IN_ int nTop, _IN_ int nLeft, _IN_ int nBottom, _IN_ int nRight);
IMAGE_SHARPNESS_DLL double ImageSharpnessSMD_U16(
	_IN_ unsigned short imageSrc[], _IN_ int nWidth, _IN_ int nHeight,
	_IN_ int nTop, _IN_ int nLeft, _IN_ int nBottom, _IN_ int nRight);
IMAGE_SHARPNESS_DLL double ImageSharpnessSMD_U32(
	_IN_ unsigned int imageSrc[], _IN_ int nWidth, _IN_ int nHeight,
	_IN_ int nTop, _IN_ int nLeft, _IN_ int nBottom, _IN_ int nRight);
IMAGE_SHARPNESS_DLL double ImageSharpnessSMD_I8(
	_IN_ char imageSrc[], _IN_ int nWidth, _IN_ int nHeight,
	_IN_ int nTop, _IN_ int nLeft, _IN_ int nBottom, _IN_ int nRight);
IMAGE_SHARPNESS_DLL double ImageSharpnessSMD_I16(
	_IN_ short imageSrc[], _IN_ int nWidth, _IN_ int nHeight,
	_IN_ int nTop, _IN_ int nLeft, _IN_ int nBottom, _IN_ int nRight);
IMAGE_SHARPNESS_DLL double ImageSharpnessSMD_I32(
	_IN_ int imageSrc[], _IN_ int nWidth, _IN_ int nHeight,
	_IN_ int nTop, _IN_ int nLeft, _IN_ int nBottom, _IN_ int nRight);

/*
*Name:		ImageSharpnessSMD2_U8/U16/U32/I8/I16/I32
*Function:	Calculate the relative normalized sharpness value using SMD2 function in an image with ROI specified;
*			Functions support image data type of uint_8/uint_16/uint_32/int8/int16/int32
*Input:		imageSrc[] is the data chunk of an image with the width of nWidth and the height of nHeight;
*			nTop\nLeft\nBottom\nRight discribed a rectangular ROI where y in [nTop, nBottom) and x in [nLeft, nRight);
*Output:	No output;
*Return:	Sharpness value in double, is negative if invalid input;
*/
IMAGE_SHARPNESS_DLL double ImageSharpnessSMD2_U8(
	_IN_ unsigned char imageSrc[], _IN_ int nWidth, _IN_ int nHeight,
	_IN_ int nTop, _IN_ int nLeft, _IN_ int nBottom, _IN_ int nRight);
IMAGE_SHARPNESS_DLL double ImageSharpnessSMD2_U16(
	_IN_ unsigned short imageSrc[], _IN_ int nWidth, _IN_ int nHeight,
	_IN_ int nTop, _IN_ int nLeft, _IN_ int nBottom, _IN_ int nRight);
IMAGE_SHARPNESS_DLL double ImageSharpnessSMD2_U32(
	_IN_ unsigned int imageSrc[], _IN_ int nWidth, _IN_ int nHeight,
	_IN_ int nTop, _IN_ int nLeft, _IN_ int nBottom, _IN_ int nRight);
IMAGE_SHARPNESS_DLL double ImageSharpnessSMD2_I8(
	_IN_ char imageSrc[], _IN_ int nWidth, _IN_ int nHeight,
	_IN_ int nTop, _IN_ int nLeft, _IN_ int nBottom, _IN_ int nRight);
IMAGE_SHARPNESS_DLL double ImageSharpnessSMD2_I16(
	_IN_ short imageSrc[], _IN_ int nWidth, _IN_ int nHeight,
	_IN_ int nTop, _IN_ int nLeft, _IN_ int nBottom, _IN_ int nRight);
IMAGE_SHARPNESS_DLL double ImageSharpnessSMD2_I32(
	_IN_ int imageSrc[], _IN_ int nWidth, _IN_ int nHeight,
	_IN_ int nTop, _IN_ int nLeft, _IN_ int nBottom, _IN_ int nRight);

/*
*Name:		ImageSharpnessEnergyGradient_U8/U16/U32/I8/I16/I32
*Function:	Calculate the relative normalized sharpness value using Energy Gradient function in an image with ROI specified;
*			Functions support image data type of uint_8/uint_16/uint_32/int8/int16/int32
*Input:		imageSrc[] is the data chunk of an image with the width of nWidth and the height of nHeight;
*			nTop\nLeft\nBottom\nRight discribed a rectangular ROI where y in [nTop, nBottom) and x in [nLeft, nRight);
*Output:	No output;
*Return:	Sharpness value in double, is negative if invalid input;
*/
IMAGE_SHARPNESS_DLL double ImageSharpnessEnergyGradient_U8(
	_IN_ unsigned char imageSrc[], _IN_ int nWidth, _IN_ int nHeight,
	_IN_ int nTop, _IN_ int nLeft, _IN_ int nBottom, _IN_ int nRight);
IMAGE_SHARPNESS_DLL double ImageSharpnessEnergyGradient_U16(
	_IN_ unsigned short imageSrc[], _IN_ int nWidth, _IN_ int nHeight,
	_IN_ int nTop, _IN_ int nLeft, _IN_ int nBottom, _IN_ int nRight);
IMAGE_SHARPNESS_DLL double ImageSharpnessEnergyGradient_U32(
	_IN_ unsigned int imageSrc[], _IN_ int nWidth, _IN_ int nHeight,
	_IN_ int nTop, _IN_ int nLeft, _IN_ int nBottom, _IN_ int nRight);
IMAGE_SHARPNESS_DLL double ImageSharpnessEnergyGradient_I8(
	_IN_ char imageSrc[], _IN_ int nWidth, _IN_ int nHeight,
	_IN_ int nTop, _IN_ int nLeft, _IN_ int nBottom, _IN_ int nRight);
IMAGE_SHARPNESS_DLL double ImageSharpnessEnergyGradient_I16(
	_IN_ short imageSrc[], _IN_ int nWidth, _IN_ int nHeight,
	_IN_ int nTop, _IN_ int nLeft, _IN_ int nBottom, _IN_ int nRight);
IMAGE_SHARPNESS_DLL double ImageSharpnessEnergyGradient_I32(
	_IN_ int imageSrc[], _IN_ int nWidth, _IN_ int nHeight,
	_IN_ int nTop, _IN_ int nLeft, _IN_ int nBottom, _IN_ int nRight);
