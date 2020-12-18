
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
#include "chrtrGUIHelp.hpp"

chrtrGUI::chrtrGUI (int *argc, char **argv, QWidget *parent)
  : QWizard (parent, 0)
{
  uint8_t readParameterFile (char *file, OPTIONS *options, char **input_files[], int32_t *numfiles);
  void set_defaults (OPTIONS *options);


  QResource::registerResource ("/icons.rcc");


  //  Set the main icon

  setWindowIcon (QIcon (":/icons/chrtrGUIWatermark.png"));


  set_defaults (&options);


  //  Check for a CHRTR parameter file on the command line.  If there is one we will override
  //  the envin options and pre-fill the input file list.

  envin (&options);


  // Set the application font

  QApplication::setFont (options.font);


  numfiles = 0;
  options.readParams = NVFalse;

  if (*argc > 1)
    {
      if (QString (argv[1]).endsWith (".chp"))
	{
	  FILE         *fp;
	  char         varin[1024], info[1024], finfile[1024];
	  int32_t      tmp_i;
	  double       tmp_pos;
	  uint8_t      input_file_flag = NVFalse;

	  if ((fp = fopen (argv[1], "r")) != NULL)
	    {
	      options.grid_size_meters = 0.0;


	      //  Loop through all the parameters until "end" is encountered.

	      while (ngets (varin, sizeof (varin), fp) != NULL)
		{
		  //  Put everything to the right of the equals sign in 'info'.

		  if (strchr (varin, '=') != NULL) strcpy (info, (strchr (varin, '=') + 1));

                  if (strstr (varin, "[grid type]")) sscanf (info, "%d", &options.type);
		  if (strstr (varin, "[gridmin]")) sscanf (info, "%lf", &options.grid_size);
		  if (strstr (varin, "[gridmeter]")) sscanf (info, "%lf", &options.grid_size_meters);
		  if (strstr (varin, "[delta]")) sscanf (info, "%lf", &options.delta);
		  if (strstr (varin, "[reg_mutfact]")) sscanf (info, "%d", &options.regional_factor);
		  if (strstr (varin, "[search_radius]")) sscanf (info, "%lf", &options.search_radius);
		  if (strstr (varin, "[error_control]")) sscanf (info, "%d", &options.error_control);
		  if (strstr (varin, "[weight_factor]")) sscanf (info, "%d", &options.weight_factor);
		  if (strstr (varin, "[force_original_value]"))
		    {
		      sscanf (info, "%d", &tmp_i);
		      options.force_original_value = (uint8_t) tmp_i;
		    }
		  if (strstr (varin, "[nibble_value]")) sscanf (info, "%d", &options.nibble);
		  if (strstr (varin, "[nominal_depth]"))
		    {
		      sscanf (info, "%d", &tmp_i);
		      options.nominal = (uint8_t) tmp_i;
		    }
		  if (strstr (varin, "[minvalue]")) sscanf (info, "%lf", &options.minimum_value);
		  if (strstr (varin, "[maxvalue]")) sscanf (info, "%lf", &options.maximum_value);
		  if (strstr (varin, "[lat_south]")) 
		    {
		      posfix (info, &tmp_pos, POS_LAT);
		      options.mbr.min_y = tmp_pos;
		    }
		  if (strstr (varin, "[lat_north]"))
		    {
		      posfix (info, &tmp_pos, POS_LAT);
		      options.mbr.max_y = tmp_pos;
		    }
		  if (strstr (varin, "[lon_west]"))
		    {
		      posfix (info, &tmp_pos, POS_LON);
		      options.mbr.min_x = tmp_pos;
		    }
		  if (strstr (varin, "[lon_east]"))
		    {
		      posfix (info, &tmp_pos, POS_LON);
		      options.mbr.max_x = tmp_pos;
		    }
		  if (strstr (varin, "[output_file]"))
		    {
		      get_string (varin, finfile);
		      options.outputFile = QString (finfile);
		    }

		  if (input_file_flag)
		    {
		      if (strstr (varin, "**  End Input Files  **")) break;
	  
		      input_filenames[numfiles] = (char *) malloc (strlen (varin) + 1);
		      strcpy (input_filenames[numfiles], varin);
		      numfiles++;
		    }

		  if (strstr (varin, "**  Input Files  **")) input_file_flag = NVTrue;
		}

	      options.readParams = NVTrue;
	      fclose (fp);
	    }
	}
    }


  //  Set the window size and location from the defaults

  this->resize (options.width, options.height);
  this->move (options.window_x, options.window_y);


  setWizardStyle (QWizard::ClassicStyle);


  setOption (HaveHelpButton, true);
  setOption (ExtendedWatermarkPixmap, false);

  connect (this, SIGNAL (helpRequested ()), this, SLOT (slotHelpClicked ()));


  setPage (0, new startPage (this, &options));
  setPage (1, new optionsPage (this, &options));
  setPage (2, new inputPage (this, &options, &inputFiles, input_filenames, numfiles));
  setPage (3, new runPage (this, &chrtrList));


  //  If we read an input parameter file, free the filenames since we have stored them in the inputFile widget.

  for (int32_t i = 0 ; i < numfiles ; i++)
    {
      free (input_filenames[i]);
    }


  setButtonText (QWizard::CustomButton1, tr("&Run"));
  setOption (QWizard::HaveCustomButton1, true);
  button (QWizard::CustomButton1)->setToolTip (tr ("Run the gridding process"));
  button (QWizard::CustomButton1)->setWhatsThis (runText);
  setButtonText (QWizard::CustomButton2, tr("&Save"));
  setOption (QWizard::HaveCustomButton2, true);
  button (QWizard::CustomButton2)->setToolTip (tr ("Save the parameters to run from the command line"));
  button (QWizard::CustomButton2)->setWhatsThis (saveText);
  connect (this, SIGNAL (customButtonClicked (int)), this, SLOT (slotCustomButtonClicked (int)));


  setStartId (0);
}


