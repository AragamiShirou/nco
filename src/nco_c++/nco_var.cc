// $Header: /data/zender/nco_20150216/nco/src/nco_c++/nco_var.cc,v 1.22 2007-02-23 21:59:32 zender Exp $ 

// Purpose: Implementation (declaration) of C++ interface to netCDF variable routines

/* Copyright (C) 2001--2005 Charlie Zender
   You may copy, distribute, and/or modify this software under the terms of the GNU General Public License (GPL) Version 2
   See http://www.gnu.org/copyleft/gpl.html for full license text */

#include <nco_var.hh> // C++ interface to netCDF variable routines

// netCDF classes

// Friendly functions begin

// Friendly functions end
// Static members begin

// Static members end
// Static member functions begin

// Static member functions end
// Public member functions begin

// Public member functions end
// Private member functions begin

// Private member functions end
// Global functions with C++ linkages begin

// Begin nco_def_var() overloads

int // O [enm] Return success code
nco_def_var // [fnc] Create variable in netCDF file
(const int &nc_id, // I [enm] netCDF file ID
 const std::string &var_nm, // I [sng] Variable name
 const nc_type &var_xtype, // I [enm] External type of variable
 const int &dmn_nbr, // I [nbr] Number of dimensions
 const int * const &dmn_id, // I [id] Dimension IDs
 int &var_id) // O [id] Variable ID
{
  // Purpose: Wrapper for nc_def_var()
  int rcd=nc_def_var(nc_id,var_nm.c_str(),var_xtype,dmn_nbr,dmn_id,&var_id);
  if(rcd != NC_NOERR) nco_err_exit(rcd,"nco_def_var");
  return rcd;
} // end nco_def_var<int *>()

int // O [enm] Return success code
nco_def_var // [fnc] Create variable in netCDF file
(const int &nc_id, // I [enm] netCDF file ID
 const std::string &var_nm, // I [sng] Variable name
 const nc_type &var_xtype, // I [enm] External type of variable
 const std::valarray<int> &dmn_id, // I [id] Dimension IDs
 int &var_id) // O [id] Variable ID
{
  // Purpose: Wrapper for nco_def_var()
  /* fxm: It would be nice if dmn_id could be passed as const, but I cannot
     figure out how to do this and pass a const int * to nc_def_var */
  //  int rcd=nco_def_var(nc_id,var_nm,var_xtype,dmn_id.size(),&dmn_id[0],var_id);
  int rcd=nco_def_var(nc_id,var_nm,var_xtype,static_cast<int>(dmn_id.size()),&(const_cast<std::valarray<int> &>(dmn_id)[0]),var_id);
  if(rcd != NC_NOERR) nco_err_exit(rcd,"nco_def_var");
  return rcd;
} // end nco_def_var<std::valarray<int>>()

// End nco_def_var() overloads
// Begin nco_inq_var() overloads

int // O [enm] Return success code
nco_inq_var // [fnc] Inquire variable
(const int &nc_id, // I [enm] netCDF file ID
 const int &var_id, // I [id] Variable ID
 std::string &var_nm, // O [sng] Variable name
 nc_type &var_typ, // O [enm] Variable type
 int &dmn_nbr, // O [nbr] Number of dimensions
 int *&dmn_id, // O [id] Dimension IDs
 int &att_nbr, // O [nbr] Number of attributes
 const int &rcd_opt) // I [enm] Optional non-fatal return code 
{
  /* Purpose: Wrapper for nc_inq_var()
     User may omit rcd_opt, or supply value of non-fatal netCDF return code */
  char var_nm_chr[NC_MAX_NAME];
  int rcd=nc_inq_var(nc_id,var_id,var_nm_chr,&var_typ,&dmn_nbr,dmn_id,&att_nbr);
  var_nm=var_nm_chr;
  if(rcd != NC_NOERR && rcd != rcd_opt) nco_err_exit(rcd,"nco_inq_varid","Unable to inquire all metadata for given variable ID, exiting...");
  return rcd;
} // end nco_inq_var() 

// Begin nco_inq_varid() overloads

int // O [enm] Return success code
nco_inq_varid // [fnc] Inquire variable ID
(const int &nc_id, // I [enm] netCDF file ID
 const std::string &var_nm, // I [sng] Variable name
 int &var_id, // O [id] Variable ID
 const int &rcd_opt) // I [enm] Optional non-fatal return code 
{
  /* Purpose: Wrapper for nc_inq_varid()
     User may omit rcd_opt, or supply value of non-fatal netCDF return code */
  int rcd=nc_inq_varid(nc_id,var_nm.c_str(),&var_id);
  if(rcd != NC_NOERR && rcd != rcd_opt) nco_err_exit(rcd,"nco_inq_varid","Unable to find ID for variable \""+var_nm+"\", exiting...");
  return rcd;
} // end nco_inq_varid() 

