#include "highgui.h"

/* show image matrix */
void cv_imshow(const char *str, const MAT *m)
{
	double tmp[m->size1][m->size2], **data = (double **)tmp;
	PLFLT w = m->size1, h = m->size2;

	/* allocate image memory and convert matrix to 2d array */
	plAlloc2dGrid(&data, w, h);
	cv_to2d(m, data);

	/* initialize plplot */
	plsetopt("plwindow", str);
	plsetopt("geometry", "400x400");
	plsetopt("ori", "1");
	plstart("xwin", 1, 1);
	pladv(0);
	plvpas(0, 1, 0, 1, h / w);
	plwind(0, w, 0, h);

	/* plot image */
	plimage((const PLFLT **)data,	/* idata */
		w, h,			/* nx, ny */
		0, w, 0, h,		/* xmin, xmax, ymin, ymax */
		0, 0,			/* zmin, zmax */
		0, w, 0, h);		/* Dxmin, Dxmax, Dymin, Dymax */

	/* free image memory and end plplot */
	plFree2dGrid(data, w, h);
	plend();
}