void chrtrGUI::initializePage (int id)
{
  button (QWizard::HelpButton)->setIcon (QIcon (":/icons/contextHelp.png"));
  button (QWizard::CustomButton1)->setEnabled (false);
  button (QWizard::CustomButton2)->setEnabled (false);

  switch (id)
    {
    case 0:
      break;

    case 1:
      break;

    case 2:
      break;

    case 3:
      button (QWizard::CustomButton1)->setEnabled (true);
      button (QWizard::CustomButton2)->setEnabled (true);
      break;
    }
}



void chrtrGUI::cleanupPage (int id)
{
  switch (id)
    {
    case 0:
      break;

    case 1:
      break;

    case 2:
      break;

    case 3:
      break;
    }
}



void 
chrtrGUI::slotHelpClicked ()
{
  QWhatsThis::enterWhatsThisMode ();
}



void 
chrtrGUI::slotGridReadyReadStandardError ()
{
  static QString resp_string = "";


  QByteArray response = gridProc->readAllStandardError ();


  //  Parse the return response for carriage returns and line feeds

  for (int32_t i = 0 ; i < response.length () ; i++)
    {
      if (response.at (i) == '\n')
        {
          QListWidgetItem *cur = new QListWidgetItem (resp_string);

          chrtrList->addItem (cur);
          chrtrList->setCurrentItem (cur);
          chrtrList->scrollToItem (cur);

          resp_string = "";
        }
      else if (response.at (i) == '\r')
        {
          QListWidgetItem *rep = chrtrList->item (chrtrList->currentRow ());
          rep->setText (resp_string);

          resp_string = "";
        }
      else
        {
          resp_string += response.at (i);
        }
    }
}



void 
chrtrGUI::slotGridReadyReadStandardOutput ()
{
  static QString resp_string = "";


  QByteArray response = gridProc->readAllStandardOutput ();


  //  Parse the return response for carriage returns and line feeds

  for (int32_t i = 0 ; i < response.length () ; i++)
    {
      if (response.at (i) == '\n')
        {
          QListWidgetItem *cur = new QListWidgetItem (resp_string);

          chrtrList->addItem (cur);
          chrtrList->setCurrentItem (cur);
          chrtrList->scrollToItem (cur);

          resp_string = "";
        }
      else if (response.at (i) == '\r')
        {
          QListWidgetItem *rep = chrtrList->item (chrtrList->currentRow ());
          rep->setText (resp_string);

          resp_string = "";
        }
      else
        {
          resp_string += response.at (i);
        }
    }
}



void 
chrtrGUI::slotGridError (QProcess::ProcessError error)
{
  switch (error)
    {
    case QProcess::FailedToStart:
      QMessageBox::critical (this, tr ("chrtrGUI MISP gridding"), tr ("Unable to start the MISP gridding process!"));
      break;

    case QProcess::Crashed:
      QMessageBox::critical (this, tr ("chrtrGUI MISP gridding"), tr ("The MISP gridding process crashed!"));
      break;

    case QProcess::Timedout:
      QMessageBox::critical (this, tr ("chrtrGUI MISP gridding"), tr ("The MISP gridding process timed out!"));
      break;

    case QProcess::WriteError:
      QMessageBox::critical (this, tr ("chrtrGUI MISP gridding"), tr ("There was a write error from the MISP gridding process!"));
      break;

    case QProcess::ReadError:
      QMessageBox::critical (this, tr ("chrtrGUI MISP gridding"), tr ("There was a read error from the MISP gridding process!"));
      break;

    case QProcess::UnknownError:
      QMessageBox::critical (this, tr ("chrtrGUI MISP gridding"), tr ("The MISP gridding process died with an unknown error!"));
      break;
    }

  QFile (temp_run_file_name).remove ();
}



void 
chrtrGUI::slotGridDone (int exitCode __attribute__ ((unused)), QProcess::ExitStatus exitStatus __attribute__ ((unused)))
{
  QApplication::restoreOverrideCursor ();
  button (QWizard::CancelButton)->setEnabled (false);
  button (QWizard::FinishButton)->setEnabled (true);

  QFile (temp_run_file_name).remove ();

  chrtrList->addItem (" ");
  QListWidgetItem *cur = new QListWidgetItem (tr ("Finished gridding data, press Finish to exit."));

  chrtrList->addItem (cur);
  chrtrList->setCurrentItem (cur);
  chrtrList->scrollToItem (cur);
}



