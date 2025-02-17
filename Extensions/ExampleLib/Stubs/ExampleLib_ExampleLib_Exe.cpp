//-----------------------------------------------------------------------------
//
//                   ** WARNING! ** 
//    This file was generated automatically by a tool.
//    Re-running the tool will overwrite this file.
//    You should copy this file to a custom location
//    before adding any customization in the copy to
//    prevent loss of your changes when the tool is
//    re-run.
//
//-----------------------------------------------------------------------------


#include "ExampleLib.h"
#include "ExampleLib_ExampleLib_Exe.h"
#include <cmath>

using namespace ExampleLib;

 INT32 Exe::OnePlusTwo( CLR_RT_HeapBlock* pMngObj, HRESULT &hr )
 {
     INT32 retVal = 1+2; 
     return retVal;
 }
 
 INT32 Exe::TwoPlusFour( CLR_RT_HeapBlock* pMngObj, HRESULT &hr )
 {
     INT32 retVal = 2+4; 
     return retVal;
 }
 
 INT32 Exe::Arg1PlusArg2( CLR_RT_HeapBlock* pMngObj, INT32 param0, INT32 param1, HRESULT &hr )
 {
     INT32 retVal = param0+param1; 
    return retVal;
}
 
 INT32 IntFunc( INT32 param0, INT32 param1 )
{
    return param0 + param1;
}

INT32 Exe::Arg1PlusArg2_IntFunc( CLR_RT_HeapBlock* pMngObj, INT32 param0, INT32 param1, HRESULT &hr )
{
    INT32 retVal = IntFunc( param0, param1 ); 
    return retVal;
}

 INT32 Exe::IntExp_Lib( CLR_RT_HeapBlock* pMngObj, INT32 param0, INT32 param1, HRESULT &hr )
{
    INT32 retVal = (INT32)pow( param0, param1 ); 
    return retVal;
}

INT32 Exe::CustomArgsIO_Int( CLR_RT_HeapBlock* pMngObj, UINT16 param0, CLR_RT_TypedArray_UINT16 param1, UINT16 * param2, CLR_RT_TypedArray_UINT16 param3, HRESULT &hr )
{
    INT32 retVal = 0; 
	//copy stuff from input buffer to output buffer
	memcpy(param3.GetBuffer(), param1.GetBuffer(), param0 * 2); // last param: how many bytes
	*param2 = param0;

    return retVal;
}