int // O [id] Variable ID
nco_inq_varid // [fnc] Inquire variable ID
(const int &nc_id, // I [enm] netCDF file ID
 const std::string &var_nm) // I [sng] Variable name
{
  // Purpose: Wrapper for nco_inq_varid()
  int var_id; // O [id] Variable ID
  int rcd=nco_inq_varid(nc_id,var_nm,var_id);
  rcd+=0; // CEWI
  return var_id;
} // end nco_inq_varid() 

// End nco_inq_varid() overloads
// Begin nco_inq_varname() overloads

int // O [enm] Return success code
nco_inq_varname // [fnc] Inquire variable name
(const int &nc_id, // I [enm] netCDF file ID
 const int &var_id, // I [id] Variable ID
 std::string &var_nm, // O [sng] Variable name
 const int &rcd_opt) // I [enm] Optional non-fatal return code 
{
  /* Purpose: Wrapper for nc_inq_varname()
     User may omit rcd_opt, or supply value of non-fatal netCDF return code */
  char var_nm_chr[NC_MAX_NAME];
  int rcd=nc_inq_varname(nc_id,var_id,var_nm_chr);
  var_nm=var_nm_chr;
  if(rcd != NC_NOERR && rcd != rcd_opt) nco_err_exit(rcd,"nco_inq_varname","Unable to find name for given variable ID, exiting...");
  return rcd;
} // end nco_inq_varname() 

std::string // O [sng] Variable name
nco_inq_varname // [fnc] Inquire variable name
(const int &nc_id, // I [enm] netCDF file ID
 const int &var_id) // I [id] Variable ID
{
  // Purpose: Wrapper for nco_inq_varname()
  std::string var_nm; // O [id] Variable name
  int rcd=nco_inq_varname(nc_id,var_id,var_nm);
  rcd+=0; // CEWI
  return var_nm;
} // end nco_inq_varname() 

// End nco_inq_varname() overloads
// Begin nco_inq_vartype() overloads

int // O [enm] Return success code
nco_inq_vartype // [fnc] Inquire variable type
(const int &nc_id, // I [enm] netCDF file ID
 const int &var_id, // I [id] Variable ID
 nc_type &var_typ, // O [enm] Variable type
 const int &rcd_opt) // I [enm] Optional non-fatal return code 
{
  /* Purpose: Wrapper for nc_inq_vartype()
     User may omit rcd_opt, or supply value of non-fatal netCDF return code */
  int rcd=nc_inq_vartype(nc_id,var_id,&var_typ);
  if(rcd != NC_NOERR && rcd != rcd_opt) nco_err_exit(rcd,"nco_inq_vartype","Unable to find type of given variable ID, exiting...");
  return rcd;
} // end nco_inq_vartype() 

nc_type // O [enm] Variable type
nco_inq_vartype // [fnc] Inquire variable type
(const int &nc_id, // I [enm] netCDF file ID
 const int &var_id) // I [id] Variable ID
{
  // Purpose: Wrapper for nco_inq_vartype()
  nc_type var_typ; // O [enm] Variable type
  int rcd=nco_inq_vartype(nc_id,var_id,var_typ);
  rcd+=0; // CEWI
  return var_typ;
} // end nco_inq_vartype() 

nc_type // O [enm] Variable type
nco_inq_vartype // [fnc] Inquire variable type
(const int &nc_id, // I [enm] netCDF file ID
 const std::string &var_nm) // I [sng] Variable name
{
  // Purpose: Wrapper for nco_inq_vartype()
  nc_type var_typ; // O [enm] Variable type
  int rcd=nco_inq_vartype(nc_id,nco_inq_varid(nc_id,var_nm),var_typ);
  rcd+=0; // CEWI
  return var_typ;
} // end nco_inq_vartype() 

// End nco_inq_vartype() overloads
// Begin nco_inq_varndims() overloads

