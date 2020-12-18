
/*********************************************************************************************

    This is public domain software that was developed by or for the U.S. Naval Oceanographic
    Office and/or the U.S. Army Corps of Engineers.

    This is a work of the U.S. Government. In accordance with 17 USC 105, copyright protection
    is not available for any work of the U.S. Government.

    Neither the United States Government, nor any employees of the United States Government,
    nor the author, makes any warranty, express or implied, without even the implied warranty
    of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE, or assumes any liability or
    responsibility for the accuracy, completeness, or usefulness of any information,
    apparatus, product, or process disclosed, or represents that its use would not infringe
    privately-owned rights. Reference herein to any specific commercial products, process,
    or service by trade name, trademark, manufacturer, or otherwise, does not necessarily
    constitute or imply its endorsement, recommendation, or favoring by the United States
    Government. The views and opinions of authors expressed herein do not necessarily state
    or reflect those of the United States Government, and shall not be used for advertising
    or product endorsement purposes.
*********************************************************************************************/


/****************************************  IMPORTANT NOTE  **********************************

    Comments in this file that start with / * ! or / / ! are being used by Doxygen to
    document the software.  Dashes in these comment blocks are used to create bullet lists.
    The lack of blank lines after a block of dash preceeded comments means that the next
    block of dash preceeded comments is a new, indented bullet list.  I've tried to keep the
    Doxygen formatting to a minimum but there are some other items (like <br> and <pre>)
    that need to be left alone.  If you see a comment that starts with / * ! or / / ! and
    there is something that looks a bit weird it is probably due to some arcane Doxygen
    syntax.  Be very careful modifying blocks of Doxygen comments.

*****************************************  IMPORTANT NOTE  **********************************/



#include "chrtrGUI.hpp"

uint8_t writeParameterFile (QString parameter_file, QStringList input_files, OPTIONS *options)
{
  //  Add .chp to filename if not there.
            
  if (!parameter_file.endsWith (".chp")) parameter_file.append (".chp");


  char fname [512];
  strcpy (fname, parameter_file.toLatin1 ());


  FILE *fp;
  if ((fp = fopen (fname, "w")) == NULL) return (NVFalse);

  char tmp[512];


  fprintf (fp, "************  CHRTR Options  ************\n");
  fprintf (fp, "[grid type] = %d\n", options->type);

  if (options->grid_size_meters > 0.0001)
    {
      fprintf (fp, "[gridmeter] = %0.9lf\n", options->grid_size_meters);
    }
  else
    {
      fprintf (fp, "[gridmin] = %0.9lf\n", options->grid_size);
    }

  fprintf (fp, "[delta] = %0.9lf\n", options->delta);
  fprintf (fp, "[reg_multfact] = %d\n", options->regional_factor);
  fprintf (fp, "[search_radius] = %0.9lf\n", options->search_radius);
  fprintf (fp, "[error_control] = %d\n", options->error_control);
  fprintf (fp, "[weight_factor] = %d\n", options->weight_factor);
  fprintf (fp, "[force_original_value] = %d\n", options->force_original_value);
  fprintf (fp, "[nibble_value] = %d\n", options->nibble);
  fprintf (fp, "[nominal_depth] = %d\n", options->nominal);
  fprintf (fp, "[minvalue] = %0.9lf\n", options->minimum_value);
  fprintf (fp, "[maxvalue] = %0.9lf\n", options->maximum_value);
  fprintf (fp, "[lat_south] = %0.9lf\n", options->mbr.min_y);
  fprintf (fp, "[lat_north] = %0.9lf\n", options->mbr.max_y);
  fprintf (fp, "[lon_west] = %0.9lf\n", options->mbr.min_x);
  fprintf (fp, "[lon_east] = %0.9lf\n", options->mbr.max_x);
  strcpy (tmp, options->outputFile.toLatin1 ());
  fprintf (fp, "[output_file] = %s\n", tmp);


  fprintf (fp, "************  Input Files  ************\n");


  for (int32_t i = 0 ; i < input_files.size () ; i++)
    {
      strcpy (tmp, input_files.at (i).toLatin1 ());
      fprintf (fp, "%s\n", tmp);
    }


  fprintf (fp, "************  End Input Files  ************\n");


  fclose (fp);


  return (NVTrue);
}
