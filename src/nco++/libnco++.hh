// $Header: /data/zender/nco_20150216/nco/src/nco++/libnco++.hh,v 1.9 2008-01-06 13:09:57 zender Exp $ 

// Purpose: Prototypes, typedefs, and global variables for libnco++

/* Copyright (C) 2006--2008 Charlie Zender
   You may copy, distribute, and/or modify this software under the terms of the GNU General Public License (GPL) Version 2
   See http://www.gnu.org/copyleft/gpl.html for full license text */

/* libnco++.hh headers depend on system headers and libnco.a headers
   Thus libnco++.a requires libnco.a to function correctly
   User must also supply prg_nm_get() and dbg_lvl_get() */

// Usage:
// #include <libnco++.hh> // C++ interface to netCDF C library

#ifndef LIBNCOXX_HH // Contents have not yet been inserted in current source file  
#define LIBNCOXX_HH

// Personal headers
#include "ncap2_utl.hh"
#include "fmc_cls.hh"
#include "prs_cls.hh"

//#include "ncoLexer.hpp" // 
//#include "ncoParser.hpp" //
//#include "ncoTree.hpp" // 
//#include "NcapVarVector.hh" // 
//#include "sdo_utl.hh" // SDO stand-alone utilities: dbg/err/wrn_prn()

#endif // LIBNCOXX_HH  