int // O [enm] Return success code
nco_inq_varndims // [fnc] Inquire variable rank
(const int &nc_id, // I [enm] netCDF file ID
 const int &var_id, // I [id] Variable ID
 int &dmn_nbr, // O [nbr] Number of dimensions
 const int &rcd_opt) // I [enm] Optional non-fatal return code 
{
  /* Purpose: Wrapper for nc_inq_varndims()
     User may omit rcd_opt, or supply value of non-fatal netCDF return code */
  int rcd=nc_inq_varndims(nc_id,var_id,&dmn_nbr);
  if(rcd != NC_NOERR && rcd != rcd_opt) nco_err_exit(rcd,"nco_inq_varndims","Unable to find number of dimensions in given variable ID, exiting...");
  return rcd;
} // end nco_inq_varndims() 

int // O [enm] Return success code
nco_inq_varndims // [fnc] Inquire variable rank
(const int &nc_id, // I [enm] netCDF file ID
 const std::string &var_nm, // I [sng] Variable name
 int &dmn_nbr, // O [nbr] Number of dimensions
 const int &rcd_opt) // I [enm] Optional non-fatal return code 
{
  /* Purpose: Wrapper for nc_inq_varndims()
     User may omit rcd_opt, or supply value of non-fatal netCDF return code */
  int var_id; // O [id] Variable ID
  int rcd=nco_inq_varid(nc_id,var_nm,var_id,rcd_opt);
  if(rcd != NC_NOERR) rcd=nco_inq_varndims(nc_id,var_id,dmn_nbr,rcd_opt);
  return rcd;
} // end nco_inq_varndims() 

int // O [nbr] Number of dimensions
nco_inq_varndims // [fnc] Inquire variable rank
(const int &nc_id, // I [enm] netCDF file ID
 const int &var_id) // I [id] Variable ID
{
  // Purpose: Wrapper for nco_inq_varndims()
  int dmn_nbr; // O [nbr] Number of dimensions
  int rcd=nco_inq_varndims(nc_id,var_id,dmn_nbr);
  rcd+=0; // CEWI
  return dmn_nbr;
} // end nco_inq_varndims() 

int // O [nbr] Number of dimensions
nco_inq_varndims // [fnc] Inquire variable rank
(const int &nc_id, // I [enm] netCDF file ID
 const std::string &var_nm) // I [sng] Variable name
{
  // Purpose: Wrapper for nco_inq_varndims()
  int dmn_nbr; // O [nbr] Number of dimensions
  int rcd=nco_inq_varndims(nc_id,nco_inq_varid(nc_id,var_nm),dmn_nbr);
  rcd+=0; // CEWI
  return dmn_nbr;
} // end nco_inq_varndims() 

// End nco_inq_varndims() overloads
// Begin nco_inq_varnatts() overloads

int // O [enm] Return success code
nco_inq_varnatts // [fnc] Inquire variable attributes
(const int &nc_id, // I [enm] netCDF file ID
 const int &var_id, // I [id] Variable ID
 int &att_nbr, // O [nbr] Number of attributes
 const int &rcd_opt) // I [enm] Optional non-fatal return code 
{
  /* Purpose: Wrapper for nc_inq_varnatts()
     User may omit rcd_opt, or supply value of non-fatal netCDF return code */
  int rcd=nc_inq_varnatts(nc_id,var_id,&att_nbr);
  if(rcd != NC_NOERR && rcd != rcd_opt) nco_err_exit(rcd,"nco_inq_varnatts","Unable to find number of attributes given variable ID, exiting...");
  return rcd;
} // end nco_inq_varnatts() 

int // O [nbr] Number of attributes
nco_inq_varnatts // [fnc] Inquire variable attributes
(const int &nc_id, // I [enm] netCDF file ID
 const int &var_id) // I [id] Variable ID
{
  // Purpose: Wrapper for nco_inq_varnatts()
  int att_nbr; // O [nbr] Number of attributes
  int rcd=nco_inq_varnatts(nc_id,var_id,att_nbr);
  rcd+=0; // CEWI
  return att_nbr;
} // end nco_inq_varnatts() 

int // O [nbr] Number of attributes
nco_inq_varnatts // [fnc] Inquire variable attributes
(const int &nc_id, // I [enm] netCDF file ID
 const std::string &var_nm) // I [sng] Variable name
{
  // Purpose: Wrapper for nco_inq_varnatts()
  int att_nbr; // O [nbr] Number of attributes
  int rcd=nco_inq_varnatts(nc_id,nco_inq_varid(nc_id,var_nm),att_nbr);
  rcd+=0; // CEWI
  return att_nbr;
} // end nco_inq_varnatts() 

// End nco_inq_varnatts() overloads

