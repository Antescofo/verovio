/////////////////////////////////////////////////////////////////////////////
// Name:        beatrpt.h
// Author:      Klaus Rettinghaus
// Created:     2018
// Copyright (c) Authors and others. All rights reserved.
/////////////////////////////////////////////////////////////////////////////

#ifndef __VRV_BEATRPT_H__
#define __VRV_BEATRPT_H__

#include "atts_cmn.h"
#include "atts_shared.h"
#include "beam.h"
#include "layerelement.h"

namespace vrv {

//----------------------------------------------------------------------------
// BeatRpt (beat repeat)
//----------------------------------------------------------------------------

/**
 * This class models the MEI <beatRpt> element.
 */
class BeatRpt : public LayerElement, public AttColor, public AttBeatRptVis {
public:
    /**
     * @name Constructors, destructors, reset and class name methods
     * Reset method resets all attribute classes
     */
    ///@{
    BeatRpt();
    virtual ~BeatRpt();
    virtual void Reset();
    virtual std::string GetClassName() const { return "BeatRpt"; }
    virtual ClassId GetClassId() const { return BEATRPT; }
    ///@}

    /** Override the method since alignment is required */
    virtual bool HasToBeAligned() const { return true; }

    /**
     * Returns the duration (in double) for the BeatRpt.
     */

    double GetBeatRptAlignmentDuration(int meterUnit) const;

private:
    //
public:
    //
private:
};

} // namespace vrv

#endif
