
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



QString metersText = 
  optionsPage::tr ("Enter the desired grid size in meters.  If you enter the grid size in meters the grid size in "
                   "minutes will be set to 0.0.  The actual grid size will not be exactly this size in meters since "
                   "we are gridding geographically.  The grid size will be computed in minutes of longitude at "
                   "the center of the area.  Due to this the shape of the grid cell will be elongated in the "
                   "north/south direction since (except at the equator) minutes of latitude are larger than "
                   "minutes of longitude.");

QString minutesText = 
  optionsPage::tr ("Enter the desired grid size in minutes.  If you enter the grid size in minutes the grid size in "
                   "meters will be set to 0.0.  A minute of latitude is always 1852 meters and a minute of longitude "
                   "is approximately the cosine of the latitude times 1852 meters (1852 meters at the equator)");

QString factorText = 
  optionsPage::tr ("The <b>Weight factor</b> is used to weigh the original input against the minimum curvature regional "
                   "grid that is created from the original input data.  The higher the value, the more weight that is "
                   "given to the input data.  The acceptable values are from 1 to 3.  A good rule of thumb for the "
                   "weight is to use 1 if the data is very random point or line data, use 2 for fairly evenly spaced "
                   "point, line, or area data, and use 3 for evenly spaced, uniform coverage.  If a smooth "
                   "representation of the field is needed then the lower values will give better results.");

QString forceText = 
  optionsPage::tr ("Select this if you wish to force the final output grid to use the original data values at the "
                   "location of those values.  This overrides the weight factor in the locations of the original "
                   "values.  The weight factor will still have some influence on the grid surface in areas near the "
                   "original values.  Generally speaking, you only want to use this option if you have set the "
                   "<b>Weight factor</b> to a value of 3.");

QString nibbleText = 
  optionsPage::tr ("Set the nibble distance in cells.  The nibbler is used to clear interpolated cells that are a set "
                   "distance from cells that contain data.  For example, if you set the nibble value to 4 then any cell "
                   "that is not within 4 bins of a bin that contains data will be cleared after the grid has been "
                   "generated.  If this is set to 0, no nibbling will be done.");

QString regionalText = 
  optionsPage::tr ("The <b>Regional factor</b> is multiplied by the <b>Grid size</b> to get the point spacing for "
                   "the minimum curvature regional grid that is merged with the original input (sparse grid) data.  "
                   "Usually the default of 4 is used.");

QString minimumText = 
  optionsPage::tr ("This should be the minimum acceptable value in the units that the data is in.  All values less than "
                   "this will be discarded.");

QString maximumText = 
  optionsPage::tr ("This should be the maximum acceptable value in the units that the data is in.  All values greater "
                   "than this will be discarded.");

QString deltaText = 
  optionsPage::tr ("The <b>Delta value</b> is the value of the maximum change in the surface between iterations at "
                   "which convergence is accepted in the regional computation.  The default of 0.05 is usually "
                   "sufficient.  This value may be raised to speed the computations somewhat but the output will "
                   "degrade.  Conversely, the output may be improved somewhat by lowering this value, but this will be "
                   "at the cost of computation time.  Further information on the minimum curvature routines may be "
                   "found in the article <b>A FORTRAN IV PROGRAM FOR INTERPOLATING IRREGULARLY SPACED DATA USING THE "
                   "DIFFERENCE EQUATIONS FOR MINIMUM CURVATURE</b> by C. J. Swain in Computers and Geosciences, "
                   "Vol. 1 pp. 231-240 and the article <b>MACHINE CONTOURING USING MINIMUM CURVATURE</b> by Ian C. "
                   "Briggs in Geophysics, Vol 39, No. 1 (February 1974), pp. 39-48.");

QString searchText = 
  optionsPage::tr ("The <b>Search radius</b> value represents the maximum distance from a grid point that data points "
                   "are to be used for the regional computation.  The default of 20.0 is not normally changed since "
                   "<b>chrtr</b> may change the value if needed.  The units of this value are grid points.  That is, "
                   "if the <b>Grid size</b> is 10.0 minutes and this value is set to 20.0 then the actual beginning "
                   "search radius will be 40.0 minutes.");

QString errorText = 
  optionsPage::tr ("The <b>Error control</b> value is the number of times that chrtr may expand <b>Search radius</b> "
                   "when computing the minimum curvature regional grid.  The default of 20 is usually not modified.");