int // O [enm] Return success code
nco_inq_vardimid // [fnc] Inquire variable dimension IDS
(const int &nc_id, // I [enm] netCDF file ID
 const int &var_id, // I [id] Variable ID
 int *&dmn_id, // O [id] Dimension IDs
 const int &rcd_opt) // I [enm] Optional non-fatal return code 
{
  /* Purpose: Wrapper for nc_inq_vardimid()
     User may omit rcd_opt, or supply value of non-fatal netCDF return code */
  int rcd=nc_inq_vardimid(nc_id,var_id,dmn_id);
  if(rcd != NC_NOERR && rcd != rcd_opt) nco_err_exit(rcd,"nco_inq_vardimid");
  return rcd;
} // end nco_inq_vardimid() 

// End nco_inq_var() overloads
// Begin nco_put_vara() overloads

// Overload 1:  Write array given ID, start, count vectors
int // O [enm] Return success code
nco_put_vara // [fnc] Write variable to netCDF file
(const int &nc_id, // I [enm] netCDF file ID
 const int &var_id, // I [id] Variable ID
 const std::valarray<size_t> &var_srt, // I [idx] Start vector
 const std::valarray<size_t> &var_cnt, // I [nbr] Count vector
 const float * const &var_val) // I [frc] Variable value
{
  // Purpose: Wrapper for nc_put_vara_float()
  int rcd=nc_put_vara_float(nc_id,var_id,&(const_cast<std::valarray<size_t> &>(var_srt)[0]),&(const_cast<std::valarray<size_t> &>(var_cnt)[0]),var_val);
  if(rcd != NC_NOERR) nco_err_exit(rcd,"nco_put_vara<valarray,valarray,float *> failed with variable "+nco_inq_varname(nc_id,var_id));
  return rcd;
} // end nco_put_vara<valarray,valarray,float *>()

int // O [enm] Return success code
nco_put_vara // [fnc] Write variable to netCDF file
(const int &nc_id, // I [enm] netCDF file ID
 const int &var_id, // I [id] Variable ID
 const size_t * const &var_srt, // I [idx] Start vector
 const size_t * const &var_cnt, // I [nbr] Count vector
 const float * const &var_val) // I [frc] Variable value
{
  // Purpose: Wrapper for nc_put_vara_float()
  int rcd=nc_put_vara_float(nc_id,var_id,var_srt,var_cnt,var_val);
  if(rcd != NC_NOERR) nco_err_exit(rcd,"nco_put_vara<size_t *,size_t *,float *> failed with variable "+nco_inq_varname(nc_id,var_id));
  return rcd;
} // end nco_put_vara<size_t *,size_t *,float *>()

int // O [enm] Return success code
nco_put_vara // [fnc] Write variable to netCDF file
(const int &nc_id, // I [enm] netCDF file ID
 const int &var_id, // I [id] Variable ID
 const size_t * const &var_srt, // I [idx] Start vector
 const size_t * const &var_cnt, // I [nbr] Count vector
 const double * const &var_val) // I [frc] Variable value
{
  // Purpose: Wrapper for nc_put_vara_double()
  int rcd=nc_put_vara_double(nc_id,var_id,var_srt,var_cnt,var_val);
  if(rcd != NC_NOERR) nco_err_exit(rcd,"nco_put_vara<size_t *,size_t *,double *> failed with variable "+nco_inq_varname(nc_id,var_id));
  return rcd;
} // end nco_put_vara<size_t *,size_t *,double *>()

int // O [enm] Return success code
nco_put_vara // [fnc] Write variable to netCDF file
(const int &nc_id, // I [enm] netCDF file ID
 const int &var_id, // I [id] Variable ID
 const size_t * const &var_srt, // I [idx] Start vector
 const size_t * const &var_cnt, // I [nbr] Count vector
 const long double * const &var_val) // I [frc] Variable value
{
  // Purpose: Wrapper for nc_put_vara_double()
  const size_t var_sz(nco_inq_varsz(nc_id,var_id)); // [nbr] Number of elements
  double *var_val_dbl=new double[var_sz]; // [frc] Double precision values
  for(size_t lmn_idx=0;lmn_idx<var_sz;lmn_idx++){
    var_val_dbl[lmn_idx]=var_val[lmn_idx];
  } // end loop over idx
  int rcd=nc_put_vara_double(nc_id,var_id,var_srt,var_cnt,var_val_dbl);
  if(rcd != NC_NOERR) nco_err_exit(rcd,"nco_put_vara<size_t *,size_t *,long double *> failed with variable "+nco_inq_varname(nc_id,var_id));
  delete []var_val_dbl;
  return rcd;
} // end nco_put_vara<size_t *,size_t *,long double *>()

