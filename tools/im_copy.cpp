//Original version: http://webserver2.tecgraf.puc-rio.br/im/examples/im_copy.cpp

/* IM 3 sample that copies an image from one file to another.
   It is good to test the file formats read and write.
   If the destiny does not supports the input image it aborts and returns an error.

  Needs "im.lib".

  Usage: im_copy <input_file_name> <output_file_name> [<output_format> [<output_compression]]

    Example: im_copy test.tif test_proc.tif
*/

#include <im.h>
#include <im_util.h>
#include <im_convert.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void PrintError(int error)
{
  switch (error)
  {
  case IM_ERR_OPEN:
    printf("Error Opening File.\n");
    break;
  case IM_ERR_MEM:
    printf("Insuficient memory.\n");
    break;
  case IM_ERR_ACCESS:
    printf("Error Accessing File.\n");
    break;
  case IM_ERR_DATA:
    printf("Image type not Suported.\n");
    break;
  case IM_ERR_FORMAT:
    printf("Invalid Format.\n");
    break;
  case IM_ERR_COMPRESS:
    printf("Invalid or unsupported compression.\n");
    break;
  default:
    printf("Unknown Error.\n");
  }
}

int main(int argc, char* argv[])
{
  if (argc < 3)
  {
    printf("Invalid number of arguments.\n");
    return 0;
  }

  imImage* iimg = NULL;
  imImage* oimg = NULL;
  imFile* ifile = NULL;
  imFile* ofile = NULL;

  int error;
  ifile = imFileOpen(argv[1], &error);
  if (!ifile)
    goto man_error;

  char format[10];
  char compression[20];
  int image_count;
  imFileGetInfo(ifile, format, compression, &image_count);

  ofile = imFileNew(argv[2], (argc < 3)? format: argv[3], &error);
  if (!ofile)
    goto man_error;

  if (argc < 4)
    imFileSetInfo(ofile, compression);
  else
    imFileSetInfo(ofile, argv[4]);

  for (int i = 0; i < image_count; i++)
  {
    iimg = imFileLoadImage(ifile, i, &error);
    if (error != IM_ERR_NONE)
      goto man_error;
    if(argc > 3 && strcmp(argv[3], "LED") == 0){
      oimg = imImageCreateBased(iimg, -1, -1, IM_MAP, -1);
      imConvertColorSpace(iimg, oimg);
    }else
      oimg = iimg;
    error = imFileSaveImage(ofile, oimg);
    if (error != IM_ERR_NONE)
      goto man_error;
  }

  free(iimg);
  free(oimg);
  imFileClose(ifile);
  imFileClose(ofile);

  return 0;

man_error:
  PrintError(error);
  if (iimg) free(iimg);
  if (oimg) free(oimg);
  if (ifile) imFileClose(ifile);
  if (ofile) imFileClose(ofile);
  return 1;
}

