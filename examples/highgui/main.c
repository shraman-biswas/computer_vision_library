#include "main.h"

/* image pixel data */
const double img_data[] = {
	0, 0, 0, 1, 0, 0, 0,
	0, 0, 1, 2, 1, 0, 0,
	0, 1, 2, 3, 2, 1, 0,
	1, 2, 3, 4, 3, 2, 1,
	0, 1, 2, 3, 2, 1, 0,
	0, 0, 1, 2, 1, 0, 0,
	0, 0, 0, 1, 0, 0, 0,
};

int main(void)
{
	printf("[ cv highgui example ]\n");

	/* create image matrix */
	MAT *img = cv_imcreate(img_data, 7, 7);

	/* print image pixels */
	printf("\nimage:\n");
	cv_imprint(img);

	/* show image */
	cv_imshow("image", img);

	return EXIT_SUCCESS;
}
