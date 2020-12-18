
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



#include "startPage.hpp"
#include "startPageHelp.hpp"

startPage::startPage (QWidget *parent, OPTIONS *op):
  QWizardPage (parent)
{
  options = op;


  setPixmap (QWizard::WatermarkPixmap, QPixmap(":/icons/chrtrGUIWatermark.png"));


  setTitle (tr ("Introduction"));

  setWhatsThis (tr ("See, it really works!"));

  QLabel *label = new QLabel (tr ("chrtrGUI is a tool for building a MInimum curvature SPline (MISP) surface from input "
                                  "data.  The area can be defined using a preexisting area file (either ISS-60, generic, "
                                  "or Army Corps .afs), by entering the corner coordinates in the provided slots, or by "
                                  "defining the area in the optional map interface.  Help is available by clicking on "
                                  "the Help button and then clicking on the item for which you want help.  Click "
                                  "<b>Next</b> to continue or <b>Cancel</b> to exit."));

  label->setWordWrap(true);


  QVBoxLayout *vbox = new QVBoxLayout (this);
  vbox->addWidget (label);
  vbox->addStretch (10);



  QGroupBox *aBox = new QGroupBox (tr ("Area file"), this);
  QHBoxLayout *aBoxLayout = new QHBoxLayout;
  aBox->setLayout (aBoxLayout);
  aBoxLayout->setSpacing (10);

  area_file_edit = new QLineEdit (this);
  area_file_edit->setWhatsThis (area_fileText);
  aBoxLayout->addWidget (area_file_edit, 10);

  QPushButton *area_file_browse = new QPushButton (tr ("Browse..."), this);
  area_file_browse->setWhatsThis (area_fileBrowseText);
  connect (area_file_browse, SIGNAL (clicked ()), this, SLOT (slotAreaFileBrowse ()));
  aBoxLayout->addWidget (area_file_browse, 1);

  QPushButton *area_map = new QPushButton (tr ("Map..."), this);
  area_map->setToolTip (tr ("Create an area file using areaCheck")); 
  area_map->setWhatsThis (area_mapText);
  connect (area_map, SIGNAL (clicked ()), this, SLOT (slotAreaMap ()));
  aBoxLayout->addWidget (area_map, 1);

  QPushButton *area_pfm = new QPushButton (tr ("PFM..."), this);
  area_pfm->setToolTip (tr ("Use the area in an already existing PFM structure")); 
  area_pfm->setWhatsThis (area_PFMText);
  connect (area_pfm, SIGNAL (clicked ()), this, SLOT (slotAreaPFM ()));
  aBoxLayout->addWidget (area_pfm);


  vbox->addWidget (aBox);


  QGroupBox *gBox = new QGroupBox (tr ("Geographic Bounds"), this);
  QHBoxLayout *gBoxLayout = new QHBoxLayout;
  gBox->setLayout (gBoxLayout);
  gBoxLayout->setSpacing (10);


  QGroupBox *sBox = new QGroupBox (tr ("South Latitude"), this);
  QHBoxLayout *sBoxLayout = new QHBoxLayout;
  sBox->setLayout (sBoxLayout);
  sBoxLayout->setSpacing (10);

  slat = new QLineEdit (this);
  slat->setToolTip (tr ("Enter south latitude of area"));
  slat->setWhatsThis (slatText);
  sBoxLayout->addWidget (slat);


  gBoxLayout->addWidget (sBox);


  QGroupBox *nBox = new QGroupBox (tr ("North Latitude"), this);
  QHBoxLayout *nBoxLayout = new QHBoxLayout;
  nBox->setLayout (nBoxLayout);
  nBoxLayout->setSpacing (10);

  nlat = new QLineEdit (this);
  nlat->setToolTip (tr ("Enter north latitude of area"));
  nlat->setWhatsThis (nlatText);
  nBoxLayout->addWidget (nlat);


  gBoxLayout->addWidget (nBox);


  QGroupBox *wBox = new QGroupBox (tr ("West Longitude"), this);
  QHBoxLayout *wBoxLayout = new QHBoxLayout;
  wBox->setLayout (wBoxLayout);
  wBoxLayout->setSpacing (10);

  wlon = new QLineEdit (this);
  wlon->setToolTip (tr ("Enter west longitude of area"));
  wlon->setWhatsThis (wlonText);
  wBoxLayout->addWidget (wlon);


  gBoxLayout->addWidget (wBox);


  QGroupBox *eBox = new QGroupBox (tr ("East Longitude"), this);
  QHBoxLayout *eBoxLayout = new QHBoxLayout;
  eBox->setLayout (eBoxLayout);
  eBoxLayout->setSpacing (10);

  elon = new QLineEdit (this);
  elon->setToolTip (tr ("Enter east longitude of area"));
  elon->setWhatsThis (elonText);
  eBoxLayout->addWidget (elon);


  gBoxLayout->addWidget (eBox);


  vbox->addWidget (gBox);


  QGroupBox *oBox = new QGroupBox (tr ("CHRTR output file"), this);
  QHBoxLayout *oBoxLayout = new QHBoxLayout;
  oBox->setLayout (oBoxLayout);
  oBoxLayout->setSpacing (10);

  QGroupBox *typeBox = new QGroupBox (tr ("Grid type"), this);
  QHBoxLayout *typeBoxLayout = new QHBoxLayout;
  typeBox->setLayout (typeBoxLayout);
  typeBoxLayout->setSpacing (10);

  gridType = new QComboBox (this);
  gridType->setToolTip (tr ("Set the grid type for the output file"));
  gridType->setWhatsThis (gridTypeText);
  gridType->setEditable (false);
  gridType->addItem ("CHRTR");
  gridType->addItem ("CHRTR2");
  gridType->setCurrentIndex (options->type);
  connect (gridType, SIGNAL (currentIndexChanged (int)), this, SLOT (slotGridTypeChanged (int)));
  typeBoxLayout->addWidget (gridType);
  oBoxLayout->addWidget (typeBox);

  outputFile = new QLineEdit (this);
  outputFile->setWhatsThis (outputFileText);
  oBoxLayout->addWidget (outputFile, 10);

  QPushButton *output_file_browse = new QPushButton (tr ("Browse..."), this);
  output_file_browse->setWhatsThis (output_fileBrowseText);
  connect (output_file_browse, SIGNAL (clicked ()), this, SLOT (slotOutputFileBrowse ()));
  oBoxLayout->addWidget (output_file_browse, 1);


  vbox->addWidget (oBox);


  //  If we read in a parameter file, set the fields.

  if (options->readParams)
    {
      QString tmp;
      nlat->setText (tmp.setNum (options->mbr.max_y, 'f', 9));
      wlon->setText (tmp.setNum (options->mbr.min_x, 'f', 9));
      elon->setText (tmp.setNum (options->mbr.max_x, 'f', 9));
      slat->setText (tmp.setNum (options->mbr.min_y, 'f', 9));
      outputFile->setText (options->outputFile);

      registerField ("nlat", nlat);
      registerField ("wlon", wlon);
      registerField ("elon", elon);
      registerField ("slat", slat);
      registerField ("outputFile", outputFile);
    }
  else
    {
      registerField ("nlat*", nlat);
      registerField ("wlon*", wlon);
      registerField ("elon*", elon);
      registerField ("slat*", slat);
      registerField ("outputFile*", outputFile);
    }
}



