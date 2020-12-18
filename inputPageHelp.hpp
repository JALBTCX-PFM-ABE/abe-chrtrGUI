
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



QString formatText = 
  inputPage::tr ("<br><br>The following file formats are accepted by the chrtrGUI program:<br><br>"
                "<ul>"
                "<li>GSF (any extension but usually .dNN where NN represents a 2 digit number)</li>"
                "<li>CHARTS HOF (extension .hof)</li>"
                "<li>CHARTS TOF (extension .tof)</li>"
                "<li>Pure File Magic (extension .pfm)</li>"
                "<li>DPG (extension .dpg)</li>"
                "<li>RDP (extension .rdp)</li>"
                "<li>LLZ (extension .llz)</li>"
                "<li>CZMIL (extension .cpf)</li>"
                "<li>SHOALS (extension .out)</li>"
                "<li>ASCII XYZ (extension .xyz, .txt, .raw [HYPACK])</li>"
                "<ul>"
                "<li>Hypack yxz file in the following format:</li>"
                "<li>DDD-MM-SS.SSSs,DDD-MM-SS.SSSs,DD.DDD</li>"
                "<li>Example: 013-27-18.771N,144-37-41.383E,53.230</li>"
                "<li>Hypack RAW files in the following format:</li>"
                "<li>YEAR DAY HH:MM:SS.SSSS   DD.ddddddddd  DDD.ddddddddd   depth   depth   depth</li>"
                "<li>Example: 2001 017 03:25:10.0620   13.430910402  144.660955271    7.06    8.77    8.02</li>"
                "<li>All fields that start with a # are comments.  Third depth is tide corrected.</li>"
                "<li>Generic YXZ files in the following formats:</li>"
                "<li> [signed] lat degrees decimal  [signed] lon degrees decimal  value</li>"
                "<li> [signed] lat degrees decimal,[signed] lon degrees decimal,value</li>"
                "<li> Example: 21.000278 -157.619722 223</li>"
                "<li> Example: 21.000278,-157.619722,223</li>"
                "</ul>"
                "<li>ASCII XYZ (extension .xyz)</li>"
                "<ul>"
                "<li>Generic XYZ files in the following formats:</li>"
                "<li> [signed] lon degrees decimal  [signed] lat degrees decimal  value</li>"
                "<li> [signed] lon degrees decimal,[signed] lat degrees decimal,value</li>"
                "<li> Example: -157.619722 21.000278 223</li>"
                "<li> Example: -157.619722,21.000278,223</li>"
                "</ul>");

QString inputBrowseText = 
  inputPage::tr ("This button allows you to select multiple input files.  You may use this button as many times as "
		 "needed to define all of the desired input files.  This may also be used in conjunction with the "
		 "<b>Browse Directories</b> button.  All selected files are added to the <b>Input files</b> list.") + formatText;

QString dirBrowseText = 
  inputPage::tr ("This button allows you to select multiple input files by specifiying a top level directory.  Using "
		 "the <b>Directory file mask</b> field as the filter, all files below the selected directory will be "
		 "searched for matching files.  These files will be added to the <b>Input files</b> list.  This may "
		 "also be used in conjunction with the <b>Browse Files</b> button.  You may use this button as many "
		 "times as needed to define all of the desired input files.") + formatText;

QString fileMaskText = 
  inputPage::tr ("This is the file search filter for the <b>Browse Directories</b> button.  You may select a filter "
                "from the existing list or type in your own special filter.  This filter is used in searching "
                "directory trees when using the <b>Browse Directories</b> button.") + formatText;

QString nominalText = 
  inputPage::tr ("Set this flag to force <b>chrtr</b> or <b>chrtr2</b> to try to use nominal depth from input GSF files.  If nominal "
                 "depth is available in the GSF file it will be used.  If not, true depth will be used and a warning "
                 "will be printed out.");

QString inputFilesText = 
  inputPage::tr ("This is a list of all files that will be input to the chrtr or chrtr2 grid.  You may edit the list or even "
                "add files by hand (although why anyone would do this is beyond me).  There is limited text editor "
                "functionality available for this list.  Right click to get a menu of functions including undo, redo, "
                "cut, paste, and others.  If you make a mistake and add duplicate files using the <b>Browse "
                "Directories</b> button or even the <b>Browse Files</b> button, fear not.  The input file list is sorted "
                "and duplicates are culled out before the gridding process is started or the CHRTR parameters file is "
                "saved.") + formatText;
