#include "main.h"

/* binary image pixel data */
static double img_data[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0,
	0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0,
	0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0,
	0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0,
	0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0,
	0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0,
	0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0,
	0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

int main(void)
{
	printf("[ cv blob analysis example ]\n");

	MAT *img=NULL, *res=NULL;

	/* create image matrix */
	cv_imcreate(&img, img_data, 12, 12);
	printf("\nbinary image:\n");
	cv_imprint(img);
	/* cv_imshow("binary image", img); */

	/* labelled connected components */
	cv_conncomp(img, &res, 1);
	printf("\nlabelled connected components:\n");
	cv_imprint(res);
	cv_imshow("labelled connected components", res);

	return EXIT_SUCCESS;
}
