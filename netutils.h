/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef netutils_h
#define netutils_h

/*!
 * convert host byte order to network byte order (Big Endian) and write its 
 * value to char array
 *
 * unlike htonll, htonl, htons... this macro convert any integer to big endian
 * because this is macro and no need type of integer
 */
#define nt_hton(src, dest)                                                    \
  do {                                                                        \
    char * __restrict _dest = dest;                                           \
    long _size = sizeof(src);                                                 \
    while (_size-- > 0) {                                                     \
      *(_dest + _size) = src & UCHAR_MAX;                                     \
      src >>= CHAR_BIT;                                                       \
    }                                                                         \
  } while(0)

/*!
 * convert network byte order to host byte order from char array
 */
#define nt_ntoh(src, dest)                                                    \
  do {                                                                        \
    char * __restrict _src = src;                                             \
    long _size = sizeof(dest);                                                \
    while (_size-- > 0) {                                                     \
      dest <<= CHAR_BIT;                                                      \
      dest |= *_src++ & UCHAR_MAX;                                            \
    }                                                                         \
  } while(0)

#endif /* netutils_h */
