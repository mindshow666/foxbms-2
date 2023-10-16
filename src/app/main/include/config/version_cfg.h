/**
 *
 * @copyright &copy; 2010 - 2023, Fraunhofer-Gesellschaft zur Foerderung der angewandten Forschung e.V.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * We kindly request you to use one or more of the following phrases to refer to
 * foxBMS in your hardware, software, documentation or advertising materials:
 *
 * - &Prime;This product uses parts of foxBMS&reg;&Prime;
 * - &Prime;This product includes parts of foxBMS&reg;&Prime;
 * - &Prime;This product is derived from foxBMS&reg;&Prime;
 *
 */

/**
 * @file    version_cfg.h
 * @author  foxBMS Team
 * @date    2021-07-14 (date of creation)
 * @updated 2023-02-23 (date of last update)
 * @version v1.5.1
 * @ingroup GENERAL
 * @prefix  VER
 *
 * @brief   Header file for the version information that is generated by the toolchain
 *
 */

#ifndef FOXBMS__VERSION_CFG_H_
#define FOXBMS__VERSION_CFG_H_

/*========== Includes =======================================================*/

#include <stdbool.h>
#include <stdint.h>

/*========== Macros and Definitions =========================================*/
/** maximum length of the string #VER_VERSION_s::gitRemote
 *
 * Has to be in line with the value in f_ti_arm_cgt.py!
 */
#define VER_VERSION_STRUCT_MAXIMUM_REMOTE_STRING_LENGTH (128u)

/** maximum length of the string #VER_VERSION_s::commitHash
 *
 * Has to be in line with the value in f_ti_arm_cgt.py!
 */
#define VER_VERSION_STRUCT_MAXIMUM_COMMIT_HASH_LENGTH (9u)

/** macro for an attribute that tells the linker script where to place the version information */
#define VER_VERSION_INFORMATION __attribute__((section(".versionInformation")))

/** struct type that describes the version information of the system */
typedef struct {
    const bool underVersionControl;         /*!< indicates whether the toolchain has detected version control */
    const bool isDirty;                     /*!< indicates whether the code deviates from the last versioned state */
    const uint8_t major;                    /*!< major release version */
    const uint8_t minor;                    /*!< minor release version */
    const uint8_t patch;                    /*!< patch release version */
    const uint16_t distanceFromLastRelease; /*!< distance in commits from the last tagged release in version control */
    const char commitHash[VER_VERSION_STRUCT_MAXIMUM_COMMIT_HASH_LENGTH]; /*!< hash of the last commit */
    const char gitRemote
        [VER_VERSION_STRUCT_MAXIMUM_REMOTE_STRING_LENGTH]; /*!< address of the git remote linked in the repository */
} VER_VERSION_s;

/*========== Extern Constant and Variable Declarations ======================*/
/** version information of the system */
extern const VER_VERSION_s ver_foxbmsVersionInformation;

/*========== Extern Function Prototypes =====================================*/

/*========== Externalized Static Functions Prototypes (Unit Test) ===========*/
#ifdef UNITY_UNIT_TEST
#endif

#endif /* FOXBMS__VERSION_CFG_H_ */
