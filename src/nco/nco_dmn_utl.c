/* $Header: /data/zender/nco_20150216/nco/src/nco/nco_dmn_utl.c,v 1.2 2002-05-05 01:27:33 zender Exp $ */

/* Purpose: Dimension utilities */

/* Copyright (C) 1995--2002 Charlie Zender
   This software is distributed under the terms of the GNU General Public License
   See http://www.gnu.ai.mit.edu/copyleft/gpl.html for full license text */

#include "nco_dmn_utl.h" /* Dimension utilities */

void
dmn_dfn /* [fnc] Define dimensions in output file */
(const char * const fl_nm, /* I [sng] Name of output file */
 const int nc_id, /* I [id] netCDF output file ID */
 dmn_sct ** const dim, /* I [sct] Dimension structures to be defined in output file */
 const int nbr_dim) /* I [nbr] Number of dimension structures in structure list */
{
  /* Purpose: Define dimensions in output file */

  int idx;
  int rcd=NC_NOERR; /* [rcd] Return code */

  for(idx=0;idx<nbr_dim;idx++){

    /* Has dimension already been defined? */
    rcd=nco_inq_dimid_flg(nc_id,dim[idx]->nm,&dim[idx]->id);

    /* If dimension has not been defined yet, define it */
    if(rcd != NC_NOERR){
      if(dim[idx]->is_rec_dmn){
	(void)nco_def_dim(nc_id,dim[idx]->nm,NC_UNLIMITED,&(dim[idx]->id));
      }else{
	(void)nco_def_dim(nc_id,dim[idx]->nm,dim[idx]->cnt,&(dim[idx]->id));
      } /* end else */
    }else{
      (void)fprintf(stderr,"%s: WARNING dimension \"%s\" is already defined in %s\n",prg_nm_get(),dim[idx]->nm,fl_nm);
    } /* end if */
  } /* end loop over idx */
  
} /* end dmn_dfn() */

dmn_sct * /* O [sct] copy of input dimension structure */
dmn_dpl /* [fnc] Duplicate input dimension structure */
(const dmn_sct * const dim) /* I [sct] Dimension structure to duplicate */
{
  /* Purpose: nco_malloc() and return duplicate of input dmn_sct */

  dmn_sct *dmn_dpl;

  dmn_dpl=(dmn_sct *)nco_malloc(sizeof(dmn_sct));

  (void)memcpy((void *)dmn_dpl,(void *)dim,sizeof(dmn_sct));

  return dmn_dpl;

} /* end dmn_dpl() */

dmn_sct * /* O [sct] Output dimension structure */
dmn_fll /* [fnc] Create and return a completed dmn_sct */
(const int nc_id, /* I [id] netCDF input file ID*/
 const int dmn_id, /* I [id] Dimension ID */
 const char * const dmn_nm) /* I [sng] Dimension name */
{
  /* Purpose: nco_malloc() and return a completed dmn_sct */

  dmn_sct *dim;
  
  int rcd=NC_NOERR; /* [rcd] Return code */
  int rec_dmn_id;
  
  dim=(dmn_sct *)nco_malloc(sizeof(dmn_sct));
  
  dim->nm=dmn_nm;
  dim->id=dmn_id;
  dim->nc_id=nc_id;
  dim->xrf=NULL;
  dim->val.vp=NULL;

  dim->is_crd_dmn=False;
  (void)nco_inq_dimlen(dim->nc_id,dmn_id,&dim->sz);
  
  /* Get the record dimension ID */
  (void)nco_inq(dim->nc_id,(int *)NULL,(int *)NULL,(int *)NULL,&rec_dmn_id);
  if(dim->id == rec_dmn_id){
    dim->is_rec_dmn=True;
  }else{
    dim->is_rec_dmn=False;
  } /* end if */
   
  rcd=nco_inq_varid_flg(dim->nc_id,dmn_nm,&dim->cid);
  if(rcd == NC_NOERR){
    dim->is_crd_dmn=True;
    /* What type is coordinate? */
    (void)nco_inq_vartype(dim->nc_id,dim->cid,&dim->type);
  } /* end if */
  
  dim->cnt=dim->sz;
  dim->srt=0L;
  dim->end=dim->sz-1L;
  dim->srd=1L;
  
  return dim;
} /* end dmn_fll() */

void
dmn_lmt_mrg /* [fnc] Merge limit structure information into dimension structures */
(dmn_sct ** const dim, /* I [sct] Dimension structures to modify */
 const int nbr_dim, /* I [nbr] Number of dimension structures in structure list */
 const lmt_sct * const lmt, /* I [sct] Dimension limit information */
 const int lmt_nbr) /* I [nbr] Number of dimensions with user-specified limits */
{
  /* Purpose: Merge limit structure information into dimension structures */

  int idx;
  int lmt_idx;

  for(idx=0;idx<nbr_dim;idx++){

    /* Decide whether this dimension has any user-specified limits */
    for(lmt_idx=0;lmt_idx<lmt_nbr;lmt_idx++){
      if(lmt[lmt_idx].id == dim[idx]->id){
	dim[idx]->cnt=lmt[lmt_idx].cnt;
	dim[idx]->srt=lmt[lmt_idx].srt;
	dim[idx]->end=lmt[lmt_idx].end;
	dim[idx]->srd=lmt[lmt_idx].srd;
	break;
      } /* end if */
    } /* end loop over lmt_idx */
  } /* end loop over dim */
} /* end dmn_lmt_mrg() */

