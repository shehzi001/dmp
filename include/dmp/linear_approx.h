/*********************************************************************
 *
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2012, Scott Niekum
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of Willow Garage nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *
 *********************************************************************/

/**
  * \author Scott Niekum
  */

#ifndef LINEAR_APPROX_H_
#define LINEAR_APPROX_H_

#include "dmp/function_approx.h"
#include <iostream>

namespace dmp{

typedef std::pair<double, double> pt_pair;

      
/// Class for function approximation by recording points and linearly interpolating
class LinearApprox : public FunctionApprox{
public:
	LinearApprox();
        LinearApprox(std::vector<double> X, std::vector<double> Y);
	virtual ~LinearApprox();

	/**\brief Evaluate the function approximator at point x
	 * \param x The point at which to evaluate
	 * \return The scalar value of the function at x
	 */
	virtual double evalAt(double x);

	/**\brief Computes the least squares weights given a set of data points
	 * \param X A vector of the domain values of the points
	 * \param Y A vector of the target values of the points
	 */
	virtual void leastSquaresWeights(double *X, double *Y, int n_pts);

        
private:
 
        std::vector<pt_pair> points;

};

}

#endif /* LINEAR_APPROX_H_ */
