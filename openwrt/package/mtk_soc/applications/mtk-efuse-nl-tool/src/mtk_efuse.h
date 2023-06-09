/* SPDX-License-Identifier:	GPL-2.0+ */
/*
 * Copyright (C) 2021 MediaTek Incorporation. All Rights Reserved.
 *
 * Author: Alvin Kuo <Alvin.Kuo@mediatek.com>
 */
#ifndef __MTK_EFUSE_H__
#define __MTK_EFUSE_H__

/*********************************************************************************
 *
 *  eFuse info (DO NOT EDIT, it copy from ATF)
 *
 ********************************************************************************/
enum MTK_EFUSE_FIELD {
	MTK_EFUSE_FIELD_SBC_PUBK0_HASH = 0,
	MTK_EFUSE_FIELD_SBC_PUBK1_HASH,
	MTK_EFUSE_FIELD_SBC_PUBK2_HASH,
	MTK_EFUSE_FIELD_SBC_PUBK3_HASH,
	MTK_EFUSE_FIELD_SBC_PUBK0_HASH_LOCK,
	MTK_EFUSE_FIELD_SBC_PUBK1_HASH_LOCK,
	MTK_EFUSE_FIELD_SBC_PUBK2_HASH_LOCK,
	MTK_EFUSE_FIELD_SBC_PUBK3_HASH_LOCK,
	MTK_EFUSE_FIELD_SBC_PUBK0_HASH_DIS,
	MTK_EFUSE_FIELD_SBC_PUBK1_HASH_DIS,
	MTK_EFUSE_FIELD_SBC_PUBK2_HASH_DIS,
	MTK_EFUSE_FIELD_SBC_PUBK3_HASH_DIS,
	MTK_EFUSE_FIELD_JTAG_DIS,
	MTK_EFUSE_FIELD_SBC_EN,
	MTK_EFUSE_FIELD_AR_EN,
	MTK_EFUSE_FIELD_DAA_EN,
	MTK_EFUSE_FIELD_BROM_CMD_DIS,
	__MTK_EFUSE_FIELD_MAX,
};
#define MTK_EFUSE_FIELD_MAX (__MTK_EFUSE_FIELD_MAX)

enum MTK_EFUSE_PUBK_HASH_INDEX {
	MTK_EFUSE_PUBK_HASH_INDEX0 = 0,
	MTK_EFUSE_PUBK_HASH_INDEX1,
	MTK_EFUSE_PUBK_HASH_INDEX2,
	MTK_EFUSE_PUBK_HASH_INDEX3,
	MTK_EFUSE_PUBK_HASH_INDEX4,
	MTK_EFUSE_PUBK_HASH_INDEX5,
	MTK_EFUSE_PUBK_HASH_INDEX6,
	MTK_EFUSE_PUBK_HASH_INDEX7,
	__MTK_EFUSE_PUBK_HASH_INDEX_MAX,
};
#define MTK_EFUSE_PUBK_HASH_INDEX_MAX (__MTK_EFUSE_PUBK_HASH_INDEX_MAX)

#define MTK_EFUSE_PUBK_HASH_LEN			32

/*********************************************************************************
 *
 *  netlink info
 *
 ********************************************************************************/
#define MTK_EFUSE_NL_GENL_NAME			"mtk-efuse"
#define MTK_EFUSE_NL_GENL_VERSION		0x1

enum MTK_EFUSE_NL_CMD {
	MTK_EFUSE_NL_CMD_UNSPEC = 0,
	MTK_EFUSE_NL_CMD_READ,
	MTK_EFUSE_NL_CMD_READ_PUBK_HASH,
	MTK_EFUSE_NL_CMD_WRITE,
	MTK_EFUSE_NL_CMD_WRITE_PUBK_HASH,
	MTK_EFUSE_NL_CMD_UPDATE_AR_VER,
	__MTK_EFUSE_NL_CMD_MAX
};
#define MTK_EFUSE_NL_CMD_MAX (__MTK_EFUSE_NL_CMD_MAX - 1)

enum MTK_EFUSE_NL_ATTR_TYPE {
	MTK_EFUSE_NL_ATTR_TYPE_UNSPEC = 0,
	MTK_EFUSE_NL_ATTR_TYPE_EFUSE_FIELD,
	MTK_EFUSE_NL_ATTR_TYPE_EFUSE_VALUE,
	MTK_EFUSE_NL_ATTR_TYPE_PUBK_HASH0,
	MTK_EFUSE_NL_ATTR_TYPE_PUBK_HASH1,
	MTK_EFUSE_NL_ATTR_TYPE_PUBK_HASH2,
	MTK_EFUSE_NL_ATTR_TYPE_PUBK_HASH3,
	MTK_EFUSE_NL_ATTR_TYPE_PUBK_HASH4,
	MTK_EFUSE_NL_ATTR_TYPE_PUBK_HASH5,
	MTK_EFUSE_NL_ATTR_TYPE_PUBK_HASH6,
	MTK_EFUSE_NL_ATTR_TYPE_PUBK_HASH7,
	__MTK_EFUSE_NL_ATTR_TYPE_MAX,
};
#define MTK_EFUSE_NL_ATTR_TYPE_MAX (__MTK_EFUSE_NL_ATTR_TYPE_MAX - 1)

/*********************************************************************************
 *
 *  efuse data in user space
 *
 ********************************************************************************/
struct mtk_efuse_data_t {
	uint32_t efuse_field;
	uint32_t efuse_value;
	uint32_t pubk_hash[MTK_EFUSE_PUBK_HASH_INDEX_MAX];
};

#endif /* __MTK_EFUSE_H__ */
