/* $Header: /data/zender/nco_20150216/nco/src/nco/nco_mss_val.c,v 1.32 2007-02-23 21:59:31 zender Exp $ */

/* Purpose: Missing value utilities */

/* Copyright (C) 1995--2007 Charlie Zender
   You may copy, distribute, and/or modify this software under the terms of the GNU General Public License (GPL) Version 2
   See http://www.gnu.org/copyleft/gpl.html for full license text */

#include "nco_mss_val.h" /* Missing value utilities */

ptr_unn /* O [sct] Default missing value for type type */
nco_mss_val_mk /* [fnc] Return default missing value for type type */
(const nc_type type) /* I [enm] netCDF type of operand */
{
  /* Threads: Routine is thread safe and makes no unsafe routines */
  /* Purpose: Return pointer union containing default missing value for type type */

  ptr_unn mss_val;

  mss_val.vp=(void *)nco_malloc(nco_typ_lng(type));

  /* Typecast pointer to values before access */
  (void)cast_void_nctype(type,&mss_val);

  switch(type){
  case NC_FLOAT: *mss_val.fp=NC_FILL_FLOAT; break; 
  case NC_DOUBLE: *mss_val.dp=NC_FILL_DOUBLE; break; 
  case NC_INT: *mss_val.lp=NC_FILL_INT; break;
  case NC_SHORT: *mss_val.sp=NC_FILL_SHORT; break;
  case NC_CHAR: *mss_val.cp=NC_FILL_CHAR; break;
  case NC_BYTE: *mss_val.bp=NC_FILL_BYTE; break;
  default: nco_dfl_case_nc_type_err(); break;
  } /* end switch */

  /* Un-typecast pointer to values after access */
  (void)cast_nctype_void(type,&mss_val);
  
  return mss_val;

} /* end nco_mss_val_mk() */
  
