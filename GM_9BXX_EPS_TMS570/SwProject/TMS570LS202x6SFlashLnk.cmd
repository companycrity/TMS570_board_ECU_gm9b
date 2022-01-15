/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : TMS570LS202x6SFlashLnk.cmd
* Module Description: Linker Command File
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Tue Dec 14 14:58:07 2010
* %version:          1 %
* %derived_by:       CZ8L9T %
* %date_modified:    Wed Nov  6 11:42:58 2013 %
*---------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/
/* Linker Settings                                                          */
--retain="*(.intvecs)"

/*--------------------------------------------------------------------------*/
/* Memory Map                                                               */
MEMORY{

	/* Bootmanager                0x0000 0000 - 0x0000 FFFF                                    */
	BOOT_VECTOR      (RX) : origin=0x00000000 length=0x00000040   /* BOOTMANAGER STARTUP CODE  */
	BOOT_FLASH       (RX) : origin=0x00000040 length=0x0000FFB8   /* BOOTMANAGER               */
	ECCSTATE_BM      (R)  : origin=0x0000FFF8 length=0x8          /* APPLICATION Upgrade State */

	GMCAL2HEADER     (RX) : origin=0x00010000 length=0x00000078 fill=0xFFFFFFFF /* APPLICATION */
	CAL2_CRC         (RX) : origin=0x00010078 length=0x00000008 fill=0xFFFFFFFF /* APPLICATION */
	CAL2_FLASH       (RX) : origin=0x00010080 length=0x00003F70 fill=0xFFFFFFFF /* APPLICATION */
	CAL2PRESENCE     (RX) : origin=0x00013FF0 length=0x00000010 fill=0xFFFFFFFF /* APPLICATION */

	GMCAL3HEADER     (RX) : origin=0x00014000 length=0x00000078 fill=0xFFFFFFFF /* APPLICATION */
	CAL3_CRC         (RX) : origin=0x00014078 length=0x00000008 fill=0xFFFFFFFF /* APPLICATION */
	CAL3_FLASH       (RX) : origin=0x00014080 length=0x0000BF70 fill=0xFFFFFFFF /* APPLICATION */
	CAL3PRESENCE     (RX) : origin=0x0001FFF0 length=0x00000010 fill=0xFFFFFFFF /* APPLICATION */

	/* Application */
	GMAPPHEADER      (RX) : origin=0x00020000 length=0x00000078  fill=0xFFFFFFFF /* APPLICATION */
	APP_CRC          (RX) : origin=0x00020078 length=0x00000008  fill=0xFFFFFFFF /* APPLICATION */
	APP_BLSHARED     (RX) : origin=0x00020080 length=0x00000080  fill=0xFFFFFFFF /* APPLICATION */
	APPVECTOR        (RX) : origin=0x00020100 length=0x00000100  fill=0xFFFFFFFF /* APPLICATION */
	APP_FLASH        (RX) : origin=0x00020200 length=0x0007FDF0  fill=0xFFFFFFFF /* APPLICATION */
	APPPRESENCE      (RX) : origin=0x0009FFF0 length=0x00000008  fill=0xFFFFFFFF /* APPLICATION */
	RSVD_VALDBLK     (RX) : origin=0x0009FFF8 length=0x00000008  fill=0xFFFFFFFF /* APPLICATION */

	GMCALHEADER      (RX) : origin=0x000A0000 length=0x00000078 fill=0xFFFFFFFF /* APPLICATION */
	CAL_CRC          (RX) : origin=0x000A0078 length=0x00000008 fill=0xFFFFFFFF /* APPLICATION */
	CAL_FLASH        (RX) : origin=0x000A0080 length=0x0001FF70 fill=0xFFFFFFFF /* APPLICATION */
	CALPRESENCE      (RX) : origin=0x000BFFF0 length=0x00000010 fill=0xFFFFFFFF /* APPLICATION */

	/* RAM Memory Regions */
	RESET_CAUSE      (RW) : origin=0x08000000 length=0x00000004 /* BOOTLOADER */
	STACKS           (RW) : origin=0x08000004 length=0x000003FC /* BOOTLOADER */
	RAM              (RW) : origin=0x08000400 length=0x0001FC00 /* BOOTLOADER */

	MMC              (RW) : origin=0xFFFFFD00   length=0x40
	DEC              (RW) : origin=0xFFFFFE00   length=0x60
	SYS              (RW) : origin=0xFFFFFFD0   length=0x30

	NHET2RAM         (RW) : origin=0xFF440000 length=0x00000800
	NHETRAM          (RW) : origin=0xFF460000 length=0x00000800
}