int // O [enm] Return success code
nco_put_vara // [fnc] Write variable to netCDF file
(const int &nc_id, // I [enm] netCDF file ID
 const int &var_id, // I [id] Variable ID
 const size_t * const &var_srt, // I [idx] Start vector
 const size_t * const &var_cnt, // I [nbr] Count vector
 const int * const &var_val) // I [frc] Variable value
{
  // Purpose: Wrapper for nc_put_vara_int()
  int rcd=nc_put_vara_int(nc_id,var_id,var_srt,var_cnt,var_val);
  if(rcd != NC_NOERR) nco_err_exit(rcd,"nco_put_vara<size_t *,size_t *,int *> failed with variable "+nco_inq_varname(nc_id,var_id));
  return rcd;
} // end nco_put_vara<size_t *,size_t *,int *>()

int // O [enm] Return success code
nco_put_vara // [fnc] Write variable to netCDF file
(const int &nc_id, // I [enm] netCDF file ID
 const int &var_id, // I [id] Variable ID
 const size_t * const &var_srt, // I [idx] Start vector
 const size_t * const &var_cnt, // I [nbr] Count vector
 const long * const &var_val) // I [frc] Variable value
{
  // Purpose: Wrapper for nc_put_vara_long()
  int rcd=nc_put_vara_long(nc_id,var_id,var_srt,var_cnt,var_val);
  if(rcd != NC_NOERR) nco_err_exit(rcd,"nco_put_vara<size_t *,size_t *,long *> failed with variable "+nco_inq_varname(nc_id,var_id));
  return rcd;
} // end nco_put_vara<size_t *,size_t *,long *>()

int // O [enm] Return success code
nco_put_vara // [fnc] Write variable to netCDF file
(const int &nc_id, // I [enm] netCDF file ID
 const int &var_id, // I [id] Variable ID
 const size_t * const &var_srt, // I [idx] Start vector
 const size_t * const &var_cnt, // I [nbr] Count vector
 const short * const &var_val) // I [frc] Variable value
{
  // Purpose: Wrapper for nc_put_vara_short()
  int rcd=nc_put_vara_short(nc_id,var_id,var_srt,var_cnt,var_val);
  if(rcd != NC_NOERR) nco_err_exit(rcd,"nco_put_vara<size_t *,size_t *,short *> failed with variable "+nco_inq_varname(nc_id,var_id));
  return rcd;
} // end nco_put_vara<size_t *,size_t *,short *>()

// End nco_put_vara() overloads
// Begin nco_put_var() overloads

// Overload 1:  Write array given ID
int // O [enm] Return success code
nco_put_var // [fnc] Write variable to netCDF file
(const int &nc_id, // I [enm] netCDF file ID
 const int &var_id, // I [id] Variable ID
 const float * const &var_val) // I [frc] Variable value
{
  // Purpose: Wrapper for nc_put_var_float()
  int rcd=nc_put_var_float(nc_id,var_id,var_val);
  if(rcd != NC_NOERR) nco_err_exit(rcd,"nco_put_var<float *> failed with variable "+nco_inq_varname(nc_id,var_id));
  return rcd;
} // end nco_put_var<float *>()

int // O [enm] Return success code
nco_put_var // [fnc] Write variable to netCDF file
(const int &nc_id, // I [enm] netCDF file ID
 const int &var_id, // I [id] Variable ID
 const double * const &var_val) // I [frc] Variable value
{
  // Purpose: Wrapper for nc_put_var_double()
  int rcd=nc_put_var_double(nc_id,var_id,var_val);
  if(rcd != NC_NOERR) nco_err_exit(rcd,"nco_put_var<double *> failed with variable "+nco_inq_varname(nc_id,var_id));
  return rcd;
} // end nco_put_var<double *>()

int // O [enm] Return success code
nco_put_var // [fnc] Write variable to netCDF file
(const int &nc_id, // I [enm] netCDF file ID
 const int &var_id, // I [id] Variable ID
 const long double * const &var_val) // I [frc] Variable value
{
  // Purpose: Wrapper for nc_put_var_double()
  const size_t var_sz(nco_inq_varsz(nc_id,var_id)); // [nbr] Number of elements
  double *var_val_dbl=new double[var_sz]; // [frc] Double precision values
  for(size_t lmn_idx=0;lmn_idx<var_sz;lmn_idx++){
    var_val_dbl[lmn_idx]=var_val[lmn_idx];
  } // end loop over idx
  int rcd=nc_put_var_double(nc_id,var_id,var_val_dbl);
  if(rcd != NC_NOERR) nco_err_exit(rcd,"nco_put_var<long double *> failed with variable "+nco_inq_varname(nc_id,var_id));
  delete []var_val_dbl;
  return rcd;
} // end nco_put_var<long double *>()

