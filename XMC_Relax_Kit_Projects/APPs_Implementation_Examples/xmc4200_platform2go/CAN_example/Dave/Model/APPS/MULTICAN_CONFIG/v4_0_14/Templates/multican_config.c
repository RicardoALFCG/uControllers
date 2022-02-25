/**
 * @file multican_config.c
 * @date 2016-03-31
 *
 * NOTE:
 * This file is generated by DAVE-4. Any manual modification done to this file will be lost when the code is regenerated.
 *
 * @cond
 ***********************************************************************************************************************
 * MULTICAN_CONFIG v4.0.14 - Configures MultiCAN peripheral
 *
 * Copyright (c) 2015-2020, Infineon Technologies AG
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,are permitted provided that the
 * following conditions are met:
 *
 *   Redistributions of source code must retain the above copyright notice, this list of conditions and the  following
 *   disclaimer.
 *
 *   Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the
 *   following disclaimer in the documentation and/or other materials provided with the distribution.
 *
 *   Neither the name of the copyright holders nor the names of its contributors may be used to endorse or promote
 *   products derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  OF THE
 * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * To improve the quality of the software, users are encouraged to share modifications, enhancements or bug fixes
 * with Infineon Technologies AG (dave@infineon.com).
 ***********************************************************************************************************************
 *
 * Change History
 * --------------
 *
 * 2015-10-26:
 *     - Initial version<br>
 *
 * 2016-03-31:
 *     - Updated coding guidelines
 */

/***********************************************************************************************************************
 * HEADER FILES
 **********************************************************************************************************************/
#include "multican_config.h"

/***********************************************************************************************************************
 * MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * LOCAL DATA
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * LOCAL ROUTINES
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * API IMPLEMENTATION
 **********************************************************************************************************************/
/* API to retrieve the version of the MULTICAN_CONFIG APP */
DAVE_APP_VERSION_t MULTICAN_CONFIG_GetAppVersion()
{
  DAVE_APP_VERSION_t version;

  version.major = (uint8_t)MULTICAN_CONFIG_MAJOR_VERSION;
  version.minor = (uint8_t)MULTICAN_CONFIG_MINOR_VERSION;
  version.patch = (uint8_t)MULTICAN_CONFIG_PATCH_VERSION;

  return (version);
}

/*Function to initialize MULTICAN_CONFIG APP */
MULTICAN_CONFIG_STATUS_t MULTICAN_CONFIG_Init(MULTICAN_CONFIG_t *handle)
{
  MULTICAN_CONFIG_STATUS_t status = MULTICAN_CONFIG_STATUS_SUCCESS;

  status = handle->multican_config_init_func();

  return (status);
}