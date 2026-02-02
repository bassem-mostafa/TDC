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

#ifndef DEBUG
    #define DEBUG
#endif

#ifdef DEBUG
    #undef DEBUG
#endif

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### Include(s) #############################################################
// #############################################################################

#include "TDC.h"
#include "TDC_Internal.h"

// #############################################################################
// #### Private Macro(s) #######################################################
// #############################################################################

// #############################################################################
// #### Private Type(s) ########################################################
// #############################################################################

typedef struct TDC_Context
{
    TDC_Instance_t Instance[ TDC_Count ];
} TDC_Context_t;

// #############################################################################
// #### Private Method(s) Prototype ############################################
// #############################################################################

static TDC_Status_t TDC_Context_Initialize( void );
static TDC_Status_t TDC_Context_Cycle( void );
static TDC_Status_t TDC_Context_DeInitialize( void );

// #############################################################################
// #### Private Variable(s) ####################################################
// #############################################################################

static TDC_Context_t TDC_Context;

// #############################################################################
// #### Private Method(s) ######################################################
// #############################################################################

static TDC_Status_t TDC_Context_Initialize( void )
{
    TDC_Status_t Status = TDC_Status_Error;

    do
    {
        TDC_Trace( "%s( void )", __FUNCTION__ );

        for ( TDC_t TDC_x = TDC_Null; TDC_x < TDC_Count; ++TDC_x )
        {
            TDC_Context.Instance[ TDC_x ].TDCx = TDC_x;
        }

        Status = TDC_Status_Success;
    }
    while ( 0 );

    return Status;
}

static TDC_Status_t TDC_Context_Cycle( void )
{
    TDC_Status_t Status = TDC_Status_Error;

    do
    {
        TDC_Trace( "%s( void )", __FUNCTION__ );

        Status = TDC_Status_Success;
    }
    while ( 0 );

    return Status;
}

static TDC_Status_t TDC_Context_DeInitialize( void )
{
    TDC_Status_t Status = TDC_Status_Error;
    do
    {
        TDC_Trace( "%s( void )", __FUNCTION__ );

        for ( TDC_t TDC_x = TDC_Null; TDC_x < TDC_Count; ++TDC_x )
        {
            TDC_Context.Instance[ TDC_x ].TDCx = TDC_x;
        }

        Status = TDC_Status_Success;
    }
    while ( 0 );
    return Status;
}

TDC_Status_t TDC_GetInstance( TDC_t TDCx, TDC_Instance_t ** Instance )
{
    TDC_Status_t Status = TDC_Status_Error;

    do
    {
        TDC_Trace( "%s( TDCx=%d, Instance=%p )", __FUNCTION__, TDCx, Instance );

        if ( Instance == NULL )
        {
            Status = TDC_Status_ArgumentInvalid;
            break;
        }

        *Instance = &TDC_Context.Instance[ TDCx ];

        Status = TDC_Status_Success;
    }
    while ( 0 );

    return Status;
}

// #############################################################################
// #### Public Method(s) #######################################################
// #############################################################################

TDC_Status_t TDC_Initialize( TDC_t TDCx )
{
    TDC_Status_t Status = TDC_Status_Error;

    do
    {
        TDC_Trace( "%s( TDCx=%d )", __FUNCTION__, TDCx );

        if ( ( Status = TDC_IsValid( TDCx ) ) != TDC_Status_Success )
        {
            break;
        }

        if ( ( Status = TDC_Context_Initialize( ) ) != TDC_Status_Success )
        {
            break;
        }

        for ( TDC_t TDC_x = TDC_Null; TDC_x < TDC_Count; ++TDC_x )
        {
            if ( TDCx != TDC_All && TDCx != TDC_x )
            {
                continue;
            }

            TDC_Status_t TDC_Status = TDC_Status_Success;
            if ( ( TDC_Status = TDC_Instance_Initialize( &TDC_Context.Instance[ TDC_x ] ) ) != TDC_Status_Success )
            {
                Status = TDC_Status;
            }
        }
    }
    while ( 0 );

    return Status;
}

