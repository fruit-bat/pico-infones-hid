/*===================================================================*/
/*                                                                   */
/*  InfoNES_Types.h : Type definitions for InfoNES                   */
/*                                                                   */
/*  2000/5/4    InfoNES Project ( based on pNesX )                   */
/*                                                                   */
/*===================================================================*/

#ifndef InfoNES_TYPES_H_INCLUDED
#define InfoNES_TYPES_H_INCLUDED

#include <stdint.h>

/*-------------------------------------------------------------------*/
/*  Type definition                                                  */
/*-------------------------------------------------------------------*/
#ifndef DWORD
typedef uint32_t  DWORD;
//typedef unsigned long DWORD;
#endif /* !DWORD */

#ifndef WORD
typedef uint16_t WORD;
//typedef unsigned short WORD;
#endif /* !WORD */

#ifndef BYTE
typedef uint8_t  BYTE;
//typedef unsigned char BYTE;
#endif /* !BYTE */

/*-------------------------------------------------------------------*/
/*  NULL definition                                                  */
/*-------------------------------------------------------------------*/
#ifndef NULL
#define NULL  0
#endif /* !NULL */

#endif /* !InfoNES_TYPES_H_INCLUDED */
