/* $Id$
 *
 * Copyright (c) 2012-2016
 * by P. Wessel, W. H. F. Smith, R. Scharroo, J. Luis, and F. Wobbe
 * See LICENSE.TXT file for copying and redistribution conditions.
 */

/* gmt_core_module.c populates the external array of GMT core with
 * module parameters such as name, group, purpose and keys strings.
 * This file also contains the following convenience functions to
 * display all module purposes or just list their names:
 *
 *   void gmt_core_module_show_all (struct GMTAPI_CTRL *API);
 *   void gmt_core_module_list_all (void *API);
 *
 * These functions may be called by gmt --help and gmt --show-modules
 *
 * Developers of external APIs for accessing GMT modules will use this
 * function indirectly via GMT_Encode_Options to retrieve option keys
 * needed for module arg processing:
 *
 *   char * gmt_core_module_info (void *API, const char *module);
 *
 * DO NOT edit this file directly! Regenerate the file by running
 * 	gmt_make_module_src.sh core
 */
#include "gmt_dev.h"
#ifndef BUILD_SHARED_LIBS
#include "gmt_core_module.h"
#endif


/* Sorted array with information for all GMT core modules */

/* name, library, and purpose for each module */
struct Gmt_moduleinfo {
	const char *name;             /* Program name */
	const char *component;        /* Component (core, supplement, custom) */
	const char *purpose;          /* Program purpose */
	const char *keys;             /* Program option info for external APIs */
#ifndef BUILD_SHARED_LIBS
	/* gmt module function pointer: */
	int (*p_func)(void*, int, void*);
#endif
};

