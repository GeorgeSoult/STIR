//
// $Id$
//
/*!

  \file
  \ingroup motion
  \brief Declaration of functions to re-interpolate an image to a new coordinate system.

  \author Kris Thielemans

  $Date$
  $Revision$
*/
/*
    Copyright (C) 2003- $Date$, Hammersmith Imanet
    See STIR/LICENSE.txt for details
*/

#include "stir/common.h"

START_NAMESPACE_STIR

class RigidObject3DTransformation;
template <int num_dimensions, typename elemT> 
  class DiscretisedDensity;
class ProjData;

//! transform image data
/*! \ingroup motion
    Currently only supports VoxelOnCartesianGrid image.
    Uses (tri)linear interpolation.
*/


Succeeded
transform_3d_object(DiscretisedDensity<3,float>& out_density, 
		    const DiscretisedDensity<3,float>& in_density, 
		    const RigidObject3DTransformation& rigid_object_transformation);

//! transform image data
/*! \ingroup motion
    Currently only supports non-arccorrected data.
*/
Succeeded
transform_3d_object(ProjData& out_proj_data,
		    const ProjData& in_proj_data,
		    const RigidObject3DTransformation& rigid_object_transformation);

END_NAMESPACE_STIR
