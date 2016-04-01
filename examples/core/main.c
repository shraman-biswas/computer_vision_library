#include "main.h"

int main(void)
{
	printf("[ cv core example ]\n");

	/* image pixel data */
	const double img_data[] = {
		0, 0, 1, 0, 0,
		0, 1, 2, 1, 0,
		1, 2, 3, 2, 1,
		0, 1, 2, 1, 0,
		0, 0, 1, 0, 0,
	};

	/* create image matrix */
	MAT *img = cv_imcreate(img_data, 5, 5);

	/* print image pixels */
	printf("image:\n");
	cv_imprint(img);

	return EXIT_SUCCESS;
}
