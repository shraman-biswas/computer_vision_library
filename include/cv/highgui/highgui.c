#include "highgui.h"

/* TODO: fix bug - error if m is non-squre */
/* show image matrix */
void cv_imshow(const char *str, const MAT *m)
{
	double tmp[m->size1][m->size2], **data = (double **)tmp;

	/* allocate image memory and convert to 2D array */
	plAlloc2dGrid(&data, m->size2, m->size1);
	cv_to2d(m, data);

	/* initialize plplot */
	plsetopt("plwindow", str);
	plsetopt("geometry", "500x500");
	plsdev("xwin");
	plinit();
	pladv(0);
	plvpas(0, 1, 0, 1, m->size1 / m->size2);
	plwind(0, m->size2, 0, m->size1);
	/* plenv(0, m->size2, 0, m->size1, 1, -2); */

	/* plot image */
	plimage((const PLFLT **)data,
		m->size2, m->size1,
		0, m->size2, 0, m->size1,
		0, 0,
		0, m->size2, 0, m->size1);

	/* free image memory and end plplot */
	plFree2dGrid(data, m->size2, m->size1);
	plend();
}
