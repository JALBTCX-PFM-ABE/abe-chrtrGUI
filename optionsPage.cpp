
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



#include "optionsPage.hpp"
#include "optionsPageHelp.hpp"

optionsPage::optionsPage (QWidget *parent, OPTIONS *op):
  QWizardPage (parent)
{
  options = op;
  prev_grid_size = options->grid_size;
  prev_grid_size_meters = options->grid_size_meters;


  setTitle (tr ("CHRTR Options"));

  setPixmap (QWizard::WatermarkPixmap, QPixmap(":/icons/chrtrGUIWatermark.png"));


  QVBoxLayout *vbox = new QVBoxLayout (this);
  vbox->setMargin (5);
  vbox->setSpacing (5);



  QGroupBox *gBox = new QGroupBox (tr ("Grid size"), this);
  QHBoxLayout *gBoxLayout = new QHBoxLayout;
  gBox->setLayout (gBoxLayout);
  gBoxLayout->setSpacing (10);


  QGroupBox *mBox = new QGroupBox (tr ("Meters"), this);
  QHBoxLayout *mBoxLayout = new QHBoxLayout;
  mBox->setLayout (mBoxLayout);
  mBoxLayout->setSpacing (10);

  meters = new QDoubleSpinBox (this);
  meters->setDecimals (1);
  meters->setRange (0.0, 1852.0);
  meters->setSingleStep (10.0);
  meters->setValue (options->grid_size_meters);
  meters->setWrapping (true);
  meters->setToolTip (tr ("Set the grid size in meters"));
  meters->setWhatsThis (metersText);
  connect (meters, SIGNAL (valueChanged (double)), this, SLOT (slotMetersChanged (double)));
  mBoxLayout->addWidget (meters);


  gBoxLayout->addWidget (mBox);


  QGroupBox *minBox = new QGroupBox (tr ("Minutes"), this);
  QHBoxLayout *minBoxLayout = new QHBoxLayout;
  minBox->setLayout (minBoxLayout);
  minBoxLayout->setSpacing (10);

  minutes = new QDoubleSpinBox (this);
  minutes->setDecimals (3);
  minutes->setRange (0.0, 60.0);
  minutes->setSingleStep (0.05);
  minutes->setValue (options->grid_size);
  minutes->setWrapping (true);
  minutes->setToolTip (tr ("Set the grid size in minutes"));
  minutes->setWhatsThis (minutesText);
  connect (minutes, SIGNAL (valueChanged (double)), this, SLOT (slotMinutesChanged (double)));
  minBoxLayout->addWidget (minutes);


  gBoxLayout->addWidget (minBox);


  vbox->addWidget (gBox);


  QGroupBox *wBox = new QGroupBox (tr ("Input weighting"), this);
  QHBoxLayout *wBoxLayout = new QHBoxLayout;
  wBox->setLayout (wBoxLayout);
  wBoxLayout->setSpacing (10);


  QGroupBox *fBox = new QGroupBox (tr ("Weight factor"), this);
  QHBoxLayout *fBoxLayout = new QHBoxLayout;
  fBox->setLayout (fBoxLayout);
  fBoxLayout->setSpacing (10);

  factor = new QSpinBox (this);
  factor->setRange (1, 3);
  factor->setSingleStep (1);
  factor->setValue (options->weight_factor);
  factor->setWrapping (true);
  factor->setToolTip (tr ("Set the input data weight factor"));
  factor->setWhatsThis (factorText);
  fBoxLayout->addWidget (factor);


  wBoxLayout->addWidget (fBox);


  QGroupBox *forceBox = new QGroupBox (tr ("Force original input value"), this);
  QHBoxLayout *forceBoxLayout = new QHBoxLayout;
  forceBox->setLayout (forceBoxLayout);
  forceBoxLayout->setSpacing (10);

  force = new QCheckBox (this);
  force->setChecked (options->force_original_value);
  force->setToolTip (tr ("Force final grid value to original input value"));
  force->setWhatsThis (forceText);
  forceBoxLayout->addWidget (force);

  wBoxLayout->addWidget (forceBox);


  vbox->addWidget (wBox);


  QGroupBox *nBox = new QGroupBox (tr ("Nibble"), this);
  QHBoxLayout *nBoxLayout = new QHBoxLayout;
  nBox->setLayout (nBoxLayout);
  nBoxLayout->setSpacing (10);

  nibble = new QSpinBox (this);
  nibble->setRange (0, 20);
  nibble->setSingleStep (1);
  nibble->setValue (options->nibble);
  nibble->setWrapping (true);
  nibble->setToolTip (tr ("Set the cell nibbler value"));
  nibble->setWhatsThis (nibbleText);
  nBoxLayout->addWidget (nibble);


  vbox->addWidget (nBox);


  QGroupBox *minmaxBox = new QGroupBox (tr ("Minimum and maximum values"), this);
  QHBoxLayout *minmaxBoxLayout = new QHBoxLayout;
  minmaxBox->setLayout (minmaxBoxLayout);
  minmaxBoxLayout->setSpacing (10);


  QGroupBox *minimumBox = new QGroupBox (tr ("Minimum"), this);
  QHBoxLayout *minimumBoxLayout = new QHBoxLayout;
  minimumBox->setLayout (minimumBoxLayout);
  minimumBoxLayout->setSpacing (10);

  minimum = new QDoubleSpinBox (this);
  minimum->setDecimals (2);
  minimum->setRange (-12000.0, 12000.0);
  minimum->setSingleStep (1000.0);
  minimum->setValue (options->minimum_value);
  minimum->setWrapping (true);
  minimum->setToolTip (tr ("Set the minimum allowable value"));
  minimum->setWhatsThis (minimumText);
  minimumBoxLayout->addWidget (minimum);


  minmaxBoxLayout->addWidget (minimumBox);


  QGroupBox *maximumBox = new QGroupBox (tr ("Maximum"), this);
  QHBoxLayout *maximumBoxLayout = new QHBoxLayout;
  maximumBox->setLayout (maximumBoxLayout);
  maximumBoxLayout->setSpacing (10);

  maximum = new QDoubleSpinBox (this);
  maximum->setDecimals (2);
  maximum->setRange (-12000.0, 12000.0);
  maximum->setSingleStep (1000.0);
  maximum->setValue (options->maximum_value);
  maximum->setWrapping (true);
  maximum->setToolTip (tr ("Set the maximum allowable value"));
  maximum->setWhatsThis (maximumText);
  maximumBoxLayout->addWidget (maximum);


  minmaxBoxLayout->addWidget (maximumBox);


  vbox->addWidget (minmaxBox);


  QGroupBox *pBox = new QGroupBox (tr ("Processing variables (expert only)"), this);
  QHBoxLayout *pBoxLayout = new QHBoxLayout;
  pBox->setLayout (pBoxLayout);
  pBoxLayout->setSpacing (10);


  QGroupBox *deltaBox = new QGroupBox (tr ("Delta value"), this);
  QHBoxLayout *deltaBoxLayout = new QHBoxLayout;
  deltaBox->setLayout (deltaBoxLayout);
  deltaBoxLayout->setSpacing (10);

  delta = new QDoubleSpinBox (this);
  delta->setDecimals (2);
  delta->setRange (0.01, 0.90);
  delta->setSingleStep (0.01);
  delta->setValue (options->delta);
  delta->setWrapping (true);
  delta->setToolTip (tr ("Set the delta convergence value"));
  delta->setWhatsThis (deltaText);
  deltaBoxLayout->addWidget (delta);


  pBoxLayout->addWidget (deltaBox);


  QGroupBox *searchBox = new QGroupBox (tr ("Search radius"), this);
  QHBoxLayout *searchBoxLayout = new QHBoxLayout;
  searchBox->setLayout (searchBoxLayout);
  searchBoxLayout->setSpacing (10);

  search = new QDoubleSpinBox (this);
  search->setDecimals (1);
  search->setRange (1.0, 1000.0);
  search->setSingleStep (10.0);
  search->setValue (options->search_radius);
  search->setWrapping (true);
  search->setToolTip (tr ("Set the search radius"));
  search->setWhatsThis (searchText);
  searchBoxLayout->addWidget (search);


  pBoxLayout->addWidget (searchBox);


  QGroupBox *errorBox = new QGroupBox (tr ("Error control"), this);
  QHBoxLayout *errorBoxLayout = new QHBoxLayout;
  errorBox->setLayout (errorBoxLayout);
  errorBoxLayout->setSpacing (10);

  error = new QSpinBox (this);
  error->setRange (1, 100);
  error->setSingleStep (10);
  error->setValue (options->error_control);
  error->setWrapping (true);
  error->setToolTip (tr ("Set the error control multiplier"));
  error->setWhatsThis (errorText);
  errorBoxLayout->addWidget (error);


  pBoxLayout->addWidget (errorBox);


  QGroupBox *regionalBox = new QGroupBox (tr ("Regional factor"), this);
  QHBoxLayout *regionalBoxLayout = new QHBoxLayout;
  regionalBox->setLayout (regionalBoxLayout);
  regionalBoxLayout->setSpacing (10);

  regional = new QSpinBox (this);
  regional->setRange (1, 10);
  regional->setSingleStep (1);
  regional->setValue (options->regional_factor);
  regional->setWrapping (true);
  regional->setToolTip (tr ("Set the regional grid multiplication factor"));
  regional->setWhatsThis (regionalText);
  regionalBoxLayout->addWidget (regional);


  pBoxLayout->addWidget (regionalBox);


  vbox->addWidget (pBox);


  registerField ("meters", meters, "value", "valueChanged");
  registerField ("minutes", minutes, "value", "valueChanged");
  registerField ("factor", factor);
  registerField ("force", force);
  registerField ("minimum", minimum, "value");
  registerField ("maximum", maximum, "value");
  registerField ("delta", delta, "value");
  registerField ("search", search, "value");
  registerField ("error", error);
  registerField ("regional", regional);
  registerField ("nibble", nibble);
}