int // O [enm] Return success code
nco_put_var // [fnc] Write variable to netCDF file
(const int &nc_id, // I [enm] netCDF file ID
 const int &var_id, // I [id] Variable ID
 const int * const &var_val) // I [frc] Variable value
{
  // Purpose: Wrapper for nc_put_var_int()
  int rcd=nc_put_var_int(nc_id,var_id,var_val);
  if(rcd != NC_NOERR) nco_err_exit(rcd,"nco_put_var<int *> failed with variable "+nco_inq_varname(nc_id,var_id));
  return rcd;
} // end nco_put_var<int *>()

int // O [enm] Return success code
nco_put_var // [fnc] Write variable to netCDF file
(const int &nc_id, // I [enm] netCDF file ID
 const int &var_id, // I [id] Variable ID
 const long * const &var_val) // I [frc] Variable value
{
  // Purpose: Wrapper for nc_put_var_long()
  int rcd=nc_put_var_long(nc_id,var_id,var_val);
  if(rcd != NC_NOERR) nco_err_exit(rcd,"nco_put_var<long *> failed with variable "+nco_inq_varname(nc_id,var_id));
  return rcd;
} // end nco_put_var<long *>()

int // O [enm] Return success code
nco_put_var // [fnc] Write variable to netCDF file
(const int &nc_id, // I [enm] netCDF file ID
 const int &var_id, // I [id] Variable ID
 const short * const &var_val) // I [frc] Variable value
{
  // Purpose: Wrapper for nc_put_var_short()
  int rcd=nc_put_var_short(nc_id,var_id,var_val);
  if(rcd != NC_NOERR) nco_err_exit(rcd,"nco_put_var<short *> failed with variable "+nco_inq_varname(nc_id,var_id));
  return rcd;
} // end nco_put_var<short *>()

// Overload 3: Write scalar given ID
int // O [enm] Return success code
nco_put_var // [fnc] Write variable to netCDF file
(const int &nc_id, // I [enm] netCDF file ID
 const int &var_id, // I [id] Variable ID
 const float &var_val) // I [frc] Variable value
{
  // Purpose: Wrapper for nc_put_var1_float()
  // fxm: Decide which method is best, this one or the one used for longs */
  std::valarray<size_t> srt(static_cast<size_t>(0U),static_cast<size_t>(nco_inq_varndims(nc_id,var_id)));
  int rcd=nc_put_var1_float(nc_id,var_id,&srt[0],&(const_cast<float &>(var_val)));
  if(rcd != NC_NOERR) nco_err_exit(rcd,"nco_put_var<float> failed with variable "+nco_inq_varname(nc_id,var_id));
  return rcd;
} // end nco_put_var<float>()

int // O [enm] Return success code
nco_put_var // [fnc] Write variable to netCDF file
(const int &nc_id, // I [enm] netCDF file ID
 const int &var_id, // I [id] Variable ID
 const double &var_val) // I [frc] Variable value
{
  // Purpose: Wrapper for nc_put_var1_double()
  std::valarray<size_t> srt(static_cast<size_t>(0U),static_cast<size_t>(nco_inq_varndims(nc_id,var_id)));
  int rcd=nc_put_var1_double(nc_id,var_id,&srt[0],&(const_cast<double &>(var_val)));
  if(rcd != NC_NOERR) nco_err_exit(rcd,"nco_put_var<double> failed with variable "+nco_inq_varname(nc_id,var_id));
  return rcd;
} // end nco_put_var<double>()

int // O [enm] Return success code
nco_put_var // [fnc] Write variable to netCDF file
(const int &nc_id, // I [enm] netCDF file ID
 const int &var_id, // I [id] Variable ID
 const long double &var_val) // I [frc] Variable value
{
  // Purpose: Wrapper for nc_put_var1_double()
  const double var_val_dbl(var_val); // [frc] Double precision value
  std::valarray<size_t> srt(static_cast<size_t>(0U),static_cast<size_t>(nco_inq_varndims(nc_id,var_id)));
  int rcd=nc_put_var1_double(nc_id,var_id,&srt[0],&(const_cast<double &>(var_val_dbl)));
  if(rcd != NC_NOERR) nco_err_exit(rcd,"nco_put_var<long double> failed with variable "+nco_inq_varname(nc_id,var_id));
  return rcd;
} // end nco_put_var<long double>()