void 
startPage::slotAreaFileBrowse ()
{
  QFileDialog fd (this, tr ("chrtrGUI Area file"));
  fd.setViewMode (QFileDialog::List);


  //  Always add the current working directory and the last used directory to the sidebar URLs in case we're running from the command line.
  //  This function is in the nvutility library.

  setSidebarUrls (&fd, options->area_dir);


  QStringList filters;
  filters << tr ("area file (*.are *.afs *.ARE *.shp *.SHP)");


  fd.setNameFilters (filters);
  fd.setFileMode (QFileDialog::ExistingFile);
  fd.selectNameFilter (tr ("area file (*.are *.afs *.ARE *.shp *.SHP)"));


  QStringList files;


  NV_F64_XYMBR mbr;
  double deg, min, sec, polygon_x[200], polygon_y[200];
  int32_t polygon_count;
  char hem;

  if (fd.exec () == QDialog::Accepted) 
    {
      files = fd.selectedFiles ();

      QString file = files.at (0);

      if (!file.isEmpty ())
        {
          char path[1024];
          strcpy (path, file.toLatin1 ());

          get_area_mbr (path, &polygon_count, polygon_x, polygon_y, &mbr);


          area_file_edit->setText (file);


          nlat->setText (QString (fixpos (mbr.max_y, &deg, &min, &sec, &hem, POS_LAT, POS_HDMS)));
          slat->setText (QString (fixpos (mbr.min_y, &deg, &min, &sec, &hem, POS_LAT, POS_HDMS)));
          elon->setText (QString (fixpos (mbr.max_x, &deg, &min, &sec, &hem, POS_LON, POS_HDMS)));
          wlon->setText (QString (fixpos (mbr.min_x, &deg, &min, &sec, &hem, POS_LON, POS_HDMS)));


	  //  Automatically name the output file.

	  if (outputFile->text ().isEmpty ())
	    {
	      QFileInfo *name = new QFileInfo (file);
	      QString oname = name->fileName ();

              switch (options->type)
                {
                case 0:
                  oname.replace (oname.length () - 4, 4, ".fin");
                  break;

                case 1:
                  oname.replace (oname.length () - 4, 4, ".ch2");
                  break;
                }

	      outputFile->setText (oname);
	    }
        }
    }

  options->area_dir = fd.directory ().absolutePath ();
}