nco_bool /* O [flg] One or both operands have missing value */
nco_mss_val_cnf /* [fnc] Change missing_value of var2 to missing_value of var1 */
(var_sct * const var1, /* I [sct] Variable with template missing value to copy */
 var_sct * const var2) /* I/O [sct] Variable with missing value to fill in/overwrite */
{
  /* Purpose: 
     1. Change missing_value of var2 to missing_value of var1 when both exist 
     2. Change missing_value of var1 to missing_value of var2 when only var2 has a missing_value
     3. Change missing_value of var2 to missing_value of var1 when only var1 has a missing_value
     4. Return false when neither operand has missing value */
  int has_mss_val=False; /* [flg] One or both operands have missing value */
  nco_bool MSS_VAL_EQL=False; /* [flg] Missing values of input operands are identical */
  long idx;
  long var_sz=long_CEWI;
  nc_type var_typ=NC_NAT; /* CEWI [enm] Type of input values */
  ptr_unn var_val;

  has_mss_val=var1->has_mss_val || var2->has_mss_val; 

  /* No missing values */
  if(!var1->has_mss_val && !var2->has_mss_val) return has_mss_val;

  if(var1->has_mss_val && var2->has_mss_val){
    var_typ=var1->type;
    (void)cast_void_nctype(var_typ,&var1->mss_val);
    (void)cast_void_nctype(var_typ,&var2->mss_val);
    switch(var_typ){
    case NC_FLOAT: MSS_VAL_EQL=(*var1->mss_val.fp == *var2->mss_val.fp); break;
    case NC_DOUBLE: MSS_VAL_EQL=(*var1->mss_val.dp == *var2->mss_val.dp); break;
    case NC_INT: MSS_VAL_EQL=(*var1->mss_val.lp == *var2->mss_val.lp); break;
    case NC_SHORT: MSS_VAL_EQL=(*var1->mss_val.sp == *var2->mss_val.sp); break;
    case NC_CHAR: MSS_VAL_EQL=(*var1->mss_val.cp == *var2->mss_val.cp); break;
    case NC_BYTE: MSS_VAL_EQL=(*var1->mss_val.bp == *var2->mss_val.bp); break;
    default: nco_dfl_case_nc_type_err(); break;
    } /* end switch */
    if(!MSS_VAL_EQL){
      /* World's most anally formatted warning message... */
      char mss_val_1_sng[NCO_MAX_LEN_FMT_SNG];
      char mss_val_2_sng[NCO_MAX_LEN_FMT_SNG];
      const char *fmt_sng;
      fmt_sng=nco_typ_fmt_sng(var1->type);
      switch(var1->type){
      case NC_FLOAT: (void)sprintf(mss_val_1_sng,fmt_sng,var1->mss_val.fp[0]); break;
      case NC_DOUBLE: (void)sprintf(mss_val_1_sng,fmt_sng,var1->mss_val.dp[0]); break;
      case NC_SHORT: (void)sprintf(mss_val_1_sng,fmt_sng,var1->mss_val.sp[0]); break;
      case NC_INT: (void)sprintf(mss_val_1_sng,fmt_sng,var1->mss_val.lp[0]); break;
      case NC_CHAR: (void)sprintf(mss_val_1_sng,fmt_sng,var1->mss_val.cp[0]); break;
      case NC_BYTE: (void)sprintf(mss_val_1_sng,fmt_sng,var1->mss_val.bp[0]); break;
      default: nco_dfl_case_nc_type_err(); break;
      } /* end switch */
      fmt_sng=nco_typ_fmt_sng(var2->type);
      switch(var2->type){
      case NC_FLOAT: (void)sprintf(mss_val_2_sng,fmt_sng,var2->mss_val.fp[0]); break;
      case NC_DOUBLE: (void)sprintf(mss_val_2_sng,fmt_sng,var2->mss_val.dp[0]); break;
      case NC_SHORT: (void)sprintf(mss_val_2_sng,fmt_sng,var2->mss_val.sp[0]); break;
      case NC_INT: (void)sprintf(mss_val_2_sng,fmt_sng,var2->mss_val.lp[0]); break;
      case NC_CHAR: (void)sprintf(mss_val_2_sng,fmt_sng,var2->mss_val.cp[0]); break;
      case NC_BYTE: (void)sprintf(mss_val_2_sng,fmt_sng,var2->mss_val.bp[0]); break;
      default: nco_dfl_case_nc_type_err(); break;
      } /* end switch */
      (void)fprintf(stderr,"%s: WARNING Input variables have different NCO_MSS_VAL_SNG's:\nFile 1 variable %s has NCO_MSS_VAL_SNG type = %s, value = %s\nFile 2 variable %s has NCO_MSS_VAL_SNG type = %s, value = %s\nFile 3 variable %s will have NCO_MSS_VAL_SNG type = %s, value = %s\nWill translate values of var2 equaling mss_val2 to mss_val1 before arithmetic operation\n",prg_nm_get(),var1->nm,nco_typ_sng(var1->type),mss_val_1_sng,var2->nm,nco_typ_sng(var2->type),mss_val_2_sng,var1->nm,nco_typ_sng(var1->type),mss_val_1_sng);
    } /* MSS_VAL_EQL */
    (void)cast_nctype_void(var_typ,&var1->mss_val);
    (void)cast_nctype_void(var_typ,&var2->mss_val);
    
    /* Missing values are already equal */
    if(MSS_VAL_EQL) return has_mss_val;
    
    /* If both files have missing_value's and they differ,
       must translate mss_val_2 in var2 to mss_val_1 before binary operation.
       Otherwise mss_val_2 would be treated as regular value in var_2
       Unfixable bug is when var1 has mss_val1 and var2 does not have a missing_value
       Then var2 values that happen to equal mss_val1 are treated as missing_values
       A generic, satisfactory solution to this problem does not exist 
       Picking missing_values that are nearly out-of-range is best workaround
       The user must be smart enough to do this, NCO cannot help */
    
    /* Typecast pointer to values before access */
    (void)cast_void_nctype(var_typ,&var1->mss_val);
    (void)cast_void_nctype(var_typ,&var2->mss_val);
    (void)cast_void_nctype(var_typ,&var2->val);
    
    /* Shortcuts to avoid indirection */
    var_val=var2->val;
    var_sz=var2->sz;
    switch(var_typ){
    case NC_FLOAT: {
      const float mss_val_1_flt=*var1->mss_val.fp;
      const float mss_val_2_flt=*var2->mss_val.fp; 
      for(idx=0L;idx<var_sz;idx++) if(var_val.fp[idx] == mss_val_2_flt) var_val.fp[idx]=mss_val_1_flt;
    } break;
    case NC_DOUBLE: {
      const double mss_val_1_dbl=*var1->mss_val.dp;
      const double mss_val_2_dbl=*var2->mss_val.dp; 
      for(idx=0L;idx<var_sz;idx++) if(var_val.dp[idx] == mss_val_2_dbl) var_val.dp[idx]=mss_val_1_dbl;
    } break;
    case NC_INT: {
      const nco_int mss_val_1_lng=*var1->mss_val.lp;
      const nco_int mss_val_2_lng=*var2->mss_val.lp; 
      for(idx=0L;idx<var_sz;idx++) if(var_val.lp[idx] == mss_val_2_lng) var_val.lp[idx]=mss_val_1_lng;
    } break;
    case NC_SHORT: {
      const short mss_val_1_sht=*var1->mss_val.sp;
      const short mss_val_2_sht=*var2->mss_val.sp; 
      for(idx=0L;idx<var_sz;idx++) if(var_val.sp[idx] == mss_val_2_sht) var_val.sp[idx]=mss_val_1_sht; 
    } break;
    case NC_CHAR: {
      const nco_char mss_val_1_chr=*var1->mss_val.cp;
      const nco_char mss_val_2_chr=*var2->mss_val.cp; 
      for(idx=0L;idx<var_sz;idx++) if(var_val.cp[idx] == mss_val_2_chr) var_val.cp[idx]=mss_val_1_chr; 
    } break;
    case NC_BYTE: {
      const nco_byte mss_val_1_byt=*var1->mss_val.bp;
      const nco_byte mss_val_2_byt=*var2->mss_val.bp; 
      for(idx=0L;idx<var_sz;idx++) if(var_val.bp[idx] == mss_val_2_byt) var_val.bp[idx]=mss_val_1_byt; 
    } break;
    default: nco_dfl_case_nc_type_err(); break;
    } /* end switch */

    /* Un-typecast the pointer to values after access */
    (void)cast_nctype_void(var_typ,&var2->val);
    (void)cast_nctype_void(var_typ,&var1->mss_val);
    (void)cast_nctype_void(var_typ,&var2->mss_val);
  
  } /* end if both variables have missing values */
  
  /* Handle cases where only one variable has missing value.
     First, if var2 has missing_value and var1 does not,
     then copy missing_value from var2 to var1 to ensure binary arithmetic 
     (which uses var1's missing_value) handles missing_value's correctly
     Assume var1 and var2 already have same type */
  if(!var1->has_mss_val && var2->has_mss_val) (void)nco_mss_val_cp(var2,var1);
  if(var1->has_mss_val && !var2->has_mss_val) (void)nco_mss_val_cp(var1,var2);
  
  return has_mss_val;
} /* end nco_mss_val_cnf() */

