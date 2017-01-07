/*
 * Copyright (C) 2016 Julian Aron Prenner <jap@polyadic.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "evoasm-pop-params.h"
#include "evoasm-util.h"

EVOASM_DEF_ALLOC_FREE_FUNCS(pop_params)

EVOASM_DEF_ZERO_INIT_FUNC(pop_params)

#define EVOASM_POP_PARAMS_DEF_GETTER_SETTER(field, value_type, field_type) \
  EVOASM_DEF_GETTER(pop_params, field, value_type) \
  EVOASM_DEF_SETTER(pop_params, field, value_type, field_type)

EVOASM_POP_PARAMS_DEF_GETTER_SETTER(n_kernels, size_t, uint16_t)

EVOASM_POP_PARAMS_DEF_GETTER_SETTER(kernel_size, size_t, uint16_t)

EVOASM_POP_PARAMS_DEF_GETTER_SETTER(deme_size, size_t, uint16_t)

EVOASM_POP_PARAMS_DEF_GETTER_SETTER(n_params, size_t, uint8_t)

EVOASM_POP_PARAMS_DEF_GETTER_SETTER(n_demes, size_t, uint16_t)

EVOASM_POP_PARAMS_DEF_GETTER_SETTER(recur_limit, size_t, uint32_t)

EVOASM_POP_PARAMS_DEF_GETTER_SETTER(n_insts, size_t, uint16_t)

EVOASM_POP_PARAMS_DEF_GETTER_SETTER(program_input, evoasm_program_io_t *, evoasm_program_io_t *)

EVOASM_POP_PARAMS_DEF_GETTER_SETTER(program_output, evoasm_program_io_t *, evoasm_program_io_t *)

static evoasm_domain_t **
evoasm_pop_params_find_domain(evoasm_pop_params_t *pop_params, evoasm_param_id_t param_id) {
  for(size_t i = 0; i < pop_params->n_params; i++) {
    if(pop_params->param_ids[i] == param_id) {
      return &pop_params->domains[i];
    }
  }
  return NULL;
}

bool
evoasm_pop_params_set_domain(evoasm_pop_params_t *pop_params, evoasm_param_id_t param_id, evoasm_domain_t *domain) {
  evoasm_domain_t **domain_ptr = evoasm_pop_params_find_domain(pop_params, param_id);
  if(domain_ptr) {
    *domain_ptr = domain;
    return true;
  } else {
    return false;
  }
}

evoasm_domain_t *
evoasm_pop_params_get_domain(evoasm_pop_params_t *pop_params, evoasm_param_id_t param_id) {
  evoasm_domain_t **domain_ptr = evoasm_pop_params_find_domain(pop_params, param_id);
  if(domain_ptr) {
    return *domain_ptr;
  } else {
    return NULL;
  }
}

evoasm_param_id_t
evoasm_pop_params_get_param(evoasm_pop_params_t *pop_params, size_t idx) {
  return pop_params->param_ids[idx];
}

void
evoasm_pop_params_set_param(evoasm_pop_params_t *pop_params, size_t idx, evoasm_param_id_t param) {
  pop_params->param_ids[idx] = param;
}

uint64_t
evoasm_pop_params_get_seed(evoasm_pop_params_t *pop_params, size_t idx) {
  return pop_params->seed.data[idx];
}

void
evoasm_pop_params_set_seed(evoasm_pop_params_t *pop_params, size_t idx, uint64_t seed) {
  pop_params->seed.data[idx] = seed;
}

void
evoasm_pop_params_destroy(evoasm_pop_params_t *pop_params) {
}

void
evoasm_pop_params_set_inst(evoasm_pop_params_t *pop_params, size_t index, evoasm_inst_id_t inst_id) {
  pop_params->inst_ids[index] = inst_id;
}

evoasm_inst_id_t
evoasm_pop_params_get_inst(evoasm_pop_params_t *pop_params, size_t idx) {
  return pop_params->inst_ids[idx];
}

bool
evoasm_pop_params_validate(evoasm_pop_params_t *pop_params) {
  if(pop_params->n_params == 0) {
    evoasm_error(EVOASM_ERROR_TYPE_POP_PARAMS, EVOASM_POP_PARAMS_ERROR_CODE_INVALID,
                 "No parameters given");
    goto fail;
  }

  if(pop_params->deme_size == 0) {
    evoasm_error(EVOASM_ERROR_TYPE_POP_PARAMS, EVOASM_POP_PARAMS_ERROR_CODE_INVALID,
                 "Deme size cannot be zero");
    goto fail;
  }

  if(pop_params->n_demes == 0) {
    evoasm_error(EVOASM_ERROR_TYPE_POP_PARAMS, EVOASM_POP_PARAMS_ERROR_CODE_INVALID,
                 "Number of demes cannot be zero");
    goto fail;
  }

//  if(pop_params->mut_rate < 0.0 || pop_params->mut_rate > 1.0) {
//    evoasm_error(EVOASM_ERROR_TYPE_POP_PARAMS, EVOASM_POP_PARAMS_ERROR_CODE_INVALID,
//                 "Mutatin rate must be in the range [0..1]");
//    goto fail;
//  }

  if(pop_params->kernel_size > EVOASM_KERNEL_MAX_SIZE) {
    evoasm_error(EVOASM_ERROR_TYPE_POP_PARAMS, EVOASM_POP_PARAMS_ERROR_CODE_INVALID,
                 "Program size cannot exceed %d", EVOASM_PROGRAM_MAX_SIZE);
    goto fail;
  }

  if(pop_params->kernel_size == 0) {
    evoasm_error(EVOASM_ERROR_TYPE_POP_PARAMS, EVOASM_POP_PARAMS_ERROR_CODE_INVALID,
                 "Kernel size cannot be zero");
    goto fail;
  }

  if(pop_params->n_kernels > EVOASM_PROGRAM_MAX_SIZE) {
    evoasm_error(EVOASM_ERROR_TYPE_POP_PARAMS, EVOASM_POP_PARAMS_ERROR_CODE_INVALID,
                 "Program size cannot exceed %d", EVOASM_PROGRAM_MAX_SIZE);
    goto fail;
  }

  if(pop_params->n_kernels == 0) {
    evoasm_error(EVOASM_ERROR_TYPE_POP_PARAMS, EVOASM_POP_PARAMS_ERROR_CODE_INVALID,
                 "Program size cannot be zero");
    goto fail;
  }

  if(pop_params->n_insts == 0) {
    evoasm_error(EVOASM_ERROR_TYPE_POP_PARAMS, EVOASM_POP_PARAMS_ERROR_CODE_INVALID,
                 "No instructions given");
    goto fail;
  }

  if(pop_params->program_input == NULL || pop_params->program_input->len == 0) {
    evoasm_error(EVOASM_ERROR_TYPE_POP_PARAMS, EVOASM_POP_PARAMS_ERROR_CODE_INVALID,
                 "No input values given");
    goto fail;
  }

  if(pop_params->program_output == NULL || pop_params->program_output->len == 0) {
    evoasm_error(EVOASM_ERROR_TYPE_POP_PARAMS, EVOASM_POP_PARAMS_ERROR_CODE_INVALID,
                 "No output values given");
    goto fail;
  }

//  if(pop_params->n_demes == 0) {
//    evoasm_error(EVOASM_ERROR_TYPE_ARG, EVOASM_ERROR_CODE_NONE,
//                 NULL, "Invalid number of demes");
//    goto fail;
//  }

  return true;

fail:
  return false;
}
