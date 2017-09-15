/**
 *  @copyright Copyright 2017 The J-PET Framework Authors. All rights reserved.
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may find a copy of the License in the LICENCE file.
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *  @file DeltaTFinder.h
 */

#ifndef DELTATFINDER_H 
#define DELTATFINDER_H 

#include <vector>
#include <map>
#include <boost/lexical_cast.hpp>
#include "TF1.h"
#include <JPetTask/JPetTask.h>
#include <JPetHit/JPetHit.h>
#include <JPetEvent/JPetEvent.h>
#include <JPetWriter/JPetWriter.h>
#include <JPetReader/JPetReader.h>
#include <JPetTreeHeader/JPetTreeHeader.h>
#include <JPetGeomMapping/JPetGeomMapping.h>

class JPetWriter;

#ifdef __CINT__
#	define override
#endif

class DeltaTFinder : public JPetTask{
public:
	DeltaTFinder(const char * name, const char * description);
	virtual ~DeltaTFinder(){};
	virtual void init(const JPetTaskInterface::Options& opts)override;
	virtual void exec()override;
	virtual void terminate()override;
	virtual void setWriter(JPetWriter* writer)override;
protected:
	void setParamManager( JPetParamManager* paramManager);
	static std::vector<std::string> split(const std::string& inString);
	static std::pair<int, std::string> retrievePositionAndFileName(const std::string& inString);
	const char * formatUniqueSlotDescription(const JPetBarrelSlot & slot, int threshold,const char * prefix);
	void fillHistosForHit(const JPetHit& hit);
	JPetGeomMapping* fBarrelMap = nullptr;
	JPetParamManager* fParamManager = nullptr;
  	bool fSaveControlHistos = true;
	JPetWriter* fWriter;
	JPetReader* fReader;
	const std::string fPosition = "DeltaTFinder_Position";
	std::string fOutputPath = "";
	std::string fOutputVelocityCalibName = "";
	double fPos = 999;
 	const int fRangeAroundMaximumBin = 2;
};
#endif /*  !DELTATFINDER_H */
