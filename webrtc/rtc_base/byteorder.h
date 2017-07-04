/*
 *  Copyright 2004 The WebRTC Project Authors. All rights reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#ifndef WEBRTC_RTC_BASE_BYTEORDER_H_
#define WEBRTC_RTC_BASE_BYTEORDER_H_

#if defined(WEBRTC_POSIX) && !defined(__native_client__)
#include <arpa/inet.h>
#endif

#include "webrtc/base/basictypes.h"

#if defined(WEBRTC_MAC)
#include <libkern/OSByteOrder.h>

#define htobe16(v) OSSwapHostToBigInt16(v)
#define htobe32(v) OSSwapHostToBigInt32(v)
#define htobe64(v) OSSwapHostToBigInt64(v)
#define be16toh(v) OSSwapBigToHostInt16(v)
#define be32toh(v) OSSwapBigToHostInt32(v)
#define be64toh(v) OSSwapBigToHostInt64(v)

#define htole16(v) OSSwapHostToLittleInt16(v)
#define htole32(v) OSSwapHostToLittleInt32(v)
#define htole64(v) OSSwapHostToLittleInt64(v)
#define le16toh(v) OSSwapLittleToHostInt16(v)
#define le32toh(v) OSSwapLittleToHostInt32(v)
#define le64toh(v) OSSwapLittleToHostInt64(v)
#elif defined(WEBRTC_WIN) || defined(__native_client__)

#if defined(WEBRTC_WIN)
#include <stdlib.h>
#include <winsock2.h>
#else
#include <netinet/in.h>
#endif

#define htobe16(v) htons(v)
#define htobe32(v) htonl(v)
#define be16toh(v) ntohs(v)
#define be32toh(v) ntohl(v)
#if defined(WEBRTC_WIN)
#define htobe64(v) htonll(v)
#define be64toh(v) ntohll(v)
#endif

#if defined(RTC_ARCH_CPU_LITTLE_ENDIAN)
#define htole16(v) (v)
#define htole32(v) (v)
#define htole64(v) (v)
#define le16toh(v) (v)
#define le32toh(v) (v)
#define le64toh(v) (v)
#if defined(__native_client__)
#define htobe64(v) __builtin_bswap64(v)
#define be64toh(v) __builtin_bswap64(v)
#endif
#elif defined(RTC_ARCH_CPU_BIG_ENDIAN)
#define htole16(v) __builtin_bswap16(v)
#define htole32(v) __builtin_bswap32(v)
#define htole64(v) __builtin_bswap64(v)
#define le16toh(v) __builtin_bswap16(v)
#define le32toh(v) __builtin_bswap32(v)
#define le64toh(v) __builtin_bswap64(v)
#if defined(__native_client__)
#define htobe64(v) (v)
#define be64toh(v) (v)
#endif
#else
#error RTC_ARCH_CPU_BIG_ENDIAN or RTC_ARCH_CPU_LITTLE_ENDIAN must be defined.
#endif  // defined(RTC_ARCH_CPU_LITTLE_ENDIAN)
#elif defined(WEBRTC_POSIX)
#include <endian.h>
#endif

namespace rtc {

// Reading and writing of little and big-endian numbers from memory

inline void Set8(void* memory, size_t offset, uint8_t v) {
  static_cast<uint8_t*>(memory)[offset] = v;
}

inline uint8_t Get8(const void* memory, size_t offset) {
  return static_cast<const uint8_t*>(memory)[offset];
}

inline void SetBE16(void* memory, uint16_t v) {
  *static_cast<uint16_t*>(memory) = htobe16(v);
}

inline void SetBE32(void* memory, uint32_t v) {
  *static_cast<uint32_t*>(memory) = htobe32(v);
}

inline void SetBE64(void* memory, uint64_t v) {
  *static_cast<uint64_t*>(memory) = htobe64(v);
}

inline uint16_t GetBE16(const void* memory) {
  return be16toh(*static_cast<const uint16_t*>(memory));
}

inline uint32_t GetBE32(const void* memory) {
  return be32toh(*static_cast<const uint32_t*>(memory));
}

inline uint64_t GetBE64(const void* memory) {
  return be64toh(*static_cast<const uint64_t*>(memory));
}

inline void SetLE16(void* memory, uint16_t v) {
  *static_cast<uint16_t*>(memory) = htole16(v);
}

inline void SetLE32(void* memory, uint32_t v) {
  *static_cast<uint32_t*>(memory) = htole32(v);
}

inline void SetLE64(void* memory, uint64_t v) {
  *static_cast<uint64_t*>(memory) = htole64(v);
}

inline uint16_t GetLE16(const void* memory) {
  return le16toh(*static_cast<const uint16_t*>(memory));
}

inline uint32_t GetLE32(const void* memory) {
  return le32toh(*static_cast<const uint32_t*>(memory));
}

inline uint64_t GetLE64(const void* memory) {
  return le64toh(*static_cast<const uint64_t*>(memory));
}

// Check if the current host is big endian.
inline bool IsHostBigEndian() {
#if defined(RTC_ARCH_CPU_BIG_ENDIAN)
  return true;
#else
  return false;
#endif
}

inline uint16_t HostToNetwork16(uint16_t n) {
  return htobe16(n);
}

inline uint32_t HostToNetwork32(uint32_t n) {
  return htobe32(n);
}

inline uint64_t HostToNetwork64(uint64_t n) {
  return htobe64(n);
}

inline uint16_t NetworkToHost16(uint16_t n) {
  return be16toh(n);
}

inline uint32_t NetworkToHost32(uint32_t n) {
  return be32toh(n);
}

inline uint64_t NetworkToHost64(uint64_t n) {
  return be64toh(n);
}

}  // namespace rtc

#endif  // WEBRTC_RTC_BASE_BYTEORDER_H_