void 
optionsPage::slotMetersChanged (double value)
{
  options->grid_size_meters = value;


  //  Disconnect the minutes value changed signal so we don't bounce back and forth.  Reconnect after
  //  setting the value.

  disconnect (minutes, SIGNAL (valueChanged (double)), 0, 0);


  //  We don't ever want both grid_size and grid_size_meters = 0.0.

  if (fabs (value < 0.0000001))
    {
      options->grid_size = prev_grid_size;
    }
  else
    {
      prev_grid_size_meters = value;
      options->grid_size = 0.0;
    }
  minutes->setValue (options->grid_size);

  connect (minutes, SIGNAL (valueChanged (double)), this, SLOT (slotMinutesChanged (double)));
}



void 
optionsPage::slotMinutesChanged (double value)
{
  options->grid_size = value;


  //  Disconnect the meter value changed signal so we don't bounce back and forth.  Reconnect after setting
  //  the value.

  disconnect (meters, SIGNAL (valueChanged (double)), 0, 0);


  //  We don't ever want both minutes and meters to be 0.0.

  if (fabs (value < 0.0000001))
    {
      options->grid_size_meters = prev_grid_size_meters;
    }
  else
    {
      prev_grid_size = value;
      options->grid_size_meters = 0.0;
    }
  meters->setValue (options->grid_size_meters);

  connect (meters, SIGNAL (valueChanged (double)), this, SLOT (slotMetersChanged (double)));
}