void 
startPage::slotMapReadyReadStandardError ()
{
  QByteArray response = mapProc->readAllStandardError ();
  char *res = response.data ();

  fprintf (stderr,"%s %s %d %s\n", __FILE__,  __FUNCTION__, __LINE__, res);
  fflush (stderr);
}



void 
startPage::slotMapReadyReadStandardOutput ()
{
  QByteArray response = mapProc->readAllStandardOutput ();
  char *res = response.data ();

  fprintf (stderr,"%s %s %d %s\n", __FILE__,  __FUNCTION__, __LINE__, res);
  fflush (stderr);
}



void 
startPage::slotMapError (QProcess::ProcessError error)
{
  switch (error)
    {
    case QProcess::FailedToStart:
      QMessageBox::critical (this, tr ("chrtrGUI map editor"), tr ("Unable to start the map editor process!"));
      break;

    case QProcess::Crashed:
      QMessageBox::critical (this, tr ("chrtrGUI map editor"), tr ("The map editor process crashed!"));
      break;

    case QProcess::Timedout:
      QMessageBox::critical (this, tr ("chrtrGUI map editor"), tr ("The map editor process timed out!"));
      break;

    case QProcess::WriteError:
      QMessageBox::critical (this, tr ("chrtrGUI map editor"), 
                             tr ("There was a write error from the map editor process!"));
      break;

    case QProcess::ReadError:
      QMessageBox::critical (this, tr ("chrtrGUI map editor"),
                             tr ("There was a read error from the map editor process!"));
      break;

    case QProcess::UnknownError:
      QMessageBox::critical (this, tr ("chrtrGUI map editor"),
                             tr ("The map editor process died with an unknown error!"));
      break;
    }
}



