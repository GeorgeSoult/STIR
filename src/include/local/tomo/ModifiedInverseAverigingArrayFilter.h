//
// $Id: 
//
/*!

  \file
  \ingroup buildblock  
  \brief 
   This is a messy first attempt to design spatially varying filter 
   Given the kernel which in this case is a lospass filter with a DC gain 1 the filter 
   is design such that the output kernel varies depending on the k0 and k1 ( for more details on these
   factors look at Fessler)

    
  \author Sanida Mustafovic
  \author Kris Thielemans
      
  \date $Date: 
  \version $Revision: 
*/

#ifndef __Tomo_ModifiedInverseAverigingArrayFilter_H__
#define __Tomo_ModifiedInverseAverigingArrayFilter_H__

#include "DiscretisedDensity.h"
#include "tomo/SeparableArrayFunctionObject.h"
#include "local/tomo/SeparableLowPassArrayFilter2.h"
#include "Array.h"
#include "IndexRange.h"
#include <vector>


#ifndef TOMO_NO_NAMESPACES
using std::vector;
#endif


START_NAMESPACE_TOMO

class  FFT_routines
{
 public:
   void find_fft_filter(Array<1,float>& filter_coefficients);
   void find_fft_unity(Array<1,float>& unity);
 private:
    Array<1,float> filter_coefficients;
    Array<1,float> unity;


};


template <int num_dimensions, typename elemT>
class ModifiedInverseAverigingArrayFilter: public SeparableLowPassArrayFilter2 <num_dimensions,elemT>
//public SeparableArrayFunctionObject <num_dimensions,elemT> 
{
public:  

  //! Default constructor
  ModifiedInverseAverigingArrayFilter();
  
  //ModifiedInverseAverigingArrayFilter(const float kapa0_over_kapa1);
  
  ModifiedInverseAverigingArrayFilter(const VectorWithOffset<elemT>& filter_coefficients, 
				      const float kapa0_over_kapa1);
  
  // temporary (?) member
  IndexRange<num_dimensions> get_kernel_index_range() const
  { return kernel_index_range; }

private:
 VectorWithOffset<float> filter_coefficients;
 IndexRange<num_dimensions> kernel_index_range;
 float kapa0_over_kapa1;

};


END_NAMESPACE_TOMO

#endif
