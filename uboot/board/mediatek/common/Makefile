# SPDX-License-Identifier:	GPL-2.0

# Empty file to make sure compilation pass
obj-y += empty.o

ifndef CONFIG_SPL_BUILD
obj-$(CONFIG_MEDIATEK_BOOTMENU) += load_data.o upgrade_helper.o boot_helper.o \
				   untar.o image_helper.o verify_helper.o \
				   dm_parser.o
ifdef CONFIG_MTD
obj-$(CONFIG_MEDIATEK_BOOTMENU) += mtd_helper.o
endif

ifdef CONFIG_MMC
obj-$(CONFIG_MEDIATEK_BOOTMENU) += mmc_helper.o
endif

obj-$(CONFIG_MEDIATEK_BOOTMENU) += cmd_mtkupgrade.o cmd_mtkload.o \
				   cmd_mtkboardboot.o cmd_mtkautoboot.o

obj-$(CONFIG_MTK_BOOTMENU_MTD) += bootmenu_mtd.o
obj-$(CONFIG_MTK_BOOTMENU_MMC) += bootmenu_mmc.o
endif

obj-$(CONFIG_MTK_ANTI_ROLLBACK) += mtk_ar.o mtk_efuse.o

obj-$(CONFIG_MTK_DUAL_BOOT) += dual_boot.o

obj-$(CONFIG_ENABLE_NAND_NMBM) += nmbm.o