void 
startPage::slotMapDone (int exitCode __attribute__ ((unused)), QProcess::ExitStatus exitStatus __attribute__ ((unused)))
{
  NV_F64_XYMBR mbr;
  double deg, min, sec, polygon_x[200], polygon_y[200];
  int32_t polygon_count;
  char hem;

  char path[512];
  strcpy (path, temp_area_name.toLatin1 ());

  if (get_area_mbr (path, &polygon_count, polygon_x, polygon_y, &mbr))
    {
      nlat->setText (QString (fixpos (mbr.max_y, &deg, &min, &sec, &hem, POS_LAT, POS_HDMS)));
      slat->setText (QString (fixpos (mbr.min_y, &deg, &min, &sec, &hem, POS_LAT, POS_HDMS)));
      elon->setText (QString (fixpos (mbr.max_x, &deg, &min, &sec, &hem, POS_LON, POS_HDMS)));
      wlon->setText (QString (fixpos (mbr.min_x, &deg, &min, &sec, &hem, POS_LON, POS_HDMS)));
    }
}



void 
startPage::slotAreaMap ()
{
  mapProc = new QProcess (this);
  QStringList arguments;


  //  If we haven't selected an area file.

  if (area_file_edit->text ().isEmpty ())
    {
      temp_area_name.sprintf ("TEMPORARY_AREA_FILE_%d.are", getpid ());


      //  If we manually entered the area bounds.

      if (!nlat->text ().isEmpty () && !slat->text ().isEmpty () && !wlon->text ().isEmpty () && !elon->text ().isEmpty ())
        {
          char string[512], ltstring[40], lnstring[40];
          FILE *fp;

          strcpy (string, temp_area_name.toLatin1 ());

          if ((fp = fopen (string, "w")) == NULL)
            {
              QMessageBox::critical (this, tr ("chrtrGUI"), tr ("Unable to open temporary area file!"));
            }
          else
            {
              strcpy (ltstring, slat->text ().toLatin1 ());
              strcpy (lnstring, wlon->text ().toLatin1 ());
              fprintf (fp, "%s, %s\n", ltstring, lnstring);
              strcpy (ltstring, nlat->text ().toLatin1 ());
              fprintf (fp, "%s, %s\n", ltstring, lnstring);
              strcpy (lnstring, elon->text ().toLatin1 ());
              fprintf (fp, "%s, %s\n", ltstring, lnstring);
              strcpy (ltstring, slat->text ().toLatin1 ());
              fprintf (fp, "%s, %s\n", ltstring, lnstring);

              fclose (fp);
            }
        }
    }


  //  If we had an area file.

  else
    {
      temp_area_name = area_file_edit->text ();
    }

 
 arguments += "--file";
 arguments += temp_area_name;


 connect (mapProc, SIGNAL (finished (int, QProcess::ExitStatus)), this, 
	  SLOT (slotMapDone (int, QProcess::ExitStatus)));
 connect (mapProc, SIGNAL (readyReadStandardError ()), this, SLOT (slotMapReadyReadStandardError ()));
 connect (mapProc, SIGNAL (readyReadStandardOutput ()), this, SLOT (slotMapReadyReadStandardOutput ()));
 connect (mapProc, SIGNAL (error (QProcess::ProcessError)), this, SLOT (slotMapError (QProcess::ProcessError)));

 mapProc->start ("areaCheck", arguments);
}



