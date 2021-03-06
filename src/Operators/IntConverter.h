/* Copyright (c) 2005, Regents of Massachusetts Institute of Technology, 
 * Brandeis University, Brown University, and University of Massachusetts 
 * Boston. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions are met:
 *
 *   - Redistributions of source code must retain the above copyright notice, 
 *     this list of conditions and the following disclaimer.
 *   - Redistributions in binary form must reproduce the above copyright 
 *     notice, this list of conditions and the following disclaimer in the 
 *     documentation and/or other materials provided with the distribution.
 *   - Neither the name of Massachusetts Institute of Technology, 
 *     Brandeis University, Brown University, or University of 
 *     Massachusetts Boston nor the names of its contributors may be used 
 *     to endorse or promote products derived from this software without 
 *     specific prior written permission.

 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED 
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR 
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR 
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, 
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, 
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR 
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS 
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef INTCONVERTER_H
#define INTCONVERTER_H

#include "../common/Constants.h"
#include "../common/Interfaces.h"
#include "../AM/ROSWOSSegment.h"
#include <string>
#include <fstream>
#include <sstream>
#include <map>

class Block;
class ROSWOSSegment;

// Abstract class for implementaion of an Operator
class IntConverter : public Operator 
{
 public:
  	IntConverter(ROSWOSSegment* rw_, int c_index, Dbc *iter,
		     void **ptr, void **buf );
  	// destructor
  	~IntConverter();

  	// Gets the next value block from the operator 
  	Block* getNextValBlock(int colIndex_);	
  
	// Gets the next position block (bitstring of positions) from the operator
	void setKey(int key_, int fieldnum_);
	void setPos(int key_, int fieldnum_);

	PosBlock* getNextPosBlock(int colIndex_);
	
	inline virtual int getLastPosition() { throw UnimplementedException("Not applicable for IntConverter"); };
  
 private:
  	int curPos;
  	int curVal;
	int key;
	int fieldnum;
	bool firstCall;
	bool byPos;
 	BasicBlock* bb;
	ValPos* p;
	ROSWOSSegment* rw;
	Dbc *_iter;
	void **_ptr, **_buf;

	int _bdb_stopper, _first_call_failed;
};

#endif // INTCONVERTER
