// $Header: /data/zender/nco_20150216/nco/src/nco_c++/libnco_c++.hh,v 1.1 2002-01-11 23:20:29 zender Exp $ 

/* Purpose: Prototypes, typedefs, and global variables for libnco_c++
   libnco_c++.hh headers depend only on system headers
   Thus libnco_c++.a may be built independently of any other libraries
   However, the user must supply prg_nm_get() and dbg_lvl_get() to link to */

// Usage:
// #include <libnco_c++.hh> // C++ interface to netCDF C library

#ifndef LIBNCO_CCC_HH // Contents have not yet been inserted in current source file  
#define LIBNCO_CCC_HH

// Personal headers
#include <nco_att.hh> // C++ interface to netCDF attribute routines
#include <nco_dmn.hh> // C++ interface to netCDF dimension routines
#include <nco_fl.hh> // C++ interface to netCDF file-level routines
#include <nco_hgh.hh> // High-level NCO utilities
#include <nco_utl.hh> // C++ interface utilities for netCDF routines
#include <nco_var.hh> // C++ interface to netCDF variable routines

#endif // LIBNCO_CCC_HH  
