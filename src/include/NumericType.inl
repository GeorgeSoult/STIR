//
// $Id$: $Date$
//
/*!
  \file 
  \ingroup buildblock 
  \brief Implementation of inline methods of class NumericType.

  \author Kris Thielemans 
  \author PARAPET project

  \date    $Date$

  \version $Revision$
*/

START_NAMESPACE_TOMO

NumericType::NumericType(Type t)
: id(t)
{}

bool NumericType::operator==(NumericType type) const
{ 
  return id == type.id; 
}

bool NumericType::operator!=(NumericType type) const
{ 
  return !(*this == type); 
}

END_NAMESPACE_TOMO