void
nco_mss_val_cp /* [fnc] Copy missing value from var1 to var2 */
(const var_sct * const var1, /* I [sct] Variable with template missing value to copy */
 var_sct * const var2) /* I/O [sct] Variable with missing value to fill in/overwrite */
{
  /* Threads: Routine is thread safe and calls no unsafe routines */
  /* Purpose: Copy missing value from var1 to var2
     On exit, var2 contains has_mss_val, and mss_val identical to var1
     Type of mss_val in var2 will agree with type of var2
     This maintains assumed consistency between type of variable and type of mss_val in all var_sct's */

  if(!var1->has_mss_val){
    var2->has_mss_val=False;
    if(var2->mss_val.vp != NULL) free(var2->mss_val.vp);
  }else{ /* endif no mss_val in var1 */
    var2->mss_val.vp=(void *)nco_realloc(var2->mss_val.vp,nco_typ_lng(var2->type));
    (void)nco_val_cnf_typ(var1->type,var1->mss_val,var2->type,var2->mss_val);
    var2->has_mss_val=True;
  } /* endif var1 has mss_val */

} /* end nco_mss_val_cp() */
  
int /* O [flg] Variable has missing value on output */
nco_mss_val_get /* [fnc] Update number of attributes, missing_value of variable */
(const int nc_id, /* I [id] netCDF input-file ID */
 var_sct * const var) /* I/O [sct] Variable with missing_value to update */
{
  /* Purpose: Update number of attributes and missing_value attribute of variable
     No matter what type missing_value is on disk, this routine ensures that 
     copy of mss_val in var_sct is stored as same type as host variable.
     Routine does not allow output missing_value to have more than one element */

  /* has_mss_val is typed as int not bool because it was sent to Fortran routines */

  static nco_bool WRN_FIRST=True; /* [flg] No warnings yet for _FillValue/missing_value problem */

  char att_nm[NC_MAX_NAME];
  
  long att_sz;
  int idx;
  
  nco_bool has_fll_val=False; /* [flg] Has _FillValue attribute */

  size_t att_lng;

  nc_type att_typ;

  ptr_unn mss_tmp;
  
  /* Refresh netCDF "mss_val" attribute for this variable */
  var->has_mss_val=False;
  var->mss_val.vp=nco_free(var->mss_val.vp);

  /* Refresh number of attributes for variable */
  (void)nco_inq_varnatts(nc_id,var->id,&var->nbr_att);

  for(idx=0;idx<var->nbr_att;idx++){
    (void)nco_inq_attname(nc_id,var->id,idx,att_nm);
    if(WRN_FIRST && !(int)strcasecmp(att_nm,"_FillValue")) has_fll_val=True;
    if((int)strcasecmp(att_nm,"missing_value")) continue;
    (void)nco_inq_att(nc_id,var->id,att_nm,&att_typ,&att_sz);
    if(att_sz != 1L && att_typ != NC_CHAR){
      (void)fprintf(stderr,"%s: WARNING the \"%s\" attribute for %s has %li elements and so will not be used\n",prg_nm_get(),att_nm,var->nm,att_sz);
      continue;
    } /* end if */
    /* if(att_typ != var->type) (void)fprintf(stderr,"%s: WARNING the \"%s\" attribute for %s will be typecast from %s to %s for arithmetic purposes\n",prg_nm_get(),att_nm,var->nm,nco_typ_sng(att_typ),nco_typ_sng(var->type)); */
    /* If we got this far then try to retrieve attribute and make sure it conforms to variable's type */
    var->has_mss_val=True;
    /* Oddly, ARM uses NC_CHAR for type of missing_value, so make allowances for this */
    att_lng=att_sz*nco_typ_lng(att_typ);
    mss_tmp.vp=(void *)nco_malloc(att_lng);
    (void)nco_get_att(nc_id,var->id,att_nm,mss_tmp.vp,att_typ);
    if(att_typ == NC_CHAR){
      /* NUL-terminate missing value string */
      if(mss_tmp.cp[att_lng-1] != '\0'){
	att_lng++;
	mss_tmp.vp=(void *)nco_realloc(mss_tmp.vp,att_lng);
	mss_tmp.cp[att_lng-1]='\0';
	/* Un-typecast pointer to values after access */
	(void)cast_nctype_void(att_typ,&mss_tmp);
      } /* end if */
    } /* end if */
    
    /* Ensure mss_val in memory is stored as same type as variable */
    var->mss_val.vp=(void *)nco_malloc(nco_typ_lng(var->type));
    (void)nco_val_cnf_typ(att_typ,mss_tmp,var->type,var->mss_val);

    /* Release temporary memory */
    mss_tmp.vp=nco_free(mss_tmp.vp);
    break;
  } /* end loop over att */

  /* Warn when _FillValue is and missing_value is not defined */
  if(has_fll_val && !var->has_mss_val && WRN_FIRST){
    if(dbg_lvl_get() > 0) (void)fprintf(stderr,"%s: WARNING Variable %s has attribute \"_FillValue\" but not \"missing_value\". To comply with netCDF conventions, NCO ignores values that equal the %s when performing arithmetic. Confusingly, values equal to the _FillValue should also be neglected. However, it is tedious and (possibly) computationally expensive to check each value against multiple missing values during arithmetic on large variables. So NCO thinks that processing variables with a \"_FillValue\" attribute and no \"%s\" attribute may produce undesired arithmetic results (i.e., where values that were intended to be neglected were not, in fact, neglected). We suggest you rename all \"_FillValue\" attributes to \"%s\" or include both \"_FillValue\" and \"%s\" attributes (with the _same values_) for all variables that have either attribute. Because it is long, this message is only printed once per operator even though multiple variables may have the same attribute configuration. More information on missing values is given at:\nhttp://nco.sf.net/nco.html#mss_val\nExamples of renaming attributes are at:\nhttp://nco.sf.net/nco.html#xmp_ncrename\nExamples of creating and deleting attributes are at:\nhttp://nco.sf.net/nco.html#xmp_ncatted\n",prg_nm_get(),var->nm,nco_mss_val_sng_get(),nco_mss_val_sng_get(),nco_mss_val_sng_get(),nco_mss_val_sng_get());
    WRN_FIRST=False;
  } /* endif _FillValue is and missing_value is not defined */

  return var->has_mss_val;

} /* end nco_mss_val_get() */

