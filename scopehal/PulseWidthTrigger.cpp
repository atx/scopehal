/***********************************************************************************************************************
*                                                                                                                      *
* ANTIKERNEL v0.1                                                                                                      *
*                                                                                                                      *
* Copyright (c) 2012-2020 Andrew D. Zonenberg                                                                          *
* All rights reserved.                                                                                                 *
*                                                                                                                      *
* Redistribution and use in source and binary forms, with or without modification, are permitted provided that the     *
* following conditions are met:                                                                                        *
*                                                                                                                      *
*    * Redistributions of source code must retain the above copyright notice, this list of conditions, and the         *
*      following disclaimer.                                                                                           *
*                                                                                                                      *
*    * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the       *
*      following disclaimer in the documentation and/or other materials provided with the distribution.                *
*                                                                                                                      *
*    * Neither the name of the author nor the names of any contributors may be used to endorse or promote products     *
*      derived from this software without specific prior written permission.                                           *
*                                                                                                                      *
* THIS SOFTWARE IS PROVIDED BY THE AUTHORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED   *
* TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL *
* THE AUTHORS BE HELD LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES        *
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR       *
* BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT *
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE       *
* POSSIBILITY OF SUCH DAMAGE.                                                                                          *
*                                                                                                                      *
***********************************************************************************************************************/

#include "scopehal.h"
#include "PulseWidthTrigger.h"

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Construction / destruction

PulseWidthTrigger::PulseWidthTrigger(Oscilloscope* scope)
	: EdgeTrigger(scope)
{
	m_lowername = "Lower Bound";
	m_parameters[m_lowername] = FilterParameter(FilterParameter::TYPE_FLOAT, Unit(Unit::UNIT_PS));

	m_uppername = "Upper Bound";
	m_parameters[m_uppername] = FilterParameter(FilterParameter::TYPE_FLOAT, Unit(Unit::UNIT_PS));

	m_widthtypename = "Condition";
	m_parameters[m_widthtypename] = FilterParameter(FilterParameter::TYPE_ENUM, Unit(Unit::UNIT_COUNTS));
	m_parameters[m_widthtypename].AddEnumValue("Less than", WIDTH_LESS);
	m_parameters[m_widthtypename].AddEnumValue("Greater than", WIDTH_GREATER);
	m_parameters[m_widthtypename].AddEnumValue("Between", WIDTH_BETWEEN);
	m_parameters[m_widthtypename].AddEnumValue("Not between", WIDTH_NOT_BETWEEN);
}

PulseWidthTrigger::~PulseWidthTrigger()
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Accessors

string PulseWidthTrigger::GetTriggerName()
{
	return "Pulse Width";
}