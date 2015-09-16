/**
 ******************************************************************************
 * @file    ota_flash_hal.c
 * @author  Matthew McGowan
 * @version V1.0.0
 * @date    25-Sept-2014
 * @brief
 ******************************************************************************
  Copyright (c) 2013-2015 Particle Industries, Inc.  All rights reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation, either
  version 3 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, see <http://www.gnu.org/licenses/>.
 ******************************************************************************
 */

#include "ota_flash_hal.h"
#undef STATIC_ASSERT
#include "hw_config.h"

void HAL_System_Info(hal_system_info_t* info, bool create, void* reserved)
{
    info->platform_id = PLATFORM_ID;
    info->module_count = 0;
    info->modules = NULL;
}


uint32_t HAL_OTA_FlashAddress()
{
    return OTA_FlashAddress();
}

uint32_t HAL_OTA_FlashLength()
{
    return OTA_FlashLength();
}

uint16_t HAL_OTA_ChunkSize()
{
    return 0;
}

bool HAL_FLASH_Begin(uint32_t address, uint32_t length, void* reserved)
{
    FLASH_Begin(address, length);
}

int HAL_FLASH_Update(const uint8_t *pBuffer, uint32_t address, uint32_t length, void* reserved)
{
    return FLASH_Update(pBuffer, address, length);
}

hal_update_complete_t HAL_FLASH_End(void* reserved)
{
    FLASH_End();
}

void HAL_FLASH_Read_ServerAddress(ServerAddress* server_addr)
{
}


bool HAL_OTA_Flashed_GetStatus(void)
{
    return false;
}

void HAL_OTA_Flashed_ResetStatus(void)
{
}

void HAL_FLASH_Read_ServerPublicKey(uint8_t *keyBuffer)
{
    //TO DO: Well, clearly this needs to change....
    unsigned char pubkey[EXTERNAL_FLASH_SERVER_PUBLIC_KEY_LENGTH] = {0x30, 0x82, 0x01, 0x22, 0x30, 0x0D, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x01, 0x01, 0x05, 0x00, 0x03, 0x82, 0x01, 0x0F, 0x00, 0x30, 0x82, 0x01, 0x0A, 0x02, 0x82, 0x01, 0x01, 0x00, 0xBE, 0xCC, 0xBE, 0x43, 0xDB, 0x8E, 0xEA, 0x15, 0x27, 0xA6, 0xBB, 0x52, 0x6D, 0xE1, 0x51, 0x2B, 0xA0, 0xAB, 0xCC, 0xA1, 0x64, 0x77, 0x48, 0xAD, 0x7C, 0x66, 0xFC, 0x80, 0x7F, 0xF6, 0x99, 0xA5, 0x25, 0xF2, 0xF2, 0xDA, 0xE0, 0x43, 0xCF, 0x3A, 0x26, 0xA4, 0x9B, 0xA1, 0x87, 0x03, 0x0E, 0x9A, 0x8D, 0x23, 0x9A, 0xBC, 0xEA, 0x99, 0xEA, 0x68, 0xD3, 0x5A, 0x14, 0xB1, 0x26, 0x0F, 0xBD, 0xAA, 0x6D, 0x6F, 0x0C, 0xAC, 0xC4, 0x77, 0x2C, 0xD1, 0xC5, 0xC8, 0xB1, 0xD1, 0x7B, 0x68, 0xE0, 0x25, 0x73, 0x7B, 0x52, 0x89, 0x68, 0x20, 0xBD, 0x06, 0xC6, 0xF0, 0xE6, 0x00, 0x30, 0xC0, 0xE0, 0xCF, 0xF6, 0x1B, 0x3A, 0x45, 0xE9, 0xC4, 0x5B, 0x55, 0x17, 0x06, 0xA3, 0xD3, 0x4A, 0xC6, 0xD5, 0xB8, 0xD2, 0x17, 0x02, 0xB5, 0x27, 0x7D, 0x8D, 0xE4, 0xD4, 0x7D, 0xD3, 0xED, 0xC0, 0x1D, 0x8A, 0x7C, 0x25, 0x1E, 0x21, 0x4A, 0x51, 0xAE, 0x57, 0x06, 0xDD, 0x60, 0xBC, 0xA1, 0x34, 0x90, 0xAA, 0xCC, 0x09, 0x9E, 0x3B, 0x3A, 0x41, 0x4C, 0x3C, 0x9D, 0xF3, 0xFD, 0xFD, 0xB7, 0x27, 0xC1, 0x59, 0x81, 0x98, 0x54, 0x60, 0x4A, 0x62, 0x7A, 0xA4, 0x9A, 0xBF, 0xDF, 0x92, 0x1B, 0x3E, 0xFC, 0xA7, 0xE4, 0xA4, 0xB3, 0x3A, 0x9A, 0x5F, 0x57, 0x93, 0x8E, 0xEB, 0x19, 0x64, 0x95, 0x22, 0x4A, 0x2C, 0xD5, 0x60, 0xF5, 0xF9, 0xD0, 0x03, 0x50, 0x83, 0x69, 0xC0, 0x6B, 0x53, 0xF0, 0xF0, 0xDA, 0xF8, 0x13, 0x82, 0x1F, 0xCC, 0xBB, 0x5F, 0xE2, 0xC1, 0xDF, 0x3A, 0xE9, 0x7F, 0x5D, 0xE2, 0x7D, 0xB9, 0x50, 0x80, 0x3C, 0x58, 0x33, 0xEF, 0x8C, 0xF3, 0x80, 0x3F, 0x11, 0x01, 0xD2, 0x68, 0x86, 0x5F, 0x3C, 0x5E, 0xE6, 0xC1, 0x8E, 0x32, 0x2B, 0x28, 0xCB, 0xB5, 0xCC, 0x1B, 0xA8, 0x50, 0x5E, 0xA7, 0x0D, 0x02, 0x03, 0x01, 0x00, 0x01};
    keyBuffer = pubkey;
}

