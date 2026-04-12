// #############################################################################
// #### Copyright ##############################################################
// #############################################################################

/*
 * Copyright 2024 BaSSeM
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

// #############################################################################
// #### Description ############################################################
// #############################################################################

// #############################################################################
// #### Control Include(s) #####################################################
// #############################################################################

#include "Platform.h"

// #############################################################################
// #### Control Macro(s) #######################################################
// #############################################################################

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

#ifndef TDC_INTERNAL_H_
    #define TDC_INTERNAL_H_

    #ifdef __cplusplus
extern "C"
{
    #endif /* __cplusplus */

    // #############################################################################
    // #### Include(s) #############################################################
    // #############################################################################

    #include "TDC_Port.h"
    #include "driver/GP22/TDC_GP22.h"

    // #############################################################################
    // #### Public Macro(s) ########################################################
    // #############################################################################

    #ifndef TDC_TIM
        #define TDC_TIM PLATFORM_DEFAULT_TIM
    #endif

    #ifndef TDC_LOG
        #define TDC_LOG PLATFORM_DEFAULT_LOG
    #endif

    #define TDC_NAME       "TDC"
    #define TDC_LOG_PREFIX UTIL_StringConcatenateConstant( TDC_NAME, "> " )

    #ifdef DEBUG
        #define TDC_Raw( Level, Format, ... ) LOG_Raw( TDC_LOG, Level, Format, ##__VA_ARGS__ )
        #define TDC_Trace( Format, ... )      LOG_Trace( TDC_LOG, UTIL_StringConcatenateConstant( TDC_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define TDC_Debug( Format, ... )      LOG_Debug( TDC_LOG, UTIL_StringConcatenateConstant( TDC_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define TDC_Info( Format, ... )       LOG_Info( TDC_LOG, UTIL_StringConcatenateConstant( TDC_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define TDC_Warning( Format, ... )    LOG_Warning( TDC_LOG, UTIL_StringConcatenateConstant( TDC_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define TDC_Error( Format, ... )      LOG_Error( TDC_LOG, UTIL_StringConcatenateConstant( TDC_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define TDC_Fatal( Format, ... )      LOG_Fatal( TDC_LOG, UTIL_StringConcatenateConstant( TDC_LOG_PREFIX, Format ), ##__VA_ARGS__ )
    #else
        #define TDC_Raw( Level, Format, ... )
        #define TDC_Trace( Format, ... )
        #define TDC_Debug( Format, ... )
        #define TDC_Info( Format, ... )
        #define TDC_Warning( Format, ... )
        #define TDC_Error( Format, ... )
        #define TDC_Fatal( Format, ... )
    #endif

    // #############################################################################
    // #### Public Type(s) #########################################################
    // #############################################################################

    typedef struct TDC_InstanceContext_t TDC_InstanceContext_t;

    typedef struct TDC_Instance
    {
        TDC_t TDCx;

        TDC_CallbackOnComplete_t OnComplete;
        TDC_CallbackOnReading_t OnReading;

        union
        {
            TDC_InstanceContext_t * Context;
            TDC_GP22_Instance_t * GP22;
        };
    } TDC_Instance_t;

    // #############################################################################
    // #### Public Method(s) #######################################################
    // #############################################################################

    TDC_Status_t TDC_GetInstance( TDC_t TDCx, TDC_Instance_t ** Instance );

    TDC_Status_t TDC_Instance_SetCallbackOnComplete( TDC_Instance_t * Instance, TDC_CallbackOnComplete_t Callback );
    TDC_Status_t TDC_Instance_SetCallbackOnReading( TDC_Instance_t * Instance, TDC_CallbackOnReading_t Callback );

    // The following APIs MUST be provided by the port
    TDC_Status_t TDC_IsValid( TDC_t TDCx );

    TDC_Status_t TDC_Instance_Initialize( TDC_Instance_t * Instance );
    TDC_Status_t TDC_Instance_Cycle( TDC_Instance_t * Instance );
    TDC_Status_t TDC_Instance_DeInitialize( TDC_Instance_t * Instance );

    TDC_Status_t TDC_Instance_SetDelayMask( TDC_Instance_t * Instance, TDC_Delay_t Delay );

    TDC_Status_t TDC_Instance_Start( TDC_Instance_t * Instance );

    // #############################################################################
    // #### Public Variable(s) #####################################################
    // #############################################################################

    // #############################################################################
    // #### File Guard #############################################################
    // #############################################################################

    #ifdef __cplusplus
} /* extern "C" */
    #endif /* __cplusplus */

#endif /* TDC_INTERNAL_H_ */

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
