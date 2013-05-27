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

#ifndef OVERLAY_H
#define OVERLAY_H

#include <MitkExports.h>
#include <itkObject.h>
#include <mitkCommon.h>
#include "mitkBaseRenderer.h"


namespace mitk {

class MITK_CORE_EXPORT Overlay : public itk::Object {
public:

  typedef std::map<const mitk::BaseRenderer*,mitk::PropertyList::Pointer> MapOfPropertyLists;

  /** \brief Base class for mapper specific rendering ressources.
   */
  class MITK_CORE_EXPORT BaseLocalStorage
  {
  public:


    bool IsGenerateDataRequired(mitk::BaseRenderer *renderer,mitk::Overlay *overlay);

    inline void UpdateGenerateDataTime()
    {
      m_LastGenerateDataTime.Modified();
    }

    PropertyList::Pointer GetPropertyList();

    inline itk::TimeStamp & GetLastGenerateDataTime() { return m_LastGenerateDataTime; }



  protected:

    /** \brief timestamp of last update of stored data */
    itk::TimeStamp m_LastGenerateDataTime;

    PropertyList::Pointer m_PropertyList;

  };

  virtual void MitkRender(BaseRenderer *renderer) = 0;

  //##Documentation
  //## @brief Get the PropertyList of the @a renderer. If @a renderer is @a
  //## NULL, the BaseRenderer-independent PropertyList of this DataNode
  //## is returned.
  //## @sa GetProperty
  //## @sa m_PropertyList
  //## @sa m_MapOfPropertyLists
  mitk::PropertyList* GetPropertyList();

  //##Documentation
  //## @brief Get the PropertyList of the @a renderer. If @a renderer is @a
  //## NULL, the BaseRenderer-independent PropertyList of this DataNode
  //## is returned.
  //## @sa GetProperty
  //## @sa m_PropertyList
  //## @sa m_MapOfPropertyLists
  virtual mitk::PropertyList* GetBRPropertyList(mitk::BaseRenderer* renderer) = 0 ;

  mitkClassMacro(Overlay, itk::Object);

protected:

  /** \brief explicit constructor which disallows implicit conversions */
  explicit Overlay();

  /** \brief virtual destructor in order to derive from this class */
  virtual ~Overlay();

private:

  /** \brief copy constructor */
  Overlay( const Overlay &);

  /** \brief assignment operator */
  Overlay &operator=(const Overlay &);

  //##Documentation
  //## @brief BaseRenderer-independent PropertyList
  //##
  //## Properties herein can be overwritten specifically for each BaseRenderer
  //## by the BaseRenderer-specific properties defined in m_MapOfPropertyLists.
  PropertyList::Pointer m_PropertyList;

};

} // namespace mitk
#endif // OVERLAY_H