static struct Gmt_moduleinfo g_core_module[] = {
#ifdef BUILD_SHARED_LIBS
	{"blockmean", "core", "Block average (x,y,z) data tables by L2 norm", "<D{,>D},RG-"},
	{"blockmedian", "core", "Block average (x,y,z) data tables by L1 norm (spatial median)", "<D{,>D},RG-"},
	{"blockmode", "core", "Block average (x,y,z) data tables by mode estimation", "<D{,>D},RG-"},
	{"filter1d", "core", "Time domain filtering of 1-D data tables", "<D{,>D},FD("},
	{"fitcircle", "core", "Find mean position and great [or small] circle fit to points on sphere", "<D{,>T},>DF"},
	{"gmt2kml", "core", "Convert GMT data tables to KML files for Google Earth", "<D{,>T},CC("},
	{"gmtconnect", "core", "Connect individual lines whose end points match within tolerance", "<D{,>D},CD),LT),QT)"},
	{"gmtconvert", "core", "Convert, paste, or extract columns from data tables", "<D{,>D}"},
	{"gmtdefaults", "core", "List current GMT default parameters", ""},
	{"gmtget", "core", "Get individual GMT default parameters", ">T}"},
	{"gmtinfo", "core", "Get information about data tables", "<D{,>T},>DC"},
	{"gmtlogo", "core", "Plot the GMT logo on maps", ">X}"},
	{"gmtmath", "core", "Reverse Polish Notation (RPN) calculator for data tables", "<D{,AD(,TD(,>D}"},
	{"gmtread", "core", "Read GMT objects into external API", "<?{,>?},-T-"},
	{"gmtregress", "core", "Linear regression of 1-D data sets", "<D{,>D}"},
	{"gmtselect", "core", "Select data table subsets based on multiple spatial criteria", "<D{,CD(,FD(,LD(,>D},RG-"},
	{"gmtset", "core", "Change individual GMT default parameters", ""},
	{"gmtsimplify", "core", "Line reduction using the Douglas-Peucker algorithm", "<D{,>D}"},
	{"gmtspatial", "core", "Geospatial operations on lines and polygons", "<D{,DD(,ND(,TD(,>D},RG-,>TD,>TN+r"},
	{"gmtvector", "core", "Operations on Cartesian vectors in 2-D and 3-D", "<D{,AD(,>D}"},
	{"gmtwhich", "core", "Find full path to specified files", ">T}"},
	{"gmtwrite", "core", "Write GMT objects from external API", "<?{,>?},-T-"},
	{"grd2cpt", "core", "Make linear or histogram-equalized color palette table from grid", "<G{+,>C},RG-"},
	{"grd2rgb", "core", "Write r/g/b grid files from a grid file, a raw RGB file, or SUN rasterfile", "<G{,CC(,RG-"},
	{"grd2xyz", "core", "Convert grid file to data table", "<G{+,>D},RG-"},
	{"grdblend", "core", "Blend several partially over-lapping grids into one larger grid", "<T{,GG},RG-"},
	{"grdclip", "core", "Clip the range of grid values", "<G{,GG},RG-"},
	{"grdcontour", "core", "Make contour map using a grid", "<G{,CC(,DDD,>X},RG-"},
	{"grdconvert", "core", "Convert between different grid formats", "<G{,>G},RG-"},
	{"grdcut", "core", "Extract subregion from a grid", "<G{,GG},RG-"},
	{"grdedit", "core", "Modify header or content of a grid", "<G{,ND(,GG},RG-"},
	{"grdfft", "core", "Mathematical operations on grids in the wavenumber (or frequency) domain", "<G{+,GG},RG-,GDE"},
	{"grdfilter", "core", "Filter a grid in the space (or time) domain", "<G{,FG(,GG},RG-"},
	{"grdgradient", "core", "Compute directional gradients from a grid", "<G{,GG},SG),RG-"},
	{"grdhisteq", "core", "Perform histogram equalization for a grid", "<G{,GG},DT),RG-"},
	{"grdimage", "core", "Project grids or images and plot them on maps", "<G{+,CC(,IG(,>X},RG-,AIA"},
	{"grdinfo", "core", "Extract information from grids", "<G{+,>T},>DC,RG-"},
	{"grdlandmask", "core", "Create a \"wet-dry\" mask grid from shoreline data base", "GG},RG-"},
	{"grdmask", "core", "Create mask grid from polygons or point coverage", "<D{,GG},RG("},
	{"grdmath", "core", "Reverse Polish Notation (RPN) calculator for grids (element by element)", "<G{,=G},RG-"},
	{"grdpaste", "core", "Join two grids along their common edge", "<G{2,GG}"},
	{"grdproject", "core", "Forward and inverse map transformation of grids", "<G{,GG},RG-"},
	{"grdraster", "core", "Extract subregion from a binary raster and save as a GMT grid", "GG},TD),RG-"},
	{"grdsample", "core", "Resample a grid onto a new lattice", "<G{,GG},RG-"},
	{"grdtrack", "core", "Sample grids at specified (x,y) locations", "<D{,DD),E-<,GG(,>D},RG-,SD)"},
	{"grdtrend", "core", "Fit trend surface to grids and compute residuals", "<G{,DG),TG),WG),RG-"},
	{"grdvector", "core", "Plot vector field from two component grids", "<G{2,CC(,>X},RG-"},
	{"grdview", "core", "Create 3-D perspective image or surface mesh from a grid", "<G{,CC(,GG(,IG(,>X},RG-"},
	{"grdvolume", "core", "Calculate grid volume and area constrained by a contour", "<G{,>D},RG-"},
	{"greenspline", "core", "Interpolate using Green's functions for splines in 1-3 dimensions", "<D{,AD(,ND(,TG(,CD),G?},RG-,GDN"},
	{"kml2gmt", "core", "Extract GMT table data from Google Earth KML files", "<T{,>D}"},
	{"makecpt", "core", "Make GMT color palette tables", ">C},ED(,TD("},
	{"mapproject", "core", "Forward and inverse map transformations, datum conversions and geodesy", "<D{,LD(,>D},W-(,RG-"},
	{"nearneighbor", "core", "Grid table data using a \"Nearest neighbor\" algorithm", "<D{,GG},RG-"},
	{"project", "core", "Project table data onto lines or great circles, generate tracks, or translate coordinates", "<D{,>D},G-("},
	{"psbasemap", "core", "Plot base maps and frames", ">X},>DA,RG-"},
	{"psclip", "core", "Initialize or terminate polygonal clip paths", "<D{,>X},C-(,RG-"},
	{"pscoast", "core", "Plot continents, countries, shorelines, rivers, and borders on maps", ">X},>DM,RG-,>TE+w-rR"},
	{"pscontour", "core", "Contour table data by direct triangulation", "<D{,CC(,ED(,DDD,>X},RG-"},
	{"psconvert", "core", "Convert [E]PS file(s) to other formats using GhostScript", "<X{,FI)"},
	{"pshistogram", "core", "Calculate and plot histograms", "<D{,>X},>D),>DI"},
	{"psimage", "core", "Place images or EPS files on maps", "<I{,>X},RG-"},
	{"pslegend", "core", "Plot legends on maps", "<T{,>X},RG-"},
	{"psmask", "core", "Clip or mask map areas with no data table coverage", "<D{,DDD,C-(,>X},LG),RG-"},
	{"psrose", "core", "Plot a polar histogram (rose, sector, windrose diagrams)", "<D{,CD(,>X}"},
	{"psscale", "core", "Plot a gray-scale or color-scale on maps", "CC{,>X},RG-,ZD("},
	{"pssolar", "core", "Plot day-light terminators and other sunlight parameters", ">X},>DM,RG-"},
	{"pstext", "core", "Plot or typeset text on maps", "<T{,>X},RG-"},
	{"pswiggle", "core", "Plot z = f(x,y) anomalies along tracks", "<D{,>X},RG-"},
	{"psxyz", "core", "Plot lines, polygons, and symbols in 3-D", "<D{,CC(,T-<,>X},RG-"},
	{"psxy", "core", "Plot lines, polygons, and symbols on maps", "<D{,CC(,T-<,>X},RG-"},
	{"sample1d", "core", "Resample 1-D table data using splines", "<D{,ND(,>D}"},
	{"spectrum1d", "core", "Compute auto- [and cross-] spectra from one [or two] time series", "<D{,>D},T-)"},
	{"sph2grd", "core", "Compute grid from spherical harmonic coefficients", "<D{,GG},RG-"},
	{"sphdistance", "core", "Create Voronoi distance, node, or nearest-neighbor grid on a sphere", "<D{,ND(,QD(,GG},RG-,Q-("},
	{"sphinterpolate", "core", "Spherical gridding in tension of data on a sphere", "<D{,GG},RG-"},
	{"sphtriangulate", "core", "Delaunay or Voronoi construction of spherical data", "<D{,>D},ND)"},
	{"splitxyz", "core", "Split xyz[dh] data tables into individual segments", "<D{,>D}"},
	{"surface_mt", "core", "Grid table data using adjustable tension continuous curvature splines", "<D{,DD(,LG(,GG},RG-"},
	{"surface", "core", "Grid table data using adjustable tension continuous curvature splines", "<D{,DD(,LG(,GG},RG-"},
	{"trend1d", "core", "Fit a [weighted] [robust] polynomial [and/or Fourier] model for y = f(x) to xy[w] data", "<D{,>D}"},
	{"trend2d", "core", "Fit a [weighted] [robust] polynomial for z = f(x,y) to xyz[w] data", "<D{,>D}"},
	{"triangulate", "core", "Optimal (Delaunay) triangulation and gridding of Cartesian table data", "<D{,>D},GG),RG-"},
	{"xyz2grd", "core", "Convert data table to a grid file", "<D{,SD),GG},RG-,SD)"},
	{NULL, NULL, NULL, NULL} /* last element == NULL detects end of array */
#else
	{"blockmean", "core", "Block average (x,y,z) data tables by L2 norm", "<D{,>D},RG-", &GMT_blockmean},
	{"blockmedian", "core", "Block average (x,y,z) data tables by L1 norm (spatial median)", "<D{,>D},RG-", &GMT_blockmedian},
	{"blockmode", "core", "Block average (x,y,z) data tables by mode estimation", "<D{,>D},RG-", &GMT_blockmode},
	{"filter1d", "core", "Time domain filtering of 1-D data tables", "<D{,>D},FD(", &GMT_filter1d},
	{"fitcircle", "core", "Find mean position and great [or small] circle fit to points on sphere", "<D{,>T},>DF", &GMT_fitcircle},
	{"gmt2kml", "core", "Convert GMT data tables to KML files for Google Earth", "<D{,>T},CC(", &GMT_gmt2kml},
	{"gmtconnect", "core", "Connect individual lines whose end points match within tolerance", "<D{,>D},CD),LT),QT)", &GMT_gmtconnect},
	{"gmtconvert", "core", "Convert, paste, or extract columns from data tables", "<D{,>D}", &GMT_gmtconvert},
	{"gmtdefaults", "core", "List current GMT default parameters", "", &GMT_gmtdefaults},
	{"gmtget", "core", "Get individual GMT default parameters", ">T}", &GMT_gmtget},
	{"gmtinfo", "core", "Get information about data tables", "<D{,>T},>DC", &GMT_gmtinfo},
	{"gmtlogo", "core", "Plot the GMT logo on maps", ">X}", &GMT_gmtlogo},
	{"gmtmath", "core", "Reverse Polish Notation (RPN) calculator for data tables", "<D{,AD(,TD(,>D}", &GMT_gmtmath},
	{"gmtread", "core", "Read GMT objects into external API", "<?{,>?},-T-", &GMT_gmtread},
	{"gmtregress", "core", "Linear regression of 1-D data sets", "<D{,>D}", &GMT_gmtregress},
	{"gmtselect", "core", "Select data table subsets based on multiple spatial criteria", "<D{,CD(,FD(,LD(,>D},RG-", &GMT_gmtselect},
	{"gmtset", "core", "Change individual GMT default parameters", "", &GMT_gmtset},
	{"gmtsimplify", "core", "Line reduction using the Douglas-Peucker algorithm", "<D{,>D}", &GMT_gmtsimplify},
	{"gmtspatial", "core", "Geospatial operations on lines and polygons", "<D{,DD(,ND(,TD(,>D},RG-,>TD,>TN+r", &GMT_gmtspatial},
	{"gmtvector", "core", "Operations on Cartesian vectors in 2-D and 3-D", "<D{,AD(,>D}", &GMT_gmtvector},
	{"gmtwhich", "core", "Find full path to specified files", ">T}", &GMT_gmtwhich},
	{"gmtwrite", "core", "Write GMT objects from external API", "<?{,>?},-T-", &GMT_gmtwrite},
	{"grd2cpt", "core", "Make linear or histogram-equalized color palette table from grid", "<G{+,>C},RG-", &GMT_grd2cpt},
	{"grd2rgb", "core", "Write r/g/b grid files from a grid file, a raw RGB file, or SUN rasterfile", "<G{,CC(,RG-", &GMT_grd2rgb},
	{"grd2xyz", "core", "Convert grid file to data table", "<G{+,>D},RG-", &GMT_grd2xyz},
	{"grdblend", "core", "Blend several partially over-lapping grids into one larger grid", "<T{,GG},RG-", &GMT_grdblend},
	{"grdclip", "core", "Clip the range of grid values", "<G{,GG},RG-", &GMT_grdclip},
	{"grdcontour", "core", "Make contour map using a grid", "<G{,CC(,DDD,>X},RG-", &GMT_grdcontour},
	{"grdconvert", "core", "Convert between different grid formats", "<G{,>G},RG-", &GMT_grdconvert},
	{"grdcut", "core", "Extract subregion from a grid", "<G{,GG},RG-", &GMT_grdcut},
	{"grdedit", "core", "Modify header or content of a grid", "<G{,ND(,GG},RG-", &GMT_grdedit},
	{"grdfft", "core", "Mathematical operations on grids in the wavenumber (or frequency) domain", "<G{+,GG},RG-,GDE", &GMT_grdfft},
	{"grdfilter", "core", "Filter a grid in the space (or time) domain", "<G{,FG(,GG},RG-", &GMT_grdfilter},
	{"grdgradient", "core", "Compute directional gradients from a grid", "<G{,GG},SG),RG-", &GMT_grdgradient},
	{"grdhisteq", "core", "Perform histogram equalization for a grid", "<G{,GG},DT),RG-", &GMT_grdhisteq},
	{"grdimage", "core", "Project grids or images and plot them on maps", "<G{+,CC(,IG(,>X},RG-,AIA", &GMT_grdimage},
	{"grdinfo", "core", "Extract information from grids", "<G{+,>T},>DC,RG-", &GMT_grdinfo},
	{"grdlandmask", "core", "Create a \"wet-dry\" mask grid from shoreline data base", "GG},RG-", &GMT_grdlandmask},
	{"grdmask", "core", "Create mask grid from polygons or point coverage", "<D{,GG},RG(", &GMT_grdmask},
	{"grdmath", "core", "Reverse Polish Notation (RPN) calculator for grids (element by element)", "<G{,=G},RG-", &GMT_grdmath},
	{"grdpaste", "core", "Join two grids along their common edge", "<G{2,GG}", &GMT_grdpaste},
	{"grdproject", "core", "Forward and inverse map transformation of grids", "<G{,GG},RG-", &GMT_grdproject},
	{"grdraster", "core", "Extract subregion from a binary raster and save as a GMT grid", "GG},TD),RG-", &GMT_grdraster},
	{"grdsample", "core", "Resample a grid onto a new lattice", "<G{,GG},RG-", &GMT_grdsample},
	{"grdtrack", "core", "Sample grids at specified (x,y) locations", "<D{,DD),E-<,GG(,>D},RG-,SD)", &GMT_grdtrack},
	{"grdtrend", "core", "Fit trend surface to grids and compute residuals", "<G{,DG),TG),WG),RG-", &GMT_grdtrend},
	{"grdvector", "core", "Plot vector field from two component grids", "<G{2,CC(,>X},RG-", &GMT_grdvector},
	{"grdview", "core", "Create 3-D perspective image or surface mesh from a grid", "<G{,CC(,GG(,IG(,>X},RG-", &GMT_grdview},
	{"grdvolume", "core", "Calculate grid volume and area constrained by a contour", "<G{,>D},RG-", &GMT_grdvolume},
	{"greenspline", "core", "Interpolate using Green's functions for splines in 1-3 dimensions", "<D{,AD(,ND(,TG(,CD),G?},RG-,GDN", &GMT_greenspline},
	{"kml2gmt", "core", "Extract GMT table data from Google Earth KML files", "<T{,>D}", &GMT_kml2gmt},
	{"makecpt", "core", "Make GMT color palette tables", ">C},ED(,TD(", &GMT_makecpt},
	{"mapproject", "core", "Forward and inverse map transformations, datum conversions and geodesy", "<D{,LD(,>D},W-(,RG-", &GMT_mapproject},
	{"nearneighbor", "core", "Grid table data using a \"Nearest neighbor\" algorithm", "<D{,GG},RG-", &GMT_nearneighbor},
	{"project", "core", "Project table data onto lines or great circles, generate tracks, or translate coordinates", "<D{,>D},G-(", &GMT_project},
	{"psbasemap", "core", "Plot base maps and frames", ">X},>DA,RG-", &GMT_psbasemap},
	{"psclip", "core", "Initialize or terminate polygonal clip paths", "<D{,>X},C-(,RG-", &GMT_psclip},
	{"pscoast", "core", "Plot continents, countries, shorelines, rivers, and borders on maps", ">X},>DM,RG-,>TE+w-rR", &GMT_pscoast},
	{"pscontour", "core", "Contour table data by direct triangulation", "<D{,CC(,ED(,DDD,>X},RG-", &GMT_pscontour},
	{"psconvert", "core", "Convert [E]PS file(s) to other formats using GhostScript", "<X{,FI)", &GMT_psconvert},
	{"pshistogram", "core", "Calculate and plot histograms", "<D{,>X},>D),>DI", &GMT_pshistogram},
	{"psimage", "core", "Place images or EPS files on maps", "<I{,>X},RG-", &GMT_psimage},
	{"pslegend", "core", "Plot legends on maps", "<T{,>X},RG-", &GMT_pslegend},
	{"psmask", "core", "Clip or mask map areas with no data table coverage", "<D{,DDD,C-(,>X},LG),RG-", &GMT_psmask},
	{"psrose", "core", "Plot a polar histogram (rose, sector, windrose diagrams)", "<D{,CD(,>X}", &GMT_psrose},
	{"psscale", "core", "Plot a gray-scale or color-scale on maps", "CC{,>X},RG-,ZD(", &GMT_psscale},
	{"pssolar", "core", "Plot day-light terminators and other sunlight parameters", ">X},>DM,RG-", &GMT_pssolar},
	{"pstext", "core", "Plot or typeset text on maps", "<T{,>X},RG-", &GMT_pstext},
	{"pswiggle", "core", "Plot z = f(x,y) anomalies along tracks", "<D{,>X},RG-", &GMT_pswiggle},
	{"psxyz", "core", "Plot lines, polygons, and symbols in 3-D", "<D{,CC(,T-<,>X},RG-", &GMT_psxyz},
	{"psxy", "core", "Plot lines, polygons, and symbols on maps", "<D{,CC(,T-<,>X},RG-", &GMT_psxy},
	{"sample1d", "core", "Resample 1-D table data using splines", "<D{,ND(,>D}", &GMT_sample1d},
	{"spectrum1d", "core", "Compute auto- [and cross-] spectra from one [or two] time series", "<D{,>D},T-)", &GMT_spectrum1d},
	{"sph2grd", "core", "Compute grid from spherical harmonic coefficients", "<D{,GG},RG-", &GMT_sph2grd},
	{"sphdistance", "core", "Create Voronoi distance, node, or nearest-neighbor grid on a sphere", "<D{,ND(,QD(,GG},RG-,Q-(", &GMT_sphdistance},
	{"sphinterpolate", "core", "Spherical gridding in tension of data on a sphere", "<D{,GG},RG-", &GMT_sphinterpolate},
	{"sphtriangulate", "core", "Delaunay or Voronoi construction of spherical data", "<D{,>D},ND)", &GMT_sphtriangulate},
	{"splitxyz", "core", "Split xyz[dh] data tables into individual segments", "<D{,>D}", &GMT_splitxyz},
	{"surface_mt", "core", "Grid table data using adjustable tension continuous curvature splines", "<D{,DD(,LG(,GG},RG-", &GMT_surface_mt},
	{"surface", "core", "Grid table data using adjustable tension continuous curvature splines", "<D{,DD(,LG(,GG},RG-", &GMT_surface},
	{"trend1d", "core", "Fit a [weighted] [robust] polynomial [and/or Fourier] model for y = f(x) to xy[w] data", "<D{,>D}", &GMT_trend1d},
	{"trend2d", "core", "Fit a [weighted] [robust] polynomial for z = f(x,y) to xyz[w] data", "<D{,>D}", &GMT_trend2d},
	{"triangulate", "core", "Optimal (Delaunay) triangulation and gridding of Cartesian table data", "<D{,>D},GG),RG-", &GMT_triangulate},
	{"xyz2grd", "core", "Convert data table to a grid file", "<D{,SD),GG},RG-,SD)", &GMT_xyz2grd},
	{NULL, NULL, NULL, NULL, NULL} /* last element == NULL detects end of array */
#endif
};

