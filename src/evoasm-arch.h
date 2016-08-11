/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * Copyright (c) 2016, Julian Aron Prenner <jap@polyadic.com>
 */

#pragma once

#include <stdint.h>

#include "evoasm-error.h"
#include "evoasm-param.h"
#include "evoasm-buf.h"
#include "evoasm-log.h"

#define EVOASM_ARCH_BUF_CAPA 32
#define EVOASM_ARCH_MAX_PARAMS 32

typedef uint8_t evoasm_reg_id_t;
#define EVOASM_REG_ID_MAX UINT8_MAX
typedef uint16_t evoasm_inst_id_t;

struct evoasm_arch_ctx;
struct evoasm_inst;

typedef enum {
  EVOASM_ARCH_X64
} evoasm_arch_id_t;

typedef struct {
  evoasm_arch_id_t id : 8;
  uint16_t n_insts;
  uint8_t n_params;
  uint8_t max_inst_len;
} evoasm_arch_cls_t;

typedef enum {
  EVOASM_ARCH_ERROR_CODE_NOT_ENCODABLE = EVOASM_N_ERROR_CODES,
  EVOASM_ARCH_ERROR_CODE_MISSING_PARAM,
  EVOASM_ARCH_ERROR_CODE_INVALID_ACCESS,
  EVOASM_ARCH_ERROR_CODE_MISSING_FEATURE,
} evoasm_arch_error_code_t;

struct evoasm_arch_ctx_t;

typedef struct {
  struct evoasm_arch_ctx *arch;
  uint8_t reg;
  uint8_t param;
  uint16_t inst;
} evoasm_arch_error_data_t;

_Static_assert(sizeof(evoasm_error_data_t) >= sizeof(evoasm_arch_error_data_t), "evoasm_arch_error_data_t exceeds evoasm_error_data_t size limit");

typedef struct {
  EVOASM_ERROR_HEADER
  evoasm_arch_error_data_t data;
} evoasm_arch_error_t;

typedef struct evoasm_arch_ctx {
  evoasm_arch_cls_t *cls;
  uint8_t buf_end;
  uint8_t buf_start;
  uint8_t buf[EVOASM_ARCH_BUF_CAPA];
  void *user_data;
  /* must have a bit for every
   * writable register    */
  evoasm_bitmap128_t acc;
} evoasm_arch_ctx_t;

void
evoasm_arch_ctx_reset(evoasm_arch_ctx_t *arch_ctx);

void
evoasm_arch_ctx_init(evoasm_arch_ctx_t *arch_ctx, evoasm_arch_cls_t *cls);

void
evoasm_arch_ctx_destroy(evoasm_arch_ctx_t *arch_ctx);

size_t
evoasm_arch_ctx_save(evoasm_arch_ctx_t *arch_ctx, evoasm_buf_t *buf);

static inline void
evoasm_arch_ctx_write8(evoasm_arch_ctx_t *arch_ctx, int64_t datum) {
  uint8_t new_end = (uint8_t)(arch_ctx->buf_end + 1);
  *((uint8_t *)(arch_ctx->buf + arch_ctx->buf_end)) = (uint8_t) datum;
  arch_ctx->buf_end = new_end;
}

static inline void
evoasm_arch_ctx_write16(evoasm_arch_ctx_t *arch_ctx, int64_t datum) {
  uint8_t new_end = (uint8_t)(arch_ctx->buf_end + 2);
  *((int16_t *)(arch_ctx->buf + arch_ctx->buf_end)) = (int16_t) datum;
  arch_ctx->buf_end = new_end;
}

static inline void
evoasm_arch_ctx_write32(evoasm_arch_ctx_t *arch_ctx, int64_t datum) {
  uint8_t new_end = (uint8_t)(arch_ctx->buf_end + 4);
  *((int32_t *)(arch_ctx->buf + arch_ctx->buf_end)) = (int32_t) datum;
  arch_ctx->buf_end = new_end;
}

static inline void
evoasm_arch_ctx_write64(evoasm_arch_ctx_t *arch_ctx, int64_t datum) {
  uint8_t new_end = (uint8_t)(arch_ctx->buf_end + 8);
  *((int64_t *)(arch_ctx->buf + arch_ctx->buf_end)) = (int64_t) datum;
  arch_ctx->buf_end = new_end;
}

static inline void
evoasm_arch_ctx_write_access(evoasm_arch_ctx_t *arch_ctx, evoasm_bitmap_t *acc, evoasm_reg_id_t reg) {
  evoasm_bitmap_set(acc, (unsigned) reg);
}

static inline void
evoasm_arch_ctx_undefined_access(evoasm_arch_ctx_t *arch_ctx, evoasm_bitmap_t *acc, evoasm_reg_id_t reg) {
  evoasm_bitmap_unset(acc, (unsigned) reg);
}

static inline evoasm_success_t
_evoasm_arch_ctx_read_access(evoasm_arch_ctx_t *arch_ctx, evoasm_bitmap_t *acc, evoasm_reg_id_t reg,
                             evoasm_inst_id_t inst, const char *file, unsigned line) {
  if(!evoasm_bitmap_get(acc, (unsigned) reg)) {
    evoasm_arch_error_data_t error_data = {
      .reg = (uint8_t) reg,
      .inst = (uint16_t) inst,
      .arch = arch_ctx
    };
    evoasm_set_error(EVOASM_ERROR_TYPE_ARCH, EVOASM_ARCH_ERROR_CODE_INVALID_ACCESS, &error_data, file, line, "read access violation");
    return false;
  }
  return true;
}

#define evoasm_arch_read_access(arch, acc, reg, inst) _evoasm_arch_read_access(arch, acc, reg, inst, __FILE__, __LINE__)
