/* $Id$
 *
 * Copyright (c) 2012
 * by P. Wessel, W. H. F. Smith, R. Scharroo, J. Luis, and F. Wobbe
 * See LICENSE.TXT file for copying and redistribution conditions.
 */

/* gmt_module.h declares the array that contains GMT module parameters such as
 * name and purpose strings, and function pointers to call the module functions.
 * DO NOT edit this file directly! Instead edit gmt_moduleinfo.txt and regenerate
 * this file with gmt_make_module_src.sh. */

#pragma once
#ifndef _GMT_MODULE_H
#define _GMT_MODULE_H

#ifdef __cplusplus /* Basic C++ support */
extern "C" {
#endif

/* CMake definitions: This must be first! */
#include "gmt_config.h"

/* Declaration modifiers for DLL support (MSC et al) */
#include "declspec.h"

/* API mode */
enum Api_mode {
  _Api_mode_must_promote_to_int = -1,
  k_mode_gmt,
  k_mode_psl
};

struct GMTAPI_CTRL; /* Forward declaration of GMTAPI_CTRL */

/* name, purpose, Api_mode, and function pointer for each GMT module */
struct Gmt_moduleinfo {
  char *name;             /* Program name */
  char *component;        /* Component (core or supplement) */
  char *purpose;          /* Program purpose */
  enum Api_mode api_mode; /* Either k_mode_gmt or k_mode_psl*/
  /* gmt module function pointer: */
  int (*p_func)(struct GMTAPI_CTRL*, int, void*);
};

/* external array with program paramerters for all GMT modules */
EXTERN_MSC struct Gmt_moduleinfo g_module[];

/* enumerator with same order and length as array g_module */
enum Gmt_module {
  k_mod_backtracker = 0,
  k_mod_blockmean,
  k_mod_blockmedian,
  k_mod_blockmode,
  k_mod_colmath,
  k_mod_filter1d,
  k_mod_fitcircle,
  k_mod_gmt2kml,
  k_mod_gmtaverage,
  k_mod_gmtconvert,
  k_mod_gmtdefaults,
  k_mod_gmtdp,
  k_mod_gmtget,
  k_mod_gmtmath,
  k_mod_gmtselect,
  k_mod_gmtset,
  k_mod_gmtspatial,
  k_mod_gmtstitch,
  k_mod_gmtvector,
  k_mod_gmtwhich,
  k_mod_gravfft,
  k_mod_grd2cpt,
  k_mod_grd2rgb,
  k_mod_grd2xyz,
  k_mod_grdblend,
  k_mod_grdclip,
  k_mod_grdcontour,
  k_mod_grdcut,
  k_mod_grdedit,
  k_mod_grdfft,
  k_mod_grdfilter,
  k_mod_grdgradient,
  k_mod_grdhisteq,
  k_mod_grdimage,
  k_mod_grdinfo,
  k_mod_grdlandmask,
  k_mod_grdmask,
  k_mod_grdmath,
  k_mod_grdokb,
  k_mod_grdpaste,
  k_mod_grdpmodeler,
  k_mod_grdproject,
  k_mod_grdraster,
  k_mod_grdreformat,
  k_mod_grdrotater,
  k_mod_grdsample,
  k_mod_grdspotter,
  k_mod_grdtrack,
  k_mod_grdtrend,
  k_mod_grdvector,
  k_mod_grdview,
  k_mod_grdvolume,
  k_mod_greenspline,
  k_mod_gshhg,
  k_mod_hotspotter,
  k_mod_img2grd,
  k_mod_kml2gmt,
  k_mod_makecpt,
  k_mod_mapproject,
  k_mod_mgd77convert,
  k_mod_mgd77info,
  k_mod_mgd77list,
  k_mod_mgd77magref,
  k_mod_mgd77manage,
  k_mod_mgd77path,
  k_mod_mgd77sniffer,
  k_mod_mgd77track,
  k_mod_minmax,
  k_mod_nearneighbor,
  k_mod_originator,
  k_mod_project,
  k_mod_ps2raster,
  k_mod_psbasemap,
  k_mod_psclip,
  k_mod_pscoast,
  k_mod_pscontour,
  k_mod_pscoupe,
  k_mod_pshistogram,
  k_mod_psimage,
  k_mod_pslegend,
  k_mod_psmask,
  k_mod_psmeca,
  k_mod_pspolar,
  k_mod_psrose,
  k_mod_psscale,
  k_mod_pssegy,
  k_mod_pssegyz,
  k_mod_pstext,
  k_mod_psvelo,
  k_mod_pswiggle,
  k_mod_psxy,
  k_mod_psxyz,
  k_mod_redpol,
  k_mod_rotconverter,
  k_mod_sample1d,
  k_mod_segy2grd,
  k_mod_spectrum1d,
  k_mod_sphdistance,
  k_mod_sphinterpolate,
  k_mod_sphtriangulate,
  k_mod_splitxyz,
  k_mod_surface,
  k_mod_testapi,
  k_mod_trend1d,
  k_mod_trend2d,
  k_mod_triangulate,
  k_mod_x2sys_binlist,
  k_mod_x2sys_cross,
  k_mod_x2sys_datalist,
  k_mod_x2sys_get,
  k_mod_x2sys_init,
  k_mod_x2sys_list,
  k_mod_x2sys_merge,
  k_mod_x2sys_put,
  k_mod_x2sys_report,
  k_mod_x2sys_solve,
  k_mod_xyz2grd,
  k_mod_xyzokb,
  k_mod_notfound
};

/* function prototypes of all GMT modules */
EXTERN_MSC int GMT_backtracker (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_blockmean (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_blockmedian (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_blockmode (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_colmath (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_filter1d (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_fitcircle (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_gmt2kml (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_gmtaverage (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_gmtconvert (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_gmtdefaults (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_gmtdp (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_gmtget (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_gmtmath (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_gmtselect (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_gmtset (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_gmtspatial (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_gmtstitch (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_gmtvector (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_gmtwhich (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_gravfft (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_grd2cpt (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_grd2rgb (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_grd2xyz (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_grdblend (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_grdclip (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_grdcontour (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_grdcut (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_grdedit (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_grdfft (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_grdfilter (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_grdgradient (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_grdhisteq (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_grdimage (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_grdinfo (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_grdlandmask (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_grdmask (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_grdmath (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_grdokb (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_grdpaste (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_grdpmodeler (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_grdproject (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_grdraster (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_grdreformat (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_grdrotater (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_grdsample (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_grdspotter (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_grdtrack (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_grdtrend (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_grdvector (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_grdview (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_grdvolume (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_greenspline (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_gshhg (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_hotspotter (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_img2grd (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_kml2gmt (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_makecpt (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_mapproject (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_mgd77convert (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_mgd77info (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_mgd77list (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_mgd77magref (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_mgd77manage (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_mgd77path (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_mgd77sniffer (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_mgd77track (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_minmax (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_nearneighbor (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_originator (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_project (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_ps2raster (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_psbasemap (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_psclip (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_pscoast (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_pscontour (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_pscoupe (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_pshistogram (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_psimage (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_pslegend (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_psmask (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_psmeca (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_pspolar (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_psrose (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_psscale (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_pssegy (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_pssegyz (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_pstext (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_psvelo (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_pswiggle (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_psxy (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_psxyz (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_redpol (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_rotconverter (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_sample1d (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_segy2grd (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_spectrum1d (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_sphdistance (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_sphinterpolate (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_sphtriangulate (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_splitxyz (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_surface (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_testapi (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_trend1d (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_trend2d (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_triangulate (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_x2sys_binlist (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_x2sys_cross (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_x2sys_datalist (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_x2sys_get (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_x2sys_init (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_x2sys_list (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_x2sys_merge (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_x2sys_put (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_x2sys_report (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_x2sys_solve (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_xyz2grd (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);
EXTERN_MSC int GMT_xyzokb (struct GMTAPI_CTRL *api_ctrl, int mode, void *args);

/* Pretty print all module names and their purposes */
EXTERN_MSC void gmt_module_show_all();

/* Pretty print module names and purposes */
EXTERN_MSC void gmt_module_show_name_and_purpose(struct Gmt_moduleinfo module);

/* Lookup module id by name */
EXTERN_MSC enum Gmt_module gmt_module_lookup (char *candidate);

#ifdef __cplusplus
}
#endif

#endif /* !_GMT_MODULE_H */
