/*
 * LF: Global Fully Replicated Key/Value Store
 * Copyright (C) 2018  ZeroTier, Inc.  https://www.zerotier.com/
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * --
 *
 * You can be released from the requirements of the license by purchasing
 * a commercial license. Buying such a license is mandatory as soon as you
 * develop commercial closed-source software that incorporates or links
 * directly against ZeroTier software without disclosing the source code
 * of your own application.
 */

#ifndef ZTLF_WHARRGARBL_H
#define ZTLF_WHARRGARBL_H

#include "common.h"

#define ZTLF_WHARRGARBL_POW_BYTES 20

/**
 * @param pow 20-byte buffer to receive proof of work results
 * @param in Input data to hash
 * @param inlen Length of input
 * @param difficulty Difficulty determining number of bits that must collide
 * @param memory Memory to use (does not need to be zeroed)
 * @param memorySize Memory size in bytes (must be at least 16)
 * @param threads Number of threads or 0 to use hardware thread count
 * @return Approximate number of iterations required
 */
uint64_t ZTLF_wharrgarbl(void *pow,const void *in,const unsigned long inlen,const uint32_t difficulty,void *memory,const unsigned long memorySize,unsigned int threads);

uint32_t ZTLF_wharrgarblVerify(const void *pow,const void *in,const unsigned long inlen);

static inline uint32_t ZTLF_wharrgarblGetDifficulty(const void *pow)
{
	const uint8_t *p = ((const uint8_t *)pow) + 16;
	uint32_t d = *p++;
	d <<= 8;
	d |= *p++;
	d <<= 8;
	d |= *p++;
	d <<= 8;
	d |= *p;
	return d;
}

#endif