TDC_Status_t TDC_Cycle( TDC_t TDCx )
{
    TDC_Status_t Status = TDC_Status_Error;

    do
    {
        TDC_Trace( "%s( TDCx=%d )", __FUNCTION__, TDCx );

        if ( ( Status = TDC_IsValid( TDCx ) ) != TDC_Status_Success )
        {
            break;
        }

        if ( ( Status = TDC_Context_Cycle( ) ) != TDC_Status_Success )
        {
            break;
        }

        for ( TDC_t TDC_x = TDC_Null; TDC_x < TDC_Count; ++TDC_x )
        {
            if ( TDCx != TDC_All && TDCx != TDC_x )
            {
                continue;
            }

            TDC_Status_t TDC_Status = TDC_Status_Success;
            if ( ( TDC_Status = TDC_Instance_Cycle( &TDC_Context.Instance[ TDC_x ] ) ) != TDC_Status_Success )
            {
                Status = TDC_Status;
            }
        }
    }
    while ( 0 );

    return Status;
}

TDC_Status_t TDC_DeInitialize( TDC_t TDCx )
{
    TDC_Status_t Status = TDC_Status_Error;

    do
    {
        TDC_Trace( "%s( TDCx=%d )", __FUNCTION__, TDCx );

        if ( ( Status = TDC_IsValid( TDCx ) ) != TDC_Status_Success )
        {
            break;
        }

        for ( TDC_t TDC_x = TDC_Null; TDC_x < TDC_Count; ++TDC_x )
        {
            if ( TDCx != TDC_All && TDCx != TDC_x )
            {
                continue;
            }

            TDC_Status_t TDC_Status = TDC_Status_Success;
            if ( ( TDC_Status = TDC_Instance_DeInitialize( &TDC_Context.Instance[ TDCx ] ) ) != TDC_Status_Success )
            {
                Status = TDC_Status;
            }
        }

        Status = TDC_Context_DeInitialize( );
    }
    while ( 0 );

    return Status;
}

TDC_Status_t TDC_SetCallbackOnComplete( TDC_t TDCx, TDC_CallbackOnComplete_t Callback )
{
    TDC_Status_t Status = TDC_Status_Error;

    do
    {
        TDC_Trace( "%s( TDCx=%d, Callback=%p )", __FUNCTION__, TDCx, Callback );

        if ( ( Status = TDC_IsValid( TDCx ) ) != TDC_Status_Success )
        {
            break;
        }

        for ( TDC_t TDC_x = TDC_Null; TDC_x < TDC_Count; ++TDC_x )
        {
            if ( TDCx != TDC_All && TDCx != TDC_x )
            {
                continue;
            }

            TDC_Status_t TDC_Status = TDC_Status_Success;
            if ( ( TDC_Status = TDC_Instance_SetCallbackOnComplete( &TDC_Context.Instance[ TDCx ], Callback ) ) != TDC_Status_Success )
            {
                Status = TDC_Status;
            }
        }
    }
    while ( 0 );

    return Status;
}

TDC_Status_t TDC_SetCallbackOnReading( TDC_t TDCx, TDC_CallbackOnReading_t Callback )
{
    TDC_Status_t Status = TDC_Status_Error;

    do
    {
        TDC_Trace( "%s( TDCx=%d, Callback=%p )", __FUNCTION__, TDCx, Callback );

        if ( ( Status = TDC_IsValid( TDCx ) ) != TDC_Status_Success )
        {
            break;
        }

        for ( TDC_t TDC_x = TDC_Null; TDC_x < TDC_Count; ++TDC_x )
        {
            if ( TDCx != TDC_All && TDCx != TDC_x )
            {
                continue;
            }

            TDC_Status_t TDC_Status = TDC_Status_Success;
            if ( ( TDC_Status = TDC_Instance_SetCallbackOnReading( &TDC_Context.Instance[ TDCx ], Callback ) ) != TDC_Status_Success )
            {
                Status = TDC_Status;
            }
        }
    }
    while ( 0 );

    return Status;
}

TDC_Status_t TDC_Start( TDC_t TDCx )
{
    TDC_Status_t Status = TDC_Status_Error;

    do
    {
        TDC_Trace( "%s( TDCx=%d )", __FUNCTION__, TDCx );

        if ( ( Status = TDC_IsValid( TDCx ) ) != TDC_Status_Success )
        {
            break;
        }

        for ( TDC_t TDC_x = TDC_Null; TDC_x < TDC_Count; ++TDC_x )
        {
            if ( TDCx != TDC_All && TDCx != TDC_x )
            {
                continue;
            }

            TDC_Status_t TDC_Status = TDC_Status_Success;
            if ( ( TDC_Status = TDC_Instance_Start( &TDC_Context.Instance[ TDCx ] ) ) != TDC_Status_Success )
            {
                Status = TDC_Status;
            }
        }
    }
    while ( 0 );

    return Status;
}

// #############################################################################
// #### Public Variable(s) #####################################################
// #############################################################################

const char TDC_VERSION[] = "0.0.0.v20260202-1914";

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
