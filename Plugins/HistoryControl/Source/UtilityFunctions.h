//
// Copyright (C) 2017 Anders Elmholdt
//

#ifndef _UTILITY_FUNCTIONS
#define _UTILITY_FUNCTIONS

#include <maya/MObject.h>
#include <maya/MPlug.h>
#include <maya/MString.h>
#include <maya/MGlobal.h>

const MString PLUGIN_NAME = "HistoryControl";

inline MString FormatMessage(const MString &msg, const MString &sourceFile, const int &sourceLine)
{
	MString txt("[");
	txt += PLUGIN_NAME;
	txt += "] ";
	txt += msg;
	txt += ", File: ";
	txt += sourceFile;
	txt += " Line: ";
	txt += sourceLine;
	return txt;
}

#define PRINT_ERROR(msg) \
{ \
	MString __msg = FormatMessage(msg, __FILE__, __LINE__); \
	MGlobal::displayError(__msg); \
}

#define CHECK_MSTATUS_AND_PRINT_ERROR(stat, msg) \
if (!stat) \
{ \
	PRINT_ERROR(msg); \
	return stat; \
}

#define CHECK_MSTATUS_AND_PRINT_ERROR_NO_RET(stat, msg) \
if (!stat) \
{ \
	PRINT_ERROR(msg); \
	return; \
}

namespace utility 
{
	MObject getDestinationNode(MPlug & plug, MStatus * stat);
}

#endif