/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (C) 2021 MediaTek Inc. All Rights Reserved.
 *
 * Author: Weijie Gao <weijie.gao@mediatek.com>
 *
 * OpenWrt MTD-based image upgrading & booting helper
 */

#ifndef _MTD_HELPER_H_
#define _MTD_HELPER_H_

#include <stdbool.h>
#include <linux/types.h>
#include <linux/mtd/mtd.h>

int mtd_erase_generic(struct mtd_info *mtd, u64 offset, u64 size);
int mtd_write_generic(struct mtd_info *mtd, u64 offset, u64 max_size,
		      const void *data, size_t size, bool verify);
int mtd_read_generic(struct mtd_info *mtd, u64 offset, void *data, size_t size);
int mtd_erase_env(struct mtd_info *mtd, u64 offset, u64 size);
int mtd_update_generic(struct mtd_info *mtd, const void *data, size_t size,
		       bool verify);
int boot_from_mtd(struct mtd_info *mtd, u64 offset);

void gen_mtd_probe_devices(void);
int mtd_upgrade_image(const void *data, size_t size);
int mtd_boot_image(void);

#endif /* _MTD_HELPER_H_ */
