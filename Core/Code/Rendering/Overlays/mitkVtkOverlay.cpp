/*===================================================================

The Medical Imaging Interaction Toolkit (MITK)

Copyright (c) German Cancer Research Center,
Division of Medical and Biological Informatics.
All rights reserved.

This software is distributed WITHOUT ANY WARRANTY; without
even the implied warranty of MERCHANTABILITY or FITNESS FOR
A PARTICULAR PURPOSE.

See LICENSE.txt or http://www.mitk.org for details.

===================================================================*/

#include "mitkVtkOverlay.h"

mitk::VtkOverlay::VtkOverlay()
{
  m_PropertyList = mitk::PropertyList::New();
}


mitk::VtkOverlay::~VtkOverlay()
{
}

mitk::PropertyList *mitk::VtkOverlay::GetPropertyList()
{
  return m_PropertyList;
}
