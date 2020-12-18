
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


QString area_fileText = 
  startPage::tr ("You may use an area file to define the extents of the area to be gridded.  Use the <b>Browse</b> button "
                 "to select the file.  The area file may be in the "
                 "ISS-60 survey planner area format (.ARE), the NAVO generic area format (.are), the Army Corps area format "
                 "(.afs), or ESRI shape file format.  Shape files must be either Polygon, PolygonZ, PolygonM, PolyLine, "
                 "PolyLineZ, or PolyLineM format and must be geographic "
                 "(not projected).  For PolyLine files the first point will be duplicated to close the polygon.  "
                 "Whether using Polygon or PolyLine files, only the first shape will be used if there are multiple "
                 "shapes in the file.<br><br>"
                 "Generic area format files (.are) contain a simple list of polygon points.  The points may be in any of the "
                 "following formats:"
                 "<ul>"
                 "<li>Hemisphere Degrees Minutes Seconds.decimal</li>"
                 "<li>Hemisphere Degrees Minutes.decimal</li>"
                 "<li>Hemisphere Degrees.decimal</li>"
                 "<li>Sign Degrees Minutes Seconds.decimal</li>"
                 "<li>Sign Degrees Minutes.decimal</li>"
                 "<li>Sign Degrees.decimal</li>"
                 "</ul>"
                 "The lat and lon must be entered one per line, separated by a comma.  You do not need to repeat the "
                 "first point, the polygon will be closed automatically.");

QString area_fileBrowseText = 
  startPage::tr ("Use this button to select an optional area file.");

QString area_mapText = 
  startPage::tr ("Use this button to graphically edit/view the area defined in the latitude and longitude boxes, or "
                "graphically create an area.  Note that even if you input a polygonal area file in the <b>Optional Area "
                "File</b> slot or defined a polygon in the <b><i>areaCheck</i></b> program you will only get a minimum "
                "bounding rectangle (MBR) since the <b><i>chrtr</i></b> and <b><i>chrtr2</i></b> programs only work with "
                 "rectangular areas.");

QString slatText = 
  startPage::tr ("This is the southern latitude of the area to be gridded.  The latitude may be entered in any of the "
                "following formats:<br><br>"
                "<ul>"
                "<li>Hemisphere Degrees decimal                 : S 28.4532</li>"
                "<li>Hemisphere Degrees minutes decimal         : S 28 27.192</li>"
                "<li>Hemisphere Degrees minutes seconds decimal : S 28 27 11.52</li>"
                "<li>Signed Degrees decimal                 : -28.4532</li>"
                "<li>Signed Degrees minutes decimal         : -28 27.192</li>"
                "<li>Signed Degrees minutes seconds decimal : -28 27 11.52</li>"
                "</ul>"
                "south latitude is negative :<br><br>"
                "Ex. : -28 27 11.52 = S28 27 11.52 = s 28 27.192<br><br>");

QString nlatText = 
  startPage::tr ("This is the northern latitude of the area to be gridded.  The latitude may be entered in any of the "
                "following formats:<br><br>"
                "<ul>"
                "<li>Hemisphere Degrees decimal                 : S 28.4532</li>"
                "<li>Hemisphere Degrees minutes decimal         : S 28 27.192</li>"
                "<li>Hemisphere Degrees minutes seconds decimal : S 28 27 11.52</li>"
                "<li>Signed Degrees decimal                 : -28.4532</li>"
                "<li>Signed Degrees minutes decimal         : -28 27.192</li>"
                "<li>Signed Degrees minutes seconds decimal : -28 27 11.52</li>"
                "</ul>"
                "South latitude is negative :<br><br>"
                "Ex. : -28 27 11.52 = S28 27 11.52 = s 28 27.192<br><br>");

QString wlonText = 
  startPage::tr ("This is the western longitude of the area to be gridded.  The longitude may be entered in any of the "
                "following formats:<br><br>"
                "<ul>"
                "<li>Hemisphere Degrees decimal                 : W 137.4532</li>"
                "<li>Hemisphere Degrees minutes decimal         : W 137 27.192</li>"
                "<li>Hemisphere Degrees minutes seconds decimal : W 137 27 11.52</li>"
                "<li>Signed Degrees decimal                 : -137.4532</li>"
                "<li>Signed Degrees minutes decimal         : -137 27.192</li>"
                "<li>Signed Degrees minutes seconds decimal : -137 27 11.52</li>"
                "</ul>"
                "West longitude is negative :<br><br>"
                "Ex. : -137 27 11.52 = W137 27 11.52 = w 137 27.192<br><br>");

QString elonText = 
  startPage::tr ("This is the eastern longitude of the area to be gridded.  The longitude may be entered in any of the "
                "following formats:<br><br>"
                "<ul>"
                "<li>Hemisphere Degrees decimal                 : W 137.4532</li>"
                "<li>Hemisphere Degrees minutes decimal         : W 137 27.192</li>"
                "<li>Hemisphere Degrees minutes seconds decimal : W 137 27 11.52</li>"
                "<li>Signed Degrees decimal                 : -137.4532</li>"
                "<li>Signed Degrees minutes decimal         : -137 27.192</li>"
                "<li>Signed Degrees minutes seconds decimal : -137 27 11.52</li>"
                "</ul>"
                "West longitude is negative :<br><br>"
                "Ex. : -137 27 11.52 = W137 27 11.52 = w 137 27.192<br><br>");

QString area_PFMText = 
  startPage::tr ("Use this button to use the minimum bounding rectangle for an area that is defined internally in a "
		 "pre-existing PFM structure.");

QString gridTypeText = 
  startPage::tr ("This combo box allows you to select the output file format.  Either the old CHRTR format or the new "
                 "CHRTR2 format.  If the name doesn't have a .fin or .ch2 extension one will be appended.  You may "
                 "use the <b>Browse</b> button to select an existing CHRTR (.fin) or CHRTR2 (.ch2) file to be overwritten.");

QString outputFileText = 
  startPage::tr ("This is the output file name.  If the name doesn't have a .fin or .ch2 extension one will be appended.  You may "
                 "use the <b>Browse</b> button to select an existing CHRTR (.fin) or CHRTR2 (.ch2) file to be overwritten.");

QString output_fileBrowseText = 
  startPage::tr ("Use this button to select an existing CHRTR (.fin) or CHRTR2 (.ch2) file to overwrite.");
