/*
 * Copyright (c) 2015, ARM Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <arch_helpers.h>
#include <cpuxgpt.h>
#include <lib/mmio.h>
//#include <mcucfg.h>

static void write_cpuxgpt(unsigned int reg_index, unsigned int value)
{
//	mmio_write_32((uintptr_t)&mt7622_mcucfg->xgpt_idx, reg_index);
//	mmio_write_32((uintptr_t)&mt7622_mcucfg->xgpt_ctl, value);
}

static void cpuxgpt_set_init_cnt(unsigned int countH, unsigned int countL)
{
	write_cpuxgpt(INDEX_CNT_H_INIT, countH);
	/* update count when countL programmed */
	write_cpuxgpt(INDEX_CNT_L_INIT, countL);
}

void generic_timer_backup(void)
{
	uint64_t cval;

	cval = read_cntpct_el0();
	cpuxgpt_set_init_cnt((uint32_t)(cval >> 32),
			     (uint32_t)(cval & 0xffffffff));
}

void plat_mt_cpuxgpt_init(void)
{
	/* use clock 25M/2 for kernel arch timer */
	write_cpuxgpt(0x0, 0x200);
}
