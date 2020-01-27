/**
 *  @file      alloc.h
 *  @brief     Function prototypes for malloc library implementation
 *  @details   This file contains the prototypes and macros for the malloc 
 *             library implementation.
 * 
 *  @author    Lakku Mahendra
 *  @date      15-Aug-2019
 *  @bug       No known bugs.
 * 
 *  @copyright No copyrights associated. Readers are free to use it every where,
 *             any where.
 */

#ifndef _ALLOC_H
#define _ALLOC_H

#include <stdio.h>
#include <stdint.h>

#define MEM_SIZE 1024 // static array size
#define MDATA    16   // meta_data size (MDATA * 4)

/** @brief  Allocates size bytes in the memory.
 *
 *  @param  size the number of bytes to allocate memory.
 *  @return pointer to allocated memory.
 */
void *dyn_alloc(size_t size);

/** @brief  Frees the memory space pointed to by ptr.
  *
  * @param  ptr the pointer to free the memory space.
  * @return void
  */
void dyn_free(void *ptr);

/** @brief  Dump the info of the meta data
  *
  * @param  void
  * @return void
  */
void dump_info(void);

#endif // _ALLOC_H