int // O [enm] Return success code
nco_put_var // [fnc] Write variable to netCDF file
(const int &nc_id, // I [enm] netCDF file ID
 const int &var_id, // I [id] Variable ID
 const int &var_val) // I [frc] Variable value
{
  // Purpose: Wrapper for nc_put_var1_int()
  std::valarray<size_t> srt(static_cast<size_t>(0U),static_cast<size_t>(nco_inq_varndims(nc_id,var_id)));
  int rcd=nc_put_var1_int(nc_id,var_id,&srt[0],&(const_cast<int &>(var_val)));
  if(rcd != NC_NOERR) nco_err_exit(rcd,"nco_put_var<int> failed with variable "+nco_inq_varname(nc_id,var_id));
  return rcd;
} // end nco_put_var<int>()

int // O [enm] Return success code
nco_put_var // [fnc] Write variable to netCDF file
(const int &nc_id, // I [enm] netCDF file ID
 const int &var_id, // I [id] Variable ID
 const long &var_val) // I [frc] Variable value
{
  /* Purpose: Wrapper for nc_put_var1_long()
     srt values are not used for scalars, but referencing srt[0] may be unsafe,
     or at least flagged as potential errors by some compilers, 
     so create valarrays of at least size 1
     fxm: Decide which method is best, this one or the one used for floats */
  const int dmn_nbr(nco_inq_varndims(nc_id,var_id));
  int rcd; // O [enm] Return success code
  if(dmn_nbr == 0){
    size_t srt_dmn_0=0; // Faster than initializing a valarray
    const size_t *srt_dmn_0_ptr(&srt_dmn_0);
    rcd=nc_put_var1_long(nc_id,var_id,srt_dmn_0_ptr,&(const_cast<long &>(var_val)));
  }else{
    // Default starting index is 0
    std::valarray<size_t> srt(static_cast<size_t>(0U),static_cast<size_t>(dmn_nbr));
    rcd=nc_put_var1_long(nc_id,var_id,&srt[0],&(const_cast<long &>(var_val)));
  } // endelse
  if(rcd != NC_NOERR) nco_err_exit(rcd,"nco_put_var<long> failed with variable "+nco_inq_varname(nc_id,var_id));
  return rcd;
} // end nco_put_var<long>()

int // O [enm] Return success code
nco_put_var // [fnc] Write variable to netCDF file
(const int &nc_id, // I [enm] netCDF file ID
 const int &var_id, // I [id] Variable ID
 const short &var_val) // I [frc] Variable value
{
  // Purpose: Wrapper for nc_put_var1_short()
  std::valarray<size_t> srt(static_cast<size_t>(0U),static_cast<size_t>(nco_inq_varndims(nc_id,var_id)));
  int rcd=nc_put_var1_short(nc_id,var_id,&srt[0],&(const_cast<short &>(var_val)));
  if(rcd != NC_NOERR) nco_err_exit(rcd,"nco_put_var<short> failed with variable "+nco_inq_varname(nc_id,var_id));
  return rcd;
} // end nco_put_var<short>()

// End nco_put_var() overloads
// Begin nco_get_var() overloads

// Overload 1: Get array given ID
int // O [enm] Return success code
nco_get_var // [fnc] Ingest variable from netCDF file
(const int &nc_id, // I [enm] netCDF file ID
 const int &var_id, // I [id] Variable ID
 float *&var_val) // O [frc] Variable value
{
  // Purpose: Wrapper for nc_get_var()
  size_t var_sz; // [nbr] Variable size
  int rcd=nco_inq_varsz(nc_id,var_id,var_sz);
  // Allocate space for variable: User is responsible for freeing space
  var_val=new float[var_sz]; // [frc] Variable value
  rcd=nc_get_var_float(nc_id,var_id,var_val);
  if(rcd != NC_NOERR) nco_err_exit(rcd,"nco_get_var<float> failed with variable "+nco_inq_varname(nc_id,var_id));
  return rcd;
} // end nco_get_var<float>()

