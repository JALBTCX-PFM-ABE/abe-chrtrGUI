
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




#ifndef VERSION

#define     VERSION     "PFM Software - chrtrGUI V3.17 - 08/07/19"

#endif

/*! <pre>

    Version 1.0
    Jan C. Depner
    08/02/05

    First version.


    Version 1.01
    Jan C. Depner
    03/28/06

    Replaced QVBox, QHBox, QVGroupBox, and QHGroupBox with QVBoxLayout, QHBoxLayout, and QGroupBox to prepare for
    Qt 4.


    Version 1.2
    Jan C. Depner
    04/13/06

    Fixed some abject stupidity in saving the options - mea culpa, mea culpa, mea maxima culpa.


    Version 1.21
    Jan C. Depner
    06/05/06

    Removed inside.cpp and get_area_mbr.cpp.  Moved to utility.


    Version 1.22
    Jan C. Depner
    06/30/06

    Added format descriptions to context help.


    Version 1.23
    Jan C. Depner
    08/08/06

    Added *.gsf to the GSF file mask.


    Version 1.24
    Jan C. Depner
    09/08/06

    Switched to overrideCursor for wait state.


    Version 1.25
    Jan C. Depner
    02/01/07

    Added PFM as an input option.


    Version 1.26
    Jan C. Depner
    02/20/07

    Save input filters.


    Version 1.27
    Jan C. Depner
    08/24/07

    Switched from setGeometry to resize and move.  See Qt4 X11 window geometry documentation.


    Version 1.28
    Jan C. Depner
    10/22/07

    Added fflush calls after prints to stderr since flush is not automatic in Windows.


    Version 1.29
    Jan C. Depner
    12/11/07

    Fixed input browse bug (XYZ).


    Version 1.30
    Jan C. Depner
    03/10/08

    Fixed the directory browse function so that you don't have to navigate around if you want the current working
    directory.


    Version 1.31
    Jan C. Depner
    03/21/08

    Fixed minor bug with the way we shelled QProcess if we had specified an area file in the Browse file dialog.


    Version 1.32
    Jan C. Depner
    04/03/08

    Added nibble option.


    Version 2.00
    Jan C. Depner
    04/07/08

    Reads chrtrGUI parameter file (.chp) from command line and populates the options and input files.
    Replaced single .h files from utility library with include of nvutility.h


    Version 2.01
    Jan C. Depner
    04/08/08

    Corrected the directory browse location problem.  Automatically name the output file the same as
    the area file but in the current working directory.


    Version 2.02
    Jan C. Depner
    06/05/08

    Added ability to define area using PFM or UNISIPS mosaic file.


    Version 2.03
    Jan C. Depner
    04/06/09

    Better default size.


    Version 2.04
    Jan C. Depner
    05/21/09

    Set all QFileDialogs to use List mode instead of Detail mode.


    Version 2.05
    Jan C. Depner
    06/16/09

    Replaced closing message box with output to chrtrList.


    Version 2.06
    Jan C. Depner
    06/26/09

    Added support for WLF data.


    Version 2.07
    Jan C. Depner
    04/29/10

    Fixed posfix and fixpos calls to use numeric constants instead of strings for type.


    Version 3.00
    Jan C. Depner
    07/27/10

    Now supports running the chrtr2 program (with CHRTR2 file format output) in addition to the old
    chrtr program.


    Version 3.01
    Jan C. Depner
    08/26/10

    Allows multiple directory selection in the directory browse option of the input file page.


    Version 3.02
    Jan C. Depner
    01/06/11

    Correct problem with the way I was instantiating the main widget.  This caused an intermittent error on Windows7/XP.


    Version 3.03
    Jan C. Depner
    06/27/11

    Save all directories used by the QFileDialogs.  Add current working directory to the sidebar for all QFileDialogs.


    Version 3.04
    Jan C. Depner
    07/22/11

    Using setSidebarUrls function from nvutility to make sure that current working directory (.) and
    last used directory are in the sidebar URL list of QFileDialogs.


    Version 3.05
    Jan C. Depner
    11/30/11

    Converted .xpm icons to .png icons.


    Version 3.06
    Jan C. Depner (PFM Software)
    12/09/13

    Switched to using .ini file in $HOME (Linux) or $USERPROFILE (Windows) in the ABE.config directory.  Now
    the applications qsettings will not end up in unknown places like ~/.config/navo.navy.mil/blah_blah_blah on
    Linux or, in the registry (shudder) on Windows.


    Version 3.07
    Jan C. Depner (PFM Software)
    01/06/14

    - Fixed an obvious screwup in inputPage.cpp where I was re-using the loop counters.
      Scoping in C++ saved my bacon but it was just too damn confusing.
    - Added CZMIL *cpf data type.


    Version 3.08
    Jan C. Depner (PFM Software)
    03/01/14

    - Removed include of hmpsparm.h (not used).


    Version 3.09
    Jan C. Depner (PFM Software)
    03/17/14

    Removed WLF support.  Top o' the mornin' to ye!


    Version 3.10
    Jan C. Depner (PFM Software)
    05/07/14

    Fixed freads and fgets without return check.


    Version 3.11
    Jan C. Depner (PFM Software)
    05/27/14

    Removed UNISIPS support and replaced with CZMIL support (even though chrtr and chrtr2 don't support it yet).


    Version 3.12
    Jan C. Depner (PFM Software)
    07/01/14

    - Replaced all of the old, borrowed icons with new, public domain icons.  Mostly from the Tango set
      but a few from flavour-extended and 32pxmania.


    Version 3.13
    Jan C. Depner (PFM Software)
    07/23/14

    - Switched from using the old NV_INT64 and NV_U_INT32 type definitions to the C99 standard stdint.h and
      inttypes.h sized data types (e.g. int64_t and uint32_t).


    Version 3.14
    Jan C. Depner (PFM Software)
    03/31/15

    - Fixed name filter for GSF files so that it wouldn't find files that don't end in .dNN where NN is numeric.
      This prevents us from seeing, for example, ESRI shape .dbf files in the GSF name list.
    - Added ability to use ESRI Polygon, PolygonZ, PolygonM, PolyLine, PolyLineZ, or PolyLineM geographic shape
      files as area files.


    Version 3.15
    Jan C. Depner (PFM Software)
    08/27/16

    - Now uses the same font as all other ABE GUI apps.  Font can only be changed in pfmView Preferences.


    Version 3.16
    Jan C. Depner (PFM Software)
    05/02/17

    - Switched to using the TEMP directory (from QDir::tempPath) for temporary shared_file.


    Version 3.17
    Jan C. Depner (PFM Software)
    08/07/19

    - Now that get_area_mbr supports shape files we don't need to handle it differently from the other
      area file types.

</pre>*/
