/*
 * Copyright (C) 2012  Peter Schildmann <linux@schildmann.info>
 *
 * Based on guruplug.h originally written by
 * Siddarth Gore <gores@marvell.com>
 * (C) Copyright 2009
 * Marvell Semiconductor <www.marvell.com>
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301 USA
 */

#ifndef _CONFIG_NSA320_H
#define _CONFIG_NSA320_H

/*
 * Version number information
 */
#define CONFIG_IDENT_STRING	"\nZyXEL NSA320 2-Bay Power Media Server"

/*
 * High Level Configuration Options (easy to change)
 */
#define CONFIG_FEROCEON_88FR131	1	/* CPU Core subversion */
#define CONFIG_KIRKWOOD		1	/* SOC Family Name */
#define CONFIG_KW88F6281	1	/* SOC Name */
#define CONFIG_MACH_NSA320		/* Machine type */
#define CONFIG_SKIP_LOWLEVEL_INIT	/* disable board lowlevel_init */

/*
 * Misc Configuration Options
 */
#define CONFIG_SHOW_BOOT_PROGRESS 1	/* boot progess display (LED's) */

/*
 * Commands configuration
 */
#define CONFIG_SYS_NO_FLASH		/* Declare no flash (NOR/SPI) */
#include <config_cmd_default.h>
#define CONFIG_CMD_DHCP
#define CONFIG_CMD_ENV
#define CONFIG_CMD_FAT
#define CONFIG_CMD_MII
#define CONFIG_CMD_NAND
#define CONFIG_CMD_PING
#define CONFIG_CMD_USB
#define CONFIG_CMD_IDE

/*
 * mv-common.h should be defined after CMD configs since it used them
 * to enable certain macros
 */
#include "mv-common.h"

#undef CONFIG_SYS_PROMPT	/* previously defined in mv-common.h */
#define CONFIG_SYS_PROMPT	"NSA320> "	/* Command Prompt */

/*
 *  Environment variables configurations
 */
#ifdef CONFIG_CMD_NAND
#define CONFIG_ENV_IS_IN_NAND		1
#define CONFIG_ENV_SECT_SIZE		0x20000		/* 128K */
#else
#define CONFIG_ENV_IS_NOWHERE		1		/* if env in SDRAM */
#endif
/*
 * max 4k env size is enough, but in case of nand
 * it has to be rounded to sector size
 */
#define CONFIG_ENV_SIZE			0x20000		/* 128k */
#define CONFIG_ENV_ADDR			0x120000
#define CONFIG_ENV_OFFSET		0x120000	/* env starts here */

/* ###################################################################### */
/* FIMXE: */
/*
0x00000000-0x00100000 : "uboot"
0x00100000-0x00180000 : "uboot_env"
0x00180000-0x00200000 : "key_store"
0x00200000-0x00280000 : "info"
0x00280000-0x00c80000 : "etc"
0x00c80000-0x01680000 : "kernel_1"
0x01680000-0x04640000 : "rootfs1"
0x04640000-0x05040000 : "kernel_2"
0x05040000-0x08000000 : "rootfs2"
*/

/*
 * Default environment variables
 */
/*
#define CONFIG_BOOTCOMMAND \
	"setenv bootargs ${console} ${mtdparts} ${bootargs_root}; "	\
	"ubi part root; " \
	"ubifsmount root; " \
	"ubifsload 0x800000 ${kernel}; " \
	"ubifsload 0x1100000 ${initrd}; " \
	"bootm 0x800000 0x1100000"

#define CONFIG_MTDPARTS		"mtdparts=orion_nand:1m(uboot),-(root)\0"

#define CONFIG_EXTRA_ENV_SETTINGS \
	"console=console=ttyS0,115200\0" \
	"mtdids=nand0=orion_nand\0" \
	"mtdparts="CONFIG_MTDPARTS \
	"kernel=/boot/uImage\0" \
	"initrd=/boot/uInitrd\0" \
	"bootargs_root=ubi.mtd=1 root=ubi0:root rootfstype=ubifs ro\0"
*/
/* ###################################################################### */

/*
 * Ethernet Driver configuration
 */
#ifdef CONFIG_CMD_NET
#define CONFIG_MVGBE_PORTS		{1, 0}	/* enable port 0 only */
#define CONFIG_PHY_BASE_ADR		0x1
#define CONFIG_PHY_GIGE
#endif /* CONFIG_CMD_NET */

/*
 * SATA Driver configuration
 */
#ifdef CONFIG_MVSATA_IDE
#define CONFIG_SYS_ATA_IDE0_OFFSET      MV_SATA_PORT0_OFFSET
#define CONFIG_SYS_ATA_IDE1_OFFSET      MV_SATA_PORT1_OFFSET
#endif /* CONFIG_MVSATA_IDE */

/*
 * File system
 */
#define CONFIG_CMD_EXT2
#define CONFIG_CMD_FAT
#define CONFIG_CMD_JFFS2
/* #define CONFIG_CMD_UBI */
/* #define CONFIG_CMD_UBIFS */
/* #define CONFIG_RBTREE */
#define CONFIG_MTD_DEVICE               /* needed for mtdparts commands */
#define CONFIG_MTD_PARTITIONS
#define CONFIG_CMD_MTDPARTS
#define CONFIG_LZO

#endif /* _CONFIG_NSA320_H */