int // O [enm] Return success code
nco_get_var // [fnc] Ingest variable from netCDF file
(const int &nc_id, // I [enm] netCDF file ID
 const int &var_id, // I [id] Variable ID
 double *&var_val) // O [frc] Variable value
{
  // Purpose: Wrapper for nc_get_var()
  size_t var_sz; // [nbr] Variable size
  int rcd=nco_inq_varsz(nc_id,var_id,var_sz);
  // Allocate space for variable: User is responsible for freeing space
  var_val=new double[var_sz]; // [frc] Variable value
  rcd=nc_get_var_double(nc_id,var_id,var_val);
  if(rcd != NC_NOERR) nco_err_exit(rcd,"nco_get_var<double> failed with variable "+nco_inq_varname(nc_id,var_id));
  return rcd;
} // end nco_get_var<double>()

int // O [enm] Return success code
nco_get_var // [fnc] Ingest variable from netCDF file
(const int &nc_id, // I [enm] netCDF file ID
 const int &var_id, // I [id] Variable ID
 long double *&var_val) // O [frc] Variable value
{
  // Purpose: Wrapper for nc_get_var()
  size_t var_sz; // [nbr] Variable size
  int rcd=nco_inq_varsz(nc_id,var_id,var_sz);
  // Allocate space for variable: User is responsible for freeing space
  var_val=new long double[var_sz]; // [frc] Variable value
  double *var_val_dbl=new double[var_sz]; // [frc] Double precision values
  rcd=nc_get_var_double(nc_id,var_id,var_val_dbl);
  if(rcd != NC_NOERR) nco_err_exit(rcd,"nco_get_var<long double> failed with variable "+nco_inq_varname(nc_id,var_id));
  for(size_t lmn_idx=0;lmn_idx<var_sz;lmn_idx++){
    var_val[lmn_idx]=var_val_dbl[lmn_idx];
  } // end loop over idx
  delete []var_val_dbl;
  return rcd;
} // end nco_get_var<long double>()

int // O [enm] Return success code
nco_get_var // [fnc] Ingest variable from netCDF file
(const int &nc_id, // I [enm] netCDF file ID
 const int &var_id, // I [id] Variable ID
 int *&var_val) // O [frc] Variable value
{
  // Purpose: Wrapper for nc_get_var()
  size_t var_sz; // [nbr] Variable size
  int rcd=nco_inq_varsz(nc_id,var_id,var_sz);
  // Allocate space for variable: User is responsible for freeing space
  var_val=new int[var_sz]; // [frc] Variable value
  rcd=nc_get_var_int(nc_id,var_id,var_val);
  if(rcd != NC_NOERR) nco_err_exit(rcd,"nco_get_var<int> failed with variable "+nco_inq_varname(nc_id,var_id));
  return rcd;
} // end nco_get_var<int>()

int // O [enm] Return success code
nco_get_var // [fnc] Ingest variable from netCDF file
(const int &nc_id, // I [enm] netCDF file ID
 const int &var_id, // I [id] Variable ID
 long *&var_val) // O [frc] Variable value
{
  // Purpose: Wrapper for nc_get_var()
  size_t var_sz; // [nbr] Variable size
  int rcd=nco_inq_varsz(nc_id,var_id,var_sz);
  // Allocate space for variable: User is responsible for freeing space
  var_val=new long[var_sz]; // [frc] Variable value
  rcd=nc_get_var_long(nc_id,var_id,var_val);
  if(rcd != NC_NOERR) nco_err_exit(rcd,"nco_get_var<long> failed with variable "+nco_inq_varname(nc_id,var_id));
  return rcd;
} // end nco_get_var<long>()

// Overload 1.5: Get array given ID
float * // O [frc] Variable value
nco_get_var // [fnc] Ingest variable from netCDF file
(const int &nc_id, // I [enm] netCDF file ID
 const int &var_id) // I [id] Variable ID
{
  // Purpose: Wrapper for nco_get_var()
  float *var_val; // [frc] Variable value
  int rcd=nco_get_var(nc_id,var_id,var_val);
  rcd+=0; // CEWI
  return var_val;
} // end nco_get_var<float>()

// Overload 2.5: Get array given name
float * // O [frc] Variable value
nco_get_var // [fnc] Ingest variable from netCDF file
(const int &nc_id, // I [enm] netCDF file ID
 const std::string &var_nm) // I [sng] Variable name
{
  // Purpose: Wrapper for nco_get_var()
  float *var_val; // [frc] Variable value
  int rcd=nco_get_var(nc_id,nco_inq_varid(nc_id,var_nm),var_val);
  rcd+=0; // CEWI
  return var_val;
} // end nco_get_var<float>()

// Overload 3: Get scalar given ID

// End nco_get_var() overloads

// Global functions with C++ linkages end
