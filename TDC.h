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

/**
 *  @file
 *
 *  @brief Platform TDC Module
 */

// #############################################################################
// #### Control Include(s) #####################################################
// #############################################################################

// #############################################################################
// #### Control Macro(s) #######################################################
// #############################################################################

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

/**
 *  @addtogroup Platform_Module
 *
 *  @{
 */

/**
 *  @defgroup Platform_TDC TDC
 *
 *  @note Default port is STUB if Unspecified
 *
 *  @{
 */

/**
 *  @defgroup Platform_TDC_Driver Driver
 *
 *  @{
 *  @}
 */

#ifndef TDC_H_
    #define TDC_H_

    #ifdef __cplusplus
extern "C"
{
    #endif /* __cplusplus */

    // #############################################################################
    // #### Include(s) #############################################################
    // #############################################################################

    #include "TDC_Port.h"

    // #############################################################################
    // #### Public Macro(s) ########################################################
    // #############################################################################

    // #############################################################################
    // #### Public Type(s) #########################################################
    // #############################################################################

    /**
     *  @brief TDC Operation Status Type
     *
     *  @enum TDC_Status_t
     */
    typedef enum TDC_Status
    {
        TDC_Status_Success = 0,     ///< Success
        TDC_Status_ArgumentInvalid, ///< Argument Invalid
        TDC_Status_NotSupported,    ///< Not Supported
        TDC_Status_Error,           ///< General Error
        TDC_Status_Busy,            ///< Busy
        TDC_Status_Timeout,         ///< Timeout
    } TDC_Status_t;

    /**
     *  @brief TDC Channel Type
     *
     *  @enum TDC_Channel_t
     */
    typedef enum TDC_Channel
    {
        TDC_Channel_Unknown = 0, ///< Unknown
        TDC_Channel_1,           ///< Channel 1 (Minimum)
        TDC_Channel_2,           ///<
        TDC_Channel_3,           ///<
        TDC_Channel_4,           ///<
        TDC_Channel_5,           ///<
        TDC_Channel_6,           ///<
        TDC_Channel_7,           ///<
        TDC_Channel_8,           ///< Channel 8 (Maximum)
    } TDC_Channel_t;

    /**
     *  @brief TDC Delay
     */
    typedef double TDC_Delay_t;

    /**
     *  @brief TDC Sample Type
     */
    typedef double TDC_Sample_t;

    /**
     *  @brief TDC On-Complete Callback Type
     *
     *  @param[in] TDCx   Instance
     *  @param[in] Status Execution status
     *
     *  @return void
     */
    typedef void ( *TDC_CallbackOnComplete_t )( TDC_t TDCx, TDC_Status_t Status );

    /**
     *  @brief TDC On-Reading Callback Type
     *
     *  @param[in] TDCx    Instance
     *  @param[in] Channel Captured Channel
     *  @param[in] Sample  Measurement Value
     *
     *  @return void
     */
    typedef void ( *TDC_CallbackOnReading_t )( TDC_t TDCx, TDC_Channel_t Channel, TDC_Sample_t Sample );

    // #############################################################################
    // #### Public Method(s) #######################################################
    // #############################################################################

    /**
     *  @brief Initialize TDC instance
     *
     *  @note MUST BE called before using any TDC API
     *
     *  @param[in] TDCx Instance
     *
     *  @return TDC_Status_t
     */
    TDC_Status_t TDC_Initialize( TDC_t TDCx );

    /**
     *  @brief Cycle TDC instance
     *
     *  @param[in] TDCx Instance
     *
     *  @return TDC_Status_t
     */
    TDC_Status_t TDC_Cycle( TDC_t TDCx );

    /**
     *  @brief DeInitialize TDC instance
     *
     *  @param[in] TDCx Instance
     *
     *  @return TDC_Status_t
     */
    TDC_Status_t TDC_DeInitialize( TDC_t TDCx );

    /**
     *  @brief Set callback for on-complete of TDC instance
     *
     *  @param[in] TDCx     Instance
     *  @param[in] Callback On-complete callback
     *
     *  @return TDC_Status_t
     */
    TDC_Status_t TDC_SetCallbackOnComplete( TDC_t TDCx, TDC_CallbackOnComplete_t Callback );

    /**
     *  @brief Set callback for on-reading of TDC instance
     *
     *  @param[in] TDCx     Instance
     *  @param[in] Callback On-reading callback
     *
     *  @return TDC_Status_t
     */
    TDC_Status_t TDC_SetCallbackOnReading( TDC_t TDCx, TDC_CallbackOnReading_t Callback );

    // TODO Add API for setting transmitting channels

    // TODO Add API for setting receiving channels

    /**
     *  @brief Set delay mask of TDC instance
     *
     *  @param[in] TDCx  Instance
     *  @param[in] Delay Delay Mask value in nano-seconds
     *
     *  @return TDC_Status_t
     */
    TDC_Status_t TDC_SetDelay( TDC_t TDCx, TDC_Delay_t Delay );

    /**
     *  @brief Starts sampling process of TDC instance
     *
     *  @param[in] TDCx Instance
     *
     *  @return TDC_Status_t
     */
    TDC_Status_t TDC_Start( TDC_t TDCx );

    // #############################################################################
    // #### Public Variable(s) #####################################################
    // #############################################################################

    /**
     *  @brief Version
     */
    extern const char TDC_VERSION[];

    // #############################################################################
    // #### File Guard #############################################################
    // #############################################################################

    #ifdef __cplusplus
} /* extern "C" */
    #endif /* __cplusplus */

#endif /* TDC_H_ */

/**
 *  @}
 *
 *  @}
 */

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
