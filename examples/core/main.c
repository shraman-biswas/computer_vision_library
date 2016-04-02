#include "main.h"

/* image pixel data */
const double img_data[] = {
	0, 0, 1, 0, 0,
	0, 1, 2, 1, 0,
	1, 2, 3, 2, 1,
	0, 1, 2, 1, 0,
	0, 0, 1, 0, 0,
};

int main(void)
{
	printf("[ cv core example ]\n");

	/* create image matrix */
	MAT *img = cv_imcreate(img_data, 5, 5);

	/* print image pixels */
	printf("\nimage:\n");
	cv_imprint(img);

	return EXIT_SUCCESS;
}