int HAL_FLASH_Read_CorePrivateKey(uint8_t *keyBuffer, private_key_generation_t* generation)
{
    //TO DO: ...as does this....
    unsigned char private_key[EXTERNAL_FLASH_CORE_PRIVATE_KEY_LENGTH] = {0x30, 0x82, 0x02, 0x5E, 0x02, 0x01, 0x00, 0x02, 0x81, 0x81, 0x00, 0xE3, 0x80, 0xED, 0xE4, 0xED, 0xEC, 0x5D, 0x60, 0x00, 0x4E, 0xF1, 0x2E, 0x39, 0x3C, 0x61, 0x48, 0x08, 0xAC, 0xC8, 0x9B, 0x4C, 0x41, 0x0A, 0xB9, 0x23, 0xED, 0xBE, 0xC1, 0xE9, 0x1C, 0x13, 0x93, 0xD0, 0xBE, 0x9B, 0x94, 0x0C, 0x8A, 0xD1, 0x59, 0xE7, 0xE9, 0xFE, 0xC3, 0x3D, 0x48, 0xD0, 0x46, 0x55, 0x3D, 0x9B, 0x0A, 0x03, 0x03, 0xAD, 0x18, 0x72, 0x75, 0xBC, 0x4A, 0xAA, 0x2B, 0x94, 0x82, 0x36, 0x6F, 0x3E, 0xB0, 0x04, 0x20, 0xC2, 0xFD, 0x5D, 0xDA, 0x07, 0x00, 0x37, 0x6A, 0x41, 0x32, 0xC8, 0x47, 0xA4, 0xBF, 0x77, 0xEC, 0x69, 0x4C, 0x6C, 0xDA, 0xCF, 0x49, 0x6A, 0xCF, 0x4E, 0x07, 0x6F, 0x16, 0xA3, 0x3B, 0xCF, 0xE6, 0x42, 0x30, 0x90, 0xB5, 0xDA, 0x55, 0x5A, 0x1A, 0xFE, 0x18, 0xB5, 0x8B, 0xBF, 0xC4, 0xFE, 0x37, 0x41, 0x58, 0xA8, 0x1B, 0x12, 0x83, 0x4D, 0xF6, 0x9D, 0x2B, 0x02, 0x03, 0x01, 0x00, 0x01, 0x02, 0x81, 0x81, 0x00, 0x99, 0xB1, 0x16, 0x05, 0x9C, 0x3E, 0x1B, 0xEE, 0xA9, 0x06, 0xAB, 0xA4, 0x60, 0x82, 0x4B, 0xEE, 0x0F, 0xFE, 0x3A, 0x1F, 0xBF, 0xEA, 0x08, 0xC6, 0x7E, 0x61, 0x34, 0x87, 0x67, 0x65, 0xD2, 0x4B, 0xFF, 0xAF, 0x65, 0x07, 0x25, 0x59, 0xFA, 0x88, 0x54, 0x46, 0x1E, 0x17, 0xE3, 0xA4, 0xF7, 0x1F, 0x2C, 0xA2, 0xCB, 0xC4, 0x7D, 0xB8, 0xD4, 0x0D, 0x39, 0xF6, 0x13, 0xD8, 0x15, 0x12, 0x0F, 0xE6, 0x89, 0xA6, 0x5F, 0xE3, 0x60, 0x8D, 0xA8, 0xE4, 0x41, 0xB3, 0xB5, 0xA6, 0xCF, 0x55, 0x45, 0xB3, 0x00, 0x8B, 0x20, 0x38, 0x27, 0x88, 0xC3, 0xCB, 0x4B, 0xF6, 0xF4, 0x78, 0xDC, 0x82, 0xC6, 0x89, 0xDA, 0xF0, 0x53, 0x2F, 0x54, 0xEC, 0xAE, 0x23, 0xE7, 0x8E, 0x61, 0xB2, 0x3F, 0x29, 0x9A, 0x2F, 0x53, 0x1C, 0xB8, 0x65, 0x5E, 0x86, 0x0B, 0x99, 0xC3, 0x92, 0x46, 0x6B, 0x75, 0xF7, 0x11, 0xE1, 0x02, 0x41, 0x00, 0xF5, 0x46, 0x1C, 0x4F, 0xAB, 0x07, 0xB6, 0xF3, 0xDC, 0x5B, 0x53, 0xB1, 0x74, 0x5C, 0x71, 0x8D, 0x2E, 0xDC, 0x53, 0xFD, 0x00, 0x3B, 0x0D, 0x1B, 0x25, 0x55, 0xB7, 0x70, 0x23, 0x56, 0xB5, 0xB9, 0x45, 0xE5, 0x6C, 0x44, 0xC6, 0x7D, 0x56, 0xFF, 0xCE, 0xE0, 0x56, 0x44, 0x21, 0x7C, 0x04, 0x07, 0xCC, 0x71, 0x97, 0x4F, 0x17, 0xA2, 0xE5, 0x7E, 0xCA, 0xDF, 0xDD, 0xFF, 0x79, 0x56, 0xCC, 0x39, 0x02, 0x41, 0x00, 0xED, 0x73, 0xE0, 0x99, 0x8A, 0xF2, 0x1C, 0xF1, 0xD7, 0x7C, 0xD4, 0xAA, 0xF5, 0x73, 0x6E, 0xC2, 0x58, 0xCC, 0x00, 0x26, 0x12, 0x9D, 0x76, 0x36, 0x40, 0xE1, 0x68, 0xA9, 0x56, 0xDA, 0x8F, 0xE2, 0x00, 0xA8, 0x7D, 0x1A, 0xD0, 0xF3, 0xDE, 0xA9, 0xB2, 0xEA, 0x14, 0xE5, 0x42, 0x97, 0x20, 0xDE, 0xE3, 0x22, 0x7C, 0xBA, 0xBC, 0xEA, 0xA3, 0xC2, 0x5E, 0xC6, 0x5E, 0xDD, 0x79, 0xA4, 0xFC, 0x83, 0x02, 0x41, 0x00, 0xBB, 0xF0, 0x39, 0xF7, 0x4D, 0xBC, 0xFE, 0x92, 0x03, 0x32, 0x33, 0x82, 0x11, 0x00, 0x58, 0xBD, 0xEE, 0xBF, 0x42, 0xD7, 0xE4, 0xDA, 0x5A, 0xA3, 0x87, 0x4B, 0x13, 0xE1, 0x28, 0x22, 0xE3, 0xE2, 0x10, 0x4D, 0xC8, 0x55, 0x36, 0xA6, 0x8A, 0x08, 0x3F, 0x53, 0xA4, 0xA6, 0x55, 0xE5, 0xFA, 0x0C, 0xA3, 0xBA, 0x12, 0x4F, 0xB7, 0x73, 0xC9, 0x58, 0x0B, 0x49, 0xD8, 0x88, 0x4E, 0x48, 0x94, 0xF9, 0x02, 0x40, 0x7F, 0xB2, 0x0D, 0x5B, 0x05, 0x29, 0xE6, 0xFE, 0xF7, 0xCF, 0x9D, 0xDE, 0xC2, 0x58, 0xED, 0x7B, 0x7E, 0x9D, 0x56, 0x87, 0x23, 0x03, 0xA3, 0x0A, 0xD2, 0x21, 0x66, 0x53, 0x8A, 0xED, 0xC6, 0xEA, 0xD7, 0x47, 0xC4, 0xDF, 0xA2, 0xF7, 0x43, 0x0B, 0x27, 0xB8, 0x52, 0xBC, 0x67, 0xEF, 0x36, 0x32, 0x27, 0x1B, 0xE8, 0xCF, 0xD3, 0xC0, 0xAB, 0x88, 0x5F, 0xC7, 0x76, 0x44, 0xCC, 0xA2, 0x39, 0x59, 0x02, 0x41, 0x00, 0x9A, 0xDF, 0x7E, 0x7F, 0xDB, 0xB1, 0xDB, 0x0E, 0xC1, 0xFC, 0x51, 0xFB, 0xC9, 0x11, 0x9B, 0x2A, 0x92, 0xCD, 0xC0, 0x6A, 0xAC, 0x87, 0x81, 0xA0, 0x02, 0x3B, 0xAF, 0x22, 0x66, 0xA2, 0x47, 0x16, 0x58, 0x75, 0x23, 0x4A, 0x5E, 0x66, 0x85, 0x7D, 0x8D, 0x0E, 0x1A, 0xD5, 0xA8, 0x5B, 0xB1, 0x7C, 0x05, 0x80, 0x12, 0xE6, 0xCB, 0x7D, 0x3C, 0xEB, 0x17, 0xC4, 0x87, 0xAA, 0xA6, 0xA2, 0xBD, 0xB8};
    keyBuffer = private_key;
}

uint16_t HAL_Set_Claim_Code(const char* code)
{
    return -1;
}

uint16_t HAL_Get_Claim_Code(char* buffer, unsigned len)
{
    if (len)
        buffer[0] = 0;
    return 0;
}


