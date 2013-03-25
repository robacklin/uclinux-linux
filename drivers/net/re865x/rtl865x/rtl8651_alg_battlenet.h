/*
* Copyright c                  Realtek Semiconductor Corporation, 2004
* All rights reserved.
* 
* Program : Blizzard Battlenet ( for Star Craft , Diablo II )
* Abstract : 
* Creator : 
* Author :
* $Id: rtl8651_alg_battlenet.h,v 1.1.2.1 2007/09/28 14:42:31 davidm Exp $
* $Log: rtl8651_alg_battlenet.h,v $
* Revision 1.1.2.1  2007/09/28 14:42:31  davidm
* #12420
*
* Pull in all the appropriate networking files for the RTL8650,  try to
* clean it up a best as possible so that the files for the build are not
* all over the tree.  Still lots of crazy dependencies in there though.
*
* Revision 1.6  2005/06/01 13:56:18  tony
* *: support alg reinit.
*
* Revision 1.5  2005/04/11 08:59:17  tony
* *: bug fixed: StarCraft support multi-user. (advanced port bouncing)
*
* Revision 1.4  2004/12/01 13:08:16  tony
* *: support StarCraft for WAN-to-LAN case.
*
* Revision 1.3  2004/04/20 03:44:02  tony
* if disable define "RTL865X_OVER_KERNEL" and "RTL865X_OVER_LINUX", __KERNEL__ and __linux__ will be undefined.
*
* Revision 1.2  2004/03/18 09:22:26  tony
* add alg reinit function, it will be called when fwdEng ReInit.
*
* Revision 1.1  2004/03/12 07:32:22  tony
* add new ALG for Blizzard Battlenet ( for Star Craft , Diablo II )
*
*
*/

#ifndef _RTL8651_ALG_BATTLENET
#define _RTL8651_ALG_BATTLENET

int32 rtl8651_l4AliasHandleBattlenetClientInbound(struct rtl_pktHdr *, struct ip *,struct rtl8651_tblDrv_naptTcpUdpFlowEntry_s *);
void  rtl8651_l4AliasHandleBattlenetReInit(void);

#endif /* _RTL8651_ALG_BATTLENET */
