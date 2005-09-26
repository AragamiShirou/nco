/* $Header: /data/zender/nco_20150216/nco/src/nco/nco_mpi.h,v 1.6 2005-09-26 07:00:39 zender Exp $ */

/* Purpose: MPI utilities */

/* NB: Currently this header is only accessed by main() MPI programs 
   Hence it is not (yet) part of libnco.a
   Header assumes its inclusion is already conditional on ENABLE_MPI
   This is currently a header mostly for file-scope constants needed by MPI routines 
   No functions (yet) but some will eventually live here after MPI functionalization
   Adding functions will require creating a corresponding *.c file
   *.c files must reside in libnco.a or link separately to MPI executables
   The latter would slightly complicate the build procedure
   I'm not yet sure I want _any_ MPI dependencies in libnco.a 
   Cross-platform link weirdness (e.g., AIX) makes this something to avoid if possible */

/* Copyright (C) 1995--2005 Charlie Zender
   This software may be modified and/or re-distributed under the terms of the GNU General Public License (GPL) Version 2
   See http://www.gnu.ai.mit.edu/copyleft/gpl.html for full license text */

/* Usage:
   #include "nco_mpi.h" *//* MPI utilities */

#ifndef NCO_MPI_H
#define NCO_MPI_H

/* Standard header files */
#include <signal.h> /* signal handling */

/* 3rd party vendors */

/* Personal headers */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

  const int msg_bfr_lng=3; /* [nbr] Number of elements in msg_bfr */
  const int wrk_id_bfr_lng=1; /* [nbr] Number of elements in wrk_id_bfr */

  /* Sleep interval between successive write token requests
     fxm: TODO nco609 tune or remove this */
  const double tkn_wrt_rqs_ntv=0.04; /* [s] Token request interval */
  
  /* Convention is to assign manager responsibilities to rank 0 process
     NB: Manager rank must be < number of processes */
  const int rnk_mgr=0; /* [idx] Manager rank */

  /* Pass idx_all_wrk_ass in place of variable ID when all variables assigned
     Values for idx_all_wrk_ass must be exclusive of valid variable IDs
     Hence use a negative integer to signify idx_all_wrk_ass */
  const int idx_all_wrk_ass=-1; /* [flg] All variables already assigned */

  /* NB: Message fields must begin in location zero */
  /* fxm: Define message structures rather than int arrays */
  const int msg_lmn_tkn_wrt_rsp=0; /* [idx] Location of response */

  /* Requests for the write token have two possible responses */
  enum tkn_wrt_rsp_val{ /* [enm] Valid responses to write token requests */
    tkn_wrt_rqs_dny, /* Deny request for write token (must wait and re-request) */
    tkn_wrt_rqs_xcp /* Accept request for write token, OK to write */
  }; /* end tkn_wrt_rsp_val enum */

  /* These (and MPI_ANY_TAG) are valid entries for the MPI message tag field 
     Processes may request to filter messages based on any of these tags */
  enum nco_msg_tag_typ{ /* [enm] MPI message tag */
    msg_tag_wrk_done, /* Notification that work is complete */
    msg_tag_wrk_rqs, /* Request for work */
    msg_tag_wrk_rsp, /* Response to work request */
    msg_tag_tkn_wrt_rqs, /* Request for write token */
    msg_tag_tkn_wrt_rsp  /* Response to write token request */
  }; /* end nco_msg_tag_typ enum */

  int nco_wai_var = 0; /* [nbr] Synchronization var for suspend/resume */
  void continue_running(int signo){nco_wai_var=1;} /* Signal handler */

#ifdef __cplusplus
} /* end extern "C" */
#endif /* __cplusplus */

#endif /* NCO_MPI_H */