/*--------------------------------------------------------------------------*/
/* Section Configuration                                                    */
SECTIONS{
	N_Cal3HeaderSeg     : {} > GMCAL3HEADER
	N_Cal2HeaderSeg     : {} > GMCAL2HEADER
	N_CalHeaderSeg      : {} > GMCALHEADER
	N_AppHeaderSeg      : {} > GMAPPHEADER
	N_NxtrSWPN          : {} > 0x00020200 /* Start of APP_FLASH. Only place statically for debug purposes. */
	N_PresPattAppSeg    : {} > APPPRESENCE
	N_PresPattCalSeg    : {} > CALPRESENCE
	N_PresPattCalSeg2   : {} > CAL2PRESENCE
	N_PresPattCalSeg3   : {} > CAL3PRESENCE
	N_GMLANID           : {} > 0x00020080

	/* APPVECTOR */
	.osresetvect    : {} > 0x00020100
	.osarmvect      : {} > 0x00020104
	.fiqarmvect     : {} > 0x0002011C

	.cinit          : { } > APP_FLASH

	.resetcause     : {} > RESET_CAUSE
	.noclear        : {} > RAM

	.bss      : LOAD_END(Lnk_BSS_End),
	            LOAD_START(Lnk_BSS_Start)
	            {
	                #include "./Source/GenDataOS/osobjs.inc"
	                *(.ossctxdata)
	            } > RAM

	.data : {
	            #include "./Source/GenDataOS/osobjs_init.inc"
	            *(.osstack)
	        } > RAM

	.sysmem : {} > RAM

	.stack : {
	             _StackSVC_   = .+ (0x0100);
	             _StackUSER_  = .+ (0x0200);
	             _StackUND_   = .+ (0x0300); /* Share stacks for undefined instruction and data abort. */
	             _StackABORT_ = .+ (0x0300);
	             _StackFIQ_   = .+ (0x0380);
	             _StackIRQ_   = .+ (0x03FC);
	         } > STACKS /* SOFTWARE SYSTEM STACK */

	.MMC     : {_e_SARMMC_ST = .;}  > MMC
	.DEC     : {_e_SARDEC_ST = .;}  > DEC
	.SYS     : {_e_SARSYS_ST = .;}  > SYS

	.SysCal2Seg : {} > CAL2_FLASH

	.CAL_SYSCAL1 : LOAD = CAL_FLASH
	{
		*(.SysCal1Seg)
	}

	.CAL_TUN0 : LOAD = CAL_FLASH
	{
		*(.TunCal0)
	}
	.CAL_TUN1 : LOAD = CAL_FLASH
	{
		*(.TunCal1)
	}
	.CAL_TUN2 : LOAD = CAL_FLASH
	{
		*(.TunCal2)
	}
	.CAL_TUN3 : LOAD = CAL_FLASH
	{
		*(.TunCal3)
	}
	.CAL_TUN4 : LOAD = CAL_FLASH
	{
		*(.TunCal4)
	}
	.CAL_TUN5 : LOAD = CAL_FLASH
	{
		*(.TunCal5)
	}
	.CAL_TUN6 : LOAD = CAL_FLASH
	{
		*(.TunCal6)
	}
	.CAL_TUN7 : LOAD = CAL_FLASH
	{
		*(.TunCal7)
	}

	.CAL_PERF : LOAD = CAL3_FLASH
	{
		*(.PerfCalSeg)
	}

	.CAL_TUN0_PERS0 : LOAD = CAL3_FLASH
	{
		*(.TunCal0Per0)
	}
	.CAL_TUN0_PERS1 : LOAD = CAL3_FLASH
	{
		*(.TunCal0Per1)
	}
	.CAL_TUN0_PERS2 : LOAD = CAL3_FLASH
	{
		*(.TunCal0Per2)
	}
	.CAL_TUN0_PERS3 : LOAD = CAL3_FLASH
	{
		*(.TunCal0Per3)
	}


	.APPFLASH: > APP_FLASH, palign(64)
		LOAD_START(Lnk_PrgFlash_Start)
		LOAD_SIZE(Lnk_PrgFlash_Length)
		{
			*(.osvtable)
			*(.text)
			*(.const)
			*(.oscode)
			*(.osconst)
			.=((.-1)/4)*4+4;  /* Force align to 32bits as osconfig is structure */
			/* Note this checksum has to run prior to the overall flash checksum */
			CCT_Range_00_Start = .;
			CCT_Range_00_BitAddrGran = 8;
			CCT_Range_00_Category = 300;
			CCT_Range_00_Algorithm = 10;
			*(.osconfig)
			CCT_Range_00_Length = . - CCT_Range_00_Start-2;
			CCT_Range_00_Address = CCT_Range_00_Start + CCT_Range_00_Length;
		}

	.HETCODE : { e_HETPROGRAM0_UN = .;} > 0xFF460000     /* HET PROGRAM */
	.HET2CODE : { e_HETPROGRAM1_UN = .;} > 0xFF440000    /* HET2 PROGRAM */

	.APPCHECKSUM: > APP_CRC
	{
		_CRC_Boot_Start = 0;
		_CRC_Boot_Address = 0xFFF8;

		_CCT_Range_01_Address = .;
		_CCT_Range_01_Length = 0x7FF70;
		_CCT_Range_01_Start = 0x20080;
		_CCT_Range_01_BitAddrGran = 8;
		_CCT_Range_01_Category = 300;
		_CCT_Range_01_Algorithm = 12;
	}

	.CALCHECKSUM: > CAL_CRC
	{
		_CCT_Range_10_Address = .;
		_CCT_Range_10_Length = 0x1FF70;
		_CCT_Range_10_Start = 0xA0080;
		_CCT_Range_10_BitAddrGran = 8;
		_CCT_Range_10_Category = 200;
		_CCT_Range_10_Algorithm = 12;

		Lnk_BootRelNum_Addr = 0x0000FFC0;
	}

	.CAL2CHECKSUM: > CAL2_CRC
	{
		_CCT_Range_11_Address = .;
		_CCT_Range_11_Length = 0x3F70;
		_CCT_Range_11_Start = 0x10080;
		_CCT_Range_11_BitAddrGran = 8;
		_CCT_Range_11_Category = 200;
		_CCT_Range_11_Algorithm = 12;
	}

	.CAL3CHECKSUM: > CAL3_CRC
	{
		_CCT_Range_12_Address = .;
		_CCT_Range_12_Length = 0xBF70;
		_CCT_Range_12_Start = 0x14080;
		_CCT_Range_12_BitAddrGran = 8;
		_CCT_Range_12_Category = 200;
		_CCT_Range_12_Algorithm = 12;
	}

	.T1_bss : {} > RAM
	.T1_traceBuffer : {} > RAM
	.T1_code : {} > APP_FLASH
	.T1_const : {} > APP_FLASH
	.T1_alignedCodeFast : > APP_FLASH
	{
		. = align(16);
		*(.T1_codeFast:T1_TraceEvent_)
		. = align(16);
		*(.T1_codeFast:T1_TraceEventFast_)
		. = align(16);
		*(.T1_codeFast:T1_GetTraceTime)
		. = align(16);
		*(.T1_codeFast:T1_TraceEventNoSusp_)
		. = align(16);
		*(.T1_codeFast)
	}
}

/*****************************************************************************
CHANGE HISTORY:

 Date      Rev      Author         Change Description              SCR #
-------   -------  --------  -----------------------------------  ----------
04/24/15  1        GMN       Initial 9Bxx Synergy Version
02/01/16  2        GMN       EA3#2919: New bootloader 02.00.00     5902
                                       and 3 sectors for cals
02/15/16  3        GMN       EA3#43112: Motor variant new tunning
                             sets and cal segs renamed             4383
11/28/16  4        CP       EA3#12343: Remove Personality sets 5,6,7
							to free up memory in PerfCalSeg
******************************************************************************/
