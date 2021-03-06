
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



QString bStartText = 
  runPage::tr ("Click this button to start the gridding process.  The progress of the batch CHRTR or CHRTR2 run will be displayed "
               "in the list box below this button.  Once you click this button you will not be able to interrupt the "
               "gridding process (short of killing it from the operating system).  After the process is finished you "
               "will only be able to quit (this is a good reason to save your settings to a .chp file).");

QString bSaveText = 
  runPage::tr ("Use this button if you wish to save the settings (including input file list) to be used to run the chrtr "
               "or chrtr2 program at a later time.  To do this you simply run <b>chrtr CHP_FILENAME</b> or <b>chrtr2 CHP_FILENAME</b>.  "
               "You may select an existing .chp file or type in the name of a new .chp file.  If you type in a new name you do not have to "
               "add the .chp extension, one will be appended automatically.");

QString chrtrListText = 
  runPage::tr ("This area will display the output of the external MISP gridding process.");
