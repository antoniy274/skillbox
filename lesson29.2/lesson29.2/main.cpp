#include "lesson29.2.h"


int main()
{
	Circle c{ 5 };
	c.printParams(&c);

	Rectangle r(2, 7);
	r.printParams(&r);

	Triangle t(5);
	t.printParams(&t);
}
