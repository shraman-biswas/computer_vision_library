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
	img = cv_imcreate(img_data, 12, 12);
	printf("\nbinary image:\n");
	cv_imprint(img);

	/* labelled connected components */
	res = cv_conncomp(img, 0);
	printf("\nlabelled connected components:\n");
	cv_imprint(res);

	return EXIT_SUCCESS;
}
