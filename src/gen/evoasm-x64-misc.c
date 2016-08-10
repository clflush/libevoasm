/* AUTOGENERATED FILE, DO NOT EDIT */

/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "evoasm-x64.h"

static const char *_evoasm_log_tag = "x64";

evoasm_success_t
evoasm_x64_load_cpuid(evoasm_x64_t *x64) {
  evoasm_buf_t buf;
  evoasm_x64_params_t params = {0};
  bool retval = true;

  uint32_t vals[3][2] = {0};
  evoasm_arch_t *arch = (evoasm_arch_t *) x64;

  evoasm_debug("Running CPUID...");

  EVOASM_TRY(alloc_failed, evoasm_buf_init, &buf, EVOASM_BUF_TYPE_MMAP, 512);

  EVOASM_TRY(enc_failed, evoasm_x64_func_prolog, x64, &buf, EVOASM_X64_ABI_SYSV);


  EVOASM_X64_SET(EVOASM_X64_INST_PARAM_REG0, EVOASM_X64_REG_A);
  EVOASM_X64_SET(EVOASM_X64_INST_PARAM_IMM0, 1);
  EVOASM_X64_ENC(mov_r32_imm32);
  evoasm_arch_save(arch, &buf);


  EVOASM_X64_ENC(cpuid);
  evoasm_arch_save(arch, &buf);


  {
    evoasm_inst_param_val_t addr_imm;
    addr_imm = (evoasm_inst_param_val_t)(uintptr_t) &vals[0][0];
    EVOASM_X64_SET(EVOASM_X64_INST_PARAM_REG0, EVOASM_X64_REG_DI);
    EVOASM_X64_SET(EVOASM_X64_INST_PARAM_IMM0, addr_imm);
    EVOASM_X64_ENC(mov_r64_imm64);
    evoasm_arch_save(arch, &buf);

    EVOASM_X64_SET(EVOASM_X64_INST_PARAM_REG1, EVOASM_X64_REG_D);
    EVOASM_X64_SET(EVOASM_X64_INST_PARAM_REG_BASE, EVOASM_X64_REG_DI);
    EVOASM_X64_ENC(mov_rm32_r32);
    evoasm_arch_save(arch, &buf);
    EVOASM_X64_UNSET(EVOASM_X64_INST_PARAM_ADDRESS_SIZE);
    EVOASM_X64_UNSET(EVOASM_X64_INST_PARAM_REG_BASE);

  }

  {
    evoasm_inst_param_val_t addr_imm;
    addr_imm = (evoasm_inst_param_val_t)(uintptr_t) &vals[0][1];
    EVOASM_X64_SET(EVOASM_X64_INST_PARAM_REG0, EVOASM_X64_REG_DI);
    EVOASM_X64_SET(EVOASM_X64_INST_PARAM_IMM0, addr_imm);
    EVOASM_X64_ENC(mov_r64_imm64);
    evoasm_arch_save(arch, &buf);

    EVOASM_X64_SET(EVOASM_X64_INST_PARAM_REG1, EVOASM_X64_REG_C);
    EVOASM_X64_SET(EVOASM_X64_INST_PARAM_REG_BASE, EVOASM_X64_REG_DI);
    EVOASM_X64_ENC(mov_rm32_r32);
    evoasm_arch_save(arch, &buf);
    EVOASM_X64_UNSET(EVOASM_X64_INST_PARAM_ADDRESS_SIZE);
    EVOASM_X64_UNSET(EVOASM_X64_INST_PARAM_REG_BASE);

  }

  EVOASM_X64_SET(EVOASM_X64_INST_PARAM_REG0, EVOASM_X64_REG_A);
  EVOASM_X64_SET(EVOASM_X64_INST_PARAM_IMM0, 7);
  EVOASM_X64_ENC(mov_r32_imm32);
  evoasm_arch_save(arch, &buf);

  EVOASM_X64_SET(EVOASM_X64_INST_PARAM_REG0, EVOASM_X64_REG_C);
  EVOASM_X64_SET(EVOASM_X64_INST_PARAM_IMM0, 0);
  EVOASM_X64_ENC(mov_r32_imm32);
  evoasm_arch_save(arch, &buf);

  EVOASM_X64_ENC(cpuid);
  evoasm_arch_save(arch, &buf);


  {
    evoasm_inst_param_val_t addr_imm;
    addr_imm = (evoasm_inst_param_val_t)(uintptr_t) &vals[1][0];
    EVOASM_X64_SET(EVOASM_X64_INST_PARAM_REG0, EVOASM_X64_REG_DI);
    EVOASM_X64_SET(EVOASM_X64_INST_PARAM_IMM0, addr_imm);
    EVOASM_X64_ENC(mov_r64_imm64);
    evoasm_arch_save(arch, &buf);

    EVOASM_X64_SET(EVOASM_X64_INST_PARAM_REG1, EVOASM_X64_REG_B);
    EVOASM_X64_SET(EVOASM_X64_INST_PARAM_REG_BASE, EVOASM_X64_REG_DI);
    EVOASM_X64_ENC(mov_rm32_r32);
    evoasm_arch_save(arch, &buf);
    EVOASM_X64_UNSET(EVOASM_X64_INST_PARAM_ADDRESS_SIZE);
    EVOASM_X64_UNSET(EVOASM_X64_INST_PARAM_REG_BASE);

  }

  {
    evoasm_inst_param_val_t addr_imm;
    addr_imm = (evoasm_inst_param_val_t)(uintptr_t) &vals[1][1];
    EVOASM_X64_SET(EVOASM_X64_INST_PARAM_REG0, EVOASM_X64_REG_DI);
    EVOASM_X64_SET(EVOASM_X64_INST_PARAM_IMM0, addr_imm);
    EVOASM_X64_ENC(mov_r64_imm64);
    evoasm_arch_save(arch, &buf);

    EVOASM_X64_SET(EVOASM_X64_INST_PARAM_REG1, EVOASM_X64_REG_C);
    EVOASM_X64_SET(EVOASM_X64_INST_PARAM_REG_BASE, EVOASM_X64_REG_DI);
    EVOASM_X64_ENC(mov_rm32_r32);
    evoasm_arch_save(arch, &buf);
    EVOASM_X64_UNSET(EVOASM_X64_INST_PARAM_ADDRESS_SIZE);
    EVOASM_X64_UNSET(EVOASM_X64_INST_PARAM_REG_BASE);

  }

  EVOASM_X64_SET(EVOASM_X64_INST_PARAM_REG0, EVOASM_X64_REG_A);
  EVOASM_X64_SET(EVOASM_X64_INST_PARAM_IMM0, 2147483649);
  EVOASM_X64_ENC(mov_r32_imm32);
  evoasm_arch_save(arch, &buf);


  EVOASM_X64_ENC(cpuid);
  evoasm_arch_save(arch, &buf);


  {
    evoasm_inst_param_val_t addr_imm;
    addr_imm = (evoasm_inst_param_val_t)(uintptr_t) &vals[2][0];
    EVOASM_X64_SET(EVOASM_X64_INST_PARAM_REG0, EVOASM_X64_REG_DI);
    EVOASM_X64_SET(EVOASM_X64_INST_PARAM_IMM0, addr_imm);
    EVOASM_X64_ENC(mov_r64_imm64);
    evoasm_arch_save(arch, &buf);

    EVOASM_X64_SET(EVOASM_X64_INST_PARAM_REG1, EVOASM_X64_REG_D);
    EVOASM_X64_SET(EVOASM_X64_INST_PARAM_REG_BASE, EVOASM_X64_REG_DI);
    EVOASM_X64_ENC(mov_rm32_r32);
    evoasm_arch_save(arch, &buf);
    EVOASM_X64_UNSET(EVOASM_X64_INST_PARAM_ADDRESS_SIZE);
    EVOASM_X64_UNSET(EVOASM_X64_INST_PARAM_REG_BASE);

  }

  {
    evoasm_inst_param_val_t addr_imm;
    addr_imm = (evoasm_inst_param_val_t)(uintptr_t) &vals[2][1];
    EVOASM_X64_SET(EVOASM_X64_INST_PARAM_REG0, EVOASM_X64_REG_DI);
    EVOASM_X64_SET(EVOASM_X64_INST_PARAM_IMM0, addr_imm);
    EVOASM_X64_ENC(mov_r64_imm64);
    evoasm_arch_save(arch, &buf);

    EVOASM_X64_SET(EVOASM_X64_INST_PARAM_REG1, EVOASM_X64_REG_C);
    EVOASM_X64_SET(EVOASM_X64_INST_PARAM_REG_BASE, EVOASM_X64_REG_DI);
    EVOASM_X64_ENC(mov_rm32_r32);
    evoasm_arch_save(arch, &buf);
    EVOASM_X64_UNSET(EVOASM_X64_INST_PARAM_ADDRESS_SIZE);
    EVOASM_X64_UNSET(EVOASM_X64_INST_PARAM_REG_BASE);

  }

  EVOASM_TRY(enc_failed, evoasm_x64_func_epilog, x64, &buf, EVOASM_X64_ABI_SYSV);

  /*evoasm_buf_dump(&buf, stderr);*/

  EVOASM_TRY(enc_failed, evoasm_buf_protect, &buf, EVOASM_MPROT_RX);
  evoasm_buf_exec(&buf);

  if(vals[0][0] & (1 << 8)) {
    x64->features |= (1 << EVOASM_X64_FEATURE_CX8);
    evoasm_info("Found support for CX8");
  } else {
    evoasm_info("Missing support for CX8");
  }
  if(vals[0][0] & (1 << 15)) {
    x64->features |= (1 << EVOASM_X64_FEATURE_CMOV);
    evoasm_info("Found support for CMOV");
  } else {
    evoasm_info("Missing support for CMOV");
  }
  if(vals[0][0] & (1 << 23)) {
    x64->features |= (1 << EVOASM_X64_FEATURE_MMX);
    evoasm_info("Found support for MMX");
  } else {
    evoasm_info("Missing support for MMX");
  }
  if(vals[0][0] & (1 << 25)) {
    x64->features |= (1 << EVOASM_X64_FEATURE_SSE);
    evoasm_info("Found support for SSE");
  } else {
    evoasm_info("Missing support for SSE");
  }
  if(vals[0][0] & (1 << 26)) {
    x64->features |= (1 << EVOASM_X64_FEATURE_SSE2);
    evoasm_info("Found support for SSE2");
  } else {
    evoasm_info("Missing support for SSE2");
  }
  if(vals[0][1] & (1 << 0)) {
    x64->features |= (1 << EVOASM_X64_FEATURE_SSE3);
    evoasm_info("Found support for SSE3");
  } else {
    evoasm_info("Missing support for SSE3");
  }
  if(vals[0][1] & (1 << 1)) {
    x64->features |= (1 << EVOASM_X64_FEATURE_PCLMULQDQ);
    evoasm_info("Found support for PCLMULQDQ");
  } else {
    evoasm_info("Missing support for PCLMULQDQ");
  }
  if(vals[0][1] & (1 << 9)) {
    x64->features |= (1 << EVOASM_X64_FEATURE_SSSE3);
    evoasm_info("Found support for SSSE3");
  } else {
    evoasm_info("Missing support for SSSE3");
  }
  if(vals[0][1] & (1 << 12)) {
    x64->features |= (1 << EVOASM_X64_FEATURE_FMA);
    evoasm_info("Found support for FMA");
  } else {
    evoasm_info("Missing support for FMA");
  }
  if(vals[0][1] & (1 << 13)) {
    x64->features |= (1 << EVOASM_X64_FEATURE_CX16);
    evoasm_info("Found support for CX16");
  } else {
    evoasm_info("Missing support for CX16");
  }
  if(vals[0][1] & (1 << 19)) {
    x64->features |= (1 << EVOASM_X64_FEATURE_SSE4_1);
    evoasm_info("Found support for SSE4_1");
  } else {
    evoasm_info("Missing support for SSE4_1");
  }
  if(vals[0][1] & (1 << 20)) {
    x64->features |= (1 << EVOASM_X64_FEATURE_SSE4_2);
    evoasm_info("Found support for SSE4_2");
  } else {
    evoasm_info("Missing support for SSE4_2");
  }
  if(vals[0][1] & (1 << 22)) {
    x64->features |= (1 << EVOASM_X64_FEATURE_MOVBE);
    evoasm_info("Found support for MOVBE");
  } else {
    evoasm_info("Missing support for MOVBE");
  }
  if(vals[0][1] & (1 << 23)) {
    x64->features |= (1 << EVOASM_X64_FEATURE_POPCNT);
    evoasm_info("Found support for POPCNT");
  } else {
    evoasm_info("Missing support for POPCNT");
  }
  if(vals[0][1] & (1 << 25)) {
    x64->features |= (1 << EVOASM_X64_FEATURE_AES);
    evoasm_info("Found support for AES");
  } else {
    evoasm_info("Missing support for AES");
  }
  if(vals[0][1] & (1 << 28)) {
    x64->features |= (1 << EVOASM_X64_FEATURE_AVX);
    evoasm_info("Found support for AVX");
  } else {
    evoasm_info("Missing support for AVX");
  }
  if(vals[0][1] & (1 << 29)) {
    x64->features |= (1 << EVOASM_X64_FEATURE_F16C);
    evoasm_info("Found support for F16C");
  } else {
    evoasm_info("Missing support for F16C");
  }
  if(vals[1][0] & (1 << 3)) {
    x64->features |= (1 << EVOASM_X64_FEATURE_BMI1);
    evoasm_info("Found support for BMI1");
  } else {
    evoasm_info("Missing support for BMI1");
  }
  if(vals[1][0] & (1 << 5)) {
    x64->features |= (1 << EVOASM_X64_FEATURE_AVX2);
    evoasm_info("Found support for AVX2");
  } else {
    evoasm_info("Missing support for AVX2");
  }
  if(vals[1][0] & (1 << 8)) {
    x64->features |= (1 << EVOASM_X64_FEATURE_BMI2);
    evoasm_info("Found support for BMI2");
  } else {
    evoasm_info("Missing support for BMI2");
  }
  if(vals[1][0] & (1 << 11)) {
    x64->features |= (1 << EVOASM_X64_FEATURE_RTM);
    evoasm_info("Found support for RTM");
  } else {
    evoasm_info("Missing support for RTM");
  }
  if(vals[1][0] & (1 << 18)) {
    x64->features |= (1 << EVOASM_X64_FEATURE_RDSEED);
    evoasm_info("Found support for RDSEED");
  } else {
    evoasm_info("Missing support for RDSEED");
  }
  if(vals[1][0] & (1 << 19)) {
    x64->features |= (1 << EVOASM_X64_FEATURE_ADX);
    evoasm_info("Found support for ADX");
  } else {
    evoasm_info("Missing support for ADX");
  }
  if(vals[1][0] & (1 << 23)) {
    x64->features |= (1 << EVOASM_X64_FEATURE_CLFLUSHOPT);
    evoasm_info("Found support for CLFLUSHOPT");
  } else {
    evoasm_info("Missing support for CLFLUSHOPT");
  }
  if(vals[1][0] & (1 << 28)) {
    x64->features |= (1 << EVOASM_X64_FEATURE_SHA);
    evoasm_info("Found support for SHA");
  } else {
    evoasm_info("Missing support for SHA");
  }
  if(vals[1][1] & (1 << 0)) {
    x64->features |= (1 << EVOASM_X64_FEATURE_PREFETCHWT1);
    evoasm_info("Found support for PREFETCHWT1");
  } else {
    evoasm_info("Missing support for PREFETCHWT1");
  }
  if(vals[2][1] & (1 << 0)) {
    x64->features |= (1 << EVOASM_X64_FEATURE_LAHF_LM);
    evoasm_info("Found support for LAHF_LM");
  } else {
    evoasm_info("Missing support for LAHF_LM");
  }


cleanup:
  EVOASM_TRY(destroy_failed, evoasm_buf_destroy, &buf);
  return retval;
enc_failed:
  retval = false;
  goto cleanup;
destroy_failed:
  return false;
alloc_failed:
  return false;
}

