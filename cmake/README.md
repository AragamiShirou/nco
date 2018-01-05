# nco_bld
build NCO and its dependencies on Windows

http://nco.sourceforge.net/

Do

```
clone
bld
```

this clones and builds

```
zlib
hdf5
curl
netcdf
nco
```

## Options

Use static linking of the C Run-time Library (CRT)

```
bld crt
```

# Changes needed

## libcurl (if building with CMake)

edit libcurl.vcxproj to include ws2_32.lib as library dependenccy and set LinkLibraryDependencies as true

```
<Lib>
<AdditionalOptions>%(AdditionalOptions) /machine:x64</AdditionalOptions>
<AdditionalDependencies>ws2_32.lib</AdditionalDependencies>
</Lib>
<ProjectReference>
<LinkLibraryDependencies>true</LinkLibraryDependencies>
</ProjectReference>
```


## hdf5

edit hdf5-static.vcxproj and add full path of zlib library as dependency

```
<Lib>
<AdditionalOptions>%(AdditionalOptions) /machine:x64</AdditionalOptions>
<AdditionalDependencies>I:\nco\cmake\zlib\build\Debug\zlibstaticd.lib</AdditionalDependencies>
</Lib>
```

edit CMakeLists.txt at root and add for case when static linking of the C Run-time Library (CRT)

```
INCLUDE(config/cmake/UserMacros/WINDOWS_MT.cmake)
```

## netcdf

edit netcdf.vcxproj and add full path of HDF5 and curl libraries as dependencies

```
<Lib>
<AdditionalOptions>%(AdditionalOptions) /machine:x64</AdditionalOptions>
<AdditionalDependencies>I:\nco\cmake\hdf5\build\bin\Debug\libhdf5_hl_D.lib;I:\nco\cmake\hdf5\build\bin\Debug\libhdf5_D.lib;I:\nco\cmake\curl\builds\libcurl-vc14-x64-debug-static-ipv6-sspi-winssl\lib\libcurl_a_debug.lib;%(AdditionalDependencies)</AdditionalDependencies>
</Lib>
```

edit CMakeLists.txt and add an option to detect the HDF5 HL library

```
INCLUDE_DIRECTORIES(${HDF5_HL_INCLUDE_DIR})
```

# NCO CMake build

NCO should detect the ZLIB dependency in HDF5 as

```
-- Looking for H5Z_DEFLATE in I:/nco/cmake/hdf5/build/bin/Debug/libhdf5_D.lib
-- Looking for H5Z_DEFLATE in I:/nco/cmake/hdf5/build/bin/Debug/libhdf5_D.lib - found
-- ZLIB library is needed...
```

the netcdf function detection should be

```
-- Found netcdf library at: I:/nco/cmake/netcdf-c/build/liblib/Debug/netcdf.lib
-- Looking for nc_inq_path in I:/nco/cmake/netcdf-c/build/liblib/Debug/netcdf.lib
-- Looking for nc_inq_path in I:/nco/cmake/netcdf-c/build/liblib/Debug/netcdf.lib - found
```

# NCO tests

```
ncks.exe -v lat http://www.esrl.noaa.gov/psd/thredds/dodsC/Datasets/cmap/enh/precip.mon.mean.nc
```

it requires curl built with WinSSL (default)

# Changes needed for static CRT

To static linking of the C Run-time Library (CRT), these changes must be made for the following libraries,
in the CMakeLists.txt file

```
set(MSVC_USE_STATIC_CRT off CACHE BOOL "Use MT flags when compiling in MSVC")
if (MSVC)
  if (MSVC_USE_STATIC_CRT)
     message("-- Using static CRT ${MSVC_USE_STATIC_CRT}")
     foreach(flag_var CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE
                          CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO
                          CMAKE_C_FLAGS_DEBUG CMAKE_C_FLAGS_RELEASE
                          CMAKE_C_FLAGS_MINSIZEREL CMAKE_C_FLAGS_RELWITHDEBINFO)
       string(REPLACE "/MD" "/MT" ${flag_var} "${${flag_var}}")
     endforeach()
  endif()
endif()
```

## zlib

https://github.com/madler/zlib

## expat (dependency for UDUNITS-2)

https://github.com/libexpat/libexpat

## UDUNITS-2

https://github.com/Unidata/UDUNITS-2