/* Pretty print all GMT core module names and their purposes for gmt --help */
void gmt_core_module_show_all (void *V_API) {
	unsigned int module_id = 0;
	char message[GMT_LEN256];
	struct GMTAPI_CTRL *API = gmt_get_api_ptr (V_API);
	GMT_Message (V_API, GMT_TIME_NONE, "\n===  GMT core: The main modules of the Generic Mapping Tools  ===\n");
	while (g_core_module[module_id].name != NULL) {
		if (module_id == 0 || strcmp (g_core_module[module_id-1].component, g_core_module[module_id].component)) {
			/* Start of new supplemental group */
			snprintf (message, GMT_LEN256, "\nModule name:     Purpose of %s module:\n", g_core_module[module_id].component);
			GMT_Message (V_API, GMT_TIME_NONE, message);
			GMT_Message (V_API, GMT_TIME_NONE, "----------------------------------------------------------------\n");
		}
		if (API->mode || (strcmp (g_core_module[module_id].name, "gmtread") && strcmp (g_core_module[module_id].name, "gmtwrite"))) {
			snprintf (message, GMT_LEN256, "%-16s %s\n",
				g_core_module[module_id].name, g_core_module[module_id].purpose);
				GMT_Message (V_API, GMT_TIME_NONE, message);
		}
		++module_id;
	}
}