void 
startPage::slotAreaPFM ()
{
  QStringList         files, filters;
  QString             file;
  int32_t             hnd;
  PFM_OPEN_ARGS       open_args;


  QFileDialog *fd = new QFileDialog (this, tr ("chrtrGUI Open PFM Structure (area)"));
  fd->setViewMode (QFileDialog::List);


  //  Always add the current working directory and the last used directory to the sidebar URLs in case we're running from the command line.
  //  This function is in the nvutility library.

  setSidebarUrls (fd, options->area_dir);


  filters << tr ("PFM (*.pfm)");

  fd->setNameFilters (filters);
  fd->setFileMode (QFileDialog::ExistingFile);
  fd->selectNameFilter (tr ("PFM (*.pfm)"));

  if (fd->exec () == QDialog::Accepted)
    {
      files = fd->selectedFiles ();

      QString pfm_name = files.at (0);


      if (!pfm_name.isEmpty())
	{
	  strcpy (open_args.list_path, pfm_name.toLatin1 ());
	  open_args.checkpoint = 0;

	  if ((hnd = open_existing_pfm_file (&open_args)) >= 0)
	    {
	      NV_F64_XYMBR mbr;
	      double deg, min, sec;
	      char hem;
	      uint8_t east = NVFalse, west = NVFalse;


	      /*  Check for dateline crossing.  If you're making an area that goes more than half way around the earth
		  you're on your own!  */

	      for (int32_t i = 0 ; i < open_args.head.polygon_count ; i++)
		{
		  if (open_args.head.polygon[i].x < -90.0) west = NVTrue;
		  if (open_args.head.polygon[i].x > 90.0) east = NVTrue;
		}


	      mbr.min_y = 99999999999.0;
	      mbr.min_x = 99999999999.0;
	      mbr.max_y = -99999999999.0;
	      mbr.max_x = -99999999999.0;
    
	      for (int32_t i = 0 ; i < open_args.head.polygon_count ; i++)
		{
		  if (east && west && open_args.head.polygon[i].x < 0.0) open_args.head.polygon[i].x += 360.0;

		  if (open_args.head.polygon[i].y < mbr.min_y) mbr.min_y = open_args.head.polygon[i].y;
		  if (open_args.head.polygon[i].y > mbr.max_y) mbr.max_y = open_args.head.polygon[i].y;
		  if (open_args.head.polygon[i].x < mbr.min_x) mbr.min_x = open_args.head.polygon[i].x;
		  if (open_args.head.polygon[i].x > mbr.max_x) mbr.max_x = open_args.head.polygon[i].x;
		}

	      close_pfm_file (hnd);


	      nlat->setText (QString (fixpos (mbr.max_y, &deg, &min, &sec, &hem, POS_LAT, POS_HDMS)));
	      slat->setText (QString (fixpos (mbr.min_y, &deg, &min, &sec, &hem, POS_LAT, POS_HDMS)));
	      elon->setText (QString (fixpos (mbr.max_x, &deg, &min, &sec, &hem, POS_LON, POS_HDMS)));
	      wlon->setText (QString (fixpos (mbr.min_x, &deg, &min, &sec, &hem, POS_LON, POS_HDMS)));


	      //  Automatically name the output file.

	      if (outputFile->text ().isEmpty ())
		{
		  QFileInfo *name = new QFileInfo (pfm_name);
		  QString oname = name->fileName ();

                  switch (options->type)
                    {
                    case 0:
                      oname.append (".fin");
                      break;

                    case 1:
                      oname.append (".ch2");
                      break;
                    }

		  outputFile->setText (oname);
		}
	    }
	}

      options->area_dir = fd->directory ().absolutePath ();
    }
}



void 
startPage::slotGridTypeChanged (int index)
{
  options->type = index;

  if (!outputFile->text ().isEmpty ())
    {
      QString text = outputFile->text ();

      switch (options->type)
        {
        case 0:
          if (text.endsWith (".ch2")) text.replace (".ch2", ".fin");
          break;

        case 1:
          if (text.endsWith (".fin")) text.replace (".fin", ".ch2");
          break;
        }

      outputFile->setText (text);
    }
}



void 
startPage::slotOutputFileBrowse ()
{
  static QString dir = ".";


  QFileDialog fd (this, tr ("chrtrGUI Output file"));
  fd.setViewMode (QFileDialog::List);
  fd.setDirectory (dir);

  QStringList filters;
  filters << tr ("CHRTR file (*.fin)")
          << tr ("CHRTR2 file (*.ch2)");


  fd.setNameFilters (filters);
  fd.setFileMode (QFileDialog::AnyFile);
  switch (options->type)
    {
    case 0:
      fd.selectNameFilter (tr ("CHRTR file (*.fin)"));
      break;

    case 1:
      fd.selectNameFilter (tr ("CHRTR2 file (*.ch2)"));
      break;
    }


  QStringList files;


  if (fd.exec () == QDialog::Accepted) 
    {
      files = fd.selectedFiles ();

      QString file = files.at (0);

      if (!file.isEmpty ())
        {
          outputFile->setText (file);
        }
    }

  dir = fd.directory ().path ();
}