nm_id_sct * /* O [sct] List of dimensions associated with input variable list */
dmn_lst_ass_var /* [fnc] Create list of all dimensions associated with input variable list */
(const int nc_id, /* I [id] netCDF input-file ID */
 const nm_id_sct * const var, /* I [sct] Variable list */
 const int nbr_var, /* I [nbr] Number of variables in list */
 int * const nbr_dim) /* O [nbr] Number of dimensions associated with input variable list */
{
  /* Purpose: Create list of all dimensions associated with input variable list */

  bool dmn_has_been_placed_on_list;

  char dmn_nm[NC_MAX_NAME];

  int dmn_id[NC_MAX_DIMS];
  int idx_dmn_in;
  int idx_var;
  int idx_var_dim;
  int idx_dmn_lst;
  int nbr_dmn_in;
  int nbr_var_dim;
  
  nm_id_sct *dim;

  *nbr_dim=0;

  /* Get number of dimensions */
  (void)nco_inq(nc_id,&nbr_dmn_in,(int *)NULL,(int *)NULL,(int *)NULL);

  /* Number of input dimensions is upper bound on number of output dimensions */
  dim=(nm_id_sct *)nco_malloc(nbr_dmn_in*sizeof(nm_id_sct));
  
  /* ...For each dimension in file... */
  for(idx_dmn_in=0;idx_dmn_in<nbr_dmn_in;idx_dmn_in++){
    /* ...begin search for dimension in dimension list by... */
    dmn_has_been_placed_on_list=False;
    /* ...looking through the set of output variables... */
    for(idx_var=0;idx_var<nbr_var;idx_var++){
      /* ...and searching each dimension of each output variable... */
      (void)nco_inq_var(nc_id,var[idx_var].id,(char *)NULL,(nc_type *)NULL,&nbr_var_dim,dmn_id,(int *)NULL);
      for(idx_var_dim=0;idx_var_dim<nbr_var_dim;idx_var_dim++){
	/* ...until output variable is found which contains input dimension... */
	if(idx_dmn_in == dmn_id[idx_var_dim]){
	  /* ...then search each member of output dimension list... */
	  for(idx_dmn_lst=0;idx_dmn_lst<*nbr_dim;idx_dmn_lst++){
	    /* ...until input dimension is found... */
	    if(idx_dmn_in == dim[idx_dmn_lst].id) break; /* ...then search no further... */
	  } /* end loop over idx_dmn_lst */
	  /* ...and if dimension was not found on output dimension list... */
	  if(idx_dmn_lst == *nbr_dim){
	    /* ...then add dimension to output dimension list... */
	    (void)nco_inq_dimname(nc_id,idx_dmn_in,dmn_nm);
	    dim[*nbr_dim].id=idx_dmn_in;
	    dim[*nbr_dim].nm=(char *)strdup(dmn_nm);
	    (*nbr_dim)++;
	  } /* end if dimension was not found in current output dimension list */
	  /* ...call off the dogs for this input dimension... */
	  dmn_has_been_placed_on_list=True;
	} /* end if input dimension belongs to this output variable */
	if(dmn_has_been_placed_on_list) break; /* break out of idx_var_dim to idx_var */
      } /* end loop over idx_var_dim */
      if(dmn_has_been_placed_on_list) break; /* break out of idx_var to idx_dmn_in */
    } /* end loop over idx_var */
  } /* end loop over idx_dmn_in */
  
  /* We now have final list of dimensions to extract. Phew. */
  
  /* Free unused space in output dimension list */
  dim=(nm_id_sct *)nco_realloc((void *)dim,*nbr_dim*sizeof(nm_id_sct));
  
  return dim;

} /* end dmn_lst_ass_var() */

nm_id_sct * /* O [sct] Dimension list */
dmn_lst_mk /* [fnc] Attach dimension IDs to dimension list */
(const int nc_id, /* I [id] netCDF file ID */
 const char ** const dmn_lst_in, /* I [sng] User-specified list of dimension names */
 const int nbr_dim) /* I [nbr] Total number of dimensions in list */
{
  /* Purpose:  */
  int idx;

  nm_id_sct *dmn_lst;
  
  dmn_lst=(nm_id_sct *)nco_malloc(nbr_dim*sizeof(nm_id_sct));
  for(idx=0;idx<nbr_dim;idx++){
    /* See if requested dimension is in input file */
    dmn_lst[idx].nm=dmn_lst_in[idx];
    (void)nco_inq_dimid(nc_id,dmn_lst[idx].nm,&dmn_lst[idx].id);
  } /* end loop over idx */
  
  return dmn_lst;
} /* end dmn_lst_mk() */

void
dmn_xrf  /* [fnc] Crossreference xrf elements of dimension structures */
(dmn_sct * const dim, /* I/O [sct] Dimension structure */
 dmn_sct * const dmn_dpl) /* I/O [sct] Dimension structure */
{
  /* Purpose: Make xrf elements of dimension structures point to eachother */

  dim->xrf=dmn_dpl;
  dmn_dpl->xrf=dim;

} /* end dmn_xrf() */