/* Produce single list on stdout of all GMT core module names for gmt --show-modules */
void gmt_core_module_list_all (void *V_API) {
	unsigned int module_id = 0;
	struct GMTAPI_CTRL *API = gmt_get_api_ptr (V_API);
	while (g_core_module[module_id].name != NULL) {
		if (API->mode || (strcmp (g_core_module[module_id].name, "gmtread") && strcmp (g_core_module[module_id].name, "gmtwrite")))
			printf ("%s\n", g_core_module[module_id].name);
		++module_id;
	}
}

/* Lookup module id by name, return option keys pointer (for external API developers) */
const char *gmt_core_module_info (void *API, char *candidate) {
	int module_id = 0;
	gmt_M_unused(API);

	/* Match actual_name against g_module[module_id].name */
	while (g_core_module[module_id].name != NULL &&
	       strcmp (candidate, g_core_module[module_id].name))
		++module_id;

	/* Return Module keys or NULL */
	return (g_core_module[module_id].keys);
}
	
#ifndef BUILD_SHARED_LIBS
/* Lookup module id by name, return function pointer */
void *gmt_core_module_lookup (void *API, const char *candidate) {
	int module_id = 0;
	gmt_M_unused(API);

	/* Match actual_name against g_module[module_id].name */
	while (g_core_module[module_id].name != NULL &&
	       strcmp (candidate, g_core_module[module_id].name))
		++module_id;

	/* Return Module function or NULL */
	return (g_core_module[module_id].p_func);
}
#endif