void 
chrtrGUI::slotCustomButtonClicked (int id __attribute__ ((unused)))
{
  uint8_t writeParameterFile (QString parameter_file, QStringList input_files, OPTIONS *options);

  char pos[100];

  strcpy (pos, field ("slat").toString ().toLatin1 ());
  posfix (pos, &options.mbr.min_y, POS_LAT);

  strcpy (pos, field ("nlat").toString ().toLatin1 ());
  posfix (pos, &options.mbr.max_y, POS_LAT);

  strcpy (pos, field ("wlon").toString ().toLatin1 ());
  posfix (pos, &options.mbr.min_x, POS_LON);

  strcpy (pos, field ("elon").toString ().toLatin1 ());
  posfix (pos, &options.mbr.max_x, POS_LON);

  options.outputFile = field ("outputFile").toString ();

  options.grid_size_meters = field ("meters").toDouble ();
  options.grid_size = field ("minutes").toDouble ();
  options.weight_factor = field ("factor").toInt ();
  options.force_original_value = field ("force").toBool ();
  options.nibble = field ("nibble").toInt ();
  options.minimum_value = field ("minimum").toDouble ();
  options.maximum_value = field ("maximum").toDouble ();
  options.delta = field ("delta").toDouble ();
  options.search_radius = field ("search").toInt ();
  options.error_control = field ("error").toInt ();
  options.regional_factor = field ("regional").toInt ();
  options.nominal = field ("nominal").toBool ();


  //  Use frame geometry to get the absolute x and y.

  QRect tmp = this->frameGeometry ();
  options.window_x = tmp.x ();
  options.window_y = tmp.y ();


  //  Use geometry to get the width and height.

  tmp = this->geometry ();
  options.width = tmp.width ();
  options.height = tmp.height ();


  //  Save the options to the QSettings file.

  envout (&options);


  //  Get the files from the QTextEdit box on the inputPage.

  QTextCursor inputCursor = inputFiles->textCursor ();

  inputCursor.setPosition (0);


  QStringList sort_files;

  sort_files.clear ();

  do
    {
      sort_files << inputCursor.block ().text ();
    } while (inputCursor.movePosition (QTextCursor::NextBlock));


  //  Sort so we can remove dupes.

  sort_files.sort ();


  //  Remove dupes and place into input_files.

  QString name, prev_name = "";
  input_files.clear ();

  for (int32_t i = 0 ; i < sort_files.size () ; i++)
    {
      name = sort_files.at (i);

      if (name != prev_name)
        {
          input_files.append (name);
          prev_name = name;
        }
    }


  QStringList arguments;

  switch (id)
    {
    case QWizard::CustomButton1:
      button (QWizard::BackButton)->setEnabled (false);
      button (QWizard::CustomButton1)->setEnabled (false);
      QApplication::setOverrideCursor (Qt::WaitCursor);


      temp_run_file_name = QDir::tempPath () + SEPARATOR + QString ("TEMPORARY_CHRTR_RUN_%1.chp").arg (getpid ());

      writeParameterFile (temp_run_file_name, input_files, &options);


      gridProc = new QProcess (this);

      arguments += temp_run_file_name;

 
      connect (gridProc, SIGNAL (finished (int, QProcess::ExitStatus)), this, SLOT (slotGridDone (int, QProcess::ExitStatus)));
      connect (gridProc, SIGNAL (readyReadStandardError ()), this, SLOT (slotGridReadyReadStandardError ()));
      connect (gridProc, SIGNAL (readyReadStandardOutput ()), this, SLOT (slotGridReadyReadStandardOutput ()));
      connect (gridProc, SIGNAL (error (QProcess::ProcessError)), this, SLOT (slotGridError (QProcess::ProcessError)));

      switch (options.type)
        {
        case 0:
          gridProc->start ("chrtr", arguments);
          break;

        case 1:
          gridProc->start ("chrtr2", arguments);
          break;
        }
      break;

    case QWizard::CustomButton2:
      QFileDialog *fd = new QFileDialog (this, tr ("chrtrGUI save parameter file"));
      fd->setViewMode (QFileDialog::List);
      fd->setDirectory (".");

      QStringList filters;
      filters << tr ("chrtrGUI parameter file (*.chp)");

      fd->setNameFilters (filters);
      fd->setFileMode (QFileDialog::AnyFile);
      fd->selectNameFilter (tr ("chrtrGUI parameter file (*.chp)"));

      if (fd->exec () == QDialog::Accepted)
        {
          QStringList files = fd->selectedFiles ();

          QString file = files.at (0);

          if (!file.isEmpty())
            {
              if (!writeParameterFile (file, input_files, &options))
                {
                  QString tmp;
                  tmp.sprintf (tr ("Error opening parameters file : %s").toLatin1 (), strerror (errno));
                  QMessageBox::warning (this, tr ("chrtrGUI Save load parameters"), tmp);
                }
            }
        }
      break;
    }
}
